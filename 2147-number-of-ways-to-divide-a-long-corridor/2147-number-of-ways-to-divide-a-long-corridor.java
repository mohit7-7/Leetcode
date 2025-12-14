class Solution {
    int mod = 10_000_000_07;
    public int numberOfWays(String corridor) {
        int n= corridor.length();
        int count=0;
        for(int i=0;i<n;i++){
            if(corridor.charAt(i)=='S') count++;
        }
        if(count ==0 || count%2 !=0) return 0;
        count = 0;
        long ans =1;
        int i=0 , p=0;
        boolean flag= false;
        while(i<n){
            if(corridor.charAt(i)=='S'){
                count++;
                if(count%2==0){
                    flag = true;
                }
                else if(count >2){
                    ans = (ans*(p+1))%mod;
                    count =1;
                    flag = false;
                    p=0;
                }
            }
            else if(flag){
                p++;
            }
            i++;
        }
        return (int)ans;
    }
}