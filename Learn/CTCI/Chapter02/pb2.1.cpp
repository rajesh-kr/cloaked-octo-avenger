#include <iostream>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void remove_duplicate(Node* head) {
    map<int, int> d;
    Node* curr = head;
    int data = curr->data;
    d[data] = 1;
    while(curr->next != NULL) {
        if(d[curr->next->data] == 1) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else {
            d[curr->next->data] = 1;
            curr = curr->next;
        }
    }
}

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

int main() {
    Node* head = NULL;
    Node* n1 = new Node(4);
    Node* n2 = new Node(2);
    Node* n3 = new Node(2);
    Node* n4 = new Node(2);
    Node* n5 = new Node(3);
    Node* n6 = new Node(4);
    Node* n7 = new Node(9);
    Node* n8 = new Node(6);

    insert_node(&head, n1);
    insert_node(&head, n2);
    insert_node(&head, n3);
    insert_node(&head, n4);
    insert_node(&head, n5);
    insert_node(&head, n6);
    insert_node(&head, n7);
    insert_node(&head, n8);

    cout << "Linked List with duplicate values: ";
    print_list(head);
    cout << "Linked List after duplicate values removed: ";
    remove_duplicate(head);
    print_list(head);

    return 0;
}
