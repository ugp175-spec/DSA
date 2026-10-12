class Solution {
public:
    int maxSum(vector<int>& nums, int k) {

        const long long mode = 1e9+7;

        vector<int> b(31,0);

        for(int num : nums)
        {
            for(int  i = 0;i < 31;i++)
            {
                if(num & (1 << i))
                {
                    b[i]++;
                }
            }
        }
        
        long long ans = 0;

        for(int j = 0;j < k;j++)
        {
            long long x = 0;

            for(int i = 0;i < 31;i++)
            {
                if(b[i] > 0)
                {
                    x |= (1LL << i);
                    b[i]--;
                }
            }

            ans = (ans +x*x) % mode;
        }

        return ans;
    }
};