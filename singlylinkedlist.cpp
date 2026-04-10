#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    // Constructor for easy node creation
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {   // Empty list
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {   // Empty list
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {   // List became empty
            tail = nullptr;
        }
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head == tail) {  // Only one node
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    void reverse(){
        Node* prev = nullptr;
        Node* next = nullptr;
        Node* current = head;

        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;

    }
    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Main function to test
int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);

    cout << "Linked List: ";
    list.display();

    list.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    list.display();

    list.reverse();
    cout<<"After reverse"<<endl;
    list.display();

    return 0;
}
