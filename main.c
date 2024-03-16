#include "booky.c"

void main()
{
    struct Stack * stack;
    initStack(stack);
    observeStack(stack);
    stackUp( stack, 90);
    stackUp( stack, 90);
    stackUp( stack, 90);
    observeStack(stack);
    stackUp( stack, 110);
    stackUp( stack, 100);
    printf("%d\n", checkStack(stack));

}

