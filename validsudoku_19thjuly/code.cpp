#include<bits/stdc++.h>
using namespace std;

bool isValid(int matrix[9][9],int i,int j,int x)
{
    //checking row and column
    for(int k=0;k<9;k++)
    {
        if(matrix[i][k]==x || matrix[k][j]==x)
        {
            return false;
        }
    }

    //checking 3X3 submatrix
    int si = i-i%3;
    int sj = j-j%3;
    for(int k=si;k<si+3;k++)
    {
        for(int l=sj;l<sj+3;l++)
        {
            if(matrix[k][l]==x)
            {
                return false;
            }
        }
    }

    return true;
}

bool solve(int matrix[9][9],int i,int j)
{
    if(i==9)
    {
        return true;
    }

    if(j==9)
    {
        return solve(matrix,i+1,0);
    }

    if(matrix[i][j]!=0)
    {
        return solve(matrix,i,j+1);
    }

    for(int c=1;c<=9;c++)
    {
        if(isValid(matrix,i,j,c))
        {
            matrix[i][j]=c;
            if(solve(matrix,i,j+1))
            {
                return true;
            }
            matrix[i][j]=0;
        }
    }

    return false;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    if(solve(matrix,0,0))
    {
        return true;
    }
    return false;
}
