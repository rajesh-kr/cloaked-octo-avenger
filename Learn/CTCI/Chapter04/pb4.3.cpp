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

int max(int x, int y) {
    return (x > y) ? x : y;
}

Node* create_bst(int arr[], int start, int end) {
    if(end < start) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node* node = new Node(arr[mid]);
    node->left = create_bst(arr, start, mid - 1);
    node->right = create_bst(arr, mid + 1, end);

    return node;
}

int get_height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    return max(get_height(root->left), get_height(root->right)) + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Node* root = create_bst(arr, 0, 8);
    int height = get_height(root);

    cout << "height : " << height << endl;

    return 0;
}
