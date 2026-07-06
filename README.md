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

## 💡 Quick-Reference Code Snippets

### Strings & Arrays
```python
# Python: Reverse a string or array instantly
reversed_str = s[::-1]

# Python: Slice syntax layout
sub_part = s[start:stop:step]
```
```java
// Java: Check if a string starts exactly with a prefix match
if (word.indexOf(prefix) == 0) { }

// Java: Drop exactly one character off the tail of a string
prefix = prefix.substring(0, prefix.length() - 1);

// Java: Array property vs String method length syntax
int totalItems = arr.length;
int totalChars = str.length();
```

### Math & Digits
```python
# Python: Extract the last digit of a number using modulo
last_digit = x % 10

# Python: Strip the last digit using floor division (keeps it an integer)
remaining_num = x // 10
```

### Memory & Loops
```cpp
// C++: Skip to the next loop iteration immediately
continue;

// C++: Guard lookaheads from running out of string memory limits
if (i + 1 < s.length()) { char nextChar = s[i+1]; }
```
```typescript
// TypeScript: Move list references forward (must use assignment '=')
list1 = list1.next;

// TypeScript: Strict gatekeeping check to prevent reading null properties
if (list1 !== null) { console.log(list1.val); }
```

---

## 🧠 The Big Concepts

### 1. Control Flow Rules
* **`if` vs `else if`**: Isolated `if` statements all check the same data point sequentially. Use `else if` to guarantee only *one* matching logic path executes.
* **Vector Mutation Pitfalls**: Class-level vectors persist across hidden test cases in platforms like LeetCode. Use local variables inside functions to keep fresh isolation state.

### 2. Stack Engine (LIFO)
* **First-Occurrence Blindness**: Global scanning methods (like `IndexOf`) fail completely when items contain mixed, nested, or mirrored duplicate pairs (e.g., `( [ ) ]`).
* **Last-In, First-Out Matching**: Stacks process symmetric patterns by tracking arrival order. Push incoming symbols down, and pop the crown to validate pairs. Always guard extractions with an empty count check to prevent runtime exception crashes.

### 3. Pointer & Linked List Architecture
* **The One-Way Street**: Singly-linked list nodes lack back-links. Advancing a unique single reference variable forward drops preceding history completely out of memory scope.
* **Anchor & Mover Model**: Managing output lists requires separate trackers: a stationary **Anchor** (Dummy Node) pinned at position 0 to provide a returnable point, and a fluid **Mover** (Tail pointer) that slides down to attach subsequent items.
* **Loop Boundary Remainders**: Dual loop conditions (`while (list1 && list2)`) exit early the exact moment a single resource runs empty. Check remainder boundaries *outside* loops to link left-behind properties from unequal collections.
