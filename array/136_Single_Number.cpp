#include<iostream>
#include<vector>
using namespace std;

// QUESTION DATA :: Given a non-empty array of integers (nums), every element appears twice except one. Find it.
class Solution {
    // Approach 1 : Make a map (key -> element; value -> number's appearances in array)
    //              Scan through the array and increment the value of number in map.
    //              Traverse the map and return the key with value 1.
    //              TC : O(n); SC : O(n)
    
    // Approach 2 : Sort the array and then traverse it and check if the adj element == current element
    //              If not, return the current element.
    //              TC : O(n); SC : O(1)

    // Approach 3 : Using XOR operator (Bit Manipulation)
    //              How XOR works : return first_bit == second_bit ? false : true;
    //              XOR is commutative => order doesn't matter (A ^ B = B ^ A)
    //              A ^ A = 0;
    //              0 ^ A = A;
    //              Use the above 3 properties to solve the question

public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++){result ^= nums[i];}
        return result;
    }
};