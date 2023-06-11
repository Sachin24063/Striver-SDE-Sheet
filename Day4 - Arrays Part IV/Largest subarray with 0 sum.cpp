class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int ans = 0;
        int prefix = 0;
        unordered_map<int, int> mp;
         mp[0] = -1;
        for(int i =0;i<n;i++){
            prefix += A[i];
            if(mp.count(prefix)){
                ans = max(ans, i-mp[prefix]);
            }
            else mp[prefix] = i;
        }
        return ans;
    }
};
