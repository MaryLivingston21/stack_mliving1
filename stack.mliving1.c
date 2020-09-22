#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "stack.mliving1.h"

int stackPush(StackNode **stack, char *name, int value){
    StackNode *newNode;
    newNode = (StackNode *) malloc(sizeof(StackNode));
    newNode->value = value;
    strcpy(newNode->name, name);
    //if stack is empty
    if (*stack == NULL){
        newNode->next = NULL;
    } else {
        newNode->next = *stack;
    }
    *stack = newNode;
    return 0;
}

StackNode *stackPop(StackNode **stack){
    //if stack is empty
    if (*stack  == NULL){
        return NULL;
    } else {
        // get head node in the stack
        StackNode *poppedNode = *stack;
        //get the second node in the stack
        StackNode *newHead = (*stack)->next;
        // free first node from the stack
        //free(*stack);
        // set the head node in the stack to Node 2
        *stack = newHead;
        // return popped node
        return poppedNode;
    }
}

StackNode *stackRemoveBottomNode(StackNode **stack){
    //if stack is empty
    if (*stack == NULL){
        return NULL;
    } else {
        //get head node in stack
        StackNode *i = *stack;
        // if only one node in stack, free stack
        if (i->next == NULL){
            *stack = NULL;
            return i;
        } else {
            // while there exists two more nodes after current node
            // while loop will terminate when at second to last node
            while (i->next->next != NULL){
                //increment i
                i = i->next;
            }
            StackNode *lastNode = i->next;
//            // once i == second to last node, free last node
//            free(lastNode);
            //set new bottom node->next to null
            i->next=NULL;
            return lastNode;
        }
    }
}

// print nodes in the stack from top - bottom
int stackPrint(StackNode *stack){
    if (stack != NULL){
        //get first node in stack
        StackNode *i = stack;
        printf("|%s| %d \n", i->name, i->value);
        // if next node exists
        while (i->next != NULL){
            //increment node
            i = i->next;
            // print node
            printf("|%s| %d \n", i->name, i->value);
        }
    } else {
        printf("(stack is empty)\n");
    }
    return 0;
}