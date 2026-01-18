# Push_Swap

> *This project was created as part of the **42 curriculum** by **[okorkech]***

---

## 📌 Overview

**Push_Swap** is an algorithmic optimization project where the goal is to sort a stack of integers using **only a limited set of operations** and **two stacks**:

- **Stack A**
- **Stack B**

The challenge lies in producing the **smallest possible number of instructions** to sort the stack correctly.

### Performance Targets

| Input Size | Target Moves |
|------------|--------------|
| 100 numbers | < 700 |
| 500 numbers | < 5500 |

To achieve this, the project implements the **Turk Algorithm**, a greedy, cost-based strategy designed specifically for the Push_Swap problem.

---

## 🧠 The Turk Algorithm

The **Turk Algorithm** (also called *Mechanical Turk*) is a **cost-analysis greedy algorithm**.  
Instead of solving the entire list at once, it repeatedly selects the **cheapest possible move** at each step.

Unlike:
- **QuickSort** (divide & conquer)
- **Radix Sort** (binary grouping)

The Turk Algorithm evaluates **real-time move cost**, optimizing stack rotations and pushes.

---

## 🔄 Algorithm Phases

### Phase 1: Intelligent Push to Stack B

- Push values from **Stack A → Stack B** until only **3 numbers remain** in A.
- Numbers are not pushed randomly:
  - Smaller ranks are pushed first (chunking)
  - Stack B is maintained in a rough descending order

**Goal:** Prepare Stack B so larger values are easier to reinsert later.

---

### Phase 2: Sort the Remaining Three

Once only 3 numbers remain in Stack A, they are sorted using a **hardcoded minimal solution**.

- Maximum operations: **2**
- Covers all permutations efficiently

---

### Phase 3: Mechanical Return (Core Logic)

This is the heart of the Turk Algorithm.

For **every node in Stack B**:

#### 1. Target Selection
- Identify the **smallest number in Stack A that is larger than the B node**
- If none exists, the target becomes the **smallest value in A**

#### 2. Cost Calculation
- Compute the number of moves required to:
  - Bring the B node to the top
  - Bring its target in A to the top

#### 3. Optimization
- If both stacks rotate **up**, use `rr`
- If both rotate **down**, use `rrr`
- Mixed rotations use individual commands

#### 4. Execution
- Select the node with the **lowest total cost**
- Execute its moves and push it to Stack A

This loop continues until **Stack B is empty**.

---

### Final Alignment

After all values are back in Stack A, a final rotation ensures the **smallest number is on top**, completing the sort.

---

## 🛠️ Instructions

### Compilation

-The project includes a `Makefile`:

```bash
make
```
Compiles the main executable `push_swap`.
```bash
make bonus
```
Compiles the bonus checker.
```bash
make clean
```
Removes object files.
```bash
make fclean
```
Removes all binaries and objects.

### ▶️ Execution

### Push_Swap (Sorting)
```bash
./push_swap 2 1 3 6 5 8
```
Outputs the list of instructions to sort the stack.

### Checker (Verification)
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

**Possible outputs:**
- `OK` → Sorted correctly
- `KO` → Sorting failed
- `Error` → Invalid input or instruction

## 🧪 Testing

## Random 100 Numbers
```bash
ARG=$(seq -100 100 | sort -R | head -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker $ARG
```

Used to benchmark performance and correctness.

## 📚 Resources

- [Push Swap Tutorial (Oceano)](https://example.com) – Stack manipulation breakdown
- Turk Algorithm Discussions – Cost-analysis logic
- Push Swap Visualizer – Visual debugging of stack operations

## 🤖 AI Usage Disclosure

AI tools were used responsibly and transparently for the following purposes:

### Debugging & Logic Verification
- Fixed intermittent KO issues
- Corrected checker parsing (rrr vs rrb)

### Test Case Generation
- Extreme inputs (INT_MAX, INT_MIN, empty strings, lone signs)

### Code Optimization
- Helper functions for Norminette compliance

**Note:** No AI-generated code was copied directly into the final implementation.

### ✅ Final Notes

This project emphasizes:
- Algorithmic efficiency
- Strict rule compliance
- Clean data structures
- Optimized move calculation