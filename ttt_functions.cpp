/*
ttt_functions.cpp:
  -Contains function definitions for ttt.cpp
*/

#include <iostream>
#include <vector>
#include <string>

/* 
greet():
  - Introduces player to game
*/

void greet() {

  std::cout << "=============\n";
  std::cout << " Tic-Tac-Toe \n";
  std::cout << "=============\n\n";
  std::cout << "Player 1 is X.\nPlayer 2 is O.\n\n";

}

/*
play_round():
  - Plays a single round of tic-tac-toe
  - std::vector<std::vector<char> > grid: Current ttt grid state
  - int row: Row chosen by player to place shape
  - int col: Column chosen by player to place shape
  - bool player: Player whose turn it is (true = Player 1, false = Player 2)
*/

std::vector<std::vector<char> > play_round(std::vector<std::vector<char> > grid, int row, int col, bool player) {

  // If player 1's turn...
  if(player) { grid[row][col] = 'X'; }
  else { grid[row][col] = 'O'; }
  
  return grid;

}

/*
show_grid():
    - Displays ttt grid to players
    std::vector<std::vector<char> > grid: Current ttt grid state
*/

void show_grid(std::vector<std::vector<char> > grid) {

  std::cout << "  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << "  \n";
  std::cout << "----- ----- -----\n";
  std::cout << "  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << "  \n";
  std::cout << "----- ----- -----\n";
  std::cout << "  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << "  \n\n";
  
}


/*
check_win():
    - Checks grid to see if input player win after previous round
    - std::vector<std::vector<char> > grid: Current ttt grid state
    - bool player: Player whose turn it is (true = Player 1, false = Player 2)
*/

bool check_win(std::vector<std::vector<char> > grid, bool player) {

  char player_shape;

  if(player) { player_shape = 'X'; }
  else { player_shape = 'O'; }

  // Check win across top row
  if(grid[0][0] == player_shape && grid[0][1] == player_shape && grid[0][2] == player_shape) {
    return true;
  }
  // Check win across middle row
  else if(grid[1][0] == player_shape && grid[1][1] == player_shape && grid[1][2] == player_shape) {
    return true;
  }
  // Check win across bottom row
  else if(grid[2][0] == player_shape && grid[2][1] == player_shape && grid[2][2] == player_shape) {
    return true;
  }
  // Check win in left column
  else if(grid[0][0] == player_shape && grid[1][0] == player_shape && grid[2][0] == player_shape) {
    return true;
  }
  // Check win in middle column
  else if(grid[0][1] == player_shape && grid[1][1] == player_shape && grid[2][1] == player_shape) {
    return true;
  }
  // Check win in right column
  else if(grid[0][2] == player_shape && grid[1][2] == player_shape && grid[2][2] == player_shape) {
    return true;
  }
  // Check win in left to right diagonal
  else if(grid[0][0] == player_shape && grid[1][1] == player_shape && grid[2][2] == player_shape) {
    return true;
  }
  // Check win in right to left diagonal
  else if(grid[0][2] == player_shape && grid[1][1] == player_shape && grid[2][0] == player_shape) {
    return true;
  }
  // Return no win if else
  else { return false; }

}

/*
check_input():
    - Checks validity of input move from player
    - std::vector<std::vector<char> > grid: Current ttt grid state
    - int row: Row chosen by player to place shape
    - int col: Column chosen by player to place shape
*/

bool check_input(std::vector<std::vector<char> > grid, int row, int col) {

  // Check row inputs
  if(row == 0 || row == 1 || row == 2) { }
  else {

    std::cout << "Please choose a valid row input...\n";
    return false;

  }

  // Check column inputs
  if(col == 0 || col == 1 || col == 2) { }
  else {

    std::cout << "Please choose a valid column input...\n";
    return false;

  }
  
  // Check if space already taken
  if(grid[row][col] != ' ') {

    std::cout << "That space is already filled...\n";
    return false;

  }

  // Return true if passes all checks
  return true;

}

/*
display_win():
    - std::vector<std::vector<char> > grid: Current ttt grid state
    - bool winner: Player who won the game (true = Player 1, false = Player 2)
*/

void display_win(std::vector<std::vector<char> > grid, bool winner) {

  show_grid(grid);

  if(winner == true) { std::cout << "Congratulations Player 1! You win!\n"; }
  else { std::cout << "Congratulations Player 2! You win!\n"; }

}