#include <iostream>
using namespace std;
struct Node {
int data;
Node* next;
};
// Function to insert at the end
void insertAtEnd(Node*& head, int val) {
Node* newNode = new Node{val, NULL};
if (!head) {
head = newNode;
return;
}
Node* temp = head;
while (temp->next)
temp = temp->next;
temp->next = newNode;
}
// Bubble Sort
void bubbleSort(Node* head) {
    if (!head) return;
    bool swapped;
    Node* ptr1;
    Node* lptr = NULL; // Marks the end of the sorted part
    do {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
            swap(ptr1->data, ptr1->next->data);
            swapped = true;
        }
        ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
// Display list
void display(Node* head) {
while (head) {
cout << head->data << " -> ";
head = head->next;
}
cout << "NULL\n";
}
void selectionSort(Node* head) {
    if (!head)
        return;

    for (Node* curr = head; curr->next != nullptr; curr = curr->next) {
        Node* minNode = curr;
        for (Node* next = curr->next; next != nullptr; next = next->next) {
            if (next->data < minNode->data)
                minNode = next;
        }
        if (minNode != curr)
            swap(curr->data, minNode->data);
    }
}
Node* insertionSort(Node* head) {
    if (!head || !head->next) return head;
    Node* sorted = NULL; // New sorted list
    Node* current = head;
    while (current) {
        Node* next = current->next;
        if (!sorted || current->data < sorted->data) {
        current->next = sorted;
        sorted = current;
        } else {
        Node* temp = sorted;
        while (temp->next && temp->next->data < current->data)
        temp = temp->next;
        current->next = temp->next;
        temp->next = current;
        }
        current = next;
    }
    return sorted;
}
int main() {
Node* head = NULL;
insertAtEnd(head, 4);
insertAtEnd(head, 2);
insertAtEnd(head, 5);
insertAtEnd(head, 1);
insertAtEnd(head, 3);
cout << "Original list:\n";
display(head);
//selectionSort(head);
//bubbleSort(head);
//display(head);
Node* sorted = insertionSort(head);
cout << "Sorted list (Bubble Sort):\n";
display(sorted);
return 0;
}