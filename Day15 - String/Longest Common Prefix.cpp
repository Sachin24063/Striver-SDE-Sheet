class Solution {
public:
    string solve(string s1, string s2) {
        if (s2.size() < s1.size()) solve(s2,s1);
        string good_str = "";
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) {
                good_str += s1[i];
            } else {
                break;
            }
        }
        return good_str;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (auto it : strs) {
            ans = solve(ans, it);
        }
        return ans;
    }
};
