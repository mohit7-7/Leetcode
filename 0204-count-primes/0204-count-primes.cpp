class Solution {
public:
    void builtprime(vector<int>&prime, int n){
        vector<int>sieve(n, 1);
        for(int i=2;i*i<n;i++){
            if(sieve[i]== 1){
                for(int j=i; i*j<n;j++){
                    sieve[i*j]= 0;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(sieve[i]== 1){
                prime.push_back(i);
            }
        }
    }
    int countPrimes(int n) {
        vector<int>prime;
        builtprime(prime,n);
        return prime.size();
    }
};