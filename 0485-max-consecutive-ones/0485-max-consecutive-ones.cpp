class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n =nums.size();
        int maximum=INT_MIN;
        int count=0;
        for(int i =0;i<n;i++){
            if(nums[i]==1){
                count+=1;
            }
            else{
                count=0;
            }
            maximum=max(maximum,count);
        }
        return maximum;
    }
};