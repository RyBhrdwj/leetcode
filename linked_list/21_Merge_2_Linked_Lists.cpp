#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    // Approach : If list1 is empty return list2 and vice versa.
    // If both lists have elements, then create 2 pointers (ptr1, ptr2) to traverse 2 lists
    // "start" as head of resultant list, and "end" as the end of resultant list
    // To choose the head, compare the heads of 2 list and choose the smaller element, move the ptr of that list to next element.
    // While both lists have elements, keep comparing the elements, add them to the end of result list, update end and increment the pointer.
    // Finally, either of the 2 list would still have some elements left, join them with the result list to get the final answer. 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)     return list2;
        if (!list2)     return list1;
        
        ListNode *ptr1 = list1, *ptr2 = list2, *end, *start;
        if (ptr1->val <= ptr2->val)
        {
            start = end = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            start = end = ptr2;
            ptr2 = ptr2->next;
        }
        while (ptr1 && ptr2)
        {
            if (ptr1->val <= ptr2->val)
            {
                end->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                end->next = ptr2;
                ptr2 = ptr2->next;
            }
            end = end->next; 
        }

        end->next = !ptr1 ? ptr2 : ptr1;
        return start;
    }
};