#include <iostream>
using namespace std;

#define sizee 10

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class HashMaps {
private:
    Node* table[sizee];

public:
    HashMaps(){
        for(int i = 0; i < sizee; i++)
            table[i] = NULL;
    }

    // 🔹 Insert using chaining
    void chainedInsert(int key){
        int index = key % sizee;
        Node* newNode = new Node(key);

        // Insert at head (fast)
        newNode->next = table[index];
        table[index] = newNode;
    }

    // 🔹 Search in chain
    bool chainedSearch(int key){
        int index = key % sizee;
        Node* temp = table[index];

        while(temp != NULL){
            if(temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // 🔹 Display hash table
    void display(){
        for(int i = 0; i < sizee; i++){
            cout << i << " : ";
            Node* temp = table[i];

            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main(){
    HashMaps h;

    h.chainedInsert(27);
    h.chainedInsert(37);
    h.chainedInsert(47);
    h.chainedInsert(57);
    h.chainedInsert(67);
    h.chainedInsert(77);

    h.display();

    if(h.chainedSearch(47))
        cout << "Element found\n";
    else
        cout << "Element not found\n";

    return 0;
}
