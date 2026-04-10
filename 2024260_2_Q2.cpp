#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
class person{
    public:
    string name;
    string address;
    int number;
};

struct Node
{
    person pers;
    Node* next;

    Node(string pname, string paddress, int num){
        pers.name = pname;
        pers.address = paddress;
        pers.number = num;
        next = nullptr;
    }
};

class Linkedlist{
    private:
    Node* head;
    public:
    Linkedlist(){
        head = nullptr;
    }
    void display(){
        Node* current = head;
        while(current!= nullptr){
            cout<<current->pers.name<<"->";
            current = current->next;
        }
        cout<<" NULL "<<endl;
    }
    void insert(string pname, string paddress, int num){
        Node* newnode = new Node(pname, paddress, num);
        if(!head){
           
            head = newnode;
            return;
        }
        else if(head->next == nullptr){
           
            if(head->pers.name > newnode->pers.name){
                newnode->next = head;
                head = newnode;
                return;
            }
            else{
                head->next = newnode;
                return;
            }
        }
        else{
            Node* current = head;
            while(current->next!=nullptr){
                if(current->next->pers.name>newnode->pers.name){
                    newnode->next = current->next;
                    current->next = newnode;
                    return;
                }
                current = current->next;
            }
            if(current->next==nullptr){
                current->next = newnode; 
            }
            return;
        }
    }

   void find(string pname) {
    Node* current = head;
    bool found = false;

    
    for (auto &ch : pname) {
        ch = tolower(ch);
    }

    while (current != nullptr) {
        string temp = current->pers.name;

        
        for (auto &ch : temp) {
            ch = tolower(ch);
        }

        if (temp == pname) {
            cout << "Found!" << endl;
            cout << "Name: " << current->pers.name << endl;
            cout << "Address: " << current->pers.address << endl;
            cout << "Phone number: " << current->pers.number << endl;
            found = true;
            break;  
        }

        current = current->next;  
    }

    if (!found) {
        cout << "Person not found!" << endl;
    }
}
};

int main() {
    Linkedlist l1;
    int n;

    cout << "How many people do you want to insert? ";
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        string name, address;
        int number;

        cout << "\nEnter details for person " << i + 1 << ":\n";

        cout << "Name: ";
        getline(cin, name);   

        cout << "Address: ";
        getline(cin, address);

        cout << "Phone number: ";
        cin >> number;
        cin.ignore(); 

        l1.insert(name, address, number);
    }

    cout << "\n--- Displaying List ---\n";
    l1.display();

    while (true) {
        string searchName;
        cout << "\nEnter a name to search (or type 'exit' to quit): ";
        getline(cin, searchName);

        if (searchName == "exit" || searchName == "Exit" || searchName == "EXIT") {
            cout << "Exiting search.\n";
            break;
        }

        l1.find(searchName);
    }

    return 0;
}
