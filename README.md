# push_swap

This project has been created as part
of the 42 curriculum by atchelde & lhaydar

## Description
A random list of integers is given via command line arguments. 
We start by two empty stacks a a & b.
At the end, stack b must be empty empty and all integers must be in stack a, sorted in ascending order, using minimal number of operations.

#### Operations allowed:

- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

#### Algorithm:


## Instructions

```bash
#clone
git clone repos_url push_swap
cd push_swap

#compile
make fclean
make

#execute

```
# Resources
- [Medium article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Explanation Guide](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)