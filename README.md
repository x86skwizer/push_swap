# Push_Swap

This repository contains a **Push Swap** project, typically found in the **42** curriculum. The goal of the project is to sort a list of integers using two stacks (**Stack A** and **Stack B**) with the fewest possible operations.  
Additionally, this implementation includes a custom version of `printf` (located in the [`includes/`](./includes/) directory) to handle printing operations.

---

## Table of Contents
1. [Overview](#overview)  
2. [Features](#features)  
3. [Directory Structure](#directory-structure)  
4. [Compilation](#compilation)  
5. [Usage](#usage)  
6. [Available Operations](#available-operations)  
7. [Algorithm](#algorithm)  
8. [Contributors](#contributors)  

---

## Overview

The **Push Swap** program takes a set of integer arguments and outputs a sequence of operations to sort those numbers using two stacks (A and B). The sorting must be accomplished through specific push-swap operations (`sa`, `pb`, `ra`, etc.). 

Key points:
- You provide a list of integers on the command line.
- If there is any invalid input (non-integer characters, duplicates, or numbers outside the integer limits), the program prints `Error` and exits.
- The program will then output the list of operations required to sort your numbers in ascending order **in Stack A**.

---

## Features

1. **Custom `printf`**: 
   - Implemented in the [`includes/`](./includes/) directory as `ft_printf` and associated helper functions.
   - This eliminates dependencies on the standard C library's `printf`.

2. **Quicksort**: 
   - A `quicksort.c` file is provided to help with sorting the array copy (`sort_arr`), which is used internally to determine pivot elements for the push-swap algorithm.

3. **Multiple Sorting Methods**:
   - **Simple swaps** (`sa`, `sb`) for small sets (up to 5 elements).
   - **Stack-based quick sort** for larger sets (splitting chunks between Stacks A and B).

4. **Error Handling**:
   - The program checks for invalid inputs, duplicates, and out-of-range integers.  
   - Prints `"Error"` and exits if an issue is detected.

---

## Directory Structure

```
.
├── Makefile
├── includes
│   ├── ft_atoi.c
│   ├── ft_nbr_base.c
│   ├── ft_printf.c
│   ├── ft_putchar.c
│   ├── ft_putnbr.c
│   ├── ft_putstr.c
│   ├── ft_strchr.c
│   ├── ft_strlen.c
│   └── libftprintf.h
├── main.c
├── operations.c
├── operations2.c
├── push_swap.h
├── push_swap_utils.c
├── quicksort.c
├── sorting_functions.c
└── stack_quick_sort.c
```

### Notable Files

- **Makefile**: 
  - Compiles all `.c` files and produces the `push_swap` executable.  
  - Targets:
    - `make` / `make all` — Builds the `push_swap` binary.
    - `make clean` — Removes compiled object files.
    - `make fclean` — Removes object files **and** the `push_swap` executable.
    - `make re` — Cleans and rebuilds.

- **includes/libftprintf.h**:  
  Header for the custom `printf` library and utility functions.

- **push_swap.h**:  
  Header containing all structures and function prototypes for the push-swap program.

- **main.c**:  
  Main entry point. Handles parsing input arguments, allocating arrays, checking for errors, and calling the sorting routine.

- **operations.c** & **operations2.c**:  
  Implement the core stack operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, etc.).

- **push_swap_utils.c**:  
  Contains helper functions, like `ft_exit` (to exit on errors) and `integer_check` (to validate input strings).

- **sorting_functions.c**:  
  - Checks if an array is sorted (`is_sorted`).
  - Handles sorting small sets (2-5 elements).
  - Delegates to larger sorting strategies if needed.

- **stack_quick_sort.c**:  
  Implements a quick-sort–inspired approach for stacking large sets of numbers in the correct order.

- **quicksort.c**:  
  Standard quicksort function used to sort a copy of the array for pivot determination.

---

## Compilation

From the project root directory:

```bash
make
```

This will produce an executable named `push_swap`.  

Other make commands:
```bash
make clean    # Remove object files (*.o)
make fclean   # Remove object files and the push_swap executable
make re       # Equivalent to 'fclean' + 'all'
```

---

## Usage

Once compiled, you can run `push_swap` with any list of integer arguments:

```bash
./push_swap 5 2 3 1 4
```

- If the program detects invalid input or duplicates, it prints `Error` and exits.
- Otherwise, it prints a sequence of stack operations (e.g., `sa`, `pb`, `ra`, etc.) which will sort the numbers in ascending order.

**Example**:
```
$> ./push_swap 3 2 1
sa
rra
```
Above is just an illustrative example—the actual output may differ depending on your implementation.

---

## Available Operations

The program uses these operations to sort:

- **sa**: Swap the top two elements of Stack A  
- **sb**: Swap the top two elements of Stack B  
- **ss**: Perform `sa` and `sb` simultaneously  
- **pa**: Push the top element of Stack B onto Stack A  
- **pb**: Push the top element of Stack A onto Stack B  
- **ra**: Rotate Stack A (top element goes to the bottom)  
- **rb**: Rotate Stack B (top element goes to the bottom)  
- **rr**: Perform `ra` and `rb` simultaneously  
- **rra**: Reverse-rotate Stack A (bottom element goes to the top)  
- **rrb**: Reverse-rotate Stack B (bottom element goes to the top)  
- **rrr**: Perform `rra` and `rrb` simultaneously  

---

## Algorithm

1. **Small Inputs (up to 5 elements)**:
   - Handle trivial cases (2 or 3 elements) with minimal swaps.
   - For 4-5 elements, push the biggest or smallest elements to Stack B, sort the remaining, then push them back.

2. **Large Inputs**:
   - Use a quick-sort–inspired partition to split numbers (in Stack A) around a pivot.
   - Push smaller half to Stack B and sort the halves recursively.
   - Carefully rotate stacks to keep ordering correct and avoid extra moves.

3. **Pivot Strategy**:
   - A separate sorted array (`sort_arr`) is used to pick pivot values efficiently.  

---

## Contributors

- **yamrire**  
  _Original 42 project author / maintainer_  
  <yamrire@student.42.fr>  

Please feel free to submit **issues** or **pull requests** if you find any bugs or have improvements in mind!
