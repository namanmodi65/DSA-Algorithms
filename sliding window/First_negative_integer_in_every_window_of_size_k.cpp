#define ll long long

vector<long long> printFirstNegativeInteger(long long int arr[],long long int N, long long int K){
     
    ll i = 0;
    ll j = 0;
    vector<ll> ans;
    queue<ll> q;
    
    while(j<N){
        if(arr[j]<0) q.push(arr[j]);
        
        if(j-i+1<K){
            j++;
        }
        else if(j-i+1 == K){
            if(!q.empty()){
                ans.push_back(q.front());
            }
            else ans.push_back(0);
            
            if(q.front() == arr[i]) q.pop();
            i++;
            j++;
        }
    }
    
     
    return ans;
 }