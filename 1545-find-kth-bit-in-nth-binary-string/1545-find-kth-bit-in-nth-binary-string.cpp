class Solution {
public:
    string getinvert(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        vector<string>bs(20);
        bs[0]= "0";
        for(int i=1;i<20;i++){
            string toput= bs[i-1]+"1"+getinvert(bs[i-1]);
            bs[i]= toput;
        }
        cout<<bs[n-1];
        return bs[n-1].at(k-1);
    }
};