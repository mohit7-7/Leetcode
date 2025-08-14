class Solution {
public:
    unordered_set<string>st;
    bool reorderedPowerOf2(int n) {
        for(int p=0;p<=30;p++){
            string power= to_string(1<<p);
            sort(begin(power), end(power));
            st.insert(power);
            
        }

        string input= to_string(n);
        sort(begin(input), end(input));
        return st.count(input);
    }
};