/*
ttt_functions.hpp:
  -Contains function declarations for ttt.cpp
*/

#include <vector>

void greet();
std::vector<std::vector<char> > play_round(std::vector<std::vector<char> > grid, int row, int col, bool player);
void show_grid(std::vector<std::vector<char> > grid);
bool check_win(std::vector<std::vector<char> > grid, bool player);
bool check_input(std::vector<std::vector<char> > grid, int row, int col);
void display_win(std::vector<std::vector<char> > grid, bool winner);