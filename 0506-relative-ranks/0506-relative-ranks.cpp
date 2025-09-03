class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n= score.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        } 
        vector<string>ans(n);
        int i=1;
        while(!pq.empty()){
            int indx= pq.top().second;
            pq.pop();
            if(i==1){  
                ans[indx]="Gold Medal";
            }
            else if(i==2){
                ans[indx]="Silver Medal";
            }
            else if(i==3){
                ans[indx]="Bronze Medal";
            }
            else{
                ans[indx]= to_string(i);
            }
            i++;
        }
        return ans;
    }
};