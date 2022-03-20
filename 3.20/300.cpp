class Solution {
public:
    int qFind(vector<int>&buffer,int target)
    {
        int pos=-1;
        if(buffer[buffer.size()-1]<target)
        {
            return pos;
        }
        int l=0;
        int r=buffer.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(buffer[mid]>=target)
            {
                pos=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return pos;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>buffer;

        for(int i=0;i<nums.size();i++)
        {
            if(buffer.empty()||nums[i]>buffer[buffer.size()-1])
            {
                buffer.push_back(nums[i]);
            }
            else
            {
                int pos=this->qFind(buffer,nums[i]);
                if(pos!=-1)
                {
                    buffer[pos]=nums[i];
                }
            }
        }
        return buffer.size();
    }
};