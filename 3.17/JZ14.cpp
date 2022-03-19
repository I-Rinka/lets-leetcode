class Solution {
public:
    bool* visit;
    int* cache;
    int MAX(int n)
    {
        int ans=n-1;
        for(int i=2;i<=n/2;i++)
        {
            int l,r;
            if(visit[i])
            {
                l=cache[i];
            }
            else
            {
                l=MAX(i);
            }
            l=std::max(i,l);

            if(visit[n-i])
            {
                r=cache[n-i];
            }
            else
            {
                r=MAX(n-i);
            }
            r=std::max(n-i,r);

            ans=std::max(ans,l*r);
        }
        visit[n]=true;
        cache[n]=ans;
        return ans;
    }
    int cuttingRope(int n) {
        this->visit=new bool[n+1]();
        this->cache=new int[n+1]();
        visit[1]=true;
        cache[1]=1;
        visit[2]=true;
        cache[2]=1;
        return this->MAX(n);
    }
};