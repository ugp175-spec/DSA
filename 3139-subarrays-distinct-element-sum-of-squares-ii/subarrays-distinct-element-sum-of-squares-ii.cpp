class Solution {
    static const int MOD = 1e9 + 7;
    int n;
    vector<long long> sum, sq, lz;

    void apply(int o, int len, long long v) {
        sq[o]  = (sq[o] + 2 * v % MOD * sum[o] + len * v % MOD * v) % MOD;
        sum[o] = (sum[o] + v * len) % MOD;
        lz[o]  = (lz[o] + v) % MOD;
    }
    void push(int o, int l, int r) {
        if (lz[o]) {
            int m = (l + r) / 2;
            apply(2*o,   m - l + 1, lz[o]);
            apply(2*o+1, r - m,     lz[o]);
            lz[o] = 0;
        }
    }
    void update(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) { apply(o, r - l + 1, 1); return; }
        push(o, l, r);
        int m = (l + r) / 2;
        if (ql <= m) update(2*o,   l,   m, ql, qr);
        if (qr >  m) update(2*o+1, m+1, r, ql, qr);
        sum[o] = (sum[2*o] + sum[2*o+1]) % MOD;
        sq[o]  = (sq[2*o]  + sq[2*o+1])  % MOD;
    }
public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4*n, 0); sq.assign(4*n, 0); lz.assign(4*n, 0);
        unordered_map<int,int> last;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;
            update(1, 0, n-1, prev + 1, i);
            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }
        return ans;
    }
};