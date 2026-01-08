#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insert_end(Node **head, int new_value);
int GetNth(Node **head, unsigned int index);
void deallocation(Node **head);

int main()
{
    Node *head = NULL;
    int number;
    insert_end(&head, 1);
    insert_end(&head, 7);
    insert_end(&head, 8);
    insert_end(&head, -2);
    insert_end(&head, 93);
    number = GetNth(&head, 3);
    printf("%d\n", number);
    deallocation(&head);
    return 0;
}

void insert_end(Node **head, int new_value)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);
    new_node->value = new_value;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return ;
    }

    Node *curr = *head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

int GetNth(Node **head, unsigned int index)
{
    Node *curr = *head;
    unsigned int i = 0;
    while(curr != NULL)
    {
        if(i == index)
            return curr->value;
        curr = curr->next;
        i++;
    }
}

void deallocation(Node **head)
{
    Node *curr = *head;
    while(curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head = NULL;
}