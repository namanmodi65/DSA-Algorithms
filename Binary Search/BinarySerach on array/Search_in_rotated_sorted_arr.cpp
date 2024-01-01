#include <iostream>
using namespace std;

int search(int* arr, int n, int key) {
    int firstEle = arr[0];
    int lastEle = arr[n-1];

    int start = 0;
    int end = n-1;
    int mid = start + (end -start) / 2;
    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
        if(arr[start] <= arr[mid]){
            if(arr[start] <= key && key <= arr[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else{
            if(arr[mid] <= key && key <= arr[end]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        mid = start + (end -start) / 2;
    }
    return -1;
}

int main(){

return 0;
}