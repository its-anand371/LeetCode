class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int p = 0, neg = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[p] = nums[i];
                p += 2;
            } else {
                result[neg] = nums[i];
                neg += 2;
            }
        }
        return result;
    }
};