/*
Author: Jonathan Wright
Description: Contains logic needed to solve a Sudoku puzzle.
*/
#ifndef _SUDOKULOGIC_H_
#define _SUDOKULOGIC_H_
#include <iostream>
#include <vector>
using namespace std;
struct Position {
    int row;
    int col;
    Position() {}
    Position(int r, int c) {
        row = r;
        col = c;
    }
};

class SudokuSolver {

    public:
    void SolvePuzzle(vector<vector<int>> puzzle);

    private:
    void PrintPuzzle() const;
    void FindPositions();
    void Solve(int p);
    bool MoveIsValid(Position p) const;
    bool RowIsValid(Position p) const;
    bool ColIsValid(Position p) const;
    bool BoxIsValid(Position p) const;

    vector<vector<int>> _puzzle;
    vector<Position> _positions;
    bool solving = true;

};
# include "sudokulogic.hpp"
#endif