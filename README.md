# 🚀 LeetCode Progress Journal

My personal tracker for mastering algorithms and data structures using Python, C++, and Java.

## 📊 Progress Dashboard

| Date | # | Problem Name | Difficulty | Solution | Key Takeaway |
| :--- | :---: | :--- | :---: | :---: | :--- |
| 06/30/2026 | 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | [Python](./Easy/0009-palindrome-number.py) | Hardcoded position variables (`ones`, `tens`) break code layout as input sizes scale up. Modulo 10 (`x % 10`) isolates the last right-hand digit by extracting the division remainder. A `while x > 0` loop combined with `(rev * 10) + digit` dynamically scales digit reversal mathematically across any input size without memory limits or string conversions. <- new revised solution Python `/` is float division (`5/2=2.5`), `//` is floor division (`5//2=2`). Reversing strings via `[::-1]` is much cleaner than manual digit extraction. |
| 07/01/2026 | 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | 🟢 Easy | [C++](./Easy/0013-Roman-to-Integer.cpp) | Substrings create memory overhead; raw loop lookaheads (`s[i+1]`) are faster. Independent `if` statements fall through and cause double-counting unless controlled with `continue` or `else if`. Out-of-bounds checks must use `< s.length()` instead of `<=`. |
| 07/02/2026 | 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 Easy | [Java](./Easy/0014-longest-common-prefix.java) | Loop lookaheads (`i + 1`) invite `ArrayIndexOutOfBoundsException` at the collection boundaries; anchoring to index 0 and iterating forward from 1 is safer. Prefix evaluation requires a static left anchor (`0`); using `.substring(0, len - 1)` systematically drops right-side characters until `.indexOf(prefix) == 0` confirms a clean match. |

## 💡 Notes & Cheatsheet

### String Slicing Shortcuts (Python) 0009
* `string[::-1]` -> Reverses a string.
* `string[start:stop:step]` -> Core slicing syntax.
* `x % 10`: Evaluates the remainder after dividing by 10. This systematically extracts the last digit of any positive number.
* `x // 10`: Floor divides by 10. This strips the last digit completely, cleanly reducing the length of the number.

### Control Flow & Memory (C++) 0013
* **`continue`**: Jumps immediately to the next iteration of a loop. Essential for skipping the second character of a matched pair (like skipping 'M' after processing 'C' in "CM").
* **`else if` vs `if`**: Separate `if` blocks all check the same index sequentially, causing bugs. `else if` ensures only *one* matching block executes.
* **Vector Mutation**: Class-level vectors persist across different test runs in environments like LeetCode. Local variables (`int total`) are cleaner and safer for state isolation.
* **String Bounds**: A string of length $N$ has valid indices from `0` to `N-1`. Evaluating `s[i+1]` when `i == N-1` points to an illegal index and crashes memory. Always gate lookaheads with `i + 1 < s.length()`.

### String & Array Mechanics (Java) 0014
* **Property vs Method**: Arrays use the immutable field metadata `.length` (e.g., `strs.length`), whereas Strings call an active internal method `.length()` (e.g., `prefix.length()`).
* **`indexOf(str) == 0`**: Serves as a perfect prefix matching check. If a substring exists but does not start at index 0, it means it is buried inside the word, not a prefix.
* **Dynamic Truncation**: `str.substring(0, str.length() - 1)` drops exactly one character off the tail of a string. Handing an empty string to `.isEmpty()` provides a clean break condition during aggressive truncation loops.
