class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        vector<int>freq(26,0);
        for(char ch: s){
            freq[ch-'a']++;
        }

        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0)
                pq.push({freq[i],i+'a'});
        }

        while(!pq.empty()){
            char ch= pq.top().second;
            int freq= pq.top().first;
            pq.pop();
            if(ans!="" && ans.back()==ch){
                if(!pq.empty()){
                    char ch2= pq.top().second;
                    int freq2= pq.top().first;
                    pq.pop();
                    ans+= ch2;
                    freq2--;
                    if(freq2 > 0) pq.push({freq2,ch2});
                }
                else{
                    return "";
                }
            }
            else{
                ans+=ch;
                freq--;
            }
            if(freq>0){
                pq.push({freq,ch});
            }
        }
        return ans;
    }
};