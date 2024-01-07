#include <bits/stdc++.h> 

long long solve(int x,int n){
    if(n == 0) return 1;
    return x*solve(x,n-1);;
}

long long Pow(int X, int N)
{
    // X^N
    return solve(X,N);
}