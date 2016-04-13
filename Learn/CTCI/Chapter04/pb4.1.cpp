#include <iostream>
using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;

    Tree(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

int abs(int x, int y) {
    return ((x - y) > 0) ? (x - y) : (y - x);
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int check_height(Tree* root) {
    // base case
    if(root == NULL) {
        return 0;
    }

    int left_height = check_height(root->left);
    if(left_height == -1) {
        return -1;
    }

    int right_height = check_height(root->right);
    if(right_height == -1) {
        return -1;
    }

    if(abs(left_height - right_height) > 1) {
        return -1;
    }

    return max(left_height, right_height) + 1;
}

bool is_balanced(Tree* root) {
    if(check_height(root) == -1) {
        return false;
    }
    return true;
}

int main() {
    // create nodes to add to root
    Tree* root = new Tree(1);
    Tree* l1 = new Tree(2);
    Tree* r1 = new Tree(3);

    root->left = l1;
    root->right = r1;

    Tree* l2 = new Tree(4);
    Tree* r2 = new Tree(5);
    Tree* l3 = new Tree(6);
    Tree* r3 = new Tree(7);

    l1->left = l2;
    l1->right = r2;
    r1->left = l3;
    r1->right = r3;

    if(is_balanced(root)) {
        cout << "Tree is balanced" << endl;
    }
    else {
        cout << "Tree is not balanced" << endl;
    }

    return 0;
}
