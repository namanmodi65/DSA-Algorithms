#include <bits/stdc++.h> 

pair<int, int> search(vector<vector<int>> matrix, int x)
{
    // Write your code here.
    int n=matrix.size();

    int m=matrix[0].size();

    int i=0 , j=m-1;

    while(i<n && j>=0){

        if(matrix[i][j]==x)

            return {i,j};

        else if(matrix[i][j]<x)

            i++;

        else 

            j--;

    }

    return {-1,-1};
}