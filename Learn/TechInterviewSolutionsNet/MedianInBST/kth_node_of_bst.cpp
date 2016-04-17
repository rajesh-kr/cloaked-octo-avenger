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

int nodes_count(Node* root) {
    if(root == NULL) {
        return 0;
    }

    return 1 + nodes_count(root->left) + nodes_count(root->right);
}

Node* kth_node(Node* root, int k) {
    if(root == NULL) {
        return NULL;
    }

    int lc = nodes_count(root->left);
    if(k == lc + 1) {
        return root;
    }

    if(k <= lc) {
        return kth_node(root->left, k);
    }
    else {
        return kth_node(root->right, k - lc - 1);
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

    int no_of_nodes = nodes_count(root);
    cout << "no_of_nodes : " << no_of_nodes << endl;

    int t = 6;
    Node* n = kth_node(root, t);
    if(n != NULL) {
        cout << t << "th node : " << n->data << endl;
    }
    else {
        cout << "Can't find node\n";
    }

    return 0;
}
