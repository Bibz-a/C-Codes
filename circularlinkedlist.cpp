#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int vals){
        val = vals;
        next = nullptr;
    }
};

class circularlist{
    private:
    Node* head;
    Node* tail;
    public:
    circularlist(){
        head = nullptr;
        tail = nullptr;
    }
    void insertathead(int val){
        Node* newnode = new Node(val);
        if(tail == nullptr){
            head = newnode;
            tail = newnode;
            tail->next = head;
        }
        else{
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
    }

    void insertattail(int val){
        Node* newnode = new Node(val);
        if(tail == nullptr){
            head = newnode;
            tail = newnode;
            tail->next = head;
        }
        else{
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }

    void display(){
        Node* current = head;
        while(current->next!= head){
            cout<<current->val<<"->";
            current = current->next;
        }
        cout<<current->val<<"->"<<"NULL"<<endl;
    }

    void deleteathead(){
        if(tail == nullptr){
            cout<<"not enough elements"<<endl;
            return;
        }
        Node* temp = head;
        tail->next = head->next;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    void deleteattail(){
        if(tail == nullptr){
            cout<<"not enough elements"<<endl;
            return;
        }
        Node* temp = tail;
        Node* current = head;
        while(current->next != tail){
            current = current->next;
        }
        tail = current;
        tail->next = head;
        temp->next = nullptr;
        delete temp;
    }
};
int main() {
    circularlist c1;
    c1.insertathead(3);
    c1.insertathead(4);
    c1.insertathead(5);
    c1.insertattail(6);
    c1.display();
    c1.deleteathead();
    c1.deleteathead();
    c1.deleteattail();
    c1.display();

    
    return 0;
}
