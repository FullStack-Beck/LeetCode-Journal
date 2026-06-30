"""
LeetCode 9: Palindrome Number
Difficulty: Easy
Link: https://leetcode.com/problems/palindrome-number/

Description:
Given an integer x, return true if x is a palindrome, and false otherwise.

Time Complexity: O(n) - where n is the number of digits.
Space Complexity: O(n) - to store the string representation.
"""

"""
This is what I created
"""
class Solution:
    def isPalindrome(self, x: int) -> bool:
        one = x % 10
        print(one)
        tens = (x // 10) % 10
        print(tens)
        hundreds = (x // 100)
        print(hundreds)
        if x >= 100:
            answer = one * 100 + tens * 10 + hundreds
            print(answer)
            if answer == x : return True
            else: return False
        elif x < 100 and x > 9:
            answer = one * 10 + tens
            print(answer)
            if answer == x : return True
            else: return False
        elif x >= 0 and x < 10 : return True
        else: return False

"""
this is an easier solution
"""
class SolutionB:
    def isPalindromeB(self, x: int) -> bool:
        if x < 0: 
            return False
        
        # Convert to string and check if it reads the same backwards
        return str(x) == str(x)[::-1]

if __name__ == "__main__":
    # Quick local testing
    sol = Solution()
    print(sol.isPalindrome(121))   # Expected: True
    print(sol.isPalindrome(-121))  # Expected: False
