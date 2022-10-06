def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        nums1.extend(nums2)
        nums1.sort()
        s= len(nums1)
        mid= s//2
        if s%2==0:
            med= (nums1[mid-1]+nums1[mid])/2
        else:
            med=nums1[mid]
        return med
