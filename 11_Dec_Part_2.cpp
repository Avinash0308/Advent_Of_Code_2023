#include <bits/stdc++.h>
using namespace std;

void get_input(vector<string> &input);

int main()
{
    vector<string> input;
    get_input(input);
    int n = input.size(), m = input[0].size();
    vector<int> row(n, 1), col(m, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (input[i][j] == '#')
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    int r = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        if (row[i])
        {
            r++;
        }
        int c = 0;
        for (int j = 0; j < m; j++)
        {
            if (col[j])
                c++;
            if (input[i][j] == '#')
            {
                v.push_back({i + r*(1e6-1), j + c*(1e6-1)});
            }
        }
    }
    long long int tot = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            tot += (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second));
        }
    }
    cout << tot << endl;
    return 0;
}

void get_input(vector<string> &v)
{
    v = {"........................................#........#.............#............#.........#................................................#....",
         "....#.............................................................................................................................#.........",
         "....................#...................................#......................................#.........................#..................",
         "............................................................................................................................................",
         "#..........#.....................#...............................................................................#..........................",
         "......................................................................................................#.....................#...............",
         "........................#..................................#.............................#..................................................",
         "............................................#.........................#..........#............#.........................#...............#...",
         "...#..........................#.......................#......................................................#..............................",
         "............#...............................................................................................................................",
         "..................................................................................................#.........................................",
         ".........................#..................................................#...............................................................",
         ".....................................#..............................................#..................#...................#................",
         "...............................................#.......................#....................................#...............................",
         "..#...............................................................#...............................................................#.........",
         "..................#.............................................................#.........#........................#........................",
         ".......................................#..............#......#..............................................................................",
         ".............................#........................................................#.........#.............................#.............",
         "...................................#....................................................................#................#...............#..",
         "...#........................................#...............................................................................................",
         "........................................................................#..................#................................................",
         "...........#........................................................................#...............................#.......#...............",
         "................#...........................................#..............................................#................................",
         "............................................................................................................................................",
         "......................#.......#.........#.........#................#...................................#..............................#.....",
         ".........#....................................................................#.............................................................",
         "..................................#..........#............#..............#..................#......#........................................",
         "............................................................................................................................................",
         "...................................................................................#..............................#.............#...........",
         "#..........................#........................#...........................................#...........................................",
         "............................................................................................................................................",
         ".....#.......#......#.........................................#.......#.................#...............#..................#................",
         "..............................................................................#.............................................................",
         ".........#.............................#............................................................#.......................................",
         ".....................................................#.......................................#.................#............................",
         "......................#...........................................#..................................................#..................#...",
         "..............#..........................................#.........................#........................................#...............",
         "..........................#.....................#................................................................................#..........",
         "..........................................................................................................#................................#",
         ".......................................#............#...................................#...................................................",
         "#...............#............................................#....................................................#.........................",
         "............................#..................................................................................................#............",
         "............#.........#.................................#.....................#.............................................................",
         "......................................................................................................#.....................................",
         "...#......................................#.........................#.......................................#..............#......#.....#...",
         "..............................................................................................#.............................................",
         "................#.............#.....................#...........................#...........................................................",
         "............................................................................................................................................",
         ".#......#.......................................#...........................................................................................",
         ".............#..........................#........................#..........#....................#..........................................",
         "............................................................................................................................................",
         "............................................................................................................................................",
         "..........................#........#.................................................................#.........................#............",
         "...#.......#..................................................#......................................................................#......",
         "................#...........................................................................................................................",
         "..........................................#............#.......................................................#............#.............#.",
         "............................................................................................................................................",
         "...................#........#....................#...................................#.............................#........................",
         "............................................................................................................................................",
         "............................................................................................................................................",
         "..............#.........#............................#.............#..............#....................#....................................",
         "......................................#.....#............................................................................................#..",
         "......#...........#...........#.........................................#........................#..........................................",
         ".............................................................................................................#........#.....................",
         "..............................................................#...............................................................#.............",
         "..................................#..............#......................................#...................................................",
         "............................................................................................................................................",
         ".............#..............................#..................................................#............................................",
         "...#.................#.................................................#..............................#.....................................",
         "............................................................................................................................................",
         "............................#..........#................#.......................#.................#..........#..............................",
         "...............................................#..................................................................................#.........",
         "..........#........................#........................................................................................................",
         "......................#................................................................................#....................................",
         "#............................................................................................#..........................#................#..",
         ".................#..............#.......#..........#.........................#..................................#...........................",
         "..................................................................#.....#........................#...............................#..........",
         ".........#....................................#............................................................#..........................#.....",
         "..#.........................................................................................................................................",
         "............................................................................................................................................",
         "....................#........................................#.......................#......................................................",
         ".............................#.............................................................#.........#............#.........#.......#.......",
         "..........................................#............#....................................................................................",
         "............................................................................................................................................",
         ".#...............#....................................................#..........#.............................................#............",
         "............#......................................#.....................................#........#.................#.......................",
         "......#.................#........#.....................................................................#...................#................",
         "........................................#......#...............................................................#.......................#....",
         "............................................................................................................................................",
         "..................................................................#.....#...................................................................",
         ".............#............................................................................................#...............................#.",
         "............................................................................................................................................",
         "............................#........................................................................................#.........#............",
         "......................................................#.....................#.................#.............................................",
         ".......................................#................................................#...................................................",
         "............................................#...............................................................................................",
         ".#..............#..................#..............#.............#..............................................#.....................#......",
         "..........................................................#............#...................................................#................",
         "........................#........................................................#..........................................................",
         "....#..............................................................#........#.........#.....................................................",
         "............................#...................................................................#...........................................",
         "........................................#....................................................................#..........#...................",
         "................................#............#..............................................#...............................................",
         "..#......................................................#......#.................................................#...................#.....",
         "...................#...................................................................................#....................................",
         ".............#....................................#..........................................................................#.............#",
         "........#.................................................................#.....#...............#...........................................",
         "..........................................#............#..................................#...............#.................................",
         "......................................................................................................................#.....................",
         ".................................#...................................................#..............................................#.......",
         ".................................................#..........#...............#..............................................#................",
         "#.....#.................#...........................................#.............................#.............#...........................",
         ".................#..........................................................................................................................",
         "........................................................................#.....................#........#.................................#..",
         "..........#...................#..........................#........................................................................#.........",
         "....................................#...........................#.........................................................#.................",
         "..........................#..................#.....................................#........................................................",
         ".....#................................................#..............................................#........#.............................",
         ".............#......................................................#................................................................#......",
         "....................#............#..............#...............................#...............#.........................................#.",
         "...........................................................................................#..............#......#..........................",
         "#..........................................................#................#.........................................#.....................",
         ".........................................#..................................................................................................",
         "......................#..............................#..................................................................................#...",
         "...#..........#....................#..........#...................................#...............................................#.........",
         ".........................................................#..............#...................................................#...............",
         "............................#....................................#.................................#...............#........................",
         "........................................................................................................................#...................",
         ".#...................#......................................................#............#...........................................#.....#",
         "............#.....................................#.........#.........#.....................................................................",
         ".............................................................................................#................#.............................",
         ".................................#.........#............#.......................................................................#...........",
         "...............#.......#.................................................................................#..................................",
         ".................................................................#.......................................................#..........#.......",
         "............................................................................................................................................",
         "............#.....#.........#...............................#..............................#......#..........#..............................",
         ".......................................................#............................#.......................................................",
         "................................#..................................#...................................................#....................",
         "............................................#......#......................#..........................................................#......",
         ".#..............................................................................................#..................#........................"};
}