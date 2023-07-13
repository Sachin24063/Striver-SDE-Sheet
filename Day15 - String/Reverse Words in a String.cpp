class Solution {
public:
    string reverseWords(string s) {
        int n = s.size()-1;
        string ans;
        while(n>=0){
            while(n>=0 && s[n] == ' ') n--;
            int end = n;
            while(n>=0 && s[n]!= ' ') n--;
            ans += s.substr(n+1, end-n);
            while(n>=0 && s[n] == ' ') n--;
            if(n >= 0) ans+=' ';
        }
        return ans;
    }
};
