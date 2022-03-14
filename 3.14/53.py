
class Solution:
    def maxSubArray(self, nums) -> int:
        if len(nums)==0:
            return

        curVal=float("-inf")
        maxVal=float("-inf")
        for i in range(len(nums)):
            curVal+=nums[i]
            if nums[i]>curVal:
                curVal=nums[i]
            if curVal>maxVal:
                maxVal=curVal
        return maxVal
