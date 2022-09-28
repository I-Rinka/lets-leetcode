class Solution {
public:
    deque<pair<int,int>>dq;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        // dq.push_back(pair<int,int>(0,nums[0]));
        for(int i=0;i<nums.size();i++)
        {
            if(dq.size()==0)
            {
                dq.push_back(pair<int, int>(i,nums[i]));
            }
            else if(nums[i]>=dq.back().second)
            {
                dq.pop_back();
                dq.push_back(pair<int, int>(i,nums[i]));
            }
            else
            {
                while(dq.size()>=0&&dq.front().second<nums[i])
                {
                    dq.pop_front();
                }
                dq.push_front(pair<int, int>(i,nums[i]));
            }
            if(i>=k-1)
            {
                while(dq.back().first<i-k+1)
                {
                    dq.pop_back();
                }
                ans.push_back(dq.back().second);
            }
        }
        return ans;
    }
};