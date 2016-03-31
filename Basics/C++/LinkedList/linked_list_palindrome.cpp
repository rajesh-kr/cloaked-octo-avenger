#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int d) {
            data = d;
            next = NULL;
        }
};

void reverse_list(Node** head) {
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

bool compare_lists(Node* first, Node* second) {
    bool result = false;
    while(first != NULL && second != NULL && first->data == second->data) {
        first = first->next;
        second = second->next;
    }

    if(first == NULL && second == NULL) {
        result = true;
    }
    else {
        result = false;
    }

    return result;
}

bool is_palindrome(Node* head) {
    // first find the middle of the linked list
    Node* fast_pointer = head;
    Node* slow_pointer = head;
    Node* prev_of_slow_pointer = NULL;
    Node* mid_node = NULL;
    Node* second_half = NULL;
    bool result = false;

    while(fast_pointer != NULL && fast_pointer->next != NULL) {
        // increase fast pointer by two, while slow pointer by one
        fast_pointer = fast_pointer->next->next;

        prev_of_slow_pointer = slow_pointer;
        slow_pointer = slow_pointer->next;
    }

    // if fast_pointer is not null, we have odd number of elments.
    // save the middle node for future processing
    if(fast_pointer != NULL) {
        mid_node = slow_pointer;
        slow_pointer = slow_pointer->next;
    }

    prev_of_slow_pointer->next = NULL; // first linked list is from head to prev_of_slow_pointer
    second_half = slow_pointer;

    // reverse second linked list
    reverse_list(&second_half);

    // compare first linked list with the reversed second linked list
    // if both are equal return true else false
    result = compare_lists(head, second_half);

    // again reverse the second linked list and merge with first to get the original
    reverse_list(&second_half);
    if(mid_node != NULL) {
        prev_of_slow_pointer->next = mid_node;
        mid_node->next = second_half;
    }
    else {
        prev_of_slow_pointer->next = second_half;
    }

    return result;
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

void print_ll(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(4);
    Node* n7 = new Node(3);
    Node* n8 = new Node(2);
    Node* n9 = new Node(1);

    insert_node(&head, n1);
    insert_node(&head, n2);
    insert_node(&head, n3);
    insert_node(&head, n4);
    insert_node(&head, n5);
    insert_node(&head, n6);
    insert_node(&head, n7);
    insert_node(&head, n8);
    insert_node(&head, n9);

    print_ll(head);

    if(is_palindrome(head)) {
        cout << "Linked list is palindrome" << endl;
    }
    else {
        cout << "Linked list is not palindrome" << endl;
    }
    print_ll(head);

    return 0;
}
