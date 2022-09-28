class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int maxPrice = *(prices.end() - 1);
        for (auto i = prices.end() - 1; i >= prices.begin(); i--)
        {
            if (*i > maxPrice)
            {
                maxPrice = *i;
            }
            if (maxPrice - *i > maxProfit)
            {
                maxProfit = maxPrice - *i;
            }
        }
        return maxProfit;
    }
};