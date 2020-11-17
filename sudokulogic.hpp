void SudokuSolver::FindPositions() {
    for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(_puzzle[i][j] == 0) {
                    Position nP(i, j);
                    _positions.push_back(nP);
                }
            }
        }
}

void SudokuSolver::SolvePuzzle(vector<vector<int>> puzzle) {
        _puzzle = puzzle;
        FindPositions();
        Solve(0);
    }

void SudokuSolver::PrintPuzzle() const{
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cout << _puzzle[i][j] << " ";
        } cout << endl;
    }
}

void SudokuSolver::Solve(int p) {
    
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

bool SudokuSolver::MoveIsValid(Position p) const{
if(RowIsValid(p) &&
        BoxIsValid(p) &&
        ColIsValid(p)) {
        PrintPuzzle();
        cout << endl;
        return true;
        }
        return false;
}


bool SudokuSolver::RowIsValid(Position p) const{
vector <int> mem(10, 0);
for(int i = 0; i < 9; ++i) {
        if(_puzzle[p.row][i] != 0) {
        mem[_puzzle[p.row][i]] += 1;
        if(mem[_puzzle[p.row][i]] > 1) return false;
        }    
} return true;
}

bool SudokuSolver::ColIsValid(Position p) const{
vector <int> mem(10, 0);
for(int i = 0; i < 9; ++i) {
        if(_puzzle[i][p.col] != 0) {
        mem[_puzzle[i][p.col]] += 1;
        if(mem[_puzzle[i][p.col]] > 1) return false;
        }    
} return true;
}

bool SudokuSolver::BoxIsValid(Position p) const{
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