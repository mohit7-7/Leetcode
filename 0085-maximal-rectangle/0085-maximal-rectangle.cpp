class Solution {
public:
        int calmaxarea(vector<int>& heights) {
        int n= heights.size();
        stack<int>st;
        vector<int>nsl(n,-1);//next smallest left cal. kro
        vector<int>nsr(n,n);//next smallest right cal. kro

        st.push(0); // index push kro.
        for(int i=1;i<n;i++){
            int curr= heights[i];
            while(!st.empty() && curr<=heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nsl[i]=st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            int curr= heights[i];
            while(!st.empty() && curr<=heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>heights(n,0);
        int maxarea =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            int area = calmaxarea(heights);
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};