#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1 : 2 words are anagrams if the other word is made from rearrangement of characters of first word.
    // Since anagrams have same length, if the given strings are not of same length they are not anagrams.
    // Count how many times each character appears in string 1, do the same for string 2 and take the difference.
    // If the final count of all characters is 0 => the strings are anagrams.
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())   return false;
        
        unordered_map<char, int> char_map;
        for (auto &&c : s){char_map[c]++;}
        for (auto &&c : t){char_map[c]--;}
        for(auto&&c : char_map)
        {
            if (c.second != 0)   return false;
        }
        return true;
    }

    // Approach 2 : Since the strings only contain lowercase alphabets, max characters possible = 26.
    // => Instead of using a hashmap, use an array of length 26.
    // Index of character = int(character) - 97 since lowercase alphabet codes start from 97.
    bool isAnagram2(string s, string t)
    {
        if (s.length() != t.length())   return false;
        vector<int> char_array(26);
        for (auto &&c : s){char_array[c - 97]++;}
        for (auto &&c : t){char_array[c - 97]--;}
        for(auto&&c : char_array)
        {
            if (c != 0)   return false;
        }
        return true;
    }
};