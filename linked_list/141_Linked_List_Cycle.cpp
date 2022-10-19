#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Approach : Floyd's Cycle finding algorithm (2 pointers -- fast and slow).
    // Intuition : If there are 2 cars on a circular track and one is moving faster than the other,
    // then they will definitely meet at a point.
    // Traverse the link with 2 pointers, one moving at a speed of 1 Node/iteration and other 2 Node/iteration
    // Return false if the fast pointer or the element next to fast pointer is NULL and true if slow and fast pointer meet.
    bool hasCycle(ListNode *head) {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;

        while(fast_ptr && fast_ptr->next)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;

            if(slow_ptr == fast_ptr)    return true;
        }
        return false;
    }
};