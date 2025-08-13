class Solution {
public:
    unordered_set<string>st;
    bool reorderedPowerOf2(int n) {
        for(int p=0;p<=29;p++){
            string power= to_string(1<<p);
            sort(begin(power), end(power));
            st.insert(power);
            
        }

        string input= to_string(n);
        return st.count(input);
    }
};