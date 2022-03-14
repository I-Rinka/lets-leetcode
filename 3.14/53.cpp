#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }

        int curVal = -0x3f3f3f3f, maxVal = -0x3f3f3f3f;
        for (auto i = nums.begin(); i < nums.end(); i++)
        {
            curVal += *i;
            if (*i > curVal)
            {
                curVal = *i;
            }
            if (curVal > maxVal)
            {
                maxVal = curVal;
            }
        }

        return maxVal;
    }
};