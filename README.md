# Sudoku-Solver

Simple Sudoku solver program trying to solve sudoku puzzles.

It first tries to solve by simple deductions according to sudoku condition. If it fails to solve the puzzle,
   then starts to solve using backtracking algorithm.

Normally program reads the puzzle input from stdin. The input format is described below. If an argument is given,
   it reads from the file given by argument.

The input format is a 9x9 table. 9 lines, 9 characters in each excluding newline. 0 means not known.
Below are some example inputs.

<details>
<summary>Example Inputs</summary>

```
030605000
600090002
070100006
090000000
810050069
000000080
400003020
900020005
000908030
```

```
800000000
003600000
070090200
050007000
000045700
000100030
001000068
008500010
090000400
```

```
700048000
050000024
000009001
020000050
309050006
000470030
000010040
180000690
200700000
```

```
090673200
002108043
538000017
610049500
003080762
205036090
850400370
400360801
076810020
```
</details>
