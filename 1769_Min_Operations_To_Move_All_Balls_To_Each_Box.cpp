#include<iostream>
#include<vector>
using namespace std;

// Question data :
// INPUT :: str boxes; (Each character is either 0 or 1 signifying a box with number of ball(s) in it)
// int n = len(boxes);
// OUTPUT :: int array[n]; (Each element representing min operations to shift all balls to that box)

class Solution {
    // Operations to move 1 ball from index A to B = |A - B|
    // => Operations to move all balls to one location = sum of moving all balls from other indices to that index
public:
    vector<int> minOperations(string boxes)
    {
        int length = boxes.length();
        vector<int> array(length);
        for(int i = 0; i < length; i++)
        {
            int operations = 0;
            for (int index = 0; index < length; index++)
            {
                if (boxes[index] == '1')    operations += abs(i - index);
            }
            array[i] = operations;
        }
        return array;
    }
};

class OptimizedSolution
{
    // First, move all the balls from Left To Right
    // When doing so, count the number of operations to move balls from leftmost box to that box.
    // Moving 1 ball to adj box = 1 operation => Moving N balls to adj box = N operations
    // "count" : keep track of number of balls;
    // "operations" : keep track of operations to move balls to that box from one end(left/right-most box)
    // Repeat the process from Right to Left
public:
    vector<int> minOperations(string boxes)
    {
        int length = boxes.length();
        vector<int> result_array(length, 0);
        for (int index = 0, count = 0, operations = 0; index < length; ++index)
        {
            operations += count;
            result_array[index] += operations;
            count += boxes[index] == '1' ? 1 : 0;
        }
        for (int index = length - 1, count = 0, operations = 0; index >= 0; --index)
        {
            operations += count;
            result_array[index] += operations;
            count += boxes[index] == '1' ? 1 : 0;
        }
        return result_array;
    }
};