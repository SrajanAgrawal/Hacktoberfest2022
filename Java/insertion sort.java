class Solution {
    public int[] sortArray(int[] nums) {
        // Insertion Sort in Java
        int n = nums.length;
        
        for(int i = 1; i < n; i++) {
            int key = nums[i];
            int j = (i - 1);
            while((j >= 0) && (nums[j] > key)) {
                nums[j+1] = nums[j];
                j = j - 1;
            }
            nums[j+1] = key;
            
            }
        return nums;
    }
}

/* Time Complexity 
    1. Worst Case = O(n^2) // As all the elements might need to be left shifted n times in a reversed array
    2. Average Case = O(n^2)
    Space Complexity
    1. Worst Case = O(1) // Inplace algorithm
    2. Average Case = O(1) 
*/
