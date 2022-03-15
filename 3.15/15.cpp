class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> ans;
        vector<vector<int>> rt_ans;
        if (nums.size() < 3)
        {
            return rt_ans;
        }
        std::sort(nums.begin(), nums.end());
        auto left = nums.begin();
        while (*left <= 0 && left < nums.end() - 1)
        {
            auto middle = left + 1;
            auto right = nums.end() - 1;
            while (middle < right)
            {
                if (*left + *middle + *right == 0)
                {
                    vector<int> el = {*left, *middle, *right};
                    ans.insert(el);
                    middle++;
                    right--;
                }
                else if (*left + *middle + *right < 0)
                {
                    middle++;
                }
                else
                {
                    right--;
                }
            }
            left++;
        }

        for (auto i = ans.begin(); i != ans.end(); i++)
        {
            rt_ans.push_back(*i);
        }
        return rt_ans;
    }
};