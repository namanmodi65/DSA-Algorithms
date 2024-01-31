// Consider an array Arr[] = {1, 4, 5, 3, 12, 10}
// For i = 0: stk = {1}
// For i = 1: stk = {1, 4}
// For i = 2: stk = {1, 4, 5}
// For i = 3: stk = {1, 3}  [pop 4 and 5 as 4 > 3 and 5 > 3]
// For i = 4: stk = {1, 3, 12}
// For i = 5: stk = {1, 3, 10} [pop 12 as 12 > 10] 

#include<bits/stdc++.h>
using namespace std;

void monotonicIncreasing(vector<int> arr){
    stack<int> s;

    for(int i=0;i<arr.size();i++){

        while (s.size() > 0 && s.top() > arr[i]) {
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
    vector<int> arr = {1, 4, 5, 3, 12, 10};
    monotonicIncreasing(arr);
    return 0;
}