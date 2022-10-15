#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution
{
    // Approach 1 : Brute Force and find the pair and return it.
    // TC : O(n^2)

    // Approach 2 : x + y = target => y = target - x;
    // Assume that the current element is x and check if the y exists.
    // To do the process in one iteration, use a hashmap.
    // On every iteration, put the (element : index) as (key : value) in the hashmap.
    // Check if y exists in hashmap and that index of y != x, if true push the index of those elements in result vector.
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> map;
        for (int index = 0; index < nums.size(); index++)
        {
            int second = target - nums[index];
            if (map.find(second) != map.end())
            {
                return {map[second], index};
            }
            map[nums[index]] = index;
        }
        return {};
    }
};