#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insert_end(Node **head, int new_value);
unsigned int count_appearances(Node **head, int searched_value);
void deallocation(Node **head);

int main()
{
    Node *head = NULL;
    unsigned int app;
    insert_end(&head, 1);
    insert_end(&head, 7);
    insert_end(&head, 1);
    insert_end(&head, 7);
    insert_end(&head, 7);
    app = count_appearances(&head, 7);
    printf("%u\n", app);
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

unsigned int count_appearances(Node **head, int searched_value)
{
    unsigned int cnt = 0;
    Node *curr = *head;
    while(curr != NULL)
    {
        if(curr->value == searched_value)
            cnt++;
        curr = curr->next;
    }
    return cnt;
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