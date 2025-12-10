class Solution {
    int mod = 1000000007;
    int fact(int n){
        long ans =1;
        while(n!=1){
            ans = (ans*n)%mod;
            n--;
        }
        return (int)ans;
    }
    public int countPermutations(int[] complexity) {
        int n= complexity.length;
        int i=0;
        for(int x : complexity){
            if(x<= complexity[0] && i!=0){
                return 0;
            }
            i++;
        }
        return (fact(n-1))%mod;
    }
}