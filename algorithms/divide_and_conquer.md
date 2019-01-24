# Divide-and-conquer
 break the problem into subproblems that are similar to the original problem but smaller in size.


## STEPS
 1. **Divide** the problem into a number of subproblems that are smaller instances of the same problem.

 2. **Conquer** the subproblems by solving them recursively. If the subproblem sizes are small enough, however, jsut solve the subproblems in a straightforward manner.

 3. **Combine** the solutions to the subproblems into the solution for the original problem.
 

### In **Merge Sort**

1. Divide: Divide the n-element sequence to be sorted into two subsequences of n/2 elements each.
2. Conquer: Sort the two subsequences recursivey using merge sort.
3. Combine: Merge the two sorted subsequences to produce the sorted answer.
