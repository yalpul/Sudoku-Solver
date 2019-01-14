#include <iostream>
#include <vector>

#include "io.hpp"
#include "utils.hpp"

using std::vector;
using std::cout;
using std::endl;

vector<int> table[9][9];

// one full pass with the current table state
// returns true if solving is finished and
// false if not
bool iterate()
{
  bool progress = false;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
    {
      if (table[i][j].size() == 1)
        continue;
      vector<int> newlist;
      for (auto num : table[i][j])
        if (!violates(i, j, num))
          newlist.push_back(num);
      if (newlist != table[i][j])
        progress = true;
      table[i][j] = newlist;
    }
  return progress;
}

bool go_over_pivots(const vector<std::pair<int,int>> &pivots, int idx)
{
  // reached the end
  if (idx == pivots.size())
    return true;
  std::pair<int,int> idxs = pivots[idx];
  int i = idxs.first, j = idxs.second;
  for (int num_i = 0; num_i < table[i][j].size(); num_i++)
  {
    int num = table[i][j][num_i];
    if (!violates(i, j, num))
    {
      vector<int> old = table[i][j];
      table[i][j] = singleton(num);
      if (go_over_pivots(pivots, idx+1))
        return true;
      else
        table[i][j] = old;
    }
  }
  return false;
}

bool solve_rec()
{
  vector<std::pair<int,int>> pivots;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (table[i][j].size() > 1)
        pivots.push_back(std::pair<int,int> {i, j});

  return go_over_pivots(pivots, 0);
}

int main(int argc, char **argv)
{
  handle_io(argc, argv);

  cout << "Trying simple rule based moves..." << endl;
  int i = -1;
  while (iterate())
    i++;
  if (i == 0)
    cout << "Simple moves didn't help." << endl;
  else
  {
    cout << "Simple moves exhausted. " << i
      << " move(s) could be made." << endl;
  }
  cout << "Attempting to solve by backtracking..." << endl;

  // backtrack
  if (solve_rec())
  {
    cout << "Solution found:" << endl << endl;
    print_table();
  }
  else
    cout << "No solution exists." << endl;
}
