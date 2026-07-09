/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    for(let i = nums.length; i >= 0; i--) { // going backwards avoids numbers falling into checked spots
        if(nums[i] == val) {
            nums.splice(i, 1)
        }
    }
};
