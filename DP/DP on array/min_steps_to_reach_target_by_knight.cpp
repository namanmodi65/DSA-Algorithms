#include<bits/stdc++.h>
bool isValid(int row,int col,int n){
    return ((row >= 0 && row < n) && (col >= 0 && col < n));
}

int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int n) {
    if(knightPosition==targetPosition) {
        return 0;
    }
    
    int x1 = knightPosition.first;
    int y1 = knightPosition.second;
    int x2 = targetPosition.first;
    int y2 = targetPosition.second;

    vector<vector<int>> arr(n,vector<int>(n,0));

    queue<pair<int, int>> q;
    q.push({x1-1,y1-1});
    auto i = q.front();
    while(!q.empty()){
        auto curr = q.front();
        int i = curr.first;
        int j = curr.second;
        q.pop();

        if(isValid(i-2,j+1,n) && arr[i-2][j+1] == 0){
            arr[i-2][j+1] = 1+arr[i][j];
            q.push({i-2,j+1});
        }

        if(isValid(i-2,j-1,n) && arr[i-2][j-1] == 0){
            arr[i-2][j-1] = 1+arr[i][j];
            q.push({i-2,j-1});
        }

        if(isValid(i+2,j-1,n) && arr[i+2][j-1] == 0){
            arr[i+2][j-1] = 1+arr[i][j];
            q.push({i+2,j-1});
        }

        if(isValid(i+2,j+1,n) && arr[i+2][j+1] == 0){
            arr[i+2][j+1] = 1+arr[i][j];
            q.push({i+2,j+1});
        }

        if(isValid(i-1,j+2,n) && arr[i-1][j+2] == 0){
            arr[i-1][j+2] = 1+arr[i][j];
            q.push({i-1,j+2});
        }

        if(isValid(i+1,j+2,n) && arr[i+1][j+2] == 0){
            arr[i+1][j+2] = 1+arr[i][j];
            q.push({i+1,j+2});
        }

        if(isValid(i-1,j-2,n) && arr[i-1][j-2] == 0){
            arr[i-1][j-2] = 1+arr[i][j];
            q.push({i-1,j-2});
        }

        if(isValid(i+1,j-2,n) && arr[i+1][j-2] == 0){
            arr[i+1][j-2] = 1+arr[i][j];
            q.push({i+1,j-2});
        }
    }
    return arr[x2-1][y2-1];


}