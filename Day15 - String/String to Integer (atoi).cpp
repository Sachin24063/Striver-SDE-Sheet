class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        double ans = 0;
        int len = 0;
        while(len < n && s[len] == ' ') len++;
        int sign = 1;
        if(s[len] == '-'){
            sign = -1;
            len++;
        }
        else if(s[len] == '+'){
            len++;
        }
        while(len < n && s[len]>='0' && s[len]<='9'){
            ans = (ans*10) + (s[len]-'0');
            if (ans * sign > INT_MAX)
                return INT_MAX;
            if (ans * sign < INT_MIN)
                return INT_MIN;
            len++;
        }
        return (int)(ans*sign);
    }
};
