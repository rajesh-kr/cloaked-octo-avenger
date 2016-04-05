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
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void remove_middle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* temp = slow->next;
    slow->data = slow->next->data;
    slow->next = slow->next->next;
    delete temp;
}

int main() {
    Node* head = NULL;
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    insert_node(&head, n1);
    insert_node(&head, n2);
    insert_node(&head, n3);
    insert_node(&head, n4);
    insert_node(&head, n5);

    cout << "Linked List :\n\t";
    print_list(head);

    remove_middle(head);
    cout << "After removing middle element:\n\t";
    print_list(head);

    return 0;
}
