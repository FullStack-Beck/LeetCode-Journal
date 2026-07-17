# 🚀 LeetCode Progress Journal

My personal tracker for mastering algorithms and data structures using Python, C++, JavaScript, C#, TypeScript, C, and Java.

## 📊 Progress Dashboard

| Date | # | Problem Name | Difficulty | Solution | Key Takeaway | Other Languages |
| :--- | :---: | :--- | :---: | :---: | :---: | :--- |
| 06/30/2026 | 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | [Python](./Easy/0009-palindrome-number.py) | Hardcoded position variables (`ones`, `tens`) break code layout as input sizes scale up. Modulo 10 (`x % 10`) isolates the last right-hand digit by extracting the division remainder. A `while x > 0` loop combined with `(rev * 10) + digit` dynamically scales digit reversal mathematically across any input size without memory limits or string conversions. <- new revised solution Python `/` is float division (`5/2=2.5`), `//` is floor division (`5//2=2`). Reversing strings via `[::-1]` is much cleaner than manual digit extraction. | |
| 07/01/2026 | 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | 🟢 Easy | [C++](./Easy/0013-Roman-to-Integer.cpp) | Substrings create memory overhead; raw loop lookaheads (`s[i+1]`) are faster. Independent `if` statements fall through and cause double-counting unless controlled with `continue` or `else if`. Out-of-bounds checks must use `< s.length()` instead of `<=`. | |
| 07/02/2026 | 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 Easy | [Java](./Easy/0014-longest-common-prefix.java) | Loop lookaheads (`i + 1`) invite `ArrayIndexOutOfBoundsException` at the collection boundaries; anchoring to index 0 and iterating forward from 1 is safer. Prefix evaluation requires a static left anchor (`0`); using `.substring(0, len - 1)` systematically drops right-side characters until `.indexOf(prefix) == 0` confirms a clean match. | [JavaScript](./Easy/0014-longest-common-prefix.js) |
| 07/02/2026 | 20 | [Valid Parentheses](https://leetcode.com/valid-parentheses/) | 🟢 Easy | [C#](./Easy/0020-valid-parentheses.cs) | `s.IndexOf()` completely blinds code to duplicated and mixed character pairs because it only searches for the first occurrence. Structural validation requires evaluating elements based on their exact arrival sequence. A Last-In, First-Out (LIFO) **Stack** structure tracks relative order cleanly: open-bracket characters are collected via `.Push()`, and matched closing characters confirm alignment by interrogating and dropping the current sequence crown via `.Pop()`. Duplicate validation rules can fail silently due to subtle copy-paste character mutations (such as validating `c == '}'` twice instead of mapping `]`). | |
| 07/06/2026 | 21 | [Merge Two Sorted Lists](https://leetcode.com/merge-two-sorted-lists/) | 🟢 Easy | [TypeScript](./Easy/0021-merge-two-sorted-lists.ts) | Reading nested object values requires handling structural nullability constraints explicitly. Directly mutating list variables inside loops severs access history; isolated pointer replication prevents memory address orphaning. Unequal subcollection distributions leave remainder tracks that must be structurally appended outside main iterative loops to capture dangling properties. | |
| 07/07/2026 | 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | 🟢 Easy | [C](./Easy/0026-remove-duplicates.c) | C arrays are fixed size sequences in memory and do not have dynamic methods like `.pop()` or properties like `.length()`. Direct array assignment (`=`) instead of an equality comparison check (`==` or `!=`) inside conditional logic introduces severe bugs. Local array variables (`int k[size]`) reside exclusively on temporary stack frames that get destroyed at function termination, meaning returning local arrays is illegal. In-place duplication filtering requires a two-pointer approach: a fast scanning index to check differences against adjacent variables (`i - 1`), and a slow write index (`unique`) that acts as a boundary pointer for modifying values in-place. | |
| 07/08/2026 | 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | 🟢 Easy | [C++](./Easy/0001-two-sum.cpp) | Concept: Nested Loop Pair MatchingA brute-force nested loop explores all unique pairs to avoid redundant self-matching by initializing the inner loop at i + 1. Calculating the target difference (target - currentnum) isolates the exact required match value ahead of time. Evaluating the inner pointer (nums[z]) directly against this pre-calculated numbercheck difference saves minor execution steps, returning the index pair {i, z} immediately upon a successful match. | |
| 07/09/2026 | 27 | [Remove Element](https://leetcode.com/remove-element/) | 🟢 Easy | [JavaScript](./Easy/0027-remove-element.js) | In JavaScript, passing an element value instead of an index iterator (`i`) to `.splice()` corrupts the removal index, and mutating an array forward inside an `i++` loop skips the adjacent element as items shift left. In C, arrays lack automatic resizing methods, requiring a secondary inner loop to shift elements left manually. The shifting boundary condition must be bounded at `j < numsSize - 1` to prevent out-of-bounds reading (`nums[j+1]`) beyond allocated memory blocks. The two-pointer pattern optimizes this process by dropping expensive shifting loops entirely. | [C](./Easy/0027-remove-element.c) |
| 07/10/2026 | 28 | [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) | 🟢 Easy | [TypeScript](./Easy/0028-find-index-first-occurrence.ts) | Sliding window loop limit optimization avoids searching index spaces where the remaining `haystack` length is smaller than the `needle`. TypeScript leverages `.substring(i, i + len)` for clean high-level comparisons, whereas C requires an inner sliding pointer `j` to manually verify byte alignments step-by-step. | [C](./Easy/0028-find-index-first-occurrence.c) |
| 07/13/2026 | 28 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | 🟢 Easy | [JavaScript](./Easy/0035-search-insert-position.js) | Sequential search naturally solves insertion problems by checking for both equality and the first element greater than the target. Array boundaries must be handled explicitly—if no existing value is greater than or equal to the target, the correct insertion point is immediately after the final element (nums.length). Traversing one index beyond the last valid element (i <= nums.length) is only safe when the out-of-bounds access is never dereferenced before the boundary check. To else if statement doesnt require the && because that already is checked by the previous if and is redundant |  |
| 07/14/2026 | 58 | [Length of Last Word](https://leetcode.com/length-of-last-word) | 🟢 Easy | [C](./Easy/0058-length-of-last-word.c) | In C, memory constraints favor a backward scanning loop ($O(1)$ space) that manually bypasses trailing spaces via index decrementing (`i--`) before counting word characters. In JavaScript, high-level string manipulation allows a clean abstraction pipeline: `.trim()` eliminates edge whitespace, and `.split(' ')` partitions the string into an array, allowing direct length access of the final element via `words[words.length - 1].length`. | [JavaScript](./Easy/0058-length-of-last-word.js) |
| 07/15/2026 | 66 | [Plus One](https://leetcode.com/plus-one) | 🟢 Easy | [Java](./Easy/0066-plus-one.java) | Reverse loops (`digits.length - 1 down to 0`) avoid `ArrayIndexOutOfBoundsException` by matching 0-indexed layout sizes. Modulo 10 (`% 10`) handles digits rollover ($9 \rightarrow 0$) natively. When all digits roll over (e.g., $999 \rightarrow 000$), a new array size `n + 1` with a leading `1` must be initialized to safely hold the expanded value carry-over. | [JavaScript](./Easy/0066-plus-one.js/add-binary) |
| 07/16/2026 | 67 | [Add Binary](https://leetcode.com) | 🟢 Easy | [JavaScript](./Easy/0067-add-binary.js) | Treating binary strings as raw JavaScript numbers breaks down due to bit precision loss on long inputs. String evaluation requires independent right-to-left tracking pointers (`i`, `j`) decremented manually. Column arithmetic sums (`digitA + digitB + carry`) dictate structural updates: sums of 2 or 3 carry a `1` to the next column, while string additions must prepend results to the front (`result = bit + result`) to prevent reverse string mutation bugs. | |
| 07/17/2026 | 69 | [Sqrt(x)](https://leetcode.com/sqrtx) | 🟢 Easy | [Java](./Easy/0069-sqrtx.java) | Binary search requires three moving pointers (`left`, `right`, `mid`) and precise arithmetic boundaries to avoid integer overflows. **Newton's Method** simplifies this by using a single guess variable (`r`) that iteratively averages itself (`(r + x / r) / 2`) until it converges on the root. In Java, native integer division handles rounding down automatically, but the guess tracking variable must use a `long` type to safely evaluate `r * r > x` without tripping 32-bit integer overflow limits on maximum test constraints. | [TypeScript](./Easy/0069-sqrtx.ts) |


# 📖 Problem → Concepts

| If the problem says... | Think... |
|------------------------|----------|
| Compare strings | Length, character access, comparison |
| Substring | Sliding window, indexing |
| First occurrence | Sliding window, nested loop |
| Remove duplicates | Two pointers |
| Merge sorted arrays/lists | Two pointers |
| Reverse | Two pointers |
| Find pair | Hash Map or Nested Loops |
| Matching brackets | Stack |
| Frequency count | Hash Map |
| Palindrome | Two pointers |
| Sorted array | Binary Search or Two Pointers |
| Smallest/Largest | Running min/max |
| Level order traversal | Queue (BFS) |
| Tree paths | DFS |
| Shortest path | BFS |
| All combinations | Backtracking |
| Optimization | Dynamic Programming |
| Length of last word | Backward iteration (C) / Trim & Split (JS) |
| Addition / Large numbers | Reverse pointer iteration, Tracking column carry-over |


---

# 🔤 STRINGS

---

## Get Length

| Language | Syntax |
|-----------|---------|
| Python | `len(s)` |
| C++ | `s.length()` |
| Java | `s.length` |
| C# | `s.Length` |
| JavaScript | `s.length` |
| TypeScript | `s.length` |
| C | `strlen(s)` |

### Concept

You usually need the length before indexing or looping.

---

## Character Access

| Language | Syntax |
|-----------|---------|
| Python | `s[i]` |
| C++ | `s[i]` |
| Java | `s.charAt(i)` |
| C# | `s[i]` |
| JavaScript | `s[i]` |
| TypeScript | `s[i]` |
| C | `s[i]` |

## Trim Whitespace

| Language | Syntax |
|-----------|---------|
| Python | `s.strip()` |
| C++ | *No built-in (Requires manual loop / regex)* |
| Java | `s.trim()` |
| C# | `s.Trim()` |
| JavaScript | `s.trim()` |
| TypeScript | `s.trim()` |
| C | *No built-in (Requires manual index tracking)* |

---

## Split Strings (By Space)

| Language | Syntax |
|-----------|---------|
| Python | `s.split()` |
| C++ | `stringstream ss(s);` |
| Java | `s.split(" ")` |
| C# | `s.Split(' ')` |
| JavaScript | `s.split(' ')` |
| TypeScript | `s.split(' ')` |
| C | `strtok(s, " ")` *(Note: mutates the original string)* |

### Concept

Almost every string algorithm eventually becomes:

```
Compare character A to character B.
```

---

## Compare Entire Strings

| Language | Syntax |
|-----------|---------|
| Python | `a == b` |
| C++ | `a == b` |
| Java | `a.equals(b)` |
| C# | `a == b` |
| JavaScript | `a === b` |
| TypeScript | `a === b` |
| C | `strcmp(a,b)==0` |

### Concept

Checks whether two strings contain the same characters.

---

## Compare Part of a String

Python

```python
s[start:end]
```

C++

```cpp
s.substr(start,length)
```

Java

```java
s.substring(start,end)
```

JavaScript / TypeScript

```javascript
s.substring(start,end)
```

C

```c
for(int i=0;i<len;i++)
{
    if(a[start+i]!=b[i])
    {
        // mismatch
    }
}
```

### Concept

Sometimes you compare a section of a string instead of the whole string.

---

## Find Character

| Language | Syntax |
|-----------|---------|
| Python | `s.find('a')` |
| C++ | `s.find('a')` |
| Java | `s.indexOf('a')` |
| C# | `s.IndexOf('a')` |
| JavaScript | `s.indexOf('a')` |
| TypeScript | `s.indexOf('a')` |
| C | `strchr(s,'a')` |

---

## Find Substring

| Language | Syntax |
|-----------|---------|
| Python | `s.find(word)` |
| C++ | `s.find(word)` |
| Java | `s.indexOf(word)` |
| C# | `s.IndexOf(word)` |
| JavaScript | `s.indexOf(word)` |
| TypeScript | `s.indexOf(word)` |
| C | `strstr(s,word)` |

### Concept

Locate where one string appears inside another.

---

## Copy Strings

| Language | Syntax |
|-----------|---------|
| Python | `b = a` |
| C++ | `string b = a;` |
| Java | `String b = a;` |
| C# | `string b = a;` |
| JavaScript | `let b = a;` |
| TypeScript | `let b = a;` |
| C | `strcpy(dest,src)` |

---

## Concatenate Strings

| Language | Syntax |
|-----------|---------|
| Python | `a+b` |
| C++ | `a+b` |
| Java | `a+b` |
| C# | `a+b` |
| JavaScript | `a+b` |
| TypeScript | `a+b` |
| C | `strcat(dest,src)` |

---

# 📦 ARRAYS

---

## Length

| Language | Syntax |
|-----------|---------|
| Python | `len(arr)` |
| C++ | `arr.size()` |
| Java | `arr.length` |
| C# | `arr.Length` |
| JavaScript | `arr.length` |
| TypeScript | `arr.length` |
| C | Must be tracked manually |

---

## Access Element

```text
arr[index]
```

Works in every language.

---

## Last Element

Python

```python
arr[-1]
```

Everything else

```text
arr[length-1]
```

---

## Append

| Language | Syntax |
|-----------|---------|
| Python | `append()` |
| C++ | `push_back()` |
| Java | `add()` |
| C# | `Add()` |
| JavaScript | `push()` |
| TypeScript | `push()` |
| C | Manual assignment |

---

## Remove Last

| Language | Syntax |
|-----------|---------|
| Python | `pop()` |
| C++ | `pop_back()` |
| Java | `remove(size-1)` |
| C# | `RemoveAt()` |
| JavaScript | `pop()` |
| TypeScript | `pop()` |
| C | Manual |

---

## Insert

Most languages

```text
insert(index,value)
```

C

```c
Shift everything right manually.
```

---

## Delete

Most languages

```text
remove(index)
```

C

```c
Shift everything left manually.
```

---

# 🔁 LOOPS

---

## For Loop

Every language supports one.

---

## While Loop

Every language supports one.

---

## Continue

Skip current iteration.

---

## Break

Exit loop immediately.

---

## Nested Loop

Used when comparing every element to every other element.

Example:

```
for each i
    for each j
```

Time Complexity

```
O(n²)
```

---

# 👉 POINTERS

---

## Reference

Stores an address.

---

## Dereference

```c
*ptr
```

Gets the value.

---

## Address Of

```c
&variable
```

Gets memory address.

---

## Null Pointer

| Language | Syntax |
|-----------|---------|
| Python | `None` |
| Java | `null` |
| JavaScript | `null` |
| C# | `null` |
| C++ | `nullptr` |
| C | `NULL` |

---

## Allocate Memory

C

```c
malloc()
```

C++

```cpp
new
```

---

## Free Memory

C

```c
free(ptr)
```

C++

```cpp
delete ptr
```

---

# 🗂 HASH MAPS

---

## Create

Python

```python
{}
```

C++

```cpp
unordered_map
```

Java

```java
HashMap
```

C#

```csharp
Dictionary
```

JavaScript

```javascript
Map
```

TypeScript

```typescript
Map
```

C

Manual implementation required.

---

## Insert

```
map[key]=value
```

---

## Lookup

```
map[key]
```

---

## Exists?

Python

```python
key in map
```

C++

```cpp
find()
```

Java

```java
containsKey()
```

JavaScript

```javascript
has()
```

---
