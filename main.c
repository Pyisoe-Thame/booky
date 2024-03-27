#include "booky.c"

void main()
{
    struct LL_Stack * stack;
    init_LL_Stack(stack);
    observe_LL_Stack(stack);
    LL_StackUp( stack, 90);
    LL_StackUp( stack, 90);
    LL_StackUp( stack, 90);
    observe_LL_Stack(stack);
    LL_StackUp( stack, 110);
    LL_StackUp( stack, 100);
    printf("%d\n", check_LL_Stack(stack));

}

