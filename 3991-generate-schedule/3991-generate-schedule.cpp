class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        if(n<5) return {};
        vector<vector<int>> pmatch;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    pmatch.push_back({i,j});
                }
            }
        }

        vector<vector<int>>ans;

        while(!pmatch.empty()){
            vector<vector<int>>remaining;
            for(int i=0;i<pmatch.size();i++){
                if(ans.empty()){
                    ans.push_back(pmatch[i]);
                    continue;
                }

                int currA= pmatch[i][0], currB= pmatch[i][1];
                int prevA= ans.back()[0], prevB= ans.back()[1];
                if(currA== prevA || currA== prevB || currB== prevA || currB==prevB){
                    int j=0;
                    //find a place to insert this match
                    while(j<ans.size()){
                        int x1 = ans[j][0], x2= ans[j][1];

                        if(j==0){
                            if(currA== x1 || currA ==x2 || currB == x1 || currB ==x2){
                                j++;
                                continue;
                            }
                            else break;
                        }

                        int x3 = ans[j-1][0] , x4= ans[j-1][1];

                        if(currA== x1 || currA == x2 || currA == x3 || currA== x4 ||
                            currB == x1 || currB == x2 || currB == x3 || currB == x4){
                            j++;
                            continue;
                        }
                        else break;

                        j++;
                    }
                    if(j==ans.size()) remaining.push_back(pmatch[i]);
                    else ans.insert(ans.begin()+j, pmatch[i]);
                }
                else{
                    ans.push_back(pmatch[i]);
                }
            }
            pmatch= remaining;
        }
        return ans;
    }
}; 