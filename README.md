# Algorithmic Problem-Solving Suite

## Overview
This project consists of efficient algorithmic solutions implemented in C++, designed to solve complex computational problems. The solutions focus on optimization techniques such as binary search, dynamic programming, and modular arithmetic to handle large-scale data efficiently.

## Features
- **Binary search optimization** for computational resource allocation
- **Dynamic programming** for minimizing costs in constrained environments
- **Logarithmic exponentiation** for efficient calculations
- **Greedy approaches** for optimal decision-making

## Project Structure
The project is organized into multiple modules, each corresponding to a different problem statement.

### **1. Server Power Allocation (`servere.cpp`)**
This solution employs **binary search** to determine the optimal power allocation across a set of servers. The key idea is to search for the **best uniform current level** that maximizes the minimum computing power of the weakest server.
- **Algorithm:**
  - Perform binary search on the current range to find the most efficient distribution.
  - Compute the difference between required and available power to adjust search bounds.
  - The solution efficiently converges to the optimal power level.
- **Time Complexity:** O(N log max_C), where max_C is the upper bound for the power supply.

### **2. Data Compression (`compresie.cpp`)**
This problem involves comparing two sequences of numbers and applying transformations to match them optimally.
- **Algorithm:**
  - Iterate through both sequences A and B.
  - If an element in A does not match the corresponding element in B, aggregate the smaller number to adjust for differences.
  - Continue until either sequence is exhausted, returning the maximum possible matched sequence length.
- **Time Complexity:** O(N + M), where N and M are the lengths of the sequences.

### **3. Grid Coloring (`colorare.cpp`)**
This problem explores the ways to color a structured grid while adhering to specific constraints.
- **Algorithm:**
  - Consider different configurations based on transitions between horizontal and vertical placements.
  - Use modular arithmetic to efficiently count valid colorings.
  - Employ **logarithmic exponentiation** for quick computation of large power values.
- **Time Complexity:** O(N log 3) due to efficient exponentiation.

### **4. Discount Optimization (`oferta.cpp`)**
This solution follows a dynamic programming approach to minimize total cost while purchasing items under promotional discounts.
- **Algorithm:**
  - Utilize an approach inspired by the "House Robber" problem.
  - At each step, decide whether to apply a 50% discount for two consecutive items or a 100% discount for three.
  - Maintain a dynamic table storing the minimum cost up to a given item.
- **Time Complexity:** O(N), ensuring efficient processing for large input sizes.

## Compilation and Execution
To compile the project, run:
```sh
make
```
This generates executable files corresponding to each problem. To execute a specific problem:
```sh
./servere
./compresie
./colorare
./oferta
```

## Memory Management
Each algorithm is implemented with optimal memory management techniques, ensuring that no unnecessary allocations are performed and that all dynamically allocated resources are freed appropriately.

## Summary
This project showcases a variety of **algorithmic techniques** tailored for high-performance computational problem-solving. The solutions are optimized for speed and memory efficiency, making them well-suited for handling large datasets.

