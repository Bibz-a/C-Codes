from datetime import datetime  # for meta

class Transaction:
    counter = 1  # unique monotonic ID

    def __init__(self, tran_type, amount, balanceafter, meta=""):
        self.id = Transaction.counter
        Transaction.counter += 1
        self.type = tran_type
        self.amount = amount
        self.balance_after = balanceafter
        self.meta = meta
        self.time = datetime.now()

    def __str__(self):
        meta_str = f" {self.meta}" if self.meta else ""
        return f"TX {self.id} {self.type} {self.amount} BAL {self.balance_after}{meta_str}"


class Account:
    def __init__(self, acc_no, name, pin, balance):
        self.__account_no = acc_no
        self.__holder_name = name
        self.__pin = str(pin)
        self.__balance = balance
        self.__daily_withdrawn = 0
        self.__transactions = []

    def check_pin(self, entered_pin):
        return self.__pin == str(entered_pin)

    def get_balance(self):
        return self.__balance

    def get_daily_withdrawn(self):
        return self.__daily_withdrawn

    def withdraw(self, amount):
        self.__balance -= amount
        self.__daily_withdrawn += amount

    def deposit(self, amount):
        self.__balance += amount

    def can_withdraw(self, amount):
        return self.__balance >= amount

    def add_tx(self, tx):
        self.__transactions.append(tx)
        if len(self.__transactions) > 10:
            self.__transactions.pop(0)

    def mini(self):
        if not self.__transactions:
            print("TX NONE")
        else:
            print("\n--- MINI STATEMENT ---")
            for tx in reversed(self.__transactions[-5:]):
                print(tx)
            print("----------------------\n")

    @property
    def account_no(self):
        return self.__account_no


