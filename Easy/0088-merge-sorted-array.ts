/**
 Do not return anything, modify nums1 in-place instead.
 */
function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    let i = m - 1
    let j = n - 1
    let k = m + n - 1
    while(j >= 0) {
        if(i >= 0 && nums1[i] > nums2[j]) {
            nums1[k] = nums1[i]
            i -= 1
        }
        else {
            nums1[k] = nums2[j]
            j -= 1
        }
        k -= 1
    }
};

/* simpler but worse way of doing it, longer and less efficient
function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    nums1.splice(m, n, ...nums2);
    nums1.sort((a, b) => a - b);
}
*/
/* same way of doing it, but cleaner written
 function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    let i = m - 1;
    let j = n - 1;

    for (let k = m + n - 1; k >= 0; k--) {
        if (j < 0) break;

        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k] = nums1[i--];
        } else {
            nums1[k] = nums2[j--];
        }
    }
}
*/
