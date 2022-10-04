class Solution {
public:
    int pivot(vector<int>& nums)
    {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        while(start<end)
        {
            mid = start + (end-start)/2;
            if(nums[mid]>=nums[0])
            {
                start = mid+1;
            }
            else
            {
                end = mid;
            }
           
        }
        return start;
    }
    int binarysearch(vector<int>& nums, int start, int end, int key)
    {
        int mid;
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(nums[mid]==key)
            {
                return mid;
            }
            else if(nums[mid]>key)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int p = pivot(nums);
        if((target >= nums[p])&&(target<=nums[nums.size()-1]))
        {
            return binarysearch(nums, p, nums.size()-1, target);
        }
        else
        {
            return binarysearch(nums, 0, p, target);
        }
        
        
    }
};
