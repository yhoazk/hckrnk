#include "..\\node\\node.h"

#include <random>

using namespace std;

const unsigned int NODE_NUMBER = 20U;


void print_linkedList(node_t* root)
{
    if(root == NULL)
    {
        cout << "Empty LD" << endl;
    }
    else
    {
        cout << root->val << "->";
        do
        {
            root = root->next;
            cout << root->val << "->";
        }while(root->next->next != NULL);
        cout <<  "->NULL" << endl;
    }

}

/* returns a pointer to the root of the LD where the node was inserted */
node_t* insert_tail( node_t* toor, float new_node_val)
{
    node_t* root = toor;
    
    while(toor->next != NULL)
    {
        toor = toor->next;
        cout << ".";
    }
    node_t* nn = new node_t;
    nn->val = new_node_val;
    nn->next = NULL;
    toor->next = nn;
    return root;
}

node_t* 



void print_reverserLinkedList( node_t* root)
{
    if(root == NULL)
    {
        cout << "Empty LD" << endl;
        return;
    }
    if(root->next != NULL)
    {
        print_reverserLinkedList( root->next);
        cout  <<"->" << root->val;

    }
    

}




node_t* insert_nodeHead( node_t* root,  float new_node_val)
{
    node_t* new_head = new node_t;
    new_head->val = new_node_val;

    new_head->next = root;
    return new_head;

}


int main (void)
{
    default_random_engine eng;
    normal_distribution<float> nd;
    node_t* ld = new node_t;
    ld->val = 0;
    ld->next = NULL;
    cout << nd(eng);
    for(unsigned int i = 0; i < NODE_NUMBER; ++i)
    {
        ld = insert_tail(ld, (float) i);
        cout << i << endl;
    }
    print_linkedList(ld); 
    ld = insert_nodeHead(ld, 488.4f);
    print_linkedList(ld); 

    print_reverserLinkedList( ld);
    return(0);
}

