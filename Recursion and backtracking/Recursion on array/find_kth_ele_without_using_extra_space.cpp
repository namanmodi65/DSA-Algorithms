#include <bits/stdc++.h>

int findKthElement(vector<int> &arr1, vector<int> &arr2, int k){ 
    int i=0;
    int j=0;
    int indx =0; 

   while(i<arr1.size() && j<arr2.size()){  
        if(indx+1 < k){     
            if(arr1[i] < arr2[j]){  
                i++;
            }  

            else j++; 
            
            indx++;   
            } 
        else {    
            if(arr1[i] < arr2[j]){ 
                return arr1[i];     
            }      
            else return arr2[j];   

        }      
    }    

    while(i<arr1.size()){
        if(indx+1 == k){  
          return arr1[i];
        }  
       i++; 
       indx++;    
    }   

 while(j<arr2.size()){    
    if(indx+1 == k){ 
        return arr2[j]; 

    } 
    j++;       
    indx++;    
}

}