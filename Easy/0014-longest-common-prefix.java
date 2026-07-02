class Solution {
    public String longestCommonPrefix(String[] strs) {
        // Edge case safety check for empty input array
        if (strs == null || strs.length == 0) return "";
        
        // Assume the entire first word is the common prefix to start with
        String prefix = strs[0];
        
        // Compare our running prefix against every remaining word in the array
        for (int i = 1; i < strs.length; i++) { 
            
            // indexOf returns 0 ONLY if 'prefix' matches exactly at the front of strs[i]
            // If it returns -1 (not found) or > 0 (found later in the word), we loop
            while (strs[i].indexOf(prefix) != 0) {
                
                // Truncate the prefix by chopping off exactly one character from the right end
                prefix = prefix.substring(0, prefix.length() - 1); 

                // Guard clause: if the prefix shrinks to nothing, no common prefix exists
                if (prefix.isEmpty()) {
                    return "";
                }
            }
        }
        
        // If we clear the loop, whatever is left of 'prefix' is the longest common prefix
        return prefix;
    }
}
