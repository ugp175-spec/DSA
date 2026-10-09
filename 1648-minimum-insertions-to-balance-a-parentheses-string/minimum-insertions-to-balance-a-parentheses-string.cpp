
class Solution {
public:
    int minInsertions(string s) {

        int ans = 0;
        int t = 0;

        for(char c : s)
        {
            if(c == '(')
            {
                if(t%2) ans++, t++;
                else
                {
                    t += 2;
                }
            }
            else if(t == 0) ans++, t = 1;
            else t--;
        }

        return ans + t;

    }
};