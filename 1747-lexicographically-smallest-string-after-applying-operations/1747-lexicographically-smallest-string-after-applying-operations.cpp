class Solution {
public: 
    void rotate(string &s, int b){
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+b);
        reverse(s.begin()+b, s.end());
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        visited.insert(s);
        queue<string>q;
        q.push(s);
        string ans= s;
        while(!q.empty()){
            string temp= q.front();
            q.pop();
            if(temp< ans){
                ans= temp;
            }

            for(int i=1;i<temp.size();i+=2){
                temp[i] =(temp[i]-'0'+a)%10 +'0';
            }
            if(!visited.count(temp)){
                q.push(temp);
                visited.insert(temp);
            }

            rotate(temp,b);
            if(!visited.count(temp)){
                visited.insert(temp);
                q.push(temp);
            }
        }
        return ans;
    }
};