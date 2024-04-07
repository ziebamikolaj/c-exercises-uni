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

void remove_last(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    // Check if there is only one node in the list
    if ((*head)->next == NULL)
    {
        free(*head);  // Free the memory of the single node
        *head = NULL; // Set the head to NULL
        return;
    }

    // Traverse the list to find the second last node
    struct Node *current = *head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    // Free the last node and set the next pointer of the second last node to NULL
    free(current->next);
    current->next = NULL;
}

int main()
{
    struct Node *head = NULL;

    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);

    remove_last(&head);

    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}