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
    // Check if y exists in hashmap and that y != x, if true add the index of those elements in result vector.
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int second = target - nums[i];
            map[nums[i]] = i;
            if (nums[i] != second && map.find(second) != map.end())
            {
                result.push_back(i);
                result.push_back(map[second]);
                return result;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> v = {3, 2, 4};
    Solution s;
    v = s.twoSum(v, 6);
    cout << v[0] << v[1];
    return 0;
}