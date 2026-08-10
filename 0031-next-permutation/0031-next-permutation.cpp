class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n =nums.size();
        int node=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                node=i-1;
                break;
            }
        }
        if (node != -1) {
            for (int i = n - 1; i > node; i--) {
                if (nums[i] > nums[node]) {
                    swap(nums[i], nums[node]);
                    break;
                }
            }
        }
        reverse(nums.begin()+node+1,nums.end());
    }
};