# 🚀 LeetCode Progress Journal

My personal tracker for mastering algorithms and data structures using Python, C++, and Java.

## 📊 Progress Dashboard

| Date | # | Problem Name | Difficulty | Solution | Key Takeaway | Other Languages |
| :--- | :---: | :--- | :---: | :---: | :---: | :--- |
| 06/30/2026 | 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | [Python](./Easy/0009-palindrome-number.py) | Hardcoded position variables (`ones`, `tens`) break code layout as input sizes scale up. Modulo 10 (`x % 10`) isolates the last right-hand digit by extracting the division remainder. A `while x > 0` loop combined with `(rev * 10) + digit` dynamically scales digit reversal mathematically across any input size without memory limits or string conversions. <- new revised solution Python `/` is float division (`5/2=2.5`), `//` is floor division (`5//2=2`). Reversing strings via `[::-1]` is much cleaner than manual digit extraction. | |
| 07/01/2026 | 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | 🟢 Easy | [C++](./Easy/0013-Roman-to-Integer.cpp) | Substrings create memory overhead; raw loop lookaheads (`s[i+1]`) are faster. Independent `if` statements fall through and cause double-counting unless controlled with `continue` or `else if`. Out-of-bounds checks must use `< s.length()` instead of `<=`. | |
| 07/02/2026 | 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 Easy | [Java](./Easy/0014-longest-common-prefix.java) | Loop lookaheads (`i + 1`) invite `ArrayIndexOutOfBoundsException` at the collection boundaries; anchoring to index 0 and iterating forward from 1 is safer. Prefix evaluation requires a static left anchor (`0`); using `.substring(0, len - 1)` systematically drops right-side characters until `.indexOf(prefix) == 0` confirms a clean match. | [JavaScript](./Easy/0014-longest-common-prefix.js) |
| 07/02/2026 | 20 | [Valid Parentheses](https://leetcode.com/valid-parentheses/) | 🟢 Easy | [C#](./Easy/0020-valid-parentheses.cs) | `s.IndexOf()` completely blinds code to duplicated and mixed character pairs because it only searches for the first occurrence. Structural validation requires evaluating elements based on their exact arrival sequence. A Last-In, First-Out (LIFO) **Stack** structure tracks relative order cleanly: open-bracket characters are collected via `.Push()`, and matched closing characters confirm alignment by interrogating and dropping the current sequence crown via `.Pop()`. Duplicate validation rules can fail silently due to subtle copy-paste character mutations (such as validating `c == '}'` twice instead of mapping `]`). | |
| 07/06/2026 | 21 | [Merge Two Sorted Lists](https://leetcode.com/merge-two-sorted-lists/) | 🟢 Easy | [TypeScript](./Easy/0021-merge-two-sorted-lists.ts) | Reading nested object values requires handling structural nullability constraints explicitly. Directly mutating list variables inside loops severs access history; isolated pointer replication prevents memory address orphaning. Unequal subcollection distributions leave remainder tracks that must be structurally appended outside main iterative loops to capture dangling properties. | |
| 07/07/2026 | 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | 🟢 Easy | [C](./Easy/0026-remove-duplicates.c) | C arrays are fixed size sequences in memory and do not have dynamic methods like `.pop()` or properties like `.length()`. Direct array assignment (`=`) instead of an equality comparison check (`==` or `!=`) inside conditional logic introduces severe bugs. Local array variables (`int k[size]`) reside exclusively on temporary stack frames that get destroyed at function termination, meaning returning local arrays is illegal. In-place duplication filtering requires a two-pointer approach: a fast scanning index to check differences against adjacent variables (`i - 1`), and a slow write index (`unique`) that acts as a boundary pointer for modifying values in-place. | |
| 07/08/2026 | 1 | [Two Sum]([https://leetcode.com](https://leetcode.com/problems/two-sum/)) | 🟢 Easy | [C++](./Easy/0001-two-sum.cpp) | Concept: Nested Loop Pair MatchingA brute-force nested loop explores all unique pairs to avoid redundant self-matching by initializing the inner loop at i + 1. Calculating the target difference (target - currentnum) isolates the exact required match value ahead of time. Evaluating the inner pointer (nums[z]) directly against this pre-calculated numbercheck difference saves minor execution steps, returning the index pair {i, z} immediately upon a successful match. | |

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
```c
// C: Explicitly format integers using format specifiers and manually add newlines
printf("%d\n", nums[i]);

// C: Output raw string blocks with an automatic built-in trailing newline
puts("Text Output");

// C: Safely compare raw bytes of memory across identical array data structures
if (memcmp(array1, array2, sizeof(array1)) == 0) { }
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

// C++: Nested loop pair matching (O(n²) time, O(1) space)
for (int i = 0; i < nums.size(); i++) {
    int numbercheck = target - nums[i];
    for (int z = i + 1; z < nums.size(); z++) {
        if (nums[z] == numbercheck) return {i, z};
    }
}

// C++: Single-pass hash map lookup (O(n) time, O(n) space)
std::unordered_map<int, int> seen;
for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (seen.find(complement) != seen.end()) return {seen[complement], i};
    seen[nums[i]] = i;
}
```
```typescript
// TypeScript: Move list references forward (must use assignment '=')
list1 = list1.next;

// TypeScript: Strict gatekeeping check to prevent reading null properties
if (list1 !== null) { console.log(list1.val); }
```
```c
// C: Standard preprocessor macro definitions representing a null pointer constant
#define NULL ((void *)0) 
#define NULL 0           

// C23: Modern native core language type-safe null pointer keyword
int* ptr = nullptr;
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

### 4. Memory & C-Array Subsystems
* **The Invisible Length Constraint**: Arrays in C are simple pointer references to block memory sequences. They store no metadata parameters like `.length`. Array size requirements must always be tracked manually or passed as an independent function parameter (`numsSize`).
* **Value Identity Limits**: Running `array1 == array2` evaluates the absolute **memory locations** where the arrays are stored, not their content. Deep array equivalence requires sequential validation loops or checking the byte stream footprint with `memcmp`.
* **Stack Lifespan Expiration**: Declaring explicit local arrays within a function context (`int k[size]`) places that memory allocation directly onto the transient execution stack. When the runtime passes a `return` keyword, the underlying stack frame vanishes, rendering returned pointers to local arrays illegal.
* **The Two-Pointer In-Place Refactoring**: Mutating continuous data spaces under fixed memory allocations uses separate reader and writer indices. Setting the initial element as a fixed unique anchor allows the scanning pointer to evaluate next-door items (`i - 1`) for layout mutations while the slow pointer overwrites records sequentially.

### 5. Time-Space Complexity Trade-offs (Searching & Lookups)
* **Brute-Force Nested Loops (`O(n²)` Time)**: Searching pairs by pinning an outer pointer and sweeping an inner pointer (`z = i + 1`) eliminates self-matching errors but creates huge computational delays as data arrays grow. 
* **Hash Map Lookups (`O(n)` Time)**: Storing visited elements inside an `std::unordered_map` layout exchanges a small memory footprint (`O(n)` Space) for instant retrieval. 
* **The Complement Strategy**: Instead of searching for arbitrary pairings, calculating the specific required difference value upfront (`target - currentnum`) transforms an open-ended search into a direct, exact-match verification problem using `.find()`.
