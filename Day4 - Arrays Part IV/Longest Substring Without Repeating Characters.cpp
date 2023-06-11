class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int n = s.size(), ans = 0;
        set<char> st;
        int start = 0;
        for (int i = start; i < n; i++) {
            if (st.find(s[i]) != st.end()) {
                ans = max(ans, i - start);
                while (s[start] != s[i]) {
                    st.erase(s[start]);
                    start++;
                }
                start++;
            }
            st.insert(s[i]);
        }
        return max(ans, n - start);
    }
};
