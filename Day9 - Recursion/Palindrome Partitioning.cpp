class Solution {
public:
    bool is_palindrome(string s, int st, int en){
        while(st <= en){
            if(s[st] != s[en]) return false;
            st ++;
            en --;
        }
        return true;
    }

public:
    void solve(string s, int idx, vector<vector<string>>& ans, vector<string> &temp){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(is_palindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s, i+1, ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, ans, temp);
        return ans;
    }
};
