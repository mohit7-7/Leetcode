class Solution {
public:
    static const unordered_set<string>& buildset() {
        static unordered_set<string> st; // Created only once
        if (st.empty()) {
            for (int p = 0; p <= 29; p++) {
                string power = to_string(1 << p);
                sort(power.begin(), power.end());
                st.insert(power);
            }
        }
        return st;
    }
    bool reorderedPowerOf2(int n) {
        auto &st= buildset();
        string input= to_string(n);
        sort(input.begin(), input.end());
        return st.count(input);
    }
};