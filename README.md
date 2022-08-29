# Sort two stacks: push_swap project

Writing a sorting algorithm is always a very important step in a developer’s journey. It
is often the first encounter with the concept of complexity.

The learning objectives of this project are rigor, use of C, and use of basic algorithms.
Especially focusing on their complexity.
Sorting values is simple. To sort them the fastest way possible is less simple. Especially
because from one integers configuration to another, the most efficient sorting solution can
differ.
- There are 2 stacks: A and B.
- A is filled with some random integers (without duplicates) and B is empty.
- A limited set of instructions on these stacks are allowed and the goal is to sort all integers using the lowest possible number of actions.
- The limited set of instructions are:

| Operation | Description |
| ------------ | ------------ |
| `sa` | swap A - swap the first 2 elements at the top of stack A |
| `sb` | swap B - swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | push A - take the first element at the top of b and put it at the top of A |
| `pb` | push B - take the first element at the top of a and put it at the top of B |
| `ra` | rotate A - shift up all elements of stack A by 1. The first element becomes the last one |
| `rb` | rotate B - shift up all elements of stack B by 1. The first element becomes the last one |
| `rr` | `ra` and `rb` at the same time |
| `rra` | reverse rotate A - shift down all elements of stack A by 1. The last element becomes the first one |
| `rrb` | reverse rotate B - shift down all elements of stack B by 1. The last element becomes the first one |
| `rrr` | `rra` and `rrb` at the same time |

## Running ##

```bash
# Clone this project
$ git clone https://github.com/smkatash/push_swap

# Access
$ cd push_swap

# Compile the program
$ make

# Run the project
$ ./push_swap 8 6 2 4

```


Summary: 
This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed it is necessary to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.


<img width="276" alt="image" src="https://user-images.githubusercontent.com/76934648/187190669-d7f2775d-bf3f-4c50-90be-1ba5b3538ae7.png">
