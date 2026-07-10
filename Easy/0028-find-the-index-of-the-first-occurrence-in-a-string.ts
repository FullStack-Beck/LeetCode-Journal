function strStr(haystack: string, needle: string): number {
    for (let i = 0; i <= haystack.length - needle.length; i++) {
        // Check if the substring starting at 'i' matches 'needle'
        if (haystack.substring(i, i + needle.length) === needle) {
            return i; // Return the exact index of the first match
        }
    }
    
    return -1; // Return -1 if the needle is not found
};
