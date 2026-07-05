class Solution {
public:
    vector<vector<int>> result;
    void two_sum(vector<int>& nums, long long target, int n1, int n2, int i, int j) {
        while (i < j) {
            long long sum = (long long)nums[i] + nums[j];
            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                result.push_back({n1, n2, nums[i], nums[j]});
                i++;
                j--;
                while (i < j && nums[i] == nums[i-1]) i++;
                while (i < j && nums[j] == nums[j+1]) j--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        result.clear();
        if (n < 4) return {};

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                long long remaining = (long long)target - nums[i] - nums[j];
                two_sum(nums, remaining, nums[i], nums[j], j + 1, n - 1);
            }
        }
        return result;
    }
};