#pragma once

#include <vector>
#include <string>

// puzzle.list:
// This begins with the total number of puzzles
// Each puzzle begins with height & width, followed by the cells.
// Cells are encoded as follows:
//   0 - Empty cell, not accessible by player
//   1 - Empty cell, accessible by player
//   2 - Increases note by 1
//   3 - Decreases note by 1
//   4 - Decreases note by 1
//   8 - Start position, increases note by 1
//   9 - Finish position, increases note by 1

struct Puzzle {
  int height, width;
  int start_x, start_y, end_x, end_y;
  std::vector<std::vector<int>> cells;
};

struct Puzzles {
  Puzzles(std::string const &filebase);
  ~Puzzles();

  Puzzle const &Puzzles::get_puzzle(int i) const;
  // internal data
  std::vector<Puzzle> puzzles;
};
