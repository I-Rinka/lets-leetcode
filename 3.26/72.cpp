class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp;
        for(int i=0;i<word1.size()+1;i++)
        {
            dp.push_back(vector<int>(word2.size()+1,0));
        }
        for(int i=0;i<word1.size()+1;i++)
        {
            dp[i][0]=i;
        }
        for(int i=0;i<word2.size()+1;i++)
        {
            dp[0][i]=i;
        }

        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                int del=dp[i][j-1];
                int ins=dp[i-1][j];
                int rep=dp[i-1][j-1];

                if(word1[i-1]==word2[j-1])
                {
                    int min=(del+1<ins+1)?del+1:ins+1;
                    min=(min<rep)?min:rep;
                    dp[i][j]=min;
                }
                else
                {
                    int min=(del+1<ins+1)?del+1:ins+1;
                    min=(min<rep+1)?min:rep+1;
                    dp[i][j]=min;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};