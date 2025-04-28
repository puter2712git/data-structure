#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct linked_list_node {
    char* data;
    struct linked_list_node* next;
} llnode;

typedef struct linked_list {
    llnode* next;
} linked_list;

extern linked_list* llist;

int llist_initialize();
int llist_finalize();

int llist_add_head(char* str);
int llist_add_tail(char* str);
char* llist_remove_head();
char* llist_remove_tail();

void llist_dump();

int llist_is_empty();

#endif