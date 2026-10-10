class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        long long k = (long long)k1 + k2;
        int n = nums1.size();
        vector<long long> diff(n);

        long long total = 0;
        long long mx = 0;

        for(int i = 0;i < n;i++)
        {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx,diff[i]);
        }

        if(total <= k)return 0;

        long long low = 0;
        long long high = mx;

        while(low < high)
        {
            long long mid = low + (high - low)/2;
            long long need = 0;

            for(long long d : diff)
            {
                if(d > mid) need += (d - mid);
            }

            if(need <= k) high = mid;
            else low = mid + 1;

        }
        
        long long ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(diff[i] > low)
            {
             k -= diff[i] - low;
                diff[i] = low;
            }
        }

        sort(diff.rbegin(),diff.rend());

        for(int i = 0;i < n && k > 0;i++)
        {
            if(diff[i] == low && low > 0)
            {
                diff[i]--;
                k--;
            }
        }

        for(long long d : diff)
        {
            ans += d*d;
        }

        return ans;
    }
};