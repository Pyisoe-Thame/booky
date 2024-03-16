#include <stdio.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 8

struct Node
{
    char content;
    struct Node * next; 
};

struct Stack
{
    int content[STACK_MAX_SIZE];
    int top;
};

void createNode( struct Node* node, char content);
void addOnHead( struct Node ** head, char content);
void showAll( struct Node ** head);
void deleteNode( struct Node ** head, char key);

void initStack( struct Stack * stack);
void stackUp( struct Stack * stack, int additive);  // add one more stack plate
void stackDown( struct Stack * stack);  // deduce by one stack plate
int checkStack( struct Stack * stack);  // print the top
void observeStack( struct Stack * stack);  // show all stack content
bool isStackFull( struct Stack* stack);
bool isStackEmpty( struct Stack* stack);

void createNode( struct Node * node, char content)
{
    node -> next = NULL;
    node -> content = content;
}

void addOnHead( struct Node ** head, char content)// Node * prevNode)
{
    struct Node * tempNode = (struct Node*) malloc(sizeof(struct Node));
    tempNode -> content = content;
    tempNode -> next = *head;
    *head = tempNode;  // only content can change, changing pointer variable doesn't work 
}

void showAll( struct Node ** head)
{
    struct Node * tempNode = *head;
    while( tempNode -> next != NULL)
    {
        printf("%c\n", tempNode -> content);
        tempNode = tempNode -> next;
    }
    printf( "%c\n", tempNode -> content);  // for the last node
}

void deleteNode( struct Node ** head, char key)
{
    struct Node * tempNode = *head, * prevNode;
    while( tempNode -> next != NULL && tempNode -> content != key)
    {
        prevNode = tempNode;
        tempNode = tempNode -> next;
    };
    if( tempNode -> next == NULL)
        return ;
    if( tempNode -> content == key)
    {
        prevNode -> next = tempNode -> next;
        free(tempNode);
    } 
}

void initStack( struct Stack* stack)
{
    stack -> top = -1;  // 0 is the first index so...
    return ;
}

void stackUp( struct Stack * stack, int additive)  // add one more stack plate
{
    if(!isStackFull(stack))
    {
        (stack -> top)++;
        stack -> content[(stack -> top)] = additive;
    }
    else 
    {
        printf("The stack is full!\n");
        printf("Free some stack space to add more.\n");
    }
    return ;
}

void stackDown( struct Stack * stack)  // deduce by one stack plate
{
    if(!isStackEmpty(stack))
        (stack -> top)--;  // space of the old top index will be overwritten in next stackUp
    else 
        printf("The stack is empty already!\n");
    return ;
}

int checkStack( struct Stack * stack)  // print the top
{
    if(!isStackEmpty(stack))
        return (stack -> content[( stack -> top )]);
    else
        return stack -> top;  // -1 will be return if stack is empty
}

void observeStack(struct Stack * stack)  // show all stack content
{
    if(!isStackEmpty(stack))
    {
        for( int i = 0; i <= (stack -> top); i++)
            printf("%d, ", stack -> content[i]);
        putchar('\n');
    }
    return ;
}

bool isStackFull( struct Stack* stack)
{
    return ( stack -> top == STACK_MAX_SIZE-1);
}

bool isStackEmpty( struct Stack* stack)
{
    return ( stack -> top == -1);
}

