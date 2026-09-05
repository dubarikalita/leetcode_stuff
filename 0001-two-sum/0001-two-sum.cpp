class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int x=target-nums[i];
            int j=find(nums.begin(),nums.end(),x)-nums.begin();
            if(find(nums.begin(),nums.end(),x)!=nums.end() && j!=i){
                ans={i,j};
            }
        }
        return ans;
    }
};