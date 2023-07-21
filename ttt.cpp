/*
Tic-Tac-Toe Project
Alexander Dickopf
June 15, 2023
*/

#include <iostream>
#include <vector>
#include "ttt_functions.hpp"

int main() {

  char player1 = 'X';
  char player2 = 'O';
  bool player1_turn = true;
  bool win = false;
  bool valid_input = false;

  std::vector<std::vector<char> > grid = { {' ', ' ', ' '}, // Top row
                                           {' ', ' ', ' '}, // Middle row
                                           {' ', ' ', ' '} }; // Bottom row
 
  greet();

  // Begin turn loop
  while(!win) {

    int row, col; // To store player input for move

    show_grid(grid);

    // Player 1's turn
    if(player1_turn){      

      // Take and validate player 1 input
      while(!valid_input) {

        std::cout << "Player 1...\nPlease choose a row: ";
        std::cin >> row;
        std::cout << "Please choose a column: ";
        std::cin >> col;

        // Check if input is legal
        valid_input = check_input(grid, row, col);

      }

      // Reset input check
      valid_input = false;

      // Update board with player 1's choice
      grid = play_round(grid, row, col, player1_turn);

      // Check if last move was a winning move
      if((win = check_win(grid, player1_turn)) == true) { win = true; }

      // Switch players' turn
      player1_turn = false;

    }

    // Player 2's turn
    else {

      // Take and validate player 2 input
      while(!valid_input) {

        std::cout << "Player 2...\nPlease choose a row: ";
        std::cin >> row;
        std::cout << "Please choose a column: ";
        std::cin >> col;

        valid_input = check_input(grid, row, col);

      }

      // Reset input check
      valid_input = false;

      // Update board with player 2's choice
      grid = play_round(grid, row, col, player1_turn);

      // Check if last move was a winning move
      if((win = check_win(grid, player1_turn)) == true) { win = true; }

      // Switch player's turn
      player1_turn = true;

    }
      //win = true; //while loop break for testing
  }

  // Display winning move and end game
  display_win(grid, player1_turn);

}