class Solution {
public:
    vector<vector<int>> result;
    
    void two_sum(vector<int>& nums, long long target, int a, int b, int start, int end){
        while(start < end){
            long long sum = nums[start] + nums[end];
            if(sum < target){
                start += 1;
            }
            else if(sum > target){
                end -= 1;
            }
            else{
                result.push_back({a, b, nums[start], nums[end]});
                start += 1;
                end -= 1;
                while(start < end && nums[start] == nums[start-1]) start += 1;
                while(start < end && nums[end] == nums[end+1]) end -= 1;
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        result.clear();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n - 2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                long long remainder = (long long)target - nums[i] - nums[j];
                two_sum(nums, remainder, nums[i], nums[j], j+1, n-1);
            }
        }
        return result;
    }
};