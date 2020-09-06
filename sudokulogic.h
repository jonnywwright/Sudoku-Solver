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

class SudokuLogic {
    public:
    void SolveSudokuPuzzle(vector<vector<int>> puzzle) {
        _puzzle = puzzle;
        FindPositions();
        Solve(0);
        PrintPuzzle();
    }
    private:

    void PrintPuzzle() {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                cout << _puzzle[i][j] << " ";
            } cout << endl;
        }
    }
    void FindPositions() {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(_puzzle[i][j] == 0) {
                    Position nP(i, j);
                    _positions.push_back(nP);
                }
            }
        }
    }
    void Solve(int p) {
        
        if(p == _positions.size()) {
            solving = false;
            return;
        }
        for(int i = 1; i < 10;) {
            _puzzle[_positions[p].row][_positions[p].col] = i;
            if(MoveIsValid(_positions[p]) ) {
                int next = p + 1;
                Solve(next);
                if(!solving) return;
            }
            ++i;
            if(i == 10) {
                _puzzle[_positions[p].row][_positions[p].col] = 0;
                return;
            }
        }
    }
    
    bool MoveIsValid(Position p) {
        if(RowIsValid(p) &&
           BoxIsValid(p) &&
           ColIsValid(p)) {
            //    cout << "move is valid" << p.row << p.col <<endl;
            PrintPuzzle();
            cout << endl;
               return true;
           }
           //   cout << "not valid move" << p.row << p.col <<endl;
           return false;
    }
    bool RowIsValid(Position p) {
        vector <int> mem(10, 0);
        for(int i = 0; i < 9; ++i) {
           if(_puzzle[p.row][i] != 0) {
               mem[_puzzle[p.row][i]] += 1;
               if(mem[_puzzle[p.row][i]] > 1) return false;
           }    
        } return true;
    }

    bool ColIsValid(Position p) {
        vector <int> mem(10, 0);
        for(int i = 0; i < 9; ++i) {
           if(_puzzle[i][p.col] != 0) {
               mem[_puzzle[i][p.col]] += 1;
               if(mem[_puzzle[i][p.col]] > 1) return false;
           }    
        } return true;
    }

    bool BoxIsValid(Position p) {
        vector<int> mem(10, 0);
        int rStart = (p.row / 3) * 3;
        int rEnd = rStart + 3;
        int cStart = (p.col / 3) * 3;
        int cEnd = cStart + 3;
        for(int i = rStart; i < rEnd; ++i) {
            for(int j = cStart; j< cEnd; ++j) {
                if(_puzzle[i][j] != 0) {
                    mem[_puzzle[i][j]] += 1;
                    if(mem[_puzzle[i][j]] > 1) return false;
                }    
            }
        } return true;
    }

    private:
    vector<vector<int>> _puzzle;
    vector<Position> _positions;
    bool solving = true;
};

#endif