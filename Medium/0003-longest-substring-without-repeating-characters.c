int lengthOfLongestSubstring(char* s) {
    int lastSeen[256];
    for (int i = 0; i < 256; i++) {
        lastSeen[i] = -1;
    }

    int left = 0;
    int maxLen = 0;

    for(int right = 0; s[right] != '\0'; right++) {
        unsigned char current = s[right];

        if(lastSeen[current] >= left) {
            left = lastSeen[current] + 1;
        }

        lastSeen[current] = right;

        int currentLen = right - left + 1;
        if(currentLen > maxLen) {
            maxLen = currentLen;
        }
    }
    return maxLen;
}
