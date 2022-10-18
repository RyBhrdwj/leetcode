#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        unordered_map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int ptr = 0; ptr < s.size(); ptr++)
        {
            char c = s[ptr];
            if ((c == 'I' || c == 'X' || c == 'C') && ptr != s.size() - 1)
            {
                char next = s[ptr + 1];
                bool cond1 = (c == 'I') && (next == 'V' || next == 'X');
                bool cond2 = (c == 'X') && (next == 'L' || next == 'C');
                bool cond3 = (c == 'C') && (next == 'D' || next == 'M');
                if (cond1 || cond2 || cond3)
                {
                    number += values[next] - values[c];
                    ptr++;
                }
                else
                {
                    number += values[c];
                }
            }
            else
            {
                number += values[c];
            }  
        }
        return number;
    }
};
