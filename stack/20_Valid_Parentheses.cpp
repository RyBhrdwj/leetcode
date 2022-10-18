#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parentheses_stack;
        for (auto &&c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                parentheses_stack.push(c);
            }
            else if (!parentheses_stack.empty() && ((parentheses_stack.top() == '(' && c == ')') || 
            (parentheses_stack.top() == '[' && c == ']') || 
            (parentheses_stack.top() == '{' && c == '}')))
            {
                parentheses_stack.pop();
            }
            else{
                return false;
            }
        }
        return parentheses_stack.empty();
    }
};