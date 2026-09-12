class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        int minIndex=0;
        int minVal=nums[0];
        int maxIndex=0;
        int maxVal=nums[0];

        for(int j=indexDifference;j<nums.size();j++){
            int i=j-indexDifference;

            if(nums[i]<minVal){
                minVal=nums[i];
                minIndex=i;
            }
            if(nums[i]>maxVal){
                maxVal=nums[i];
                maxIndex=i;
            }
            if(nums[j]-minVal>=valueDifference){
                return {minIndex,j};
            }
            if(maxVal-nums[j]>=valueDifference){
                return {j,maxIndex};
            }
        }
        return {-1,-1};
    }
};