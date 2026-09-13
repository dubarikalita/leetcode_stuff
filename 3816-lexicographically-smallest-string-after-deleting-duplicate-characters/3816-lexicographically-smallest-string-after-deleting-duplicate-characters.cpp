class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int>freq(26,0);
        for(char c:s){
            freq[c -'a']++;
        }
        string ans;
        for(char c:s){
            while(!ans.empty() && ans.back()>c && freq[ans.back()-'a']>1){
                freq[ans.back()-'a']--;
                ans.pop_back();
            }
            ans.push_back(c);
        }

        while(!ans.empty() && freq[ans.back()-'a']>1){
            freq[ans.back()-'a']--;
            ans.pop_back();
        }
        return ans;
    }
};