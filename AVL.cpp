#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(NULL), right(NULL), height(1) {}
};

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

// INSERTION
Node* insertNode(Node* root, int key) {
    if(!root){
        return new Node(key);
    }

    if(key < root->key){
        root->left = insertNode(root->left, key);
    }
    else if(key > root->key){
        root->right = insertNode(root->right, key);
    }
    else{
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if(balance>1 && key < root->left->key){
        return rightRotate(root);
    }
    if(balance < -1 && key > root->right->key){
        return leftRotate(root);
    }//LR
    if(balance > 1 && key > root->left->key )
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// FIND MIN VALUE NODE
Node* minValueNode(Node* node) {
    while (node->left)
        node = node->left;
    return node;
}

// DELETE
Node* deleteNode(Node* root, int key) {
    if(!root){
        return root;
    }

    if(key < root->key){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->key){
        root->right = deleteNode(root->right, key);
    }
    else{
        //u are on that node
        if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == nullptr){
            Node* temp =  root->right;
            delete root;
            return temp;
        }
        else{
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if(!root){
        return nullptr;
    }
    
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    int bal = getBalance(root);

    if(bal < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }
    if(bal >  1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }
    if(bal>1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bal < -1 && getBalance(root->right) >  0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// TRAVERSAL
void preOrder(Node* root) {
    if (root) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = NULL;

    // INSERTIONS
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    cout << "Preorder after insertions: ";
    preOrder(root);
    cout << endl;

    // DELETION
    root = deleteNode(root, 40);

    cout << "Preorder after deleting 40: ";
    preOrder(root);
    cout << endl;

    return 0;
}
