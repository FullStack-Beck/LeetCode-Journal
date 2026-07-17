class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x;
    
        int left = 2;
        int right = x / 2;
        int ans = 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Using division instead of (mid * mid <= x) to prevent integer overflow
            if (mid <= x / mid) {
                ans = mid;       // mid could be the answer, save it
                left = mid + 1;  // Look for a larger valid integer
            } else {
                right = mid - 1; // mid is too large, look in the lower half
            }
        }
        return ans;
    }
}
/*
Newton's Method rather then binary search
class Solution {
    public int mySqrt(int x) {
        long r = x;
        
        // Iteratively average the guess until r * r is no longer greater than x
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        
        return (int) r;
    }
}
 */
