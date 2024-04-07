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

void pop(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *temp = *head; // Save the old head node
    *head = (*head)->next;     // Move the head pointer to the next node

    free(temp); // Free the old head node
}

int main()
{
    struct Node *head = NULL;

    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);

    pop(&head);

    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}