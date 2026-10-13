class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long ans = 0;

        int n = nums.size();

        vector<int> m(n);

        long long sum = 0;
        long long min = 0;

        for(int i = 0;i < n;i++)
        {
            m[i] = nums[i]*nums[i];
            sum += m[i];
        }

        sort(m.begin(),m.end());

        for(int i = 0;i < (n/2);i++)
        {
            min += m[i];
        }

        ans = sum - (2*min);

        return ans;

        
        
    }
};