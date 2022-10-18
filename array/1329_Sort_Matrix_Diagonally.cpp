#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();
        unordered_map<int, vector<int>> diagonal_map;

        for (int row_ptr = 0; row_ptr < rows; row_ptr++)
        {
            for (int col_ptr = 0; col_ptr < columns; col_ptr++)
            {
                int index = row_ptr - col_ptr;
                if (diagonal_map.find(index) != diagonal_map.end())
                {
                    diagonal_map[index].push_back(matrix[row_ptr][col_ptr]);
                }
                else
                {
                    diagonal_map[index] = vector<int>{matrix[row_ptr][col_ptr]};
                }
            }            
        }
        for (auto it = diagonal_map.begin(); it != diagonal_map.end(); it++)
        {
            vector<int> diagonal = diagonal_map[it->first];
            sort(diagonal.begin(), diagonal.end());
            diagonal_map[it->first] = diagonal;
        }
        for (int row_ptr = 0; row_ptr < rows; row_ptr++)
        {
            for (int col_ptr = 0; col_ptr < columns; col_ptr++)
            {
                int index = row_ptr - col_ptr;
                vector<int>& diagonal = diagonal_map[index];
                matrix[row_ptr][col_ptr] = diagonal.front();
                diagonal.erase(diagonal.begin());
            }
        }
        return matrix;
    }
};