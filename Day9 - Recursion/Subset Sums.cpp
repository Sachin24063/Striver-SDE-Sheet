class Solution
{
public:
    void solve(int idx, int sum, vector<int>& arr, int N, vector<int>& answer){
        if(idx == N){
            answer.push_back(sum);
            return;
        }
        //pickup that index into our sum
        solve(idx+1, sum+arr[idx],arr,N,answer);
        
        //not pickup that index
        solve(idx+1, sum, arr, N, answer);
    }
    public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> answer;
        solve(0,0,arr,N,answer);
        sort(answer.begin(),answer.end());
        return answer;
    }
};
