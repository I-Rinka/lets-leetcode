class Solution {
public:
    void gen(string cur,int left,int right,int n,vector<string>&ans)
    {
        if(cur.size()==n*2)
        {
            ans.push_back(cur);
            return;
        }

        if(left<n)
        {
            this->gen(cur+'(',left+1,right,n,ans);
        }
        if(right<left)
        {
            this->gen(cur+')',left,right+1,n,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       this->gen(string(),0,0,n,ans);
       return ans;
    }
};