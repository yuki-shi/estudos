#include <stdio.h>
#include <stdlib.h>


// Crio um struct que será meu node
// Cada node consiste de um elemento + um pointer para o próx node
typedef struct node
{
    int value;
    struct node* next;
}
node_t;

node_t* create_new_node(int value);

void printList(node_t*head);

int main()
{
    node_t* head = NULL;
    node_t* tmp;

    for(int i = 0; i < 25; i++)
    {
        tmp = create_new_node(i);
        tmp->next = head;
        head = tmp;
    }

    printList(head);
    free(tmp);
    free(head);
    return 0;
}

// Cria novos nodes
node_t* create_new_node(int value)
{
    node_t* result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

void printList(node_t*head)
{
    node_t *temporary = head;
    while(temporary != NULL)
    {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}
