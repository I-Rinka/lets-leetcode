class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        std::unordered_map<char, int> mp;
        int begin = 0, maxL = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                if (mp[s[i]] + 1 < begin)
                {
                    begin = begin;
                }
                else
                {
                    begin = mp[s[i]] + 1;
                }
                mp.erase(s[i]);
            }
            mp[s[i]] = i;
            int l = i - begin + 1;
            if (l > maxL)
            {
                maxL = l;
            }
        }
        return maxL;
    }
};