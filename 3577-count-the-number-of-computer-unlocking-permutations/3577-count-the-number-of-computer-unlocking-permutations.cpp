class Solution {
public:
    int mod = 1e9+7;

    int fact(int n){
        long long ans=1;
        while(n!=1){
            ans= (ans*n)%mod;
            n--;
        }
        return (int) ans;
    }
    int countPermutations(vector<int>& complexity) {
        int n= complexity.size();
        int i=0;
        for(int x : complexity){
            if((x<= complexity[0]) && i!=0){
                return 0;
            }
            i++;
        }
        return (fact(n-1)) %mod; 
    }
};