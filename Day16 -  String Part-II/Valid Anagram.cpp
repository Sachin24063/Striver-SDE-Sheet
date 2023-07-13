class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;
        if(s.size() != t.size()) return false;
        for(auto it: s)mp[it]++;
        for(auto it: t)mp[it]--;

        for(auto it: mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
