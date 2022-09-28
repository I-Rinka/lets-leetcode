class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        auto nums2 = nums;
        int len = nums2.size();
        std::sort(nums2.begin(), nums2.end());

        for (int i = 0; i < len; i++)
        {
            int t = target - nums2[i];
            auto fd = std::find(nums2.begin() + i + 1, nums2.end(), t);
            if (fd != nums2.end())
            {
                int len = nums.size();
                set<int> ans;
                for (int j = 0; j < len; j++)
                {
                    if (nums[j] == *fd)
                    {
                        ans.insert(j);
                    }
                    else if (nums[j] == nums2[i])
                    {
                        ans.insert(j);
                    }
                }
                vector<int> t_ans(ans.begin(), ans.end());
                return t_ans;
            }
        }

        vector<int> ans;
        return ans;
    }
};