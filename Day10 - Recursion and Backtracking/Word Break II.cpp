#include <bits/stdc++.h>

unordered_set<string> dictSet;

vector<string> solve(string s, int n, unordered_set<string>& st) {
    vector<string> result;

    if (n <= 0) {
        result.push_back("");
        return result;
    }

    for (int i = 1; i <= n; i++) {
        string prefix = s.substr(0, i);
        if (st.count(prefix)) {
            vector<string> suffixes = solve(s.substr(i), n - i, st);
            for (string suffix : suffixes) {
                if (suffix.empty()) {
                    result.push_back(prefix);
                } else {
                    result.push_back(prefix + " " + suffix);
                }
            }
        }
    }

    return result;
}

vector<string> wordBreak(string s, vector<string>& dictionary) {
    dictSet = unordered_set<string>(dictionary.begin(), dictionary.end());
    return solve(s, s.size(), dictSet);
}
