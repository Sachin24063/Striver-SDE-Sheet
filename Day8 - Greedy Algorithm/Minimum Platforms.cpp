class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	//stack<int> st;
    	int ans = 1, platform_needed = 1;
    	int i = 1, j = 0;
    	while(i<n && j<n){
    	    if(arr[i] <= dep[j]){
    	        platform_needed ++;
    	        i++;
    	    }
    	    else if(arr[i] >= dep[j]){
    	        platform_needed --;
    	        j++;
    	    }
    	    ans = max(ans, platform_needed);
    	}
    	return ans;
    }
};
