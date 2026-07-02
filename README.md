# 🚀 LeetCode Progress Journal

My personal tracker for mastering algorithms and data structures using Python.

## 📊 Progress Dashboard

| Date | # | Problem Name | Difficulty | Solution | Key Takeaway |
| :--- | :---: | :--- | :---: | :---: | :--- |
| 06/30/2026 | 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | [Python](./Easy/0009-palindrome-number.py) | Hardcoded position variables (`ones`, `tens`) break code layout as input sizes scale up. Modulo 10 (`x % 10`) isolates the last right-hand digit by extracting the division remainder. A `while x > 0` loop combined with `(rev * 10) + digit` dynamically scales digit reversal mathematically across any input size without memory limits or string conversions. <- new revised solution Python `/` is float division (`5/2=2.5`), `//` is floor division (`5//2=2`). Reversing strings via `[::-1]` is much cleaner than manual digit extraction. |
| 07/01/2026 | 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | 🟢 Easy | [C++](./Easy/0013-Roman-to-Integer.cpp) | Substrings create memory overhead; raw loop lookaheads (`s[i+1]`) are faster. Independent `if` statements fall through and cause double-counting unless controlled with `continue` or `else if`. Out-of-bounds checks must use `< s.length()` instead of `<=`. |

## 💡 Notes & Cheatsheet

### String Slicing Shortcuts (Python)
* `string[::-1]` -> Reverses a string.
* `string[start:stop:step]` -> Core slicing syntax.
* `x % 10`: Evaluates the remainder after dividing by 10. This systematically extracts the last digit of any positive number.
* `x // 10`: Floor divides by 10. This strips the last digit completely, cleanly reducing the length of the number.

### Control Flow & Memory (C++)
* **`continue`**: Jumps immediately to the next iteration of a loop. Essential for skipping the second character of a matched pair (like skipping 'M' after processing 'C' in "CM").
* **`else if` vs `if`**: Separate `if` blocks all check the same index sequentially, causing bugs. `else if` ensures only *one* matching block executes.
* **Vector Mutation**: Class-level vectors persist across different test runs in environments like LeetCode. Local variables (`int total`) are cleaner and safer for state isolation.
* **String Bounds**: A string of length $N$ has valid indices from `0` to `N-1`. Evaluating `s[i+1]` when `i == N-1` points to an illegal index and crashes memory. Always gate lookaheads with `i + 1 < s.length()`.
