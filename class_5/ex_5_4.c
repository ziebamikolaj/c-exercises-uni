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

void remove_by_index(struct Node **head, int index)
{
    if (*head == NULL)
    {
        return;
    }

    // Check if the node to be removed is the first node
    if (index == 0)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node before the one to be removed
    struct Node *current = *head;
    for (int i = 0; current != NULL && i < index - 1; i++)
    {
        current = current->next;
    }

    // Check if the index is out of bounds or the current node is the last node
    if (current == NULL || current->next == NULL)
    {
        return;
    }

    // Remove the node by updating the pointers and freeing the memory
    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

int main()
{
    struct Node *head = NULL;

    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);

    remove_by_index(&head, 1);

    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}