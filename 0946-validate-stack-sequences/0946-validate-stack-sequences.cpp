class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        int j=0;
        int i =0;
        stack<int>st;
        for(i =0;i<n;i++){
            st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j+=1;
            }
        }
        return st.empty();
    }
};