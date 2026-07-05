class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n =arr.size();
        map<int,int>mp;
        for(int i =0;i<n;i++){
            int remainder = target-arr[i];
            if(mp.find(remainder)!=mp.end()){
                return {mp[remainder],i};
            }
            else{
                mp[arr[i]]=i;
            }
        }
        return {};
    }
};