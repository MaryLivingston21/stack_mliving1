//
// Created by Mary Livingston on 2020-09-18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.mliving1.h" // here, substitute your own include file

int main() {
    StackNode *stack;
    StackNode *node;

    stack = NULL;

    stackPush(&stack, "one", 1);
    stackPush(&stack, "two", 2);
    stackPush(&stack, "three", 3);
    stackPush(&stack, "four", 4);

    stackPrint(stack);

    node = stackPop(&stack);
    printf("popped |%s|, value = %d\n", node->name, node->value);
    node = stackPop(&stack);
    printf("popped |%s|, value = %d\n", node->name, node->value);

    stackPush(&stack, "five", 5);
    stackPush(&stack, "six", 6);

    printf("here is the stack:\n");
    stackPrint(stack);

    printf("remove from end:\n");
    node = stackRemoveBottomNode(&stack);
    while (node != NULL) {
        //printf("Node removed: ");
        printf("|%s| %d\n", node->name, node->value);
        node = stackRemoveBottomNode(&stack);
        //printf("LOOK\n");
        //stackPrint(stack);
    }


    stackPush(&stack, "seven", 7);
    stackPush(&stack, "eight", 8);

    printf("now pop everything\n");
    node = stackPop(&stack);
    while (node != NULL) {
        printf("|%s| %d\n", node->name, node->value);
        node = stackPop(&stack);
    }

    printf("here is the stack:\n");
    stackPrint(stack);
    return 0;
}

