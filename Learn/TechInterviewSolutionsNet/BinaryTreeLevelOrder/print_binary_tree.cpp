#include <iostream>
#include <queue>
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

void print_level_order(Node* root) {
    queue<Node*> q;
    q.push(root);
    Node* node = NULL;

    while(!q.empty()) {
        node = q.front();
        q.pop();
        cout << node->data << " ";

        if(node->left != NULL) {
            q.push(node->left);
        }

        if(node->right != NULL) {
            q.push(node->right);
        }
    }

    cout << endl;
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

    print_level_order(root);

    return 0;
}
