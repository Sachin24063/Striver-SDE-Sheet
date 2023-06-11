vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    map<int,int> mp;
    long long sum=0;
    for(auto it: A){
        sum+=it;
        mp[it]++;
    }
    int a;
    for(auto it:mp){    
        if(it.second>1){
            a = it.first;
        }
    }
    sum = sum - a;
    long long ans = (n * (n+1)) / 2;
       long long temp = ans-sum;
       return {a,(int)temp};
}
