#include<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class RecursiveSolution {
    // First element in a preorder is root, using recursion make it root, split the rest of array
    // into left and right subtree, call the function of them making them it's left and right child.
public:
    TreeNode* create(vector<int>& array) {
        if (array.empty())  return NULL;
        
        TreeNode* root = new TreeNode(array[0]);
        vector<int> larray, rarray;
        for (auto &&element : array)
        {
            if (element < root->val)
            {
                larray.push_back(element);
            }
            else if (element > root->val)
            {
                rarray.push_back(element);
            }
        }
        root->left = create(larray);
        root->right = create(rarray);
        return root;   
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return create(preorder);
    }
};

class IterativeSolution {
    // For every element in the array, traverse through the BST until the right position is found and then place it.
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty())   return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < int(preorder.size()); i++)
        {
            TreeNode* element = new TreeNode(preorder[i]);
            TreeNode *ptr = root;
            TreeNode *parent_ptr = NULL;
            while (ptr)
            {
                parent_ptr = ptr;
                ptr = element->val < ptr->val ? ptr->left : ptr->right;
            }
            if (parent_ptr->val > element->val)
            {
                parent_ptr->left = element;
            }
            else
            {
                parent_ptr->right = element;
            } 
        }
        return root;
    }
};

class OptimizedSolution{
    // In preorder of BST, root is followed by left subtree elements and then right subtree elements.
    // To find the split point, we first build the left subtree and then the right.
    // NULL is placed in 2 conditions : left subtree is complete OR all elements have been placed.
    // So if next element > current element => there's no element in left subtree => return NULL.
public:
    int index = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int parent_value){
        if (index == preorder.size() || preorder[index] > parent_value)  return NULL;
        int current_value = preorder[index++];
        TreeNode* node = new TreeNode(current_value);
        node->left = bstFromPreorder(preorder, current_value);
        node->right = bstFromPreorder(preorder, parent_value);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder){
        return bstFromPreorder(preorder, INT_MAX);
    }
};