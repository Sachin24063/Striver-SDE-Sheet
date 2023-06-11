vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size();
    long long int xorSum = 0;
    long long int xorNums = 0;
    long long int xorAB = 0;

    for (int i = 0; i < n; i++) {
        xorSum ^= A[i];
        xorNums ^= (i + 1);
    }
    xorAB = xorSum ^ xorNums;
    long long int rightmostSetBit = xorAB & (~(xorAB - 1));

    long long int num1 = 0;
    long long int num2 = 0;

    for (int i = 0; i < n; i++) {
        if ((A[i] & rightmostSetBit) != 0)
            num1 ^= A[i];
        else
            num2 ^= A[i];
    }

    for (int i = 1; i <= n; i++) {
        if ((i & rightmostSetBit) != 0)
            num1 ^= i;
        else
            num2 ^= i;
    }
    for (int i = 0; i < n; i++) {
        if (A[i] == num1)
            return {num1, num2};
    }

    return {num2, num1};
}
