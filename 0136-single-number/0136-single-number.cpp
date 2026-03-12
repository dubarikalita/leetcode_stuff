class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int reqdNum=nums[0];
        for(int i=1;i<nums.size();i++){
            reqdNum=reqdNum^nums[i];
        }
        return reqdNum;
    }
};