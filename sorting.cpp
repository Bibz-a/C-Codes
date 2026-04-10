#include <iostream>
using namespace std;
void bubble(int arr[], int n){
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0; j < n - i -1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for(int j = 0; j < n; j++){
            cout<<arr[j]<<" ";
        }
    cout<<endl;
}

void insert(int arr[], int n){
    for(int i = 1; i < n; i++){
        int curr = arr[i];
        int prev = i - 1; 
        while(prev>= 0 && arr[prev]>=curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }

    for(int j = 0; j < n; j++){
            cout<<arr[j]<<" ";
        }
    cout<<endl;
}

void selection(int arr[], int n){
   for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // assume current index is minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j; // update minimum index
        }
        // swap current element with minimum
        swap(arr[i], arr[minIndex]);
    }
}

void selectionSort() {
    for (Node* i = head; i != nullptr; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (j->data < minNode->data)
                minNode = j;
        }
        swap(i->data, minNode->data);
    }
}

void insertionSort() {
    if (!head || !head->next) return;

    Node* sorted = nullptr;

    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        if (!sorted || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data)
                temp = temp->next;
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    head = sorted;
}

int main() {
    int a[5] = {4,5,2,1,3};
    bubble(a,5);
    insert(a,5);
    return 0;
}