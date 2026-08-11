class Solution {
public:
    int maximum(vector<int>&nums){
        int maximum=INT_MIN;
        for(int i =0;i<nums.size();i++){
            maximum=max(maximum,nums[i]);
        }
        return maximum;
    }
    long long total_hours(vector<int>&nums,int speed){
        long long sum=0;
        for(int i =0;i<nums.size();i++){
            sum+=(nums[i]+speed-1)/speed;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=maximum(piles);
        int total=0;
        while(start<end){
            int mid=start+(end-start)/2;
            total=total_hours(piles,mid);
            if(total<=h){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};