class Solution {
public:
    int search_last(vector<int>&nums,int target){
        int start=0;
        int end=nums.size()-1;
        int result=-1;
        while(start<=end){
            int mid=start+((end-start)/2);
            if(nums[mid]==target){
                result=mid;
                start=mid+1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return result;
    }
    int search_first(vector<int>&nums,int target){
        int start=0;
        int end=nums.size()-1;
        int result=-1;
        while(start<=end){
            int mid=start+((end-start)/2);
            if(nums[mid]==target){
                result=mid;
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start=0;
        int end=n-1;
        int left_first=search_first(nums,target);
        int right_last=search_last(nums,target);
        return {left_first,right_last};
    }
};