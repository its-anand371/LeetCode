class Solution {
public:
    int maximum(vector<int>&nums,int n){
        int maximum=INT_MIN;
        for(int i =0;i<n;i++){
            maximum=max(nums[i],maximum);
        }
        return maximum ;
    }
    int totalHours(vector<int>&piles,int mid){
        long long total = 0;
        for (int i = 0; i < piles.size(); i++) {
        total += ceil((double)piles[i] / (double)mid);
    }
    return (int)min(total, (long long)INT_MAX);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int start=1;
        int end=maximum(piles,n);
        while(start<=end){
            int mid=start+(end-start)/2;
            int hours =  totalHours(piles,mid);
            if(hours<=h){
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        return start;
    }
};