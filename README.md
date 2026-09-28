# DSA Assignment 2 – Organisational Hierarchy

## Assignment Question

A company organisational hierarchy is represented using a suitable tree structure. The program displays the hierarchy using level-order traversal and compares Linear Search and Binary Search for locating department names.

## Data Structures Used

* General Tree – to represent the organisational hierarchy
* Queue – used for level-order traversal
* Sorted Array – to store department names for searching

## Search Methods

* Linear Search
* Binary Search

Three department searches are performed:

* Development
* HR
* IT

## Files in This Repository

* `organisation.c` – C source code
* `input_output.txt` – Input data and program output
* `analysis.pdf` – Trace table, complexity analysis, comparison table and final conclusion

## Time Complexity

| Operation             | Time Complexity |
| --------------------- | --------------- |
| Tree Construction     | O(n)            |
| Level-order Traversal | O(n)            |
| Linear Search         | O(n)            |
| Binary Search         | O(log n)        |

## Conclusion

The general tree is suitable for representing the organisational hierarchy because it clearly shows the parent-child relationships between departments. The sorted array is suitable for searching department names, and Binary Search reduces the search range by half at each step.
