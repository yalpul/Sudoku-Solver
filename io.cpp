#include <iostream>
#include <vector>
#include <fstream>
#include "io.hpp"
#include "utils.hpp"

extern std::vector<int> table[9][9];

void print_table()
{
  for (int i = 0; i < 9; i++)
  {
    if (i > 0 && i % 3 == 0)
      std::cout << "---------------" << std::endl;
    for (int j = 0; j < 9; j++)
    {
      if (j > 0 && j % 3 == 0)
        std::cout << " | ";
      if (table[i][j].size() == 1)
        std::cout << table[i][j][0];
      else
        std::cout << "0";
    }
		std::cout << std::endl;
  }
	std::cout << std::endl;
}

void read_from_file(char *filename)
{
	std::ifstream file_handle;
	file_handle.open(filename);
	if (!file_handle.is_open())
	{
		std::cerr << "File couldn't be opened!" << std::endl;
		exit(1);
	}

  for (int i = 0; i < 9; i++)
  {
    std::string line;
    file_handle >> line;
    for (int j = 0; j < 9; j++)
      if (line[j] != '0')
        table[i][j] = singleton(line[j] - '0');
      else
        table[i][j] = fullset();
  }
	file_handle.close();
}

void handle_io(int argc, char **argv)
{
	// read from file
	if (argc == 2)
	{
		read_from_file(argv[1]);
		return;
	}

	// read from stdin
  for (int i = 0; i < 9; i++)
  {
    std::string line;
		std::cin >> line;
    for (int j = 0; j < 9; j++)
      if (line[j] != '0')
        table[i][j] = singleton(line[j] - '0');
      else
        table[i][j] = fullset();
  }
}
