class Solution {
public:
    typedef pair<int,pair<int,int>> PP; // heigth and coordinates(for checking neighbours)

    vector<vector<int>>directions= {{-1,0},{0,1}, {0,-1}, {1,0}};
    int trapRainWater(vector<vector<int>>& height) {
        int m= height.size();
        int n= height[0].size();
        priority_queue<PP, vector<PP>, greater<PP>>pq;
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        //push boundary elements first 
        for(int i=0;i<n;i++){
            pq.push({height[0][i],{0,i}});
            visited[0][i]= true;
            pq.push({height[m-1][i],{m-1,i}});
            visited[m-1][i]= true;
        }
        for(int i=0;i<m;i++){
            pq.push({height[i][0], {i,0}});
            visited[i][0]= true;
            pq.push({height[i][n-1],{i,n-1}});
            visited[i][n-1]= true;
        }


        int water=0;
        while(!pq.empty()){
            PP p = pq.top();
            pq.pop();
            
            int cheight= p.first;
            int i= p.second.first;
            int j= p.second.second;

            //find neighbours now if smaller that means they can trap some water.
            for(vector<int>&dir : directions){
                int i_ = i+dir[0];
                int j_ = j+dir[1];
                if(i_ >=0 && i_<m && j_>=0 && j_ <n && !visited[i_][j_]){
                    water += max((cheight- height[i_][j_]),0);
                    int heig= max(cheight, height[i_][j_]);
                    pq.push({heig,{i_,j_}});
                    visited[i_][j_]= true;
                }
            } 
        }
        return water;
    }
};