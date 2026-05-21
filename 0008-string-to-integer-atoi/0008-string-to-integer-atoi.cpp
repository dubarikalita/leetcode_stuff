class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();

        while(i<n && s[i]==' '){
            i++;
        }

        bool  isNeg=false;
        if(i<n && s[i]=='-'){
            i++;
            isNeg=true;
        }
        else if(i<n && s[i]=='+'){
            i++;
        }

        long ans=0;
        while(i<n && s[i]>='0' && s[i]<='9'){
           int d=s[i]-'0';
           ans=ans*10+d;
           if(isNeg && -ans<INT_MIN) return INT_MIN;
            if(!isNeg && ans>INT_MAX)  return INT_MAX;
            i++;
    
        }

        return isNeg? -ans:ans;
    }
};