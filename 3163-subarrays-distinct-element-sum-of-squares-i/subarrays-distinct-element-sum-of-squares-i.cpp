class Solution {
public:
    int sumCounts(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        for(int i = 0;i < n;i++)
        {
            vector <int> temp(101,0);
            int count = 0;
            for(int j = i;j < n;j++)
            {
                if(temp[nums[j]] == 0)
                {
                    count++;
                    temp[nums[j]] = 1;
                }
                ans += count*count;
            }
        }

        return ans;
        
    }
};