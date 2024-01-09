#include <bits/stdc++.h>

bool solve(string &str){
    if(str.size()<=1) return false;

    for(int i=0;i<str.size()-1;i++){
        if(str[i]=='$' && str[i+1]=='$'){
            string newStr = str;
            newStr[i] = '*';
            newStr[i+1] = '*';
            if(!solve(newStr)) return true;
        }
    }
    return false;
}

bool canNinjaWin(string& str) {
    return solve(str);
}