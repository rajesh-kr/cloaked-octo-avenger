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
    Node* curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

bool contains_loop(Node* head) {
    Node* slow_p = head;
    Node* fast_p = head;

    while(fast_p != NULL && fast_p->next != NULL) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if(slow_p == fast_p) {
            return true;
        }
    }

    return false;
}

int main() {
    Node* head = NULL;

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    insert_node(&head, n1);
    insert_node(&head, n2);
    insert_node(&head, n3);
    insert_node(&head, n4);
    insert_node(&head, n5);
    insert_node(&head, n6);
    n6->next = n2;

    if(contains_loop(head)) {
        cout << "Linked list contains loop" << endl;
    }
    else {
        cout << "Linked list doesn't contains loop" << endl;
    }

    return 0;
}
