#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void add_first(struct Node **head, int value)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;

    new_node->next = *head;

    *head = new_node;
}

void add_on_index(struct Node **head, int index, int value)
{
    // If the index is 0, add the new node at the beginning of the list
    if (index == 0)
    {
        add_first(head, value);
        return;
    }

    // Traverse the list to find the node at the given index
    struct Node *current = *head;
    for (int i = 0; current != NULL && i < index - 1; i++)
    {
        current = current->next;
    }

    // If the index is out of range, return without adding the new node
    if (current == NULL)
    {
        return;
    }

    // Create a new node and set its data
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;

    // Insert the new node between the current node and the next node
    new_node->next = current->next;
    current->next = new_node;
}

int main()
{
    struct Node *head = NULL;

    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);

    add_on_index(&head, 1, 4);

    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}