#include <iostream>
// bazel run ... --strategy=CppCompile=standalone
// bazel build ... --strategy=CppCompile=standalone

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
void reverseList(L &list){

}

ListNode createListNode(const std::string& list){

    ListNode tmp(0);

    for(auto& c : list){
        std::cout << ":: " << static_cast<char>(c) << '\n';
        tmp.val = static_cast<int>(c);

    }
    return(std::move())
}


int main(int argc, char const *argv[])
{


    createListNode("abcde", &L1);

    return 0;
}
