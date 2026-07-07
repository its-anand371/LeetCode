class Solution {
public:
    vector<vector<int>>result;
    void two_sum(vector<int>&nums,long long &remainder,int n1,int n2,int i,int j ){
        while(i<j){
            long long sum=(long long) nums[i]+nums[j];
            if(sum>remainder){
                j--;
            }
            else if(sum<remainder){
                i++;
            }
            else{
                result.push_back({n1,n2,nums[i],nums[j]});
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n =nums.size();
        if(n<4) return{};
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                long long remainder=(long long)target-nums[i]-nums[j];
                two_sum(nums,remainder,nums[i],nums[j],j+1,n-1);
            }
        }
        return result;
    }
};