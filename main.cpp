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
		for (int j = 0; j < 9; j++)
			if (table[i][j].size() == 1)
				cout << table[i][j][0];
			else
				cout << "L";
		cout << endl;
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		std::string line;
		cin >> line;
		for (int j = 0; j < 9; j++)
			if (line[j] != '_')
				table[i][j] = singleton(line[j] - '0');
			else
				table[i][j] = fullset();
	}
	print_table();
}

