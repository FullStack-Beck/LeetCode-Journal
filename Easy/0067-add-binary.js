/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let i = a.length - 1;
    let j = b.length - 1;
    let carry = 0;
    let result = ""; // This will hold our final string

    while (i >= 0 || j >= 0) {
        let digitA = i >= 0 ? Number(a[i]) : 0;
        let digitB = j >= 0 ? Number(b[j]) : 0;
        
        let sum = digitA + digitB + carry;

        if (sum === 2) {
            carry = 1;
            result = "0" + result;
        } else if (sum === 3) {
            carry = 1;
            result = "1" + result;
        } else if (sum === 1) {
            carry = 0;
            result = "1" + result;
        } else {
            carry = 0;
            result = "0" + result;
        }

        i--;
        j--;
    }
    
    if (carry === 1) {
        result = "1" + result;
    }

    return result;
};
