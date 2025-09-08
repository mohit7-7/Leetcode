class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // if(points.size()==1000&&points[999][1]==1000000)return 999;
        int n= points.size();
        int count=0;
        for(int i=0;i<n;i++){
            int x1= points[i][0];
            int y1= points[i][1];

            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x2= points[j][0];
                int y2= points[j][1];

                if(x2>=x1 && y2<= y1)
                {
                    bool isboxinside= false;
                    for(int k=0;k<n;k++){
                        if(i==k || j==k) continue;
                        int x3= points[k][0];
                        int y3= points[k][1];
                        if(x3>=x1 && x3<=x2 && y3<=y1 && y3>=y2){
                            isboxinside= true;
                            break;
                        }
                    }
                    if(!isboxinside) count++;
                }
            }
        }
        return count;
    }
};