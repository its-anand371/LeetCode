class Solution {
public:
    vector<int> leftmax(vector<int>&height,int n){
        vector<int>left(n);
        left[0]=height[0];
        int maximum=height[0];
        for(int i =1;i<n;i++){
            left[i]=max(height[i],left[i-1]);
        }
        return left;
    }
    vector<int> rightmax(vector<int>&height,int n){
        vector<int>right(n);
        right[n-1]=height[n-1];
        int maximum=height[n-1];
        for(int i =n-2;i>=0;i--){
            right[i]=max(height[i],right[i+1]);
        }
        return right;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        int sum=0;
        vector<int>left_max=leftmax(height,n);
        vector<int>right_max=rightmax(height,n);
        for(int i =0;i<n;i++){
            int water=min(left_max[i],right_max[i])-height[i];
            sum+=water;
        }
        return sum;
    }
};