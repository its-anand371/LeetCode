class Solution {
public:
    int maximum(vector<int>&nums,int n ){
        int maximum=INT_MIN;
        for(int i =0;i<n;i++){
            maximum=max(maximum,nums[i]);
        }
        return maximum;
    }
    long long number(vector<int>&nums,int &limit,int &mid){
        long long count=0;
        for(int i =0;i<nums.size();i++){
            count+=(nums[i]+mid-1)/mid;
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int limit) {
        int n = nums.size();
        int start=1;
        int end=maximum(nums,n);
        int ans=end;
        int count=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            count=number(nums,limit,mid);
            if(count<=limit){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};