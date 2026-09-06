class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int left=0;
        int right=0;
        int maxLen=0;
        while(right<s.size()){
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left){
                    left=hash[s[right]]+1;
                }
            }
            int len=right-left+1;
            maxLen=max(len,maxLen);
            hash[s[right]]=right;

            right++;
        }
        return maxLen;
    }
};