#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;

    while(left<right && top<bottom)
    {
        int temp = mat[top][left];

        for(int i=left+1;i<=right;i++)
        {
            int k = mat[top][i];
            mat[top][i] = temp;
            temp = k;
        }
        top++;

        for(int i=top;i<=bottom;i++)
        {
            int k = mat[i][right];
            mat[i][right] = temp;
            temp = k;
        }
        right--;

        for(int i=right;i>=left;i--)
        {
            int k = mat[bottom][i];
            mat[bottom][i] = temp;
            temp = k;
        }
        bottom--;

        for(int i=bottom;i>=top;i--)
        {
            int k = mat[i][left];
            mat[i][left] = temp;
            temp = k;
        }
        left++;

        mat[top-1][left-1] = temp;
    }
}