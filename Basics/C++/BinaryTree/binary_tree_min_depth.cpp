#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

int min(int a, int b) {
    return (a > b) ? b : a;
}

int min_depth(Node* root) {
    // checko for the leaf node
    if(root->left == NULL && root->right == NULL) {
        return 0;
    }
    else {
        if(root->left == NULL) {
            return 1 + min_depth(root->right);
        }
        else if(root->right == NULL) {
            return 1 + min_depth(root->left);
        }
        else {
            return 1 + min(min_depth(root->left), min_depth(root->right));
        }
    }
}

int main() {
    /*      1
     *     / \
     *    2   3
     *   / \
     *  4   5
     * Graph to be tested
     */
    Node* root = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);

    // create a tree here
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;

    int mindep = min_depth(root);
    cout << mindep << endl;

    return 0;
}
