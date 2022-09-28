class Solution:

# O(lgn)
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        mid = int((len(nums1)+len(nums2))/2)
        if (len(nums1)+len(nums2)) % 2 == 0:
            return (self.getKmin(nums1, nums2, mid)+self.getKmin(nums1, nums2, mid+1))/2

        else:
            return float(self.getKmin(nums1, nums2, mid+1))

    def getKmin(self, nums1, nums2, K):
        # if K == 1:
        #     if len(nums1) == 0:
        #         return nums2[0]
        #     elif len(nums2) == 0:
        #         return nums1[0]
        #     else:
        #         if nums1[0] > nums2[0]:
        #             return nums2[0]
        #         return nums1[0]
        if K<=10:
            t=nums1+nums2
            t.sort()
            return t[K-1]

        if len(nums1) == 0 or len(nums1) < len(nums2):
            nums1, nums2 = nums2, nums1
        if len(nums2) == 0:
            return nums1[K-1]

        mid = int(K/2)-1
        m1 = nums1[mid]
        p1 = mid
        if mid >= len(nums2):
            m2 = nums2[len(nums2)-1]
            p2 = len(nums2)-1
        else:
            m2 = nums2[mid]
            p2 = mid

        if m1 > m2:
            return self.getKmin(nums1, nums2[p2+1:], K-(p2+1))
        else:
            return self.getKmin(nums1[p1+1:], nums2, K-(p1+1))