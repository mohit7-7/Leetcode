class Solution {
public:
    int countCollisions(string directions) {
        int countR = 0;
        int n= directions.size();
        int ans = 0;
        bool stationary = false;
        for(int i=0;i<n;i++){
            if(directions[i]=='R'){
                countR++;
                stationary = false;
            }
            else if(directions[i]=='S'){
                ans += countR;
                countR=0;
                stationary = true;
            }
            else{
                if(stationary){
                    ans++;
                }
                else{
                    if(countR){
                        ans+=2;
                        countR--;
                        stationary = true;
                        ans += countR;
                        countR=0;
                    }
                }
            }
        }
        return ans;
    }
};
