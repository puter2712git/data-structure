#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

linked_list* llist;

int llist_initialize()
{
    llist = (linked_list*)malloc(sizeof(linked_list));
    llist->next = NULL;

    return 0;
}

int llist_finalize()
{
    llnode* curr = llist->next;
    while (curr != NULL) {
        llnode* freed = curr;
        curr = curr->next;
        free(freed->data);
        free(freed);
    }
    free(llist);

    return 0;
}

int llist_add_head(char* str)
{
    llnode* new_node = (llnode*)malloc(sizeof(llnode));
    new_node->next = llist->next;
    llist->next = new_node;

    new_node->data = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(new_node->data, str);

    return 0;
}

int llist_add_tail(char* str)
{
    llnode* new_node = (llnode*)malloc(sizeof(llnode));

    if (llist_is_empty()) {
        llist->next = new_node;
    } else {
        llnode* tmp = llist->next;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
    new_node->next = NULL;

    new_node->data = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(new_node->data, str);

    return 0;
}

char* llist_remove_head()
{
    if (llist_is_empty()) {
        fprintf(stderr, "[!] Linked list is empty! Cannot remove from linked list.\n");
        return NULL;
    }

    llnode* rem = llist->next;
    llist->next = rem->next;

    char* data = rem->data;
    free(rem);

    return data;
}

char* llist_remove_tail()
{
    if (llist_is_empty()) {
        fprintf(stderr, "[!] Linked list is empty! Cannot remove from linked list.\n");
        return NULL;
    }

    llnode* rem = llist->next;
    llnode* prev = NULL;
    while (rem->next != NULL) {
        prev = rem;
        rem = rem->next;
    }
    prev->next = NULL;

    char* data = rem->data;
    free(rem);

    return data;
}

int llist_dump()
{
    if (llist_is_empty()) {
        fprintf(stderr, "[!] Linked list is empty! Cannot dump linked list.\n");
        return EXIT_FAILURE;
    }

    fprintf(stdout, "========== Dumping Linked List ==========\n");
    fprintf(stdout, "HEAD\n");
    llnode* tmp = llist->next;
    while (tmp != NULL) {
        fprintf(stdout, "-> %s\n", tmp->data);
        tmp = tmp->next;
    }

    return EXIT_SUCCESS;
}

int llist_is_empty()
{
    return llist->next == NULL;
}