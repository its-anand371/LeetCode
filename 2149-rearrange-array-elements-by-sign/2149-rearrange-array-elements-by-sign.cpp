class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        int po =0;
        int ne =1;
        for(int i =0;i<n;i++){
            if(nums[i]>0){
                result[po]=nums[i];
                po+=2;
            }
            else{
                result[ne]=nums[i];
                ne+=2;
            }
        }
        return result;
    }
};