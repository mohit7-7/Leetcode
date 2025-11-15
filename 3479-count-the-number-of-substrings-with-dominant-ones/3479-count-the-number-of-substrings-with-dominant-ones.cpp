class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.size();
        int ans=0;
        vector<int>ps(n,0);
        ps[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            ps[i]= ps[i-1]+(s[i]-'0');
        }
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int cone = (ps[j])- (i>0 ? ps[i-1]: 0);
                int czero = (j-i+1)-cone;

                if((1LL*czero*czero)> cone){
                    int skip= czero*czero - cone;
                    j = j+skip-1;
                    continue;
                }
                if((1LL*czero*czero)  == cone){
                    ans++;
                }

                else{  //cone > czero*czero 
                    ans++;
                    int k = sqrt(cone)- czero;
                    int next = j+k;
                    if(next >= n){
                        ans += n-j-1;
                        break;
                    }
                    ans += k;
                    j= next; 
                }
            }
        }
        return ans;
    }
};