# Algorithms

> Algorithms is a step by step procedure for solving a computational problems.

## Algorithm vs Program

- Algorithm
	- Design phase
	- Domain knowledge
		- The one who having a knowledge about the domain for which the application is being developed need to design and construct algorithms.
	- writing in any languages
	- It's not dependent on hardware, operating system or what's machine you are going to use.
	- Analyze (time complexity, space complexity, and etc.)
- Program
	- Implementaion phase
	- Programmer do this job
	- writing in programming language
	- It's dependent on hardware and operating system.
	- Testing

## Priori Analysis & Posterior Testing

- Priori Analysis
	- Algorithm
	- Independent of language
	- Hardware Independent
	- Time * Space function
- Posterior Testing
	- Program
	- Language dependent
	- Hardware dependent
	- Watch time * Bytes

## Characteristics of Algorithm

1. Input
	- 0 or more 'i/p'.
2. Output
	- at least 1 'o/p'.
3. Definiteness
	- every steps are doing here is known step and so nothingn magical.
4. Finiteness
	- must have finite set of statements.
5. Effectiveness
	- don't do anything unnecessary.

## How to write an algorithm

You can write in any syntax with understandable steps for example:
- write a step inside block of code (`{}`) or define the word 'Begin' and 'End' at the starting and ending of steps respectively.
- assign a variable by `name = value` or `name <- value`.

## How to analyze on algorithm

1. Time -> How much time dost it use to perform a task?
2. Space -> How much memory does it use?
3. Network -> How much networks does it consume?
4. Power -> How much powers does it consume?
5. CPU Registers -> How much cpu registers does it consume?

## Asymptotic notations

Asymtotic notations are the mathematical notations used to describe the run time of an algorithm when the input towards a particular value or a limiting value.

There are mainly three asymptotic notations:
- Big-O notation -> represents the upper bound of the running time of an algorithm.
- Omega notation -> represents the lower bound of the running time of an algorithm.
- Theta notation -> represents the upper and the lower bound of the running time of an algorithm.

## Best, Worst and Average Case Analysis

There is no fix notation to show is the algorithm best-case or worst-case. Best-case and Worst-case can be written in any notations.

Note! Don't take it wrong that Big-O if for worst case or Omega if for best case.

For example:
1. Linear Search
	- Best case
		- Searching key element present at first index.
		- Best cast time is constant -> `B(n) = 1`
	- Worst case
		- Searching a key at last index
		- Worst case time is n -> `W(n) = n`
	- Average case
		- all possible case time / no. of case
		- Average time = `( 1 + 2 + 3 + ... + n ) / n = ( n + 1 ) / 2`
2. Binary Search Tree
	- Best case
		- Searching root element
		- Best case time -> `B(n) = 1`
	- Worst case
		- Searchin for leaf element
		- Worst case time is the height of binary search tree -> `W(n) = h`
			- minimum worst case is `log(n)` (balanced)
			- maximum worst case is `n` (skewed left or right)

## Disjoint Sets Data Structure - Weighted Union and Collapsing Find

1. Disjoint Sets & Operation
	- disjoint sets
		- two sets are said to be disjoint sets if they have no element in common.
2. Detecting a cycle
	- algorithms:
		1. Create a disjoint sets for each vertex of the graph.
		2. For every edge u, v in the graph.
			- Find root of the sets to which elements u and v belongs
			- If both u and v have same root in disjoint sets, a cycle is found.
3. Graphical Representation
4. Array Representation
5. Weighted Union & Collapsing Find