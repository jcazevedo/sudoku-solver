#include <constraint_propagation_sudoku_solver.h>

constraint_propagation_sudoku_solver::constraint_propagation_sudoku_solver()
{
}

constraint_propagation_sudoku_solver::~constraint_propagation_sudoku_solver()
{
}

void constraint_propagation_sudoku_solver::set_up_neighbours()
{
    int n = sudoku_puzzle::MATRIX_SIZE;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
        {
            affected[r][c].push_back(vector<pair<int, int> >());
            affected[r][c].push_back(vector<pair<int, int> >());
            affected[r][c].push_back(vector<pair<int, int> >());
            for (int i = 0; i < n; i++)
            {
                if (i != r)
                    neighbours[r][c].push_back(make_pair(i, c));
                if (i != c)
                    neighbours[r][c].push_back(make_pair(r, i));
                affected[r][c][0].push_back(make_pair(i, c));
                affected[r][c][1].push_back(make_pair(r, i));
            }
        }

    for (int r1 = 0; r1 < n; r1++)
        for (int c1 = 0; c1 < n; c1++)
            for (int r2 = 0; r2 < 3; r2++)
                for (int c2 = 0; c2 < 3; c2++)
                {
                    int fr = r2;
                    int fc = c2;

                    if (r1 >= 3)
                        fr += 3;
                    if (r1 >= 6)
                        fr += 3;

                    if (c1 >= 3)
                        fc += 3;
                    if (c1 >= 6)
                        fc += 3;

                    if (r1 != fr && c1 != fc)
                        neighbours[r1][c1].push_back(make_pair(fr, fc));
                    affected[r1][c1][2].push_back(make_pair(fr, fc));
                }
}

constraint_propagation_sudoku_solver::puzzle_values 
constraint_propagation_sudoku_solver::get_values(const sudoku_puzzle & puzzle)
{
    vector<int> all_values;
    puzzle_values final;

    int n = sudoku_puzzle::MATRIX_SIZE;
    for (int i = 1; i <= n; i++)
        all_values.push_back(i);

    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            final.values[r][c] = all_values;

    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
        {
            int v = puzzle.get_value(r, c);
            if (v != 0)
            {
                set_value(final, r, c, v);
            }
        }

    return final;
}

bool constraint_propagation_sudoku_solver::set_value(puzzle_values & puzzle,
                                                     int r,
                                                     int c,
                                                     int v)
{
    vector<int> current_values = puzzle.values[r][c];
    int n = current_values.size();

    for (int i = 0; i < n; i++)
    {
        if (current_values[i] != v)
        {
            bool stat = remove_from_candidates(puzzle, r, c, current_values[i]);        
            if (!stat)
                return false;
        }
    }

    return true;
}

bool constraint_propagation_sudoku_solver::remove_from_candidates(puzzle_values & puzzle, int r, int c, int v)
{
    vector<int> & current_values = puzzle.values[r][c];
    vector<int>::iterator itr = find(current_values.begin(),
                                     current_values.end(),
                                     v);

    if (itr == current_values.end())
        return true;

    current_values.erase(itr);

    if (current_values.size() == 0)
        return false;
    else if (current_values.size() == 1)
    {
        vector<pair<int, int> > nbs = neighbours[r][c];
        int n = nbs.size();

        for (int i = 0; i < n; i++)
        {
            bool stat = remove_from_candidates(puzzle,
                                               nbs[i].first,
                                               nbs[i].second,
                                               current_values[0]);
            if (!stat)
                return false;
        }
    }

    vector<vector<pair<int, int> > > afs = affected[r][c];
    int n = afs.size();
    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int> > remaining;
        int nn = afs[i].size();
        for(int j = 0; j < nn; j++)
        {
            if (find(puzzle.values[afs[i][j].first][afs[i][j].second].begin(),
                     puzzle.values[afs[i][j].first][afs[i][j].second].end(),
                     v) !=
                puzzle.values[afs[i][j].first][afs[i][j].second].end())
                remaining.push_back(afs[i][j]);
        }

        if (remaining.size() == 0)
            return false;
        else if (remaining.size() == 1)
        {
            bool stat = set_value(puzzle,
                                  remaining[0].first,
                                  remaining[0].second,
                                  v);
            if (!stat)
                return false;
        }
    }

    return true;
}

bool constraint_propagation_sudoku_solver::solved(const puzzle_values & puzzle)
{
    int n = sudoku_puzzle::MATRIX_SIZE;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (puzzle.values[i][j].size() > 1)
                return false;
    return true;
}

bool constraint_propagation_sudoku_solver::solve_aux(puzzle_values & puzzle)
{
    if (solved(puzzle))
        return true;
    
    int n = sudoku_puzzle::MATRIX_SIZE;
    int m = 10;
    int r = 0;
    int c = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((int) puzzle.values[i][j].size() < m &&
                puzzle.values[i][j].size() > 1)
            {
                m = puzzle.values[i][j].size();
                r = i;
                c = j;
            }

    puzzle_values new_puzzle = puzzle;
    vector<int> & values = puzzle.values[r][c];
    int vn = values.size();
    for (int i = 0; i < vn; i++)
        if (set_value(new_puzzle, r, c, values[i]) && solve_aux(new_puzzle))
        {
            puzzle = new_puzzle;
            return true;
        }

    return false;
}

bool constraint_propagation_sudoku_solver::solve(sudoku_puzzle & puzzle)
{
    set_up_neighbours();
    puzzle_values values = get_values(puzzle);

    if (solve_aux(values))
    {
        int n = sudoku_puzzle::MATRIX_SIZE;
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++)
                puzzle.set_value(r, c, values.values[r][c][0]);
        return true;
    }

    return false;
}
