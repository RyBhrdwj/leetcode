#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;

class FirstSolution {
    // Use an unordered map to get occurences of all unique numbers.
    // For every element in unordered map, check if any other element has same occurences.
    // If so return false, else return true after the loop ends.
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurence_map;
        for (int i = 0; i < arr.size(); i++)
        {
            if (occurence_map.find(arr[i]) == occurence_map.end()) // Element not present
            {
                occurence_map[arr[i]] = 1;
            }
            else
            {
                occurence_map[arr[i]]++;
            }
        }

        for (auto &&number : occurence_map)
        {
            for (auto &&number2 : occurence_map)
                if(!(number2 == number))
                {
                    if(number2.second == number.second)
                    {
                        return false;
                    }
                }
        }
    return true;
    }
};

class OptimizedFirstSolution {
    // Use an unordered map to get occurences of all unique numbers.
    // Put all the occurences in a set, if the size of set == map return true else false.
    // NOTE : Better Way to Create Map : No need to check if element exists or not, just increment it.
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurence_map;
        set<int> occurence_set;
        for (int i = 0; i < arr.size(); i++)
        {
            occurence_map[arr[i]]++;
        }
        for(auto it = occurence_map.begin(); it != occurence_map.end(); it++)
        {
            occurence_set.insert(it->second);
        }
        return occurence_set.size() == occurence_map.size() ? true : false;
    }
};

class SecondSolution {
    // Use count sort to get occurences, sort them and if 2 adjacent numbers(not 0) are equal return false else true.
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> occurrences(2001, 0);
        for (auto &&number : arr)   {++occurrences[number+1000];}
        sort(begin(occurrences), end(occurrences));
        for (auto i = 0; i < 2000; ++i)
        {
            if(occurrences[i] && (occurrences[i] == occurrences[i+1]))  return false;
        }
        return true;
    }
};  