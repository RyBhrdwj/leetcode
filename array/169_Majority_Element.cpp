#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// QUESTION DATA :: Given : array (nums) of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
// Assumption : Majority element always exists in array.

class Solution {
public:
    // Approach 1 : MAP : Use a map and count appearences of all elements until one of them becomes majority.
    int majorityElement_1(vector<int>& nums) {
        unordered_map<int, int> map;
        int limit = nums.size()/2;
        for (auto &&element : nums)
        {
            ++map[element];
            if (map[element] > limit)   return limit;
        }
        return -1;
    }

    // Approach 2 : "IMP INFO FROM Q. : Majority element exists and appears for > n/2 times"
    // => No. of appearences(majority element) - No. of appearences of other elements combined is always +ve
    // Ex. [1, 9, 2, 9, 4, 9, 9] : Appearences(9) - Appearences(1 + 2) = 1 (positive)
    // Assume the first element to be the majority, traverse the rest of list.
    // While traversing, if the current element == majority, increase count of majority
    // If not, check if count variable if zero, if so make the current element majority and increment count
    // Else decrement count since neither the element is majority nor the count is zero.

    int majorityElement_2(vector<int>& nums) {
        int count = 1;
        int majority = nums[0];
        for (int index = 1; index < nums.size(); ++index)
        {
            if (nums[index] == majority)
            {
                ++count;
            }
            else if (count == 0)
            {
                ++count;
                majority = nums[index];
            }
            else
            {
                --count;
            }
        }
        return majority;
    }
};