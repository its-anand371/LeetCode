class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n =nums.size();
        int up=1;
        int down=1;
        int maximum=1;
        for (int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                up=down+1;
                down=1;
            }
            else if(nums[i]<nums[i-1]){
                down=up+1;
                up=1;
            }
            else{
                up=1;
                down=1;
            }
            maximum=max(maximum,max(up,down));
        }
        return maximum;
    }

};