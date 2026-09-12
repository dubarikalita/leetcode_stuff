class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long res=nums[0];
        long long sum=nums[0];
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            res=max(res,(sum+i)/(i+1));
        }
        return res;
    }
};