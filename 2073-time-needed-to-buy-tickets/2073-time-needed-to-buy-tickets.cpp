class Solution {
public:
    queue<int>q;
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int time=0;
        while(tickets[k]){
            int current = q.front();
            q.pop();
            tickets[current]--;
            time++;
            if(tickets[current]!=0){
                q.push(current);
            }
        }
        
        return time;
        
    }
};