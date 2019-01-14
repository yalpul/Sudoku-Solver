#ifndef _UTILS_H_
#define _UTILS_H_

// gives vector with signle element
std::vector<int> singleton(int num);

// gives vector with elements 1..9
std::vector<int> fullset();

// return true if placing <num> on <i>th row and
// <j>th column violates the sudoku condition
bool violates(int i, int j, int num);

#endif
