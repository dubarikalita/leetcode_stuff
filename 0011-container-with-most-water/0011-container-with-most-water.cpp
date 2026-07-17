class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left=0;
        int right=height.size()-1;
        int max_area=0;

        while(left<right){

            int curr_height=min(height[left],height[right]);
            int curr_width=right-left;
            int curr_area=curr_height*curr_width;

            max_area=max(max_area,curr_area);

            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return max_area;
    }
};