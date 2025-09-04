class Solution {
public: 
    double gain(int pass, int total){
        return (double)(pass+1)/(total+1)- (double)pass/total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>>pq;
        for(int i=0;i<classes.size();i++){
            int passing= classes[i][0];
            int total= classes[i][1];
            pq.push({gain(passing,total),i});
        }
        while(extraStudents--){
            int indx= pq.top().second;
            pq.pop();
            int newpass = ++classes[indx][0];
            int newtotal = ++classes[indx][1];
            pq.push({gain(newpass, newtotal),indx});
        }

        double ans= 0.0;
        for(auto c : classes){
            ans += (double)c[0]/c[1];
        }
        return ans/classes.size();
    }
};