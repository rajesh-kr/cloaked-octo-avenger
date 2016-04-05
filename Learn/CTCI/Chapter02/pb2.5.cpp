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
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

Node* sum1(Node* num1, Node* num2) {
    int carry = 0;
    Node* s = NULL;

    while(num1 && num2) {
        int add = num1->data + num2->data + carry;
        carry = add / 10;
        add = add % 10;
        Node* temp = new Node(add);
        insert_node(&s, temp);
        num1 = num1->next;
        num2 = num2->next;
    }

    if(num1) {
        while(num1) {
            int add = num1->data + carry;
            carry = carry / 10;
            add = add % 10;
            Node* temp = new Node(add);
            insert_node(&s, temp);
            num1 = num1->next;
        }
    }
    else if(num2){
        while(num2) {
            int add = num2->data + carry;
            carry = carry / 10;
            add = add % 10;
            Node* temp = new Node(add);
            insert_node(&s, temp);
            num2 = num2->next;
        }
    }

    if(carry != 0) {
        Node* temp = new Node(carry);
        insert_node(&s, temp);
    }

    return s;
}

void reverse(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

Node* sum2(Node* num1, Node* num2) {
    // reverse the linked list to get the number in backward format
    // here, we have number in backward format
    // so, commenting these
    //reverse(&num1);
    //reverse(&num2);
    Node* s = sum1(num1, num2);
    reverse(&s);
    return s;
}

int main() {
    Node* head1 = NULL;
    Node* a1 = new Node(7);
    Node* a2 = new Node(1);
    Node* a3 = new Node(6);
    insert_node(&head1, a1);
    insert_node(&head1, a2);
    insert_node(&head1, a3);

    Node* head2 = NULL;
    Node* b1 = new Node(5);
    Node* b2 = new Node(9);
    Node* b3 = new Node(2);
    insert_node(&head2, b1);
    insert_node(&head2, b2);
    insert_node(&head2, b3);

    print_list(head1);
    print_list(head2);

    Node* s = sum1(head1, head2);
    print_list(s);
    Node* r = sum2(head1, head2);
    print_list(r);

    return 0;
}
