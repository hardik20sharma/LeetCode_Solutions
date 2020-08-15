class Solution
{
    void swap(int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
        
    public int removeElement(int[] nums, int val)
    {
        int i = 0, n = nums.length;
        while(i < n)
            if(nums[i] == val)
            {
                swap(nums, i, n-1);
                n--;
            }
            else
                i++;
        return n;
    }
}
