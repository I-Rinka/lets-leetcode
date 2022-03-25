class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 向右找最小的比自己大的
        // 如果找不到了就原地排序
        // 如果找到了，就交换位置后排序

        for(int i=nums.size()-2;i>=0;i--)
        {
            int minMax=INT_MAX;
            int pos=-1;
            for(int j=nums.size()-1;j>i;j--)
            {
                if(nums[j]>nums[i])
                {
                    if(nums[j]<minMax)
                    {
                        minMax=nums[j];
                        pos=j;
                    }
                }
            }

            if(pos!=-1)
            {
                nums[pos]=nums[i];
                nums[i]=minMax;
                sort(nums.begin()+i+1,nums.end());
                return;
            }
            else if(i==0)
            {
                sort(nums.begin(),nums.end());
            }

        }
    }
};