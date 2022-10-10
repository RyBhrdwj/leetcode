#include<iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class FirstSolution {
    // Find the max of the array, make it the root, if array is empty return null.
    // Slice the input vector and call the function on sliced vectors to find left and right child.
    // Return the root
    // Time : O(n^2); Space : O(n)
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int size = nums.size();
        if(size > 0)
        {
            int max = nums[0];
            int max_index = 0;
            vector<int> lvector, rvector;

            for(int i = 1; i < size; i++)
            {
                if(nums[i] > max)
                {
                    max = nums[i];
                    max_index = i;
                }
            }

            for(int i = 0; i < size; i++)
            {
                if(i < max_index)
                {
                    lvector.push_back(nums[i]);
                }
                else if(i > max_index)
                {
                    rvector.push_back(nums[i]);
                }
            }

            TreeNode* root = new TreeNode(max);
            root->left = constructMaximumBinaryTree(lvector);
            root->right = constructMaximumBinaryTree(rvector);
            return root;
        }
        else
        {
            return nullptr;
        }
    }
};

class Solution{
// Optimized Solution using a stack.
// https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C%2B%2B-O(N)-solution
};