class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n =arr.size();
        int maxsofar=-1;
        for(int i =n-1;i>=0;i--){
            int curr=arr[i];
            arr[i]=maxsofar;
            maxsofar=max(maxsofar,curr);
        }   
        return arr;
    }
};