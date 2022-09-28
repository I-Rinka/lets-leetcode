class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {


        int l=0;
        int r=nums.size()-1;
        int p=-1;

        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
            {
                p=mid;
                break;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }

        if(p==-1)
        {
            return vector<int>{-1,-1};
        }
        else
        {
            int lAns=0;
            for(int i=p;i>=0;i--)
            {
                // cout<<"l:"<<nums[i]<<" target:"<<target<<endl;
                if(nums[i]!=target)
                {
                    lAns=i+1;
                    break;
                }
            }

            int rAns=nums.size()-1;
            for(int i=p;i<nums.size();i++)
            {
                if(nums[i]!=target)
                {
                    rAns=i-1;
                    break;
                }
            }

            return vector<int>{lAns,rAns};
        }
    }
};