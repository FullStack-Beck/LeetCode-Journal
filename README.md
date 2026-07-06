# 🚀 LeetCode Progress Journal

My personal tracker for mastering algorithms and data structures using Python, C++, and Java.

## 📊 Progress Dashboard

| Date | # | Problem Name | Difficulty | Solution | Key Takeaway | Other Languages |
| :--- | :---: | :--- | :---: | :---: | :---: | :--- |
| 06/30/2026 | 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | [Python](./Easy/0009-palindrome-number.py) | Hardcoded position variables (`ones`, `tens`) break code layout as input sizes scale up. Modulo 10 (`x % 10`) isolates the last right-hand digit by extracting the division remainder. A `while x > 0` loop combined with `(rev * 10) + digit` dynamically scales digit reversal mathematically across any input size without memory limits or string conversions. <- new revised solution Python `/` is float division (`5/2=2.5`), `//` is floor division (`5//2=2`). Reversing strings via `[::-1]` is much cleaner than manual digit extraction. | |
| 07/01/2026 | 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | 🟢 Easy | [C++](./Easy/0013-Roman-to-Integer.cpp) | Substrings create memory overhead; raw loop lookaheads (`s[i+1]`) are faster. Independent `if` statements fall through and cause double-counting unless controlled with `continue` or `else if`. Out-of-bounds checks must use `< s.length()` instead of `<=`. | |
| 07/02/2026 | 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 Easy | [Java](./Easy/0014-longest-common-prefix.java) | Loop lookaheads (`i + 1`) invite `ArrayIndexOutOfBoundsException` at the collection boundaries; anchoring to index 0 and iterating forward from 1 is safer. Prefix evaluation requires a static left anchor (`0`); using `.substring(0, len - 1)` systematically drops right-side characters until `.indexOf(prefix) == 0` confirms a clean match. | [JavaScript](./Easy/0014-longest-common-prefix.js) |
| 07/02/2026 | 20 | [Valid Parentheses](https://leetcode.com) | 🟢 Easy | [C#](./Easy/0020-valid-parentheses.cs) | `s.IndexOf()` completely blinds code to duplicated and mixed character pairs because it only searches for the first occurrence. Structural validation requires evaluating elements based on their exact arrival sequence. A Last-In, First-Out (LIFO) **Stack** structure tracks relative order cleanly: open-bracket characters are collected via `.Push()`, and matched closing characters confirm alignment by interrogating and dropping the current sequence crown via `.Pop()`. Duplicate validation rules can fail silently due to subtle copy-paste character mutations (such as validating `c == '}'` twice instead of mapping `]`). | |
| 07/06/2026 | 21 | [Merge Two Sorted Lists](https://leetcode.com) | 🟢 Easy | [TypeScript](./Easy/0021-merge-two-sorted-lists.ts) | Reading nested object values requires handling structural nullability constraints explicitly. Directly mutating list variables inside loops severs access history; isolated pointer replication prevents memory address orphaning. Unequal subcollection distributions leave remainder tracks that must be structurally appended outside main iterative loops to capture dangling properties. | |

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

### Structural Order & State Tracking (C# / General) 0020
* **First-Occurrence Blindness**: Scanning global properties or using global index matches (like `IndexOf`) fails entirely when strings contain multiple nested, interlocking, or trailing sequences (such as `(){}}{`). 
* **LIFO Stack Engine**: Stacks operate via a Last-In, First-Out model. This makes them the ultimate structure for processing symmetric patterns or matching historical pairs.
* **Stack State Gating**: Attempting to extract or pop from a collection when its internal element count is empty will immediately trigger a runtime exception. Always guard extractions with a `stack.Count == 0` validation check.
* **Copy-Paste Mutation Risks**: Reusing multi-line condition blocks by copying and pasting creates silent logical traps. A single unadjusted character target (like evaluating `c == '}'` against a square bracket target) bypasses validation assertions without raising syntax warnings.
* **Universal Concept, Local Design**: Dedicated `Stack` class APIs are available natively in managed environments (C#, Java, C++), while modern script engines (Python, JavaScript) utilize optimized native arrays/lists via append and pop hooks. Low-level environments (C) require developers to manually bind an array to a cursor tracking variable.

### Pointer Navigation & Memory Isolation (TypeScript / General) 0021
* **Null Pointer Gatekeeping**: Statically-typed environments enforce type definitions (`ListNode | null`). Accessing child keys (like `.val` or `.next`) without wrapping code in validation filters (`if (list !== null)`) risks runtime reference errors.
* **The "One-Way Street" Problem**: Singly-linked list nodes lack back-link properties. Advancing a unique single tracker forward drops preceding history blocks completely out of memory scope once left behind.
* **Anchor & Mover Model**: Managing tracking lists requires separate active references: a stationary **Anchor** (Dummy Node) pinned to structural position 0 to provide a returnable point, and a fluid **Mover** (Tail pointer) that slides downward to attach subsequent entries.
* **Pointer Redirection**: Statement lines written as isolated child properties (like `list1.next;`) represent data lookups and execute with zero mutation effects. Advancing reference frames down an object chain requires variable reassignment via assignment assignment syntax (`list1 = list1.next;`).
* **Loop Boundary Cleanup**: Iterative loop conditions (`while (list1 && list2)`) drop out prematurely the exact moment a single resource runs empty. Evaluating remainder boundaries outside iterative conditions ensures leftover data sets remain linked when lists are of unequal lengths.
