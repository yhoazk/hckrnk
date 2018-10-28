#include <iostream>
// bazel run ... --strategy=CppCompile=standalone
// bazel build ... --strategy=CppCompile=standalone
// bazel build ... --compilation_mode=dbg --strategy=CppCompile=standalone

struct ListNode {
    int val;
    ListNode *next;
    // This is the example where the phase of allocation and
    // initialization make the things more complicated
    // There should be a default constructor which only allocates
    ListNode(int x) : val(x), next(nullptr) {}
};

//////// GIVEN //////////////////////////////////////
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    }
};

//////// GIVEN //////////////////////////////////////

/* reverse linked list in place */
/*  Not really needed, just  nice to have */
/* Expects the root node, returns the end node and hte root as end node */
template<typename L>
L* reverseList(L *list){
    L* curr = list;
    L* last = nullptr;
    L* next = curr->next;
    bool done = false;
    // el primer nodo necesita un tratamiento diferente al resto por que le next debe ser nullptr
    //while(curr->next != nullptr){
    while(!done){
        curr->next = last;
        last = curr;
        if(next == nullptr){ 
            done = true;
            break;
        }
        curr = next;
        next = curr->next;
    }
    return(curr);
}

/*how to keep the address of the root node */
// Flaky method
ListNode* createListNode(const std::string& list){

    //ListNode tmp('g');
    ListNode* index;
    ListNode* root = new ListNode( static_cast<int>( *std::begin(list) ) );
    if(1 == list.size())
    {
        return root;
    }
    bool first = true;
    for(auto i = std::begin(list)+1; i != std::end(list)-1; ++i){
        std::cout << ":: " << static_cast<char>(*i);
        //root->val = static_cast<int>(c);
        root->next = new ListNode(static_cast<int>(*i));
        if(first){
            first = false;
            index = root;
            std::cout << "\nf: " << index->val << '\n';
        }
        root = root->next;
    }
    // add the last element
    root->next = new ListNode(static_cast<int>(list.back()));
    std::cout << std::endl;
    return(index);
}


// ListNode* recursiveCreateListNode(const std::string& list){

// }

void printListNode(ListNode* l){
    using namespace std;
    ListNode* index;
    index = const_cast<ListNode*>(l);

    while(true){
        cout << static_cast<char>(index->val);
        index = index->next;
        if(index == nullptr){
            break;
        }
        cout << "->";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // TODO: HAndle list of size 2 or 3
   ListNode* l = createListNode("12456789abcdefghijklmnopqrts");
   printListNode(l);
   ListNode* rl = reverseList(l);
   printListNode(rl);
    return 0;
}
