# Leetcode-174.-Dungeon-Game

# 🏰 Dungeon Game Problem - Minimum Initial Health Required 👑

Welcome, adventurer! 🧙‍♂️ In this quest, a knight must travel from the top-left to the bottom-right of a grid-shaped dungeon, slaying monsters (negative cells 🧟‍♂️) and collecting power-ups (positive cells 🍗). Our mission? Determine the **minimum health** he must start with so that he **never drops below 1 HP** along the journey. 🩻

---

## 📘 Problem Overview

You're given an `m x n` grid representing rooms in a dungeon. Each cell contains an integer:

* Positive ➕: Health gain
* Negative ➖: Health loss
* Zero 0⃣: Neutral

You can only move **right ➡️** or **down ⬇️**, and you must ensure the knight survives every step with **at least 1 HP**.

---

## 📊 Time & Space Complexity

| Approach                     | Time Complexity           | Space Complexity         |
| ---------------------------- | ------------------------- | ------------------------ |
| 🔁 Recursive (Top-Down)      | Exponential `O(2^(m+n))`  | `O(m+n)` recursion stack |
| 🔍 Binary Search + DFS       | `O((log(maxHP)) * m * n)` | `O(m * n)`               |
| ⚖️ Bottom-Up DP (Tabulation) | `O(m * n)`                | `O(m * n)`               |

---

## 🔄 Approach 1: Pure Recursive (Top-Down)

### 📅 Idea:

* Start from top-left.
* Try all paths (right ➡️ and down ⬇️).
* Track the **minimum health** needed to reach the destination.
* At every step, choose the path which requires lesser initial health.

### ⚡️ Drawbacks:

* Exponential time!
* Recomputes the same subproblems many times.
* Not suitable for large inputs.

---

## 🔎 Approach 2: Binary Search + DFS

### 🔢 Idea:

* Apply **binary search** on the answer (i.e., the initial health).
* For each guess, simulate a path using DFS to see if the knight survives.

### ✨ Highlights:

* Combines logic with search space pruning.
* Efficient for bounded grid sizes.

### ⚡️ Drawbacks:

* Slightly complex to implement.
* Requires careful simulation of health at each step.

---

## 📈 Approach 3: Bottom-Up Dynamic Programming

### 🌟 Idea:

* Work backwards from the bottom-right cell to the top-left.
* At each cell, calculate the **minimum health** needed to move forward.
* Use a DP table to store and reuse results.

### 🔥 Highlights:

* Most efficient.
* Clean and simple logic.
* Works in `O(m*n)` time and space.

---

## 📈 Example

```text
Input:
[[-2,-3,3],
 [-5,-10,1],
 [10,30,-5]]

Output: 7

Explanation:
The knight must start with at least 7 HP to ensure he never drops below 1 HP.
Optimal path: (0,0) → (0,1) → (0,2) → (1,2) → (2,2)
```

---

## 📑 Author

**Name:** Ridham Garg
**Institution:** Thapar University, Patiala
**Roll No.:** 102203014

---

## 📊 Summary Table

| Approach            | Description                                        | Time                 | Space      |
| ------------------- | -------------------------------------------------- | -------------------- | ---------- |
| Recursive           | Try all paths with no memo                         | `O(2^(m+n))`         | `O(m+n)`   |
| Binary Search + DFS | Binary search the answer with DFS check            | `O(log(HP) * m * n)` | `O(m*n)`   |
| Bottom-Up DP        | Tabulate minimum HP at each cell from end to start | `O(m * n)`           | `O(m * n)` |

---

Happy Coding! 🧠 Let the knight survive the dungeon! 💪
