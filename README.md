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

The project includes a `Makefile`:

```bash
make
