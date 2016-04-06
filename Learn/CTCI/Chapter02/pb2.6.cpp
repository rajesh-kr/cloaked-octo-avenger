#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char c) {
        data = c;
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

Node* find_loop(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL) {
        // increase fast by two and slow by one
        fast = fast->next->next;
        slow = slow->next;

        // if both pointers meet, break out of the loop
        if(fast == slow) {
            break;
        }
    }

    // incase there is no loop, return null
    if(fast == NULL || fast->next == NULL) {
        return NULL;
    }

    // now move slow to head and increase both the pointer one by one
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

int main() {
    Node* head = NULL;
    Node* n1 = new Node('A');
    Node* n2 = new Node('B');
    Node* n3 = new Node('C');
    Node* n4 = new Node('D');
    Node* n5 = new Node('E');

    insert_node(&head, n1);
    insert_node(&head, n2);
    insert_node(&head, n3);
    insert_node(&head, n4);
    insert_node(&head, n5);

    n5->next = n3;

    //print_list(head);
    Node* loop = find_loop(head);
    if(loop != NULL) {
        cout << loop->data << endl;
    }
    else {
        cout << "NO LOOP" << endl;
    }

    return 0;
}
