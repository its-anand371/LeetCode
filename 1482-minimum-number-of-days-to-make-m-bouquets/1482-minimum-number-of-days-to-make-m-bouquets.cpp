class Solution {
public:
    int days(vector<int>&nums,int &limit,int k){
        int bouq_count=0;
        int days_count=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<=limit){
                days_count+=1;
            }
            else{
                days_count=0;
            }
            if(days_count==k){
                bouq_count+=1;
                days_count=0;
            }
        }
        return bouq_count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n =bloomDay.size();
        int start=1;
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        int l=0;
        while(start<=end){
            int mid=start+((end-start)/2);
            l = days(bloomDay,mid,k);
            if(l>=m){
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