#include <iostream>
#include <string>
using namespace std;

struct Incident{
    int incidentID;
    string description;
    Incident* next;

    Incident(int id, string desc){
        incidentID = id;
        description = desc;
        next = nullptr;
    }
};
struct Node{
    int locationID;
    Node* left;
    Node* right;
    int height;
    Incident* incidentlist;
    Node(int v){
        locationID = v;
        left = nullptr;
        right = nullptr;
        height = 1;
        incidentlist = nullptr;
    }
};

int height(Node* node){
    if(node == nullptr){
        return 0;
    }
    else{
        return node->height;
    }
}

int getbalance(Node* node){
    if(node == nullptr){
        return 0;
    }
    else{
        return (height(node->left)-height(node->right));
    }
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* child = y->left;

    y->left = x;
    x->right = child;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return y;
}


Node* insertNode(Node* root, int locationID){

    if(!root)
        return new Node(locationID);
    
    
    if(locationID < root->locationID){
        root->left = insertNode(root->left, locationID);
    }
    else if(locationID > root->locationID){
        root->right = insertNode(root->right, locationID);
    }
    else{
        return root;
    }


    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getbalance(root);

    if (balance > 1 && locationID < root->left->locationID)
        return rightRotate(root);

    if (balance < -1 && locationID > root->right->locationID)
        return leftRotate(root);

    if (balance > 1 && locationID > root->left->locationID) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && locationID < root->right->locationID) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


Node* searchlocation(Node* root, int locationID){
    if(!root || root->locationID == locationID)
        return root;
    
    if(locationID < root->locationID){
        return searchlocation(root->left, locationID);
    }
    else{
        return searchlocation(root->right, locationID);
    }
}

void addincident(Node* location, int incidientid, string desc){
    Incident* newincident = new Incident(incidientid, desc);
    newincident->next = location->incidentlist;
    location->incidentlist = newincident; //insertion at head
}

void deleteincident(Node* location, int incidentid){
    Incident* curr = location->incidentlist;
    Incident* prev = nullptr;

    while(curr){
        if(curr->incidentID == incidentid){
            if(prev){
                prev->next = curr->next;
            }
            else{
                location->incidentlist = curr->next;
            }

            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void displayIncidents(Incident* head) {
    while (head) {
        cout << "   Incident ID: " << head->incidentID
             << " | " << head->description << endl;
        head = head->next;
    }
}

void inorderTraversal(Node* root) {
    if (!root) return;

    inorderTraversal(root->left);

    cout << "Location ID: " << root->locationID << endl;
    displayIncidents(root->incidentlist);

    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);


    Node* loc = searchlocation(root, 50);

    if(loc){
        addincident(loc, 101, "Fire at blue area");
        addincident(loc, 102, "Gas Leak near sector F3");
    }

    loc = searchlocation(root, 30);

    if(loc){
        addincident(loc, 201, "Road accident");
    }

    cout<<"RECORDS"<<endl;
    inorderTraversal(root);
    deleteincident(searchlocation(root, 50), 102);
    cout<<"DELETION OF INCIDENT 102 AT 50"<<endl;
    inorderTraversal(root);
    return 0;
}
