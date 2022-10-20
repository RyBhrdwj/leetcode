#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    // Approach : A number is a happy number if, after a sequence of steps, the number yields 1.
    // In each step we replace the number with sum of squares of its digits.
    // Non-happy numbers ALYWAYS FORM A CYCLE. (i.e return to a number that has already appeared in the sequence before)
    // Create an array, while the number != 1, replace it with its sum of squares of digits
    // Check if this number has appeared before in the list, if so return false.
    // Add the number to the list and repeat the above the 3 steps again.
public:
    int happyNumber(int num)
    {
        int number = 0;
        while(num > 0)
        {
            int digit = num % 10;
            number += digit*digit;
            num /= 10;
        }
        return number;
    }

    bool isHappy(int n)
    {
        // NOTE : Used a hashmap instead of array to improve time to search [O(n) --> O(1)]
        // vector<int> unhappy_numbers;
        // if(std::find(unhappy_numbers.begin(), unhappy_numbers.end(), number) != unhappy_numbers.end())
        // {
        //     return false;
        // }
        // unhappy_numbers.push_back(number);

        unordered_map<int, int> sequence;
        int number = n;
        while(number != 1)
        {
            number = happyNumber(number);
            if (sequence[number] == 0)
            {
                sequence[number]++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool isHappy2(int n)
    {
        // New Info : The series of sum squares of digits will always either come on 1 or 89.
        // (Only applicable for natural numbers)
        int number = n;
        while (number != 1)
        {
            number = happyNumber(number);
            if (number == 89)   return false;
        }
        return true;
    }

    bool isHappyCycle(int n)
    {
        // Use Floyd's cycle finding algorithm. (2 pointers --> slow & fast)
        // If there is no loop both will meet at 1, else they will meet at one point in the loop.
        int slow = n, fast = n;
        do
        {
            slow = happyNumber(slow);
            fast = happyNumber(happyNumber(fast));
        }
        while (slow != fast);
        return fast == 1;
    }
};