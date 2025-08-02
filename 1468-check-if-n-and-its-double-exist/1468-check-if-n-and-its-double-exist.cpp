class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       unordered_set<float>st;
       for(int num: arr){
            if(st.count((float)num/2) || st.count(num*2)) return true;
            st.insert((float)num);
       } 
       return false;
    }
};