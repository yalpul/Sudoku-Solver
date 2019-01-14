#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

vector<int> table[9][9];

vector<int> singleton(int num)
{
	vector<int> single = {num};
	return single;
}

vector<int> fullset()
{
	vector<int> fset = {1,2,3,4,5,6,7,8,9};
	return fset;
}

void print_table()
{
	for (int i = 0; i < 9; i++)
	{
    if (i > 0 && i % 3 == 0)
      cout << "---------------" << endl;
		for (int j = 0; j < 9; j++)
    {
      if (j > 0 && j % 3 == 0)
        cout << " | ";
			if (table[i][j].size() == 1)
				cout << table[i][j][0];
			else
				cout << "0";
    }
		cout << endl;
	}
  cout << endl;
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
	if (idx == pivots.size())
	{
		print_table();
		return true;
	}
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
}

void solve_rec()
{
	vector<std::pair<int,int>> pivots;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (table[i][j].size() > 1)
				pivots.push_back(std::pair<int,int> {i, j});

	go_over_pivots(pivots, 0);
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		std::string line;
		cin >> line;
		for (int j = 0; j < 9; j++)
			if (line[j] != '0')
				table[i][j] = singleton(line[j] - '0');
			else
				table[i][j] = fullset();
	}
	int i = 0;
	while (iterate())
	{
		cout << ++i << ". move\n";
		print_table();
	}
	// backtrack
	solve_rec();
}
