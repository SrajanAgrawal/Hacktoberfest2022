class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
	
		# inbuilt function, it will not make you understand how the merge sort is working
        # return sorted(nums)
	
        temp = [0] * len(nums)

        # merge the two different sorted arrays
        # nums[low:mid] and nums[mid+1:high]
        # so that elements at low to high become sorted
        def merge(low, mid, high):
            h = low; i = low; j = mid + 1

            # elements exist in both arrays
            while h <= mid and j <= high:
                if nums[h] <= nums[j]:
                    temp[i] = nums[h]; h += 1
                else:
                    temp[i] = nums[j]; j += 1
                i += 1
            
            # elements still exist at left sorted array
            while h <= mid: 
                temp[i] = nums[h]; h += 1; i += 1
            
            # elements still exist at right sorted array
            while j <= high: 
                temp[i] = nums[j]; j += 1; i += 1
            
            # assign the sorted elements in temp to original array
            for j in range(low, i): nums[j] = temp[j]

        def mergeSort(low, high):
            if low < high:
                # divide into two subproblems
                mid = int((low + high) / 2)
                
                # solve the subproblems
                mergeSort(low, mid)
                mergeSort(mid +1, high)

                # combine the solutions
                merge(low, mid, high)

        mergeSort(0, len(nums)-1)
        return nums
