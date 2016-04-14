#include <iostream>
#include <climits>
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

bool check_bst(Node* root, int min, int max) {
    if(root == NULL) {
        return true;
    }

    if(root->data < min || root->data >= max) {
        return false;
    }

    return check_bst(root->left, min, root->data) && check_bst(root->right, root->data, max);
}

int main() {
    /*       5
     *     /   \
     *    2     7
     *   / \   / \
     *  1   3 6   8
     *       \     \
     *        4     9
     */
    Node* root = new Node(5);

    Node* l = new Node(2);
    Node* r = new Node(7);
    root->left = l;
    root->right = r;

    Node* ll = new Node(1);
    Node* rl = new Node(3);
    l->left = ll;
    l->right = rl;

    Node* rrl = new Node(4);
    rl->right = rrl;

    Node* lr = new Node(6);
    Node* rr = new Node(8);
    r->left = lr;
    r->right = rr;

    Node* rrr = new Node(9);
    rr->right = rrr;

    if(check_bst(root, INT_MIN, INT_MAX)) {
        cout << "Tree is BST" << endl;
    }
    else {
        cout << "Tree is not BST" << endl;
    }

    return 0;
}
