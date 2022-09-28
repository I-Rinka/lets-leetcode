class Solution {
public:
    int mySqrt(int x) {
        if(x<0)
        {return 0;}
        int l=0;
        int r=x/2;
        while(l<=r)
        {
            unsigned long long mid=(l+r)/2;
            if(mid*mid<=x)
            {
                if((mid+1)*(mid+1)>x)
                {
                    return mid;
                }
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return x;
    }
};