class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
        if(n==0)
        {
            return;
        }
        int cur1=m-1;
        int cur2=n-1;

        while(cur2>=0)
        {
            if(cur1<0)
            {
                nums1[cur1+cur2+1]=nums2[cur2];
                cur2--;
            }
            else{
                if(nums2[cur2]>nums1[cur1])
                {
                    nums1[cur1+cur2+1]=nums2[cur2];
                    cur2--;
                }
                else
                {
                    nums1[cur1+cur2+1]=nums1[cur1];
                    cur1--;
                }
            }
        }
        return;
    }
};