#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 8

struct Node
{
    int content;
    struct Node * next; 
};

struct Stack
{
    int content[STACK_MAX_SIZE];
    int top;
};

struct LL_Stack
{
    struct Node** node;
    int top;
};

struct Queue
{
    struct Node** node;
    int last;
};

struct Tree  // just a wrapper to abstract my tree usage incase of complications
{
    struct TreeNode* root; 
};

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

void createNode( struct Node* node, int content);
void addOnHead( struct Node ** head, int content);
void showAll( struct Node ** head);
void deleteNode( struct Node ** head, int key);

void initStack( struct Stack * stack);
void init_LL_Stack( struct LL_Stack* stack);
void stackUp( struct Stack * stack, int additive);  // add one more stack plate
void LL_StackUp( struct LL_Stack * stack, int additive);
void stackDown( struct Stack * stack);  // deduce by one stack plate
void LL_StackDown( struct LL_Stack * stack);
int checkStack( struct Stack * stack);  // print the top
int check_LL_Stack( struct LL_Stack * stack);
void observeStack( struct Stack * stack);  // show all stack content
void observe_LL_Stack( struct LL_Stack * stack);
bool isStackFull( struct Stack* stack);
bool isStackEmpty( struct Stack* stack);

void createNode( struct Node * node, int content)
{
    node -> next = NULL;
    node -> content = content;
}

void addOnHead( struct Node ** head, int content)// Node * prevNode)
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

void deleteNode( struct Node ** head, int key)
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

void init_LL_Stack( struct LL_Stack* stack)
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

void LL_StackUp( struct LL_Stack * stack, int additive)
{
    struct Node * newNode = (struct Node*) malloc(sizeof(struct Node));
    if( newNode == NULL )  // Handle memory allocation failure
    {   
        perror("Memory allocation failure! \n\rPlease track the dynamic memory space.");
        return;
    }
    createNode( newNode, additive);
    if( stack -> top != -1)  // if LL stack is not empty
    {
        newNode -> next = stack -> node[stack -> top];  // link the new node
    }
    stack -> node[++( stack -> top)] = newNode;
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

void LL_StackDown( struct LL_Stack * stack)
{
    if( stack -> top != -1)
    {
        free( stack -> node[stack -> top]);
        (stack -> top)--;
    }
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

int check_LL_Stack( struct LL_Stack * stack)
{
    if( stack -> top != -1)
        return ( stack -> node[stack -> top] -> content);
    else
        return -1;  // -1 will be return if stack is empty
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

void observe_LL_Stack(struct LL_Stack * stack)
{
    if( stack -> top != -1)
    {
        for( int i = stack -> top; i >= 0; i--)
            printf("%d, ", stack -> node[i] -> content);
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

