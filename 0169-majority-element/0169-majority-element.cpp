class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans=nums[0];
        int count=1;
        for(int i =1;i<n;i++){
            if(count==0){
                ans=nums[i];
                count+=1;
            }
            else if(ans==nums[i]){
                count+=1;
            }
            else{
                count-=1;
            }
        }
        return ans;
    }
};