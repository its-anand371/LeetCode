class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maximum = INT_MIN;
        double sum=0;
        for (int i = 0; i <n; i++) {
            sum+=nums[i];
            if(i>=k){
                sum-=nums[i-k];
            }
            if (i >= k - 1) {
                maximum = max(maximum, sum);
            }
        }
        return maximum/k;
    }
};