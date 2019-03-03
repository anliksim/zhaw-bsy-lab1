//******************************************************************************
// File:    test1.c
// Purpose: unit test for single linked list
// Author:  M. Thaler, 2012
// Version: v.fs19
//******************************************************************************
// Testing
//
//
//******************************************************************************

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "commondefs.h"
#include "mlist.h"
#include "mthread.h"

//******************************************************************************
// prototype of local functions

void beginTest(const char *str);

void endTest(void);

void print_thread(mthread_t *thread);

void print_list(mlist_t *list);


//******************************************************************************

int main(void) {

    mlist_t *queue1 = NULL;

    // #1 new, empty list ------------------------------------------------------

    beginTest("initialization of queue");

    queue1 = mlNewList();

    mthread_t *thread = mtNewThread(1u, 0, 123u);
    mthread_t *thread2 = mtNewThread(2u, 1, 2123u);

    mlEnqueue(queue1, thread);
    mlEnqueue(queue1, thread2);
    printf("Count: %u\n", mlGetNumNodes(queue1));

    print_list(queue1);

    mthread_t *dq_thread = mlDequeue(queue1);
    print_thread(dq_thread);

    print_list(queue1);

    mlDelList(queue1);

    endTest();

    free(thread);

    exit(EXIT_SUCCESS);
}


//******************************************************************************

void print_thread(mthread_t *thread) {
    printf("ReadyTime: %u\n", mtGetReadyTime(thread));
    printf("TID: %u\n", mtGetID(thread));
}

void print_list(mlist_t *list) {
    printf("List:\n");
    printf("*******\n");
    for (tnode_t *node = list->head->next; node != NULL; node = node->next) {
        print_thread(node->tcb);
    }
    printf("*******\n");
}

void beginTest(const char *str) {
    printf("\n*************************************************************\n");
    if (str != NULL)
        printf("check: %s\n", str);
}


void endTest(void) {
    printf("-> passed\n");
}
