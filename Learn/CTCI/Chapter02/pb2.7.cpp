#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// insert node at the end of the linked list
void insert_node(Node** head, Node* n) {
    if(*head == NULL) {
        *head = n;
    }
    else {
        Node* curr = *head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = n;
    }
}

void print_list(Node* head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL;" << endl;
}

Node* reverse(Node* head) {
    // copy the linked list to create a new linked list and then reverse it
    Node* rev = NULL;
    while(head != NULL) {
        Node* temp = new Node(head->data);
        insert_node(&rev, temp);
        head = head->next;
    }

    Node* curr = rev;
    Node* prev = NULL;
    Node* next = NULL;

    // revese the linked list
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    rev = prev;
    return rev;
}

bool is_palindrome(Node* head, Node* rev) {
    while(head != NULL && rev != NULL) {
        if(head->data != rev->data) {
            return false;
        }
        head = head->next;
        rev = rev->next;
    }

    // this should never be true
    if(head != NULL || rev != NULL) {
        return false;
    }

    return true;
}

int main() {
    Node* head = NULL;
    Node* n1 = new Node(1);
    Node* n2 = new Node(3);
    Node* n3 = new Node(5);
    Node* n4 = new Node(3);
    Node* n5 = new Node(1);
    //Node* n5 = new Node(2);
    insert_node(&head, n1);
    insert_node(&head, n2);
    insert_node(&head, n3);
    insert_node(&head, n4);
    insert_node(&head, n5);

    // reverse the linked list
    Node* rev = reverse(head);

    cout << "Original List:\n\t";
    print_list(head);
    cout << "Reversed List:\n\t";
    print_list(rev);
    // compare the linked list and print result
    cout << is_palindrome(head, rev) << endl;
    return 0;
}
