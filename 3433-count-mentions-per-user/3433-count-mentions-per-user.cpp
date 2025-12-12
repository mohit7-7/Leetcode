class Solution {
public:
    void applymsg(vector<string>&event , vector<int>&mentions , vector<int>&offline){
        int time = stoi(event[1]);
        vector<string> ids;
        stringstream ss(event[2]);

        string token;
        while(ss >> token){
            ids.push_back(token);
        }

        for(string id: ids){
            if(id=="ALL"){
                for(int i=0;i<mentions.size();i++){
                    mentions[i]++;
                }
            }
            else if(id=="HERE"){
                for(int i=0;i<mentions.size();i++){
                    if(offline[i]==0 || offline[i]+60 <= time){
                        mentions[i]++;
                    }
                }
            }
            else{
                mentions[stoi(id.substr(2))]++;
            }
        }

    }


    vector<int> countMentions(int n, vector<vector<string>>& events) {
        auto lambda = [](auto&v1 , auto&v2){
            int t1= stoi(v1[1]);
            int t2= stoi(v2[1]);
            if(t1==t2){
                return v1[0]>v2[0];
            }
            return t1<t2;
        };
        sort(events.begin(), events.end(), lambda);

        vector<int>mentions(n);
        vector<int>offline(n);
         
        for(auto&event : events){
            if(event[0]=="MESSAGE"){
                applymsg(event , mentions , offline);
            }
            else if(event[0]=="OFFLINE"){
                int time = stoi(event[1]);
                int id= stoi(event[2]);
                offline[id] = time;
            }
        }
        return mentions;
    }
};