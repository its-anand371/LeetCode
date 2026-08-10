class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int n=nums.size();
        int maxsofar=-1;
        for(int i =n-1;i>=0;i--){
            int curr=nums[i];
            nums[i]=maxsofar;
            maxsofar=max(maxsofar,curr);
        }
        return nums;
    }
};