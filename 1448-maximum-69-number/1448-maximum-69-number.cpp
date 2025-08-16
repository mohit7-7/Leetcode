class Solution {
public:
    int maximum69Number (int num) {
        int temp=num;
        int countfromright=-1,pos=0;
        while(temp){
            int digit = temp%10;
            if(digit==6) countfromright= pos;
            pos++;
            temp /= 10;
        }
        if(countfromright==-1) return num;
        return num+ 3*(pow(10,countfromright));
    }
};

// right side se sbse last m aane vala 6 dhundo usme 3 plus krna hai bss...

// 99669 
//+  300(3*10^2) here 2-- no. of elements in right side of 6 so just track that.
//=99969 ans

