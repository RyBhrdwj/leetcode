#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    // Approach : Traverse the matrix and, 1 - flip/reverse each list; 2 - invert each list.
    // 1st step can be done with the help of 2 pointers and 2nd with XOR operator.
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
    {
        for(auto iter = image.begin(); iter != image.end(); ++iter)
        {
            vector<int>& array = *iter;
            int size = array.size();
            for(int i = 0, j = size - 1; i <= j; ++i, --j)
            {
                // Swapping the elements to reverse the array
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                // Using XOR gate to invert the bits.
                array[i] ^= 1;
                if(i != j)  array[j] ^= 1; // Checking before inverting so as to avoid inverting middle element twice. 
            }
        }
        return image;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> vec{{1,1,0},{1,0,1},{0,0,0}};
    a.flipAndInvertImage(vec);
    return 0;
}