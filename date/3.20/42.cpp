class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        vector<int>dpl(height.size(),0);
        dpl[0]=height[0];
        int solid=height[0];
        for(int i=1;i<height.size();i++)
        {
            solid+=height[i];
            dpl[i]=std::max(dpl[i-1],height[i]);

        }

        vector<int>dpr(height.size(),0);
        dpr[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--)
        {
            dpr[i]=std::max(dpr[i+1],height[i]);
        }

        int area=0;

        for(int i=0;i<height.size();i++)
        {
            area+=std::min(dpl[i],dpr[i]);
        }
        ans=area-solid;
        return ans;
    }
};
