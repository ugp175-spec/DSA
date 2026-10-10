class Solution {
public:
    string reorganizeString(string s) {

        vector<int> fre(26,0);
        int n = s.size();
        vector<char> vec(n);

        int N = n%2 == 0 ? n/2 : (n+1)/2;

        for(int i = 0;i < s.size();i++)
        {
            fre[s[i]-'a']++;
            if(fre[s[i] - 'a'] > N) return "";
        }

        vector<pair<int,int>> ch;

        for(int i = 0;i < 26;i++)
        {
            ch.push_back({fre[i],i});
        }

        sort(ch.rbegin(),ch.rend());


        int j = 0;

        for(int i = 0;i < 26;i++)
        {
        
            while(j < n && ch[i].first != 0)
            {
                
                vec[j] = char('a' + ch[i].second);
                ch[i].first--;
                j = j+2;
            }
        }

        j = 1;
        for(int i = 0;i < 26;i++)
        {
        
            while(j < n && ch[i].first != 0)
            {
                
                vec[j] = char('a' + ch[i].second);
                ch[i].first--;
                j = j+2;
            }
        }


        return string(vec.begin(),vec.end());



        
    }
};