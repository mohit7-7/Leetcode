class Solution {
public:
    string padding(string x){
        if(x.length()==4)return x;
        while(x.length()!=4){
            x ="0"+x;
        }
        return x;
    }
    int generateKey(int num1, int num2, int num3) {
        string no1= padding(to_string(num1));
        string no2= padding(to_string(num2));
        string no3= padding(to_string(num3));
        string key="";
        for(int i=0;i<4;i++){
            char mini= min({no1[i], no2[i], no3[i]});
            key+=mini;
        }
        int ans= stoi(key);
        return ans;
    }
};