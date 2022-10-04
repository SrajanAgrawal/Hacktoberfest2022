// pivot generally means the greatest element in the array

// we are applying binary search here as it's worst case complexity is O(logN)

public class pivotElement {
    public static void main(String[] args) {
        int[] arr = {6,8,32,76,98,0,1,2,3,4};
        int target = 8;
        System.out.println(searchPivot(arr));
        System.out.println(search(arr, target));

    }
    //      !!--IMPORTANT--!! this is finding pivot program ONLY in ROTATED SORTED ARRAY like above example
    //       If you did not find the pivot, it means array is not rotated. (pivot == -1)
    static int search(int[] nums, int target ) {
        int pivot = searchPivot(nums);
//       If you did not find the pivot, it means array is not rotated.
        if (pivot == -1) {
            // just do normal binary search
            return BinarySearch(nums, target, 0,nums.length - 1);
        }
//        if pivot is found , you have found 2 ascending sorted arrays
        if(nums[pivot] == target){
            return pivot;
        }
        if(target >= nums[0]){
            return BinarySearch(nums, target, 0 , pivot - 1);
        }
        else{  // if (target < nums[0])
            return BinarySearch(nums, target,pivot +1, nums.length-1);
        }

    }
    // ----------- FOR SEARCHING IN ARRAY -----------------------------------
    static int BinarySearch(int[] arr,int target, int start,int end ){
        while(start <= end)
        {
            int mid= start +(end - start)/2;
            if(target < arr[mid]){
                end = mid-1;
            } else if(target > arr[mid]){
                start = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
    // ------------------ HERE WE ARE FINDING PIVOT FOR ROTATED SORTED ARRAY ------------------------//

    static int searchPivot(int[] arr){
        int start = 0;
        int end = arr.length - 1;
        while(start < end){
            int mid = start + (end - start)/2;
            // first case
            if(mid < end && arr[mid] > arr[mid+1]){
                return mid;
            }
            // second case
            if(mid > start && arr[mid] < arr[mid-1]){
                return mid-1;
            }
            // third case
            if(arr[start]>= arr[mid]){
                end = mid - 1;
            }// fourth case
            else {           //if(arr[start] < arr[mid])
                start = mid+1;

            }
        }
        return -1;
    }
}
