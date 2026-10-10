class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {

        vector<int> ans;
        int n = t.size();
        stack <int> st;

        for(int i =n-1;i >= 0;i--)
        {
            while(!st.empty() && t[i] >= t[st.top()])
            {
                st.pop();
            }
            if(st.empty()) ans.push_back(0);
            else ans.push_back(st.top()-i);

            st.push(i);
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};