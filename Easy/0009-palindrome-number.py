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
This is what I created, this solution only works with numbers under 1000 see new solution at the very bottom
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
this is an easier solution, works by converting to a string
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

"""
this version doesnt convert to a string
"""
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # if x is less then 0 or if the remainder = 0 and x doesnt = 0 return false
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        # save the original number so we can compare
        original = x
        reverse = 0 # a placeholder value before we flip the number around

        while x > 0:
            digit = x % 10 # 121 = 12.1 the % keeps the .1
            reverse = (reverse * 10) + digit # reverse = 0 * 10 + 1 reverse is now 1
            print(reverse)
            print(digit)
            x = x // 10 # 121 is now 12 repeat
            print(x)
        # second run 12 % 10 is now 1.2 keep the 2
        # reverse = 1 * 10 + 2 reverse is now 12
        
        return original == reverse
