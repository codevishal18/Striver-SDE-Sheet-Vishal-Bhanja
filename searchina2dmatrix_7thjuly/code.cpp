#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int i = 0;
    int j = mat[0].size()-1;

    while(i<mat.size() && j>=0)
    {
        if(mat[i][j]==target)
        {
            return true;
        }
        else if(mat[i][j]>target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return false;
}