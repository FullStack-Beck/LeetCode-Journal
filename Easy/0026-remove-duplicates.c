int removeDuplicates(int* nums, int numsSize) {
    int unique = 1; 
    for(int i = 1; i < numsSize; i++) // loop starts at 1, nums size is 3 or 0, 1, 2
    {
        if(nums[i] != nums[i - 1]) //nums[1] = 1 nums[0] = 1 // so it doesn't log it,
        { // nums[2] = 2 nums[1] = 1 the if statement is finally not skipped
            nums[unique] = nums[i]; //we set nums[1] = to nums[2], nums[1,2,2] instead of nums[1,1,2]
            unique++; // unique is increased from 1 to 2
        }
    }
    return unique; // the judge is reading the first #'s of nums[] based on unique so it reads the first 2 in our specific case giving us nums[1,2,_]
}
