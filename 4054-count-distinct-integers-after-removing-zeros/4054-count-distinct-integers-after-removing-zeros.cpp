class Solution {
public:
long long pow9(int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= 9;
    }
    return result;
}

long long countDistinct(long long n) {
    string s = to_string(n);
    int len = s.length();
    long long total = 0;
    // Count numbers with fewer digits than n (all without zeros)
    for (int l = 1; l < len; l++) {
        total += pow9(l);
    }
    // Count numbers with exactly len digits without zeros and <= n
    bool tight = true;
    long long exact = 0;
    for (int i = 0; i < len; i++) {
        int digit = s[i] - '0';
        if (!tight) {
            exact += pow9(len - i);
            break;
        }
        if (digit == 0) {
            tight = false;
            break;
        }
        if (digit > 1) {
            exact += (digit - 1) * pow9(len - i - 1);
        }
    }
    if (tight) {
        exact++;
    }
    total += exact;
    return total;
}
};