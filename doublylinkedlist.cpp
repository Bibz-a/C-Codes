#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class DLL{
    private:
    Node* head;
    Node* tail;
    public:
    DLL(){
        head = nullptr;
        tail = nullptr;
    }
    void insertathead(int val){
        Node* newnode = new Node(val);
        if(head == nullptr){
            head = newnode;
            tail = newnode;
        }
        else{
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    void insertattail(int val){
        Node* newnode = new Node(val);
        if(head == nullptr){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    void reverseDll(){
        Node* temp = nullptr;
        Node* current = head;
        while(current!=nullptr){
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if(temp!=nullptr){
            head = temp->prev;
        }

    }
    void insertatmid(int val){
        Node* newnode = new Node(val);
        if(head == nullptr){
            head = newnode;
            tail = newnode;
        }
        else{
            Node* slow = head;
            Node* fast = head;
            while(fast!=nullptr && fast->next!= nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            Node* mid = slow;
            Node* midnext = slow->next;
            if(midnext!=nullptr && mid!=nullptr){
                mid->next = newnode;
                newnode->prev = mid;
                newnode->next = midnext;
                midnext->prev = newnode;
            }
        }
    }
    void display(){
        Node* current = head;
        cout<<"NULL<−>";
        while(current!=nullptr){
            cout<<current->data<<"<−>";
            current = current->next;
        }
        cout<<"NULL"<<endl;
    }
    void traversereverse(){
        if (head == nullptr)
        return;
        Node* current = tail;
        cout<<"NULL<−>";
        while(current!=nullptr){
            cout<<current->data<<"<−>";
            current = current->prev;
        }
        cout<<"NULL"<<endl;
    }
    void deleteathead(){
        if (head == nullptr)
        return;
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    void deleteattail(){
         Node* temp = tail;
         tail = tail->prev;
         tail->next = nullptr;
         delete temp;
    }
    void deletebyval(int val) {
    if (head == nullptr)
        return; 

    Node* current = head;

    // find the node
    while (current != nullptr && current->data != val) {
        current = current->next;
    }

    // value not found
    if (current == nullptr)
        return;

    if (current == head) {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete current;
        return;
    }
    if (current->next != nullptr) // if not last node
        current->next->prev = current->prev;

    if (current->prev != nullptr) // if not head
        current->prev->next = current->next;

    delete current;
}
    
    void deleteAll(int val) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == val) {
            Node* temp = current; 
            current = current->next;

            // if it's the head
            if (temp == head) {
                head = temp->next;
                if (head != nullptr)
                    head->prev = nullptr;
            }
            // if it's the tail
            else if (temp == tail) {
                tail = temp->prev;
                if (tail != nullptr)
                    tail->next = nullptr;
            }
            // if it's in the middle
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
        } 
        else {
            current = current->next;
        }
    }
}

};

int main() {
    DLL l1;
    l1.insertattail(3);
    l1.insertattail(1);
    l1.insertattail(5);
    l1.insertattail(9);
    l1.insertatmid(2);
    l1.insertathead(9);
    l1.insertathead(9);
    l1.display();
    l1.deleteAll(9);
    l1.display();
    return 0;
}