#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* next;

    Node(int pval){
        value = pval;
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

    void InsertVal(int val){
        Node* newnode = new Node(val);

        if(!head){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }
    void printlist(){
        Node* current = head;
        while(current){
            cout<<current->value<<" -> ";
            current = current->next;
        } 
        cout<<" null "<<endl;
    }

    void detectloop(){
        Node* slow = head;
        Node* fast = head;
        int count = 0;
        while(fast!=nullptr && fast->next!= nullptr){
            slow = slow->next;
            count++;
            fast = fast->next->next;
            if(slow == fast){
                cout<<"loop found at : "<<count<<endl;
                fast->next=nullptr;
                cout<<"removed the loop."<<endl;
                return;
            }
        }
        cout<<"No loop found"<<endl;
    }
    void createloop() {
        if (!head || !head->next) return;

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head->next; 
        cout<<"loop created"<<endl;
    }
};
int main() {
   
    Linkedlist list;

    list.InsertVal(10);
    list.InsertVal(20);
    list.InsertVal(30);

    list.printlist();     
    list.detectloop();    

    list.createloop();    
    list.detectloop();
    list.detectloop();
    return 0;
}
