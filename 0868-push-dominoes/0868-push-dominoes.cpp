class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes='L'+dominoes+'R';
        int n =dominoes.size();
        string res;
        int prev=0;
        for(int curr=1;curr<n;curr++){
            if(dominoes[curr]=='.')continue;
            if(prev!=0) res+=dominoes[prev];
            int span = curr-prev-1;
            if(dominoes[curr]== dominoes[prev]){ 
                res+= string(span, dominoes[prev]);
            }
            else if(dominoes[prev]=='L' && dominoes[curr]=='R'){
                res+= string(span,'.');
            }
            else{
                res+= string(span/2,'R')
                    + string(span%2,'.')
                    + string(span/2,'L');
            }
            prev= curr;
        }
        return res;
    }
};