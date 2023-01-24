#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int getNthFromLast(Node *head, int n)
{
    static int i = 0;
    if (head == NULL)
        return -1;

    int aim = getNthFromLast(head->next, n);
    if(aim != 0 && aim != -1)
        return aim;
    if (++i == n)
        return head->data;
}

void push(struct Node **head_ref, int new_data)
{
    /* Allocate node */
    Node *new_node = (Node *)malloc(sizeof(Node));

    /* Put in the data */
    new_node->data = new_data;

    /* link the old list of the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// Driver's Code
int main()
{

    /* Start with the empty list */
    struct Node *head = NULL;

    // create linked 35->15->4->20
    push(&head, 5);
    push(&head, 78);

    // Function call
    cout << getNthFromLast(head, 2);
    return 0;
}