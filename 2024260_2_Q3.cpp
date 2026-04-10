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
    Node* tail;
    public:
    Linkedlist(){
        head = nullptr;
        tail = nullptr;
    }

    void insert(int val){
        Node* newnode = new Node(val);
        if(!head){
            head = newnode;
            tail = newnode;
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
    void swap(int pos1, int pos2){
        pos1--;
        pos2--;
        int n = returnlen();

        if(n == 0){
            cout<<"Empty list"<<endl;
            return;
        }
        
        if(pos1>=n || pos2 >=n){
            cout<<"Invalid positions"<<endl;
            return;
        }
        if(pos1<0|| pos2 <0){
            cout<<"Invalid positions"<<endl;
            return;
        }

        if(pos1 == pos2){
            return;
        }

        Node* temp1 = head;
        for(int i = 0;i<pos1; i++){
            temp1 = temp1->next;
        }

        
        Node* temp2 = head;
        for(int i = 0;i<pos2; i++){
            temp2 = temp2->next;
        }
        //adjacent case

        if (temp1->next == temp2) { // temp1 before temp2
            if (temp1->prev != nullptr) temp1->prev->next = temp2; 
            else head = temp2; //temp1 is head 

            if (temp2->next != nullptr) temp2->next->prev = temp1;
            else tail = temp1; //temp2 is tail

            temp1->next = temp2->next;
            temp2->prev = temp1->prev;
            temp2->next = temp1;
            temp1->prev = temp2;
            return;
        }
        else if (temp2->next == temp1) { // temp2 before temp1
            if (temp2->prev!= nullptr) temp2->prev->next = temp1;
            else head = temp1; //temp2 is head

            if (temp1->next) temp1->next->prev = temp2;
            else tail = temp2; //temp1 is head

            temp2->next = temp1->next;
            temp1->prev = temp2->prev;
            temp1->next = temp2;
            temp2->prev = temp1;
            return;
        }

        Node* prev1 = temp1->prev;
        Node* next1 = temp1->next;
        Node* prev2 = temp2->prev;
        Node* next2 = temp2->next;

        if(prev1) { //if temp1 is head
            prev1->next = temp2;
        }
        else{
            head = temp2;
        }
        if(next1){ //if temp2 is tail
            next1->prev = temp2;
        }
        if(next2){ //if temp2 is tail
            next2->prev = temp1;
        }
        else{
            tail = temp1;
        }

        if(prev2){
            prev2->next = temp1;
        }
        else{
            head = temp1;
        }

        temp1->prev = prev2;
        temp1->next = next2;

        temp2->prev = prev1;
        temp2->next = next1;



    }


};
int main() {
    Linkedlist l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.display();
    l1.swap(1,3);
    l1.display();

    return 0;
}