class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)

        halfLen = ((len(nums1) + len(nums2) + 1) // 2)
        
        low = 0
        high = len(nums1)

        while low <= high:
            i = (low + high) // 2
            j = halfLen - i

            # Boundary values (use Infinity for out-of-bound cuts)
            maxLeft1  = float('-inf') if i == 0 else nums1[i - 1]
            minRight1 = float('inf')  if i == len(nums1) else nums1[i]

            maxLeft2  = float('-inf') if j == 0 else nums2[j - 1]
            minRight2 = float('inf')  if j == len(nums2) else nums2[j]

            # Valid partition check!
            if (maxLeft1 <= minRight2 and maxLeft2 <= minRight1):
                # Odd total length: median is the largest element in the left half
                if ((len(nums1) + len(nums2)) % 2 == 1):
                    return max(maxLeft1, maxLeft2)
                
                # Even total length: average of max-left and min-right
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2
            
            elif (maxLeft1 > minRight2):
                # Too far right in nums1! Shift cut to the left.
                high = i - 1
            
            else: 
                # Too far left in nums1! Shift cut to the right.
                low = i + 1

        return 0.0
        
