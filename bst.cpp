#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // INSERT
    Node* insert(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }
        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }

    void insertValue(int val) {
        root = insert(root, val);
    }

    // SEARCH
    bool search(Node* root, int key) {
        if (root == nullptr) return false;
        if (root->data == key) return true;

        if (key < root->data) return search(root->left, key);
        else return search(root->right, key);
    }

    // MIN VALUE (Helper for deletion)
    Node* findMin(Node* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // DELETE
    Node* deleteNode(Node* root, int key) {
        if (!root) return nullptr;

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // node found
            // Case 1: no child / 1 child
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: two children → replace with inorder successor
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void deleteValue(int key) {
        root = deleteNode(root, key);
    }

    // TRAVERSALS
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void Mirror(Node* root){
        if(root == NULL){
            return;
        }

        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        Mirror(root->left);
        Mirror(root->right);
    }
};

int main() {
    BST tree;

    tree.insertValue(50);
    tree.insertValue(30);
    tree.insertValue(20);
    tree.insertValue(40);
    tree.insertValue(70);
    tree.insertValue(60);
    tree.insertValue(80);

    cout << "Inorder: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder: ";
    tree.postorder(tree.root);
    cout << endl;

    cout << "\nDeleting 20...\n";
    tree.deleteValue(20);

    cout << "Inorder after deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "\nSearch 60 → ";
    cout << (tree.search(tree.root, 60) ? "Found" : "Not Found") << endl;

    return 0;
}
