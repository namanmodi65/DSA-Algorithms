class Solution {
public:
    void fillLps(string str,vector<int> &lps){
        int n = str.size();
        int i = 1;
        int len = 0;
        lps[0]=0;
        while(i<n){
            if(str[i]==str[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len == 0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        vector<int> lps(m,0);
        fillLps(needle,lps);
        
        int i = 0;
        int j = 0;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j == m){
                    return i-j;
                }
            }
            else if(i<n && haystack[i]!=needle[j]){
                if(j == 0) i++;
                else j = lps[j-1];
            }
        }

        return -1;    
    }
};