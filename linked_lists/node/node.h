#ifndef _NODE_
#define _NODE_

#include <iostream>

#ifndef NULL
  #define NULL ((void*)0)
#endif

typedef struct node
{
    float val;
    struct node* next;
} node_t;

void print_linkedList(node_t* root);

void print_reverserLinkedList( node_t* root);

void insert_nodeTail( node_t* root,  node_t* new_node);

node_t* insert_nodeHead( node_t* root,  float new_val);




#endif /* _NODE_ */
