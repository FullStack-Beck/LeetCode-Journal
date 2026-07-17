function mySqrt(x: number): number {
    if (x < 2) return x;
    
    let left = 2;
    // Use Math.floor to ensure integer division
    let right = Math.floor(x / 2); 
    let ans = 1;
    
    while (left <= right) {
        // Use Math.floor to ensure mid remains a whole number
        let mid = left + Math.floor((right - left) / 2);
        
        // Math.floor(x / mid) replicates C++ integer division behavior
        if (mid <= Math.floor(x / mid)) {
            ans = mid;       
            left = mid + 1;  
        } else {
            right = mid - 1; 
        }
    }
    return ans;
}
/*
More efficient solution for .TS
function mySqrt(x: number): number {
    let r = x;
    
    // Iteratively approach the true square root
    while (r * r > x) {
        r = Math.floor((r + x / r) / 2);
    }
    
    return r;
}
*/ 
