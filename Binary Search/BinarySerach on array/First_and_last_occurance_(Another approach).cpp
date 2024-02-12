class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;        
        int last = -1;

        int start = 0;
        int end = nums.size()-1;
        vector<int>::iterator low1, low2; 
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid] == target){
                low1 = std::lower_bound(nums.begin(), nums.end(), target); 
                low2 = std::upper_bound(nums.begin(), nums.end(), target); 
                first = (low1 - nums.begin());
                last = (low2 - nums.begin())-1;
                return {first,last};
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }        
        return {first,last};
    }
};