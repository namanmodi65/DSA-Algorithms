// Consider an array: arr[] = {15, 17, 12, 13, 14, 10}
// For i = 0: stk = {15}
// For i = 1: stk = {17} [pop 15 as 15 < 17]
// For i = 2: stk = {17, 12}
// For i = 3: stk = {17, 13}  [pop 12 as 12 < 13]
// For i = 4: stk = {17, 14}  [pop 13 as 13 < 14]
// For i = 5: stk = {17, 14, 10}


#include<bits/stdc++.h>
using namespace std;

void monotonicIncreasing(vector<int> arr){
    stack<int> s;

    for(int i=0;i<arr.size();i++){

        while (s.size() > 0 && s.top() < arr[i]) {
            s.pop();
        }
        s.push(arr[i]);

        // if(s.empty() || s.top()<arr[i]){
        //     s.push(arr[i]);
        // }
        // else{
        //     while(!s.empty()){
        //         if(s.top()<arr[i]){
        //             s.push(arr[i]);
        //             break;
        //         }
        //         s.pop();
        //     }
        // }
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}

int main(){
    vector<int> arr = {15, 17, 12, 13, 14, 10};
    monotonicIncreasing(arr);
    return 0;
}