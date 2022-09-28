class Solution {
public:
    string longestPalindrome(string s) {
        vector<bool>v(s.size(),false);
        vector<vector<bool>>dp(s.size(),v);

        for(int i=0;i<s.size();i++)
        {
            dp[i][i]=true;
        }

        int ansl=0,maxL=1;
        for(int i=1;i<s.size();i++)
        {
            for(int j=0;j<s.size()-i;j++)
            {
                int start=j;
                int end=start+i;

                if(i==1)
                {
                    dp[start][end]=(s[start]==s[end]);
                    if(dp[start][end]&&maxL<2)
                    {
                        maxL=2;
                        ansl=start;
                    }
                }
                else{
                    dp[start][end]=(s[start]==s[end])&&dp[start+1][end-1];
                    if(dp[start][end]&&(end+1-start>maxL))
                    {
                        maxL=end+1-start;
                        ansl=start;
                    }
                }

            }
        }
        return s.substr(ansl,maxL);
    }
};