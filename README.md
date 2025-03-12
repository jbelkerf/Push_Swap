
# Push Swap

**Author**: jbelkerf (Jaouad Belkerf)

## Project Description

The Push Swap project is a sorting algorithm challenge where the objective is to sort a stack of integers using a limited set of operations. The project is part of the 42 curriculum and tests both algorithmic knowledge and mastery of system-level programming in C.

The goal of the project is to implement a program that sorts a list of numbers using two stacks (A and B), without using any library functions other than the standard C library. The sorting is done through a series of moves that involve pushing, popping, swapping, and rotating the stacks.

## Files

### Source Files

- **gnl**: A folder containing the Get Next Line project, used here to handle line-by-line input reading.
- **libft**: The custom library that includes helper functions.
- **operations**: Contains the operations that manipulate the stacks (push, swap, rotate, etc.).
- **Makefile**: The Makefile used to build the project.
- **check_errors.c / check_errors.o**: Functions for error checking during stack operations.
- **checker.c / checker.o**: The checker program for verifying the result of stack operations.
- **count_moves.c**: A function to count the number of moves made during sorting.
- **header.h**: Header file containing function prototypes and necessary definitions.
- **parce_it.c / parce_it.o**: Functions for parsing the input and handling edge cases like empty arguments.
- **push_swap.c / push_swap.o**: Main sorting algorithm for Push Swap.
- **set_sorted_index.c / set_sorted_index.o**: Adds a sorted index to each element in the stack for efficient sorting.
- **sort_the_stack.c / sort_the_stack.o**: Implements the logic to sort the stack with minimal moves.
- **test.sh**: A script to test and validate the program.
- **tools.c / tools.o**: Helper functions used throughout the project.

### Checker

The project includes a checker program that verifies if the sorting operations have been applied correctly by simulating the movements performed by your sorting algorithm.

### Error Handling

The project also includes robust error handling to ensure that invalid operations or incorrect inputs are caught early, preventing crashes or undefined behavior.

## Compilation

To compile the project, simply run:

```bash
make
```

This will compile all necessary files and create the executables `push_swap` and `checker`.

## Usage

### Sorting with `push_swap`:

```bash
./push_swap <numbers>
```

Where `<numbers>` is a list of integers to be sorted.

### Verifying with `checker`:

```bash
./checker <numbers> <operations>
```

Where `<numbers>` is the list of integers, and `<operations>` is a series of operations (e.g., `sa`, `pb`, etc.) that will be checked against the `push_swap` output.

## License

This project is licensed under the MIT License.
