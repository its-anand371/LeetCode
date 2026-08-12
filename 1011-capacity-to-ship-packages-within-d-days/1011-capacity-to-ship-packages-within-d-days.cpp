class Solution {
public:
    int sum_of_all(vector<int>&nums,int &n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return sum;
    }
    long long packages(vector<int>&nums,int &limit,int &mid){
        int count=1;
        int load=0;
        for(int i =0;i<nums.size();i++){
            if(load+nums[i]>mid){
                count+=1;
                load=nums[i];
            }
            else{
                load+=nums[i];
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int n = nums.size();
        int start = *max_element(nums.begin(), nums.end());
        int end=sum_of_all(nums,n);
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            int n = packages(nums,days,mid);
            if(n<=days){
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