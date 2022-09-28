class Solution {
public:
    vector<bool>visit;
    void dfs(int index,vector<int>&current_result,vector<vector<int>>&ans,vector<int>&nums)
    {
        this->visit[index]=true;
        current_result.push_back(nums[index]);
        if(current_result.size()==this->visit.size())
        {
            ans.push_back(vector<int>(current_result));
        }
        else
        {
            for(int i=0;i<visit.size();i++)
            {
                if(!visit[i])
                {
                    this->dfs(i,current_result,ans,nums);
                }
            }
        }
        current_result.pop_back();
        this->visit[index]=false;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            visit.push_back(false);
        }

        vector<vector<int>>ans;
        vector<int>current_ans;

        for(int i=0;i<nums.size();i++)
        {
            this->dfs(i,current_ans,ans,nums);
        }

        return ans;
    }
};