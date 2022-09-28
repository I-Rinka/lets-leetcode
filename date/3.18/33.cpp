class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 1. find pivot
        // 2. quick find
        if(nums.size()==0)
        {
            return -1;
        }
        int pivot=this->findPivot(nums,0,nums.size()-1);
        int r=-1;
        if((r=this->findNum(nums,0,pivot,target))!=-1)
        {
            return r;
        }
        else
        {
            return this->findNum(nums,pivot+1,nums.size()-1,target);
        }
    }
    int findNum(vector<int>&nums,int l,int r,int target)
    {
    }
    int findPivot(vector<int>& nums,int l,int r)
    {
        
    }
};