class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        stack<int>st;
        vector<int>nsl(n);//next smallest left cal. kro
        vector<int>nsr(n);//next smallest right cal. kro
        
        
        nsl[0]=-1;
        st.push(0); // index push kro.
        for(int i=1;i<n;i++){
            int curr= heights[i];
            while(!st.empty() && curr<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsl[i]=-1;
            }
            else{
                nsl[i]=st.top();
            }
            st.push(i);
        }
        
        //stack ko khali krlo.
        while(!st.empty()){
            st.pop();
        }
        
        nsr[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            int curr= heights[i];
            while(!st.empty() && curr<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsr[i]=n; // stack empty hua toh -1 nhi n ko daalenge to get the correct area.
            }
            else{
                nsr[i]= st.top();
            }
            st.push(i);
        }      
        
        int maxarea= INT_MIN;
        for(int i=0;i<n;i++){
            int width= nsr[i]-nsl[i]-1;
            int area= heights[i]*width;
            maxarea= max(area, maxarea);
        }
         return maxarea;
    }
};