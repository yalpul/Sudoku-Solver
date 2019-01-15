#include <vector>
#include "utils.hpp"

extern std::vector<int> table[9][9];

std::vector<int> singleton(int num)
{
	std::vector<int> single = {num};
  return single;
}

std::vector<int> fullset()
{
	std::vector<int> fset = {1,2,3,4,5,6,7,8,9};
  return fset;
}

// return true if placing <num> on <i>th row and
// <j>th column violates the sudoku condition
bool violates(int i, int j, int num)
{
  for (int k = 0; k < 9; k++)
    if (table[i][k].size() == 1 && table[i][k][0] == num)
      return true;
  for (int k = 0; k < 9; k++)
    if (table[k][j].size() == 1 && table[k][j][0] == num)
      return true;
  int i_low_limit = i < 3 ? 0 : (i < 6 ? 3 : 6);
  int j_low_limit = j < 3 ? 0 : (j < 6 ? 3 : 6);
  int i_high_limit = i < 3 ? 3 : (i < 6 ? 6 : 9);
  int j_high_limit = j < 3 ? 3 : (j < 6 ? 6 : 9);
  for (int k = i_low_limit; k < i_high_limit; k++)
    for (int m = j_low_limit; m < j_high_limit; m++)
      if (table[k][m].size() == 1 && table[k][m][0] == num)
        return true;
  return false;
}

bool is_solved()
{
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (table[i][j].size() > 1)
        return false;
  return true;
}
