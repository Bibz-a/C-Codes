#include <iostream>
#include <string>
using namespace std;
struct Node{
    string URL;
    Node* next;
    Node(string x){
        URL = x;
        next = nullptr;
    }
};

class backbutton{
    private:
    Node* head;
    public:
    backbutton(){
        head = nullptr;
    }

    void push(string URL){
        Node* newnode = new Node(URL);
        if(head == nullptr){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }

    string pop(){
       if(head == nullptr){
            cout<<"No sites visited."<<endl;
            return "NO SITES";
       }
       else{
            string x = head->URL;
            head = head->next;
            return x;
       }
    }
       void display(){
            if(head == nullptr){
                cout<<"NO SITES TO DISPLAY"<<endl;
                return;
            }
            else{
                Node* current = head;
                while(current!=nullptr){
                    cout<<current->URL<<endl;
                    current = current->next;
                }
            }
       }
};
int main() {
    backbutton b1;
    b1.push("google");
    b1.push("facebook");
    b1.push("Youtube");
    b1.display();
    b1.pop();
    b1.display();
    return 0;
}