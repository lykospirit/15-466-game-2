#include "Puzzles.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cassert>

Puzzles::Puzzles(std::string const &file) {
  std::string puzzles_path = file;
  std::ifstream in(puzzles_path, std::ifstream::in);

  int puzzle_count, height, width, cell;
  in >> puzzle_count;
  for (int i=0; i<puzzle_count; i++){
    Puzzle p;
    in >> height >> width;
    p.height = height; p.width = width;
    p.cells.resize(height);
    for (int j=0; j<height; j++){
      for (int k=0; k<width; k++){
        in >> cell;
        p.cells[j].push_back(cell);
        if (cell == 8) { p.start_x = j; p.start_y = k; }
        if (cell == 9) { p.end_x = j; p.end_y = k; }
      }
    }
    puzzles.push_back(p);
  }

  in.close();
}

Puzzles::~Puzzles(){}

Puzzle const &Puzzles::get_puzzle(int i) const {
  if (i >= puzzles.size()){
    throw std::runtime_error("Puzzles::get_puzzle(): index out of bounds.");
  }
  return puzzles[i];
}
