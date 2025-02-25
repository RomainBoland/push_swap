# Push_Swap

A highly efficient sorting algorithm project written in C. This project sorts a stack of integers using a limited set of operations with the goal of minimizing the number of operations required.

## Table of Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Operations](#operations)
- [Project Structure](#project-structure)
- [Examples](#examples)
- [Performance](#performance)

## Overview

Push_swap is a sorting algorithm project that uses two stacks (A and B) and a set of specific operations to sort data. The goal is to sort all integers in stack A in ascending order using the minimum number of operations.

## Requirements

- GCC compiler
- Make
- C standard libraries

## Installation

Clone the repository and compile the project:

```bash
git clone git@github.com:RomainBoland/push_swap.git
cd push_swap
make
```

This will create an executable named `push_swap`.

## Usage

```bash
./push_swap [integers]
```

The program takes a list of integers as arguments and outputs the series of operations needed to sort them.

Example:
```bash
./push_swap 5 2 3 1 4
```

The program will display a list of operations that, when applied in order, will sort the stack.

## Algorithm

The project implements different sorting strategies based on the number of integers:

- For 2 numbers: Simple swap if needed
- For 3 numbers: Optimized algorithm with a maximum of 2 operations
- For 4-5 numbers: Simple algorithm using both stacks
- For larger sets: Optimized algorithm using cost calculation to determine the most efficient moves

For large sets, the algorithm:
1. Keeps the 3 smallest numbers in stack A and pushes the rest to stack B
2. Sorts the 3 numbers in stack A
3. For each number in stack B, calculates the cost to put it in the correct position in stack A
4. Moves the cheapest node from B to A until B is empty
5. Rotates stack A until the smallest number is at the top

## Operations

The allowed operations are:

- `sa`: Swap the first two elements of stack A
- `sb`: Swap the first two elements of stack B
- `ss`: Perform `sa` and `sb` simultaneously
- `pa`: Push the top element from stack B to stack A
- `pb`: Push the top element from stack A to stack B
- `ra`: Rotate stack A upward (first element becomes last)
- `rb`: Rotate stack B upward
- `rr`: Perform `ra` and `rb` simultaneously
- `rra`: Rotate stack A downward (last element becomes first)
- `rrb`: Rotate stack B downward
- `rrr`: Perform `rra` and `rrb` simultaneously

## Project Structure

```
push_swap/
├── includes/
│   └── push_swap.h      # Main header file
├── libft/               # Custom C library
├── src/
│   ├── check_param/     # Input validation
│   ├── error_handling/  # Error management
│   ├── stack_ops/       # Stack operations implementation
│   └── utils/           # Utility functions and sorting algorithms
├── main.c               # Program entry point
└── Makefile             # Build configuration
```

## Examples

Sorting a small list:
```
$ ./push_swap 3 2 1
ra
sa
```

## Performance

The algorithm is designed to meet the following performance requirements:

- 3 numbers: Maximum 2 operations
- 5 numbers: Maximum 12 operations
- 100 numbers: Less than 700 operations (optimal range: 600-700)
- 500 numbers: Less than 5500 operations (optimal range: 5000-5500)

## Author

Romain Boland - [GitHub](https://github.com/RomainBoland)

