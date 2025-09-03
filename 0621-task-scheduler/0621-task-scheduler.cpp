class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char ch: tasks){
            freq[ch-'A']++;
        }

        int time=0;
        priority_queue<int>pq;
        
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }

        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq= pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &f: temp){
                if(f>0) pq.push(f);
            }

            if(pq.empty()){
                time += temp.size();
            }
            else{
                time+= n+1;
            }

        }

        return time;
        
    }
};