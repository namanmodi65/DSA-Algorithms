void shortest_distance(vector<vector<int>>&arr){
	    int n = arr.size();
	    
	    for(int k=0;k<n;k++){
	        
	        for(int i=0;i<n;i++){
	            
	            for(int j=0;j<n;j++){
	                
	               if(arr[i][j] == -1) arr[i][j]=1e9;
	               arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
	                
	            }
	            
	        }
	        
	    }
	    
	   for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++){
	           if(arr[i][j] == 1e9) arr[i][j] = -1;
	       }
	   }
	 
	}