class CashCassette:
    def __init__(self):
        self.notes = {5000: 10, 1000: 25, 500: 30, 100: 50}

    def dispense(self, amount):
        combo = self._find_combi(amount)
        if combo is None:
            return None
        for d, c in combo.items():
            self.notes[d] -= c
        return combo

    def _find_combi(self, amount):
        denum = sorted(self.notes.keys(), reverse=True)

        def greedy_try(notes_left):
            remaining = amount
            use = {}
            for d in denum:
                can_use = min(notes_left[d], remaining // d)
                use[d] = can_use
                remaining -= can_use * d
            return use if remaining == 0 else None

        firsttry = greedy_try(self.notes)
        if firsttry:
            return firsttry

        for d in denum:
            for reduceby in range(1, self.notes[d] + 1):
                temp = dict(self.notes)
                temp[d] -= reduceby
                t = greedy_try(temp)
                if t:
                    t[d] = t.get(d, 0)
                    return t
        return None


class Bank:
    def __init__(self):
        self.accounts = {}
        self.cassette = CashCassette()
        self.add_account(Account("1001", "ALI RAZA", "1234", 50000))
        self.add_account(Account("1002", "AYESHA M RAZA", "2468", 20000))
        self.add_account(Account("1003", "HAMZA B ZUBAIR", "1357", 150000))

    def add_account(self, acc):
        self.accounts[int(acc.account_no)] = acc

    def get_account(self, acc_no):
        return self.accounts.get(int(acc_no))


class ATM:
    def __init__(self, bank):
        self.bank = bank
        self.state = "IDLE"
        self.current_account = None
        self.pin_tries = 0

    def show_menu(self):
        print("\n===== ATM MENU =====")
        if self.state == "IDLE":
            print("1. Insert Card")
            print("0. Exit")
        elif self.state == "CARD_INSERTED":
            print("1. Enter PIN")
            print("2. Eject Card")
        elif self.state == "AUTHENTICATED":
            print("1. Balance Inquiry")
            print("2. Withdraw Cash")
            print("3. Deposit Cash")
            print("4. Transfer Funds")
            print("5. Mini Statement")
            print("6. Eject Card")
        print("====================")

    def card_insert(self):
        acc_no = input("Enter account number: ")
        acc = self.bank.get_account(acc_no)
        if not acc:
            print("ERROR UNKNOWN_ACCOUNT")
            return
        self.current_account = acc
        self.state = "CARD_INSERTED"
        self.pin_tries = 0
        print(f"CARD_OK {acc.account_no}")

    def enter_pin(self):
        pin = input("Enter PIN: ")
        if self.current_account.check_pin(pin):
            print("PIN_OK")
            self.state = "AUTHENTICATED"
            self.current_account.add_tx(Transaction("PIN", 0, self.current_account.get_balance()))
        else:
            self.pin_tries += 1
            rem = 3 - self.pin_tries
            if rem == 0:
                print("CARD_EJECTED (Too many wrong tries)")
                self.state = "IDLE"
                self.current_account = None
            else:
                print(f"PIN_INVALID {rem} tries left")

    def balance(self):
        bal = self.current_account.get_balance()
        print(f"BALANCE {bal}")
        self.current_account.add_tx(Transaction("BALANCE", 0, bal))

    def withdraw(self):
        try:
            amount = int(input("Enter amount to withdraw: "))
        except:
            print("ERROR FORMAT")
            return
        if amount % 100 != 0 or amount < 100 or amount > 50000:
            print("ERROR AMOUNT_INVALID")
            return
        if not self.current_account.can_withdraw(amount):
            print("ERROR INSUFFICIENT_FUNDS")
            return
        if self.current_account.get_daily_withdrawn() + amount > 100000:
            print("ERROR DAILY_LIMIT_EXCEEDED")
            return
        mix = self.bank.cassette.dispense(amount)
        if not mix:
            print("ERROR DENOMINATION_UNAVAILABLE")
            return
        self.current_account.withdraw(amount)
        mix_str = " ".join([f"{d}x{c}" for d, c in mix.items() if c > 0])
        print(f"WITHDRAW_OK {amount} {mix_str}")
        meta = "MIX=" + ",".join([f"{d}x{c}" for d, c in mix.items() if c > 0])
        self.current_account.add_tx(Transaction("WITHDRAW", amount, self.current_account.get_balance(), meta))

    def deposit(self):
        try:
            amt = int(input("Enter amount to deposit: "))
        except:
            print("ERROR FORMAT")
            return
        if amt <= 0 or amt % 100 != 0:
            print("ERROR AMOUNT_INVALID")
            return
        self.current_account.deposit(amt)
        print(f"DEPOSIT_OK {amt}")
        self.current_account.add_tx(Transaction("DEPOSIT", amt, self.current_account.get_balance()))

    def transfer(self):
        target_no = input("Enter target account number: ")
        target_acc = self.bank.get_account(target_no)
        if not target_acc:
            print("ERROR TARGET_UNKNOWN")
            return
        try:
            amt = int(input("Enter amount to transfer: "))
        except:
            print("ERROR FORMAT")
            return
        if target_acc == self.current_account:
            print("ERROR TARGET_SAME_AS_SOURCE")
            return
        if amt <= 0 or amt > self.current_account.get_balance():
            print("ERROR INSUFFICIENT_FUNDS")
            return
        self.current_account.withdraw(amt)
        target_acc.deposit(amt)
        print(f"TRANSFER_OK {amt} to {target_no}")
        self.current_account.add_tx(Transaction("TRANSFER_OUT", amt, self.current_account.get_balance(), f"TO={target_no}"))
        target_acc.add_tx(Transaction("TRANSFER_IN", amt, target_acc.get_balance(), f"FROM={self.current_account.account_no}"))

    def eject(self):
        print("CARD_EJECTED")
        self.state = "IDLE"
        self.current_account = None


# Main Program (menu loop)
bank = Bank()
atm = ATM(bank)

print("=== Welcome to State Machine ATM ===")

while True:
    atm.show_menu()
    choice = input("Enter choice: ")

    if atm.state == "IDLE":
        if choice == "1":
            atm.card_insert()
        elif choice == "0":
            print("Goodbye!")
            break
        else:
            print("Invalid choice.")

    elif atm.state == "CARD_INSERTED":
        if choice == "1":
            atm.enter_pin()
        elif choice == "2":
            atm.eject()
        else:
            print("Invalid choice.")

    elif atm.state == "AUTHENTICATED":
        if choice == "1":
            atm.balance()
        elif choice == "2":
            atm.withdraw()
        elif choice == "3":
            atm.deposit()
        elif choice == "4":
            atm.transfer()
        elif choice == "5":
            atm.current_account.mini()
        elif choice == "6":
            atm.eject()
        else:
            print("Invalid choice.")
