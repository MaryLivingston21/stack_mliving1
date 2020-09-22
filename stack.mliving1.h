//
// Created by Mary Livingston on 2020-09-18.
//

#ifndef STACK_MLIVING1_STACK_MLIVING1_H
#define STACK_MLIVING1_STACK_MLIVING1_H

#define MAX_NAME_LENGTH 32
typedef struct StackNodeStruct {
    char name[MAX_NAME_LENGTH];
    int value;
    struct StackNodeStruct *next;
} StackNode;

//Create new node and push it onto the stack
//always returns 0
int stackPush(StackNode **stack, char *name, int value);

//pop node off top of stack
// return popped node if stack not empty
// else return null
StackNode *stackPop(StackNode **stack);

// remove bottom node from stack
// return removed node if stack not empty
// else return null
StackNode *stackRemoveBottomNode(StackNode **stack);

// print nodes in the stack from top - bottom
int stackPrint(StackNode *stack);

#endif //STACK_MLIVING1_STACK_MLIVING1_H
