/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    for(i = 0; i <= nums.length; i++) {
        if(target == nums[i]) {
            return i;
        }
        else if(target < nums[i] && target != nums[i - 1]) {
            return i;
        }
        else if(i == nums.length) {
            return nums.length;
        }
    }
};
