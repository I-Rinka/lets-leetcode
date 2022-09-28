class Solution {
public:
    int climbStairs(int n) {
        int floarP=2;
        int floarPP=1;
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return 1;
        }
        else if(n==2)
        {
            return 2;
        }
        int ans=0;
        for(int i=3;i<=n;i++)
        {
            ans=floarP+floarPP;
            floarPP=floarP;
            floarP=ans;
        }
        return ans;
    }
};