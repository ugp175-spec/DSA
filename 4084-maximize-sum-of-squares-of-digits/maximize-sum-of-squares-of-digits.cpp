class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string ans = "";

        if (sum > num * 9) return "";
        int n = 9;
       while(sum >= 0 && ans.size() < num)
       {
            if(sum >= n)
            {
                ans.push_back(char(n + '0'));
                sum -= n;
            }
            else
            {
                n--;
            }
       }

        return ans;
    }
};