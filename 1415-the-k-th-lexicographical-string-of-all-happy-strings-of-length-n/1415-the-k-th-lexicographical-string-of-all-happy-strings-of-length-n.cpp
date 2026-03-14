class Solution {
public:
    void solve(int n, string curr, vector<string>&result){
        if(curr.length()==n){
            result.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch<='c';ch++){
            if(!curr.empty() && curr.back()==ch) continue;
            curr.push_back(ch);
            solve(n , curr, result);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {

        int total = 3 * (1<<(n-1));
        if(k>total) return "";
        
        string curr ="";
        vector<string> result;
        solve(n,curr, result);
        return result[k-1];
    }
};