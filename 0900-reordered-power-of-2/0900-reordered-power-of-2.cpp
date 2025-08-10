class Solution {
public:
    vector<int> getcountformat(int n){
        vector<int>vec(10);
        while(n){
            vec[n%10]++;
            n /=10;
        }
        return vec;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> input= getcountformat(n);
        for(int p=0;p<=29;p++){
            if(input == getcountformat(1<<p)) return true;
        }
        return false;
    }
};