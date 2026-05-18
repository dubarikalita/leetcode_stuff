class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOcc(nums,target);
        int last=lastOcc(nums,target);
        auto it=find(nums.begin(),nums.end(),target);
        if( it==nums.end()) return {-1,-1};

        return {first,last};
    }

    int firstOcc(vector<int> &nums,int target){
        int l=0;
        int h=nums.size()-1;
        int ans=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]>=target){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }

    int lastOcc(vector<int> &nums,int target){
        int l=0;
        int h=nums.size()-1;
        int ans=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]<=target){
                ans=m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return ans;
    }
};