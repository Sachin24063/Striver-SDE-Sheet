int Solution::solve(vector<int> &A, int B) {
   unordered_map<int, int> mp;
   int ans = 0, x = 0;
   for(int i=0;i<A.size();i++){
       x = x ^ A[i];
       if(x == B){
           ans++;
       }
       if(mp.find(x ^ B) != mp.end()){
           ans += mp[x ^ B];
       }
       mp[x]++;
   }
    return ans;
}
