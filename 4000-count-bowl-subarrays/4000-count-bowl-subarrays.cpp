#define ll long long
class Solution {
public:                  
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, n), pge(n, -1); 
        
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()) nge[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()) pge[i] = st.top();
            st.push(i);
        }

        ll count = 0;
        for(int i=0; i<n; i++){
            if(nge[i]!=n && (nge[i]-i+1)>2) count++;
            if(pge[i]!=-1 && (i-pge[i]+1)>2) count++;
        }
        return count;
    }
};
