class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // indices of unresolved days

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int prev = st.top();
                st.pop();
                answer[prev] = i - prev;
            }
            st.push(i);
        }

        return answer;
    }
};