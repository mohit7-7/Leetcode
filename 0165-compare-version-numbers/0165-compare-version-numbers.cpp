class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0;
        int j=0;
        int ver1=0;
        int ver2=0;
        while(i <  v1.length() || j < v2.length()){
            while(i < v1.length() && v1[i]!='.'){
                ver1 = ver1*10 + (v1[i]-'0');
                i++;
            }
            while(j < v2.length() && v2[j] !='.' ){
                ver2=ver2*10 + (v2[j]-'0');
                j++;
            }
            if(ver1>ver2) return 1;
            else if(ver2>ver1) return -1;
            ver1 = ver2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};