class Solution {
public:
    vector<vector<int>> result;

    void two_sum(vector<int>& nums, int a, int b,
                 int start, int end, long long remainder) {

        while (start < end) {
            long long sum = 1LL * nums[start] + nums[end];

            if (sum > remainder) {
                end--;
            }
            else if (sum < remainder) {
                start++;
            }
            else {
                result.push_back({a, b, nums[start], nums[end]});

                while (start < end && nums[start] == nums[start + 1]) start++;
                while (start < end && nums[end] == nums[end - 1]) end--;

                start++;
                end--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long remainder = 1LL * target - nums[i] - nums[j];

                two_sum(nums, nums[i], nums[j],
                        j + 1, n - 1, remainder);
            }
        }

        return result;
    }
};