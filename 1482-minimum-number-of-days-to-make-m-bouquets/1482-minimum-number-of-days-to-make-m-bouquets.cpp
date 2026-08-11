class Solution {
public:
    int minimum(vector<int>&nums,int n ){
        int minimum=INT_MAX;
        for(int i =0;i<n;i++){
            minimum=min(minimum,nums[i]);
        }
        return minimum;
    }
    int maximum(vector<int>&nums,int n ){
        int maximum=INT_MIN;
        for(int i =0;i<n;i++){
            maximum=max(maximum,nums[i]);
        }
        return maximum;
    }
    int bloom(vector<int>&nums,int &k ,int &mid){
        int bouq_count=0;
        int cons_count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                cons_count++;
            }
            else{
                cons_count=0;
            }
            if(cons_count==k){
                bouq_count+=1;
                cons_count=0;
            }
        }
        return bouq_count;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        int start=minimum(nums,n);
        int end=maximum(nums,n);
        if((long long )m*n<nums.size()){
            return -1;
        }
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int n=bloom(nums,k,mid);
            if(n>=m){
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