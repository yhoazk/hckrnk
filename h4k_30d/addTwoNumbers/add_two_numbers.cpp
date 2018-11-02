#include <iostream>
// bazel run ... --strategy=CppCompile=standalone
// bazel build ... --strategy=CppCompile=standalone
// bazel build ... --compilation_mode=dbg --strategy=CppCompile=standalone

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
 * can the linked lists be of different size?
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        using namespace std;
        ListNode* rl1 = l1;//reverseList(l1);    
        ListNode* rl2 = l2;//reverseList(l2);
        int rem = 0;
        int res = 0;
        int sum = 0;
        bool done;
        while(true){
            sum = rl1->val + rl2->val + rem;
            if(sum >= 10){
                rem = static_cast<int>(sum / 10);
                sum = sum % 10;
            }
            cout << "val1: " << rl1->val << " val2: " << rl2->val << " : rl2+rl1 = " << sum << '\n';
            if(rl1->next == nullptr or rl2->next == nullptr){
                break;
            }
            rl1 = rl1->next;
            rl2 = rl2->next;
        }
        return rl1;
    }
};

//////// GIVEN //////////////////////////////////////



/*how to keep the address of the root node */
// Flaky method
ListNode* createListNode(const std::string& list){

    //ListNode tmp('g');
    ListNode* index;
    ListNode* root = new ListNode( static_cast<int>( *std::begin(list) -0x30) );
    if(1 == list.size())
    {
        return root;
    }
    bool first = true;
    for(auto i = std::begin(list)+1; i != std::end(list)-1; ++i){
        std::cout << ":: " << static_cast<char>(*i);
        //root->val = static_cast<int>(c);
        root->next = new ListNode(static_cast<int>(*i - 0x30));
        if(first){
            first = false;
            index = root;
            std::cout << "\nf: " << static_cast<char>(index->val) << '\n';
        }
        root = root->next;
    }
    // add the last element
    root->next = new ListNode(static_cast<int>(list.back() - 0x30));
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
        cout << static_cast<char>(index->val + 0x30);
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
   ListNode* l1 = createListNode("243");
   ListNode* l2 = createListNode("564");
   printListNode(l1);
   printListNode(l2);
   Solution s{};
   s.addTwoNumbers(l1, l2);
    return 0;
}
