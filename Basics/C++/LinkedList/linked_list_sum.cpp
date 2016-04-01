#include <iostream>
using namespace std;

/* This programs calculate the
 * sum of two numbers represented 
 * by linked list. 
 * A number 123 is represented as
 * 1->2->3 using linked list
 */

// create a node for the linked list
struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// inserts a node at the end of the list
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
        cout << curr->data;
        curr = curr->next;
    }
    cout << endl;
}

// reverses a linked list
void reverse_list(Node** head) {
    Node* curr = *head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// calculate the sum of two linked list
Node* get_sum(Node* num1, Node* num2) {
    Node* first = num1;
    Node* second = num2;
    
    // reverse the two linked list
    reverse_list(&first);
    reverse_list(&second);

    int carry = 0;
    int s;
    Node* sum = NULL;

    // calculate the sum while the length of two linked lists are same
    while(first != NULL && second != NULL) {
        s = first->data + second->data + carry;
        carry = s / 10;
        s = s % 10;
        Node* temp = new Node(s);
        insert_node(&sum, temp);
        first = first->next;
        second = second->next;
    }

    // now calculate for the remaining list
    if(first != NULL) {
        while(first != NULL) {
            s = first->data + carry;
            carry = s / 10;
            s = s % 10;
            Node* temp = new Node(s);
            insert_node(&sum, temp);
            first = first->next;
        }
    }
    else if(second != NULL) {
        while(second != NULL) {
            s = second->data + carry;
            carry = s / 10;
            s = s % 10;
            Node* temp = new Node(s);
            insert_node(&sum, temp);
            second = second->next;
        }
    }

    // if we have carry, create a node and add it to list
    if(carry != 0) {
        Node* temp = new Node(carry);
        insert_node(&sum, temp);
    }

    reverse_list(&sum);
    return sum;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    Node* a1 = new Node(5);
    Node* a2 = new Node(6);
    Node* a3 = new Node(3);
    Node* a4 = new Node(9);

    Node* b1 = new Node(8);
    Node* b2 = new Node(4);
    Node* b3 = new Node(2);

    insert_node(&head1, a1);
    insert_node(&head1, a2);
    insert_node(&head1, a3);
    insert_node(&head1, a4);

    insert_node(&head2, b1);
    insert_node(&head2, b2);
    insert_node(&head2, b3);

    cout << "First number: ";
    print_list(head1);
    cout << "Second number: ";
    print_list(head2);
    cout << "Sum : ";
    Node* sum = get_sum(head1, head2);
    print_list(sum);

    return 0;
}
