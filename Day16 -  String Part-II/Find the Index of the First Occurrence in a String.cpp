class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        int n = haystack.size();
        vector<int> LPS(m);
        LPS[0] = 0; int len = 0, i=1;
        while(i<m){
            if(needle[i] == needle[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
                if(len == 0){
                    LPS[i] = 0;
                    i++;
                }
                else{
                    len = LPS[len-1];
                }
            }
        }
         i=0; 
         int j =0;
        while(i<n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j==m) return i-j;
            }
            else{
                if(j != 0) j = LPS[j-1];
                else i++;
            }
        }
        return -1;
    }
};
