#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next;

    Node(int pval){
        val = pval;
        next = nullptr;
    }
};

class CircularLinkedSingly{
    private:
        Node* head = nullptr;
    public:
        CircularLinkedSingly()
};
int main() {
    
    return 0;
}