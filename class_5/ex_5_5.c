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

void remove_first_by_value(struct Node **head, int value)
{
    if (*head == NULL)
    {
        return;
    }

    // Check if the first node contains the value
    if ((*head)->data == value)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node before the one to be removed
    struct Node *current = *head;
    while (current->next != NULL && current->next->data != value)
    {
        current = current->next;
    }

    // Check if the value was not found
    if (current->next == NULL)
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

    remove_first_by_value(&head, 3);

    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}