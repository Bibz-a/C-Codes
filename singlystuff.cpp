#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
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

    void addnode(int val){
        Node* newnode = new Node(val);
        if(head == nullptr){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }
    void display(){
        Node* current = head;
        while(current!= nullptr){
            cout<<current->data<<"->";
            current = current->next;
        }
        cout<<"NULL"<<endl;
    }
    void bubblesort(){
        Node* largest;
        largest = head;
        Node* current = head;
        int length = 0;
        while(current!= nullptr){
            length++;
            current = current->next;
        }
        current = head;
        for(int i = 0; i < length - 1; i++){
            while(largest->next != nullptr){
                if(largest->data > largest->next->data){
                    if(largest == head){
                        swap(largest, largest->next);
                        largest = largest->next;
                        head = largest->next;
                        if(largest->next->data>largest->data){
                        break;
                        }
                    }
                    else{
                        swap(largest, largest->next);
                        largest = largest->next;
                        if(largest->next->data>largest->data){
                        break;
                    }
                    }
                    
                }
            }
            largest = head;
        }
    }

    void reverse(){
        Node* curr = head;
        Node* next = nullptr;
        Node* prev = nullptr;

        while(curr!=nullptr ){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void middle(){
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"Middle element is: "<<slow->data<<endl;
    }

    void detectloop(){
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                cout<<"LOOP FOUND"<<endl;
            }
        }
        cout<<"loop not found"<<endl;
    }
    void swapkth(int k){
        Node* current = head;
        int length = 0;
        while(current!= nullptr){
            length++;
            current = current->next;
        }
        if(k<=0 || k>length){
            return;
        }
        if(k==length-k+1){
            return;
        }
        Node* begin=head;
        Node* beginprev = nullptr;
        Node* endnode=head;
        Node* endprev = nullptr;
        for(int i=1;i<k;i++){
            beginprev = begin;
            begin = begin->next;
        }

        for(int i = 1; i < length-k + 1; i++ ){
            endprev = endnode;
            endnode = endnode->next;
        }
        if(beginprev!=nullptr){
            beginprev->next = endnode;
        }
        if(endprev!=nullptr){
            endprev->next = begin;
        }
        Node* temp = begin->next;
        begin->next = endnode->next;
        endnode->next = temp;

        if(k==1){
            head = endnode;
        }
        if(k == length){
            head = begin;
        }
    }

    void removenthfromend(int n){
        Node* current = head;
        int length = 0;
        while(current!= nullptr){
            length++;
            current = current->next;
        }
        if(n<=0){
            return;
        }
        if(n>length){
            return;
        }
        Node* nnode = head;
        Node* nnodeprev = nullptr;
        if(n==length){
            head = head->next;
            return;
        }
        for(int i = 1; i < length - n + 1; i++){
            nnodeprev = nnode;
            nnode = nnode->next;
        }
        if(nnodeprev){
            nnodeprev->next = nnode->next;
        }

        
    }
};


int main() {
    Linkedlist l1;
    l1.addnode(5);
    l1.addnode(3);
    l1.addnode(1);
    l1.addnode(6);
    l1.addnode(7);
    l1.addnode(8);
    l1.display();
    l1.reverse();
    l1.display();
    l1.middle();
    l1.detectloop();
    l1.swapkth(2);
    l1.display();
    l1.removenthfromend(6);
    l1.display();
    return 0;
}
