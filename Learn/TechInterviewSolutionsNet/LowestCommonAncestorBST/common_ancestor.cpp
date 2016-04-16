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

int common_ancestor(Node* root, int first, int second) {
    if(root == NULL) {
        return -1;
    }
    int data = root->data;
    if(data == first || data == second) {
        return data;
    }

    if(data > first && data > second) {
        return common_ancestor(root->left, first, second);
    }
    else if(data < first && data < second) {
        return common_ancestor(root->right, first, second);
    }
    else {
        return data;
    }
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

    int d = common_ancestor(root, 2, 9);
    cout << d << endl;

    return 0;
}
