class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n= s.size(), m= p.size();
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int j=0;j<m;j++){
            freq1[p[j]-'a']++;
        }
        int i=0, j=0;
        while(j<n){
            freq2[s[j]-'a']++;
            if(j-i+1==m){
                if(freq1==freq2){
                    ans.push_back(i);
                }
                freq2[s[i]-'a']--;
                i++;
            }
            j++;
        } 
        return ans;
    } 
};