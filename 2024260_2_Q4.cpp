#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* next;
    Node* prev;

    Node(int pval){
        value = pval;
        next = nullptr;
        prev = nullptr;
    }
};

class Linkedlist{
    private:
    Node* head;
    public:
    Linkedlist(){
        head = nullptr;
    }

    void insert(int val){
        Node* newnode = new Node(val);
        if(!head){
            head = newnode;
        }
        else{
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    int returnlen(){
        int count = 0;
        Node* current = head;
        while(current!= nullptr){
            count++;
            current = current->next;
        }
        return count;
    }
    void display(){
        Node* current = head;
        while(current!= nullptr){
            cout<<current->value<<"->";
            current = current->next;
        }
        cout<<" NULL "<<endl;
    }
    

    void changehead(int pos){
        int l = returnlen();
        if(pos<=0 || pos >= l ){
            return;
        }
        if(l == 0 || l == 1){ //khali ya eik node
            return;
        }

        int count = 1;
        Node* temp = head;

        while(temp != nullptr){
            if(pos == count){
                break;
            }
            count++;
            temp = temp->next;
        }
        Node* end = head;
        while(end->next != nullptr){
            end = end->next;
        }

        end->next = head;
        head->prev = end;
        Node* beforeNewHead = temp->prev;

        beforeNewHead->next = nullptr;
        temp->prev = nullptr;

        head = temp;

    }


};
int main() {
    Linkedlist l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.display();
    l1.changehead(3);
    l1.display();
    return 0;
}