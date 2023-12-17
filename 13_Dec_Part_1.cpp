#include <bits/stdc++.h>
using namespace std;

vector<string> get_input();
long long int solve(vector<string> &s);
bool check_ver(vector<string> &s, int x, int y);
bool check_hor(string &a, string &b);

int main()
{
    vector<string> input = get_input();
    long long int ans = 0;
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        vector<string> cur;
        while (i < n && input[i].size())
        {
            cur.push_back(input[i]);
            i++;
        }
        ans += solve(cur);
    }
    cout << ans << endl;
    return 0;
}

long long int solve(vector<string> &s)
{
    int n = s.size();
    int m = s[0].size();
    for (int i = 0; i < m - 1; i++)
    {
        int x = i, y = i + 1;
        bool pos = true;
        while (pos && x >= 0 && y < m)
        {
            pos = check_ver(s, x, y);
            x--, y++;
        }
        if (pos)
            return i + 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x = i, y = i + 1;
        bool pos = true;
        while (pos && x >= 0 && y < n)
        {
            pos = check_hor(s[x], s[y]);
            x--, y++;
        }
        if (pos)
            return (i + 1) * 100;
    }
    return 0;
}

bool check_hor(string &a, string &b)
{
    return a == b;
}

bool check_ver(vector<string> &s, int x, int y)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i][x] != s[i][y])
            return false;
    }
    return true;
}

vector<string> get_input()
{
    vector<string> input = {"#.#.##.##.#", "#..#..####.", "#.#####..##", "#.##..####.", "##.#..####.", "..#...#..#.", "##...#....#", "....##....#", "##.##.#..#.", "#..#.##..##", "##.###.##.#", "...#.#.##.#", ".#.#.#.##.#", "##.###.##.#", "#..#.##..##", "", "##.#...#.#.", "##.##..#.#.", ".#.##......", "..######..#", "..######..#", ".#.##......", "##.##..#.#.", "##.#...#.#.", "...##...#..", "...#.###..#", "#..#######.", "..#.##.###.", "..###.##.#.", "..##.##.##.", "..#.#..##..", "", "#.....###..###.", ".###....#..#...", ".#..#.#..##..#.", "##.##.#..##..#.", ".#....#.#..#.#.", ".###.#..#..#..#", "#.###..######..", "#..#...######..", "..#.##.##..##.#", "..#.##.##..##.#", "#......######..", "", ".##.#######", ".##....##.#", "#..#.#.#.##", "#####....##", "####.....##", "#..#.#.#.##", ".##....##.#", ".##.#######", "####.#.###.", "#..#####..#", "......#####", "........###", "#..###.###.", "", "#..##..", "#..#...", "###.#..", "##..###", "####.##", "..#.#..", "..#.###", ".##.##.", ".##.##.", "..#.###", "..#.#..", "", "##.##.#####", "#.####.#.##", "..#..#....#", "#########..", "########.##", "...##...#.#", ".#....#...#", "########..#", "..####.....", "#......###.", "#......###.", "..####.....", "########..#", ".#....#...#", "...##...#..", "########.##", "#########..", "", "...#.#..#....#.", "#.##..##.####.#", ".##.#.##.#..#.#", "#.#.#..##.##.##", "..#.######..###", "...#.###......#", ".##...##......#", "##..#.##.####.#", ".###......##...", "##..#..#..##..#", "####.#..##..##.", ".###..#.######.", "#....##...##...", "#.....#...##...", ".###..#.######.", "", "#..####", ".##.#..", ".##.#.#", "#..####", "#..####", ".##.#.#", ".##.#..", "#..####", ".##...#", "#..###.", "..###..", "", "##.##.....#.#", "##.##.......#", "......#.##...", "##.#.#..#.#..", "##.#..#######", "##...###..#..", "##.##.#..#.##", "####.#...#..#", "###.....####.", "...##....#...", "...##.#.##.##", "....#..#...##", "###...#......", "", "#####.##..#", "#.#..######", ".#.#...####", ".#.#...####", "#.#..######", "###.#.##..#", "...#.######", "##.#...####", "....#..####", ".#.#....##.", ".....#.#..#", "", ".#....#.#..##", ".#....#....##", "..#..#.......", ".##..##...###", "##########..#", ".#.##.#.###.#", "..#..#...#.##", "#.####.##..#.", ".#....#..##..", "#......###.##", ".#.##.#..###.", "...##...####.", ".#....#...#..", "##.##.####.##", "##....##...##", "#.####.####..", "###..#####.##", "", ".##.####....#", ".##.#..####.#", "#####...#.###", ".......#.....", "####.#...##..", ".##....####.#", ".##....######", ".##....######", ".##....####.#", "####.#...##..", ".......#.....", "#####...#.###", ".##.#..####.#", ".##.####....#", ".###..#...##.", "", "#####.#.#.#..#.#.", "#..###.###.##.###", "....#...#..##..#.", "#..####..#....#..", "#..###..#.####.#.", "#####.#.#..##..#.", "#####.#.#####.##.", ".##..###..####..#", "#..#.#..########.", "#..##.#####..####", "####...#..#..#..#", "", "########.....", "...##.....##.", ".........####", "#.#..#.#####.", "#.#######..#.", "#.####.#.#..#", "###..#####.#.", "#.#..#.#..##.", "..####....#.#", "..####...#...", "#.#..#.#.#..#", "#.####.#.....", "#.####.#.....", "", "###....#.##.#.#", "..#....#....###", "#####.#..#.#.##", "##.#.#..##..#..", "..###..##...#..", "#####.##...####", ".....#...##.##.", "###....####..##", "##.###.##.###..", "..##.####.#...#", "###.##...#..###", "..##.#..##.#...", "..##.##.##.#...", "###.##...#..###", "..##.####.#...#", "", ".#......#.#######", "............####.", "....##.....##..##", ".###..###........", "....##....#..##..", "##.#..#.##.######", "...####...#######", "..######..##.##.#", ".########..#.##..", "###....#####.##.#", "#...##...##......", "...#..#...#..##..", "##.####.##.......", ".##....##.#..##..", "#.##..##.#.#.##.#", ".#.#..#.#.##.##.#", ".##.##.##.##.##.#", "", "....#.#.#..#.#.", "####.#..#.#.#..", "#..##.#.#..####", "####..###......", "....###.#.###..", "....#.##....#.#", "#..##.###.####.", "....##.#...#...", "#..#.#.#.#..###", "####.#.#...##..", "####.#.#...##..", "#..#.#.#.#..#.#", "....##.#...#...", "#..##.###.####.", "....#.##....#.#", "....###.#.###..", "####..###......", "", "..#####....#####.", "##..##########..#", ".##.#..####..#.##", "..######..######.", "..######..######.", ".##.#..####..#.##", "##..##########..#", "..#####....#####.", ".....########....", "..#..##....##..#.", ".###.##.##.##.###", ".#.#####..#####.#", "..#....#..#.#..#.", "", ".###.##.###", ".###.##.###", "####....#.#", "#...####...", "####....###", ".#...##...#", "..###..###.", "#..#.##.#..", "#....##....", "", "#.#.#.#....#.", "###..##.##.##", "...##.#....#.", "..##.#.####.#", "##.#.#.#..#.#", ".#..##..##..#", "#.#...#....#.", "...##.#....#.", "...##.#....#.", "#.#...#....#.", ".#...#..##..#", "##.#.#.#..#.#", "..##.#.####.#", "", "#......", ".#.####", "#.#####", ".##...#", "..#....", "###.##.", "##.####", ".#..##.", ".##....", "##..##.", "##..##.", "", "##..#.#..#..###", "##.#......#....", "####....#.#####", ".#.##.##.......", "#..#.#..####..#", "#..#.#..####..#", ".#.##.##.......", "", ".#..###.#", "..#...##.", "#####.#.#", "....#.###", "#.###.#.#", "###.####.", "##..#..#.", ".#.#.....", ".#.#.....", "##..#..#.", "###.####.", "#.###.#.#", "....#.###", "#####...#", "..#...##.", ".#..###.#", ".#..###.#", "", "#.#.#.....###.##.", "#.#.#.....###.##.", "#...#.#.#####..#.", "..#....#.####....", "#.#.##.##..###..#", "#.#....#.#.#.####", ".##.#####........", ".#.#.##..#####..#", ".#.......#.######", "..##.###.##.#####", "####.#..##..#....", "##..#.#.##.##.##.", "#.#..#.#....##..#", "", "#...#.####.#.#.##", "#..#.#.#..##..#.#", ".###...###..#....", "####..###.###..##", "##..##...###.##..", "#.#.##.##..#.#..#", "#.#.##.##.##.#..#", ".##.#.##...###...", ".##.#.##...###...", "#.#.##.##.##.#..#", "#.#.##.##..#.#..#", "", "..........##.", ".##.#.#.####.", "####..###.###", "####.#..#..##", ".##.##.#...#.", "....####...#.", ".##...###..##", "####.###.#.##", "....###.#...#", "#..#.##....#.", "#..#.##.#..#.", "", ".###...#.....", ".###...#.....", "..####.#####.", "...#.##.##.##", "#.###...###..", "####.#.#.###.", "#.#.#.##...##", "#.#.#.##...##", "####.###.###.", "#.###...###..", "...#.##.##.##", "..####.#####.", ".###...#.....", "", ".###..#.#", ".#.#..#.#", ".#.###..#", "##....###", "##....###", ".#.###..#", ".#.#..#.#", ".###..#.#", "..###.#.#", ".##.#.#.#", "####..###", "###..##.#", "#.#.###.#", "###..####", "#.#.#.#.#", "......#..", "#..#####.", "", "#...#..#..###..##", ".#.##.#.##.......", ".##.#.#...#......", "#..#.#...###.##.#", "#.#...###.#######", "####.##..#...##..", "##..#.####.######", "..#.#..#.####..##", "...######.###..##", "####....###......", ".#####.#.##..##..", ".##..#..#........", "####...###...##..", "", "###.##..#", "###.##..#", "###.####.", "##..#####", "#....#..#", "#..##.##.", "..#..####", "", "####......#######", "####..##..#######", ".##.#.##.#.##..##", "###...##...######", "..##..##..##.....", ".#..#....#..#..#.", "####..##..#######", "#..###..###..##..", ".####.##.####..##", ".#..........#..#.", "#..#..##..#..##..", "", "....#..#..#..#..#", "....#..#..#..#..#", "#.#.#.###.#..#.##", "..#..###...##...#", ".#......##....##.", "##..#...#.#..#.#.", "#.#######.##.#.##", "##...##.#..##..#.", "####..#..######..", ".##..#..##.##.##.", "...#...#..####..#", "#####.###......##", ".#####.#.######.#", ".#.....#.#.##.#.#", ".###.......##....", ".#...#....#..#...", ".#.#..##..#..#..#", "", "###...###", "..#.#.#..", "#.#...#.#", "###.#.#.#", "...##.#..", "####..#.#", "..#..#..#", "###....#.", "....#.#..", "....#.#..", "###....#.", "", "..#..###.##", "##.##.###..", "..##....##.", "..##..##.##", "##..##.####", "#####.#....", "##.#....###", "", ".#.#.##.#..", "#....#.##..", "#.#.###.###", "#.##.###.##", ".#.##...###", "#..........", "...##....##", "#...#......", "###.#.#....", "###.#.#....", "#...#......", ".#.##....##", "#..........", ".#.##...###", "#.##.###.##", "", "..####...#.####.#", "#......##..#..#..", "#.#..#.#####..###", "##....#####.##.##", "..####......##..#", "..#..#..#.#.##.#.", "#..##..##.######.", "..####..###....##", "###..#######..###", ".#.##.#.#..#..#..", ".######.##.#..#.#", "", "..##..###..", "..#####....", "...#.#.#.##", "...#.#.####", "..#####....", "..##..###..", "##......##.", "##.#..#.###", "###..##....", "...##..##.#", "##.###.#.#.", "###.#.#....", "..##...#..#", "####.###.##", "....#..#.##", "", "#....##....", "..##....##.", "#.##....##.", ".#...##...#", "#..........", "#####..####", "#....##....", "", "..#..#.", "##.#.##", "#..#...", "#...##.", "...#...", "...#...", "#...##.", "#..#...", "##.#.##", "..#..#.", "....#..", "#.#..##", "##....#", "...#...", "...##..", "", ".####.####.", ".###.......", "..#####..##", "...#.##..#.", "#.#.###..##", ".#..##....#", "..#....##..", "#.#.#.#..#.", "#.#.#.#..#.", "", "...#..####....#..", "....#.###...##...", "###....#...#.#...", "...###...##....##", "##.##..#..###.#..", "#..#.#...#.#...##", "..#....#...#..#..", "..#....#...#..#..", "#....#...#.#...##", "##.##..#..###.#..", "...###...##....##", "###....#...#.#...", "....#.###...##...", "...#..####....#..", "....#..###.#..###", "#.....###....##..", "....####....##...", "", "#.#.#.#..#.#...#.", "#..#.#.#..#...###", "##.#..#.#.....#.#", "###..#..#..#...##", "##..#....#...#.#.", ".##.#....#...##..", ".##......#...##..", "##..#....#...#.#.", "###..#..#..#...##", "##.#..#.#.....#.#", "#..#.#.#..#...###", "#.#.#.#..#.#...#.", ".####...#..##.#..", "####.##.#####.##.", ".####.#####..#.#.", "#...###.......###", "#...###.......###", "", ".#.##.#..##...#", "###..###.##.#..", "#.####.##..#.##", "#.#..#......#..", "#.#..#......#..", "#.####.##..#.##", "###..###.##.#..", "", "...#.##.##.##.#..", "##....######....#", "##..#.##..##.#..#", "###.#.######.#.##", "..#...#.##.#...#.", "...#.#.####.#.#..", "..###.##..##.###.", "....#...##...#...", "..#..##....##..#.", ".#.#.#..##..#.#.#", "##....#.##.#....#", "##.#####..#####.#", "##....#....#....#", "...###.####.###..", "..#####....#####.", "##...#.####.#...#", "########..#######", "", "####.##...##.##.#", "#..##.######..#..", "#..##.######.##..", "..#.#..##########", ".#.#..#.###.##.##", "#.#.#..##...###.#", "#....#..#.#.#....", "#....#..#.#.#....", "#.#.#..##...###.#", ".#.#..#.###.##.##", "..#.#..##########", "#..##.######.##..", "#..##.######..#..", "", "##.#..#", "######.", ".#..#..", ".....##", ".....##", ".#..#..", "######.", "##.#..#", ".###.#.", "..#.##.", "....##.", ".###.#.", "##.#..#", "", "##....###.#..##..", ".#...##.##.##..##", "#...##.###..#..#.", "#..####...#######", "#..####.#.#######", "#...##.###..#..#.", ".#...##.##.##..##", "##....###.#..##..", "###.#.###..#....#", "#...##.#..#..##..", "......#..#..#..#.", ".#.....##...#..#.", "..#...##.##......", "", ".####.#", "...#.##", "#...###", "#.##...", ".##....", "....#..", ".#..#..", ".....##", ".##..##", "#...###", "#...###", "", "##.#.##", "#..#.#.", "#.#..##", "#.##.##", "##..#..", "..#.###", ".#.####", ".#..###", ".#..###", "", "#.##..###.#", "...####.##.", ".#.###.###.", "#.....###..", "..####.####", "....#..#.##", "....#..#.##", "..####.####", "#.....###..", ".#.###.###.", "...####.##.", "#.##..###.#", "#.##..###.#", "...####.##.", ".#.###.###.", "#......##..", "..####.####", "", ".###...#...##", "..##.#...#..#", "....#.##.####", "..#....###.#.", "..###.##.####", "..####..#...#", "..##..#...#..", ".......##..##", "...#.#.####..", "###.#.##.##..", "..#.###.#.#.#", "####.....#.##", "###...#####.#", "...#####.####", "##.#.#####.##", "##.#.#####.##", "...#####.####", "", "#..###.#..##.", ".....#.....##", "####....####.", "....#.....###", "#####.##.#.#.", ".##..#####.##", ".....##..####", "#######..#.##", ".##..##..#...", "#####.#..###.", "#..#.###..###", "#..#.###..###", "#####.##.###.", ".##..##..#...", "#######..#.##", "", "..#..##.....#", "###.#.##.###.", "#.###.#######", "####.#..#....", "####.#..#....", "#.###.#######", "###.#.##.###.", "..#..##.....#", "#.######..##.", ".#.##....##..", "##.#.....##..", "##.#.....##..", ".#.##....##..", "#.######..###", "..#..##.....#", "", "........####...#.", "........####...#.", "#...######.##.##.", ".####.##.#...##.#", "##..###.#......##", "#....##.###.#....", "#######....#.#.##", ".####.#..#.###..#", ".####.##...#.##.#", "", "#####.#.#", "#..##.##.", ".....#...", "#####..#.", ".##.....#", "....#.###", "....#.###", ".##.....#", "#####..#.", ".....#...", "#..##.##.", "#####.#.#", ".##..#...", "..#...#..", ".##.##..#", "....##...", "####...#.", "", "###....", "#.###.#", "###...#", ".#.#.##", "###.###", "###.###", ".#.#.##", "###...#", "#.###.#", "###....", ".#####.", "#..#...", ".####.#", ".####.#", "#..#..#", ".#####.", "###....", "", "......#..####..#.", "##..##.#.####.#.#", "..##...##....##..", "......#..####..#.", "#.##.##..#..#..##", "##..##.#.####.#.#", ".........#####...", ".#..#..###..###..", "#....###..##..###", "#######........##", "#########....####", "########..##..###", ".......##.##.##..", "######.##....##.#", "......###....###.", "......#..####..#.", "##..##.#..##..#.#", "", "..#..####..#.", "..#..#..#..#.", "##.##....##.#", "...########..", "###..###...##", "##.##....##.#", "..#..####..#.", "##....##....#", "..##########.", "##.########.#", "...##.##.##..", "", "..####..####..##.", ".###.####.###.##.", "##.##....##.##..#", ".####....####....", "#.#.#.##.#.#..##.", "#####.##.########", "#...#....#...#..#", "", "..##..#.##.##.##.", "..##..###########", "#....#..##.##.##.", ".####.##.##..##.#", "##..##..########.", "######.##..##..##", "#....##..#.##.#..", "#....###..#..#..#", ".....##.##....##.", "", ".....#...##..####", ".....#...#...####", ".....#...#...####", ".....#...##..####", ".#..####...#...#.", "#########.##..###", "#####.##...##.#.#", "..#.#.##.##...##.", "....###..##.##.##", "#.###..##.#..##.#", ".....########..##", "##..###.##..#####", ".####.#.#..#...##", "##..#..#.###.#.#.", "#.##...##.#.....#", ".#.#.....#.......", "#...#####.######.", "", "#......###.##.#", ".##.##.#.#.##.#", "######...######", ".###.###..####.", "###..####..##..", "###..####..##..", ".###.###..####.", "######...######", ".##.##...#.##.#", "#......###.##.#", "#.#####..##..##", "", "#.##.#.#...", "..##..##...", "#.##.#.####", ".#####.....", "#....##..##", "..##.......", ".####......", "#....#.#.##", "##..###.#..", ".####.#.###", "..##..#....", "#....#.....", ".####.###..", "", "#..###..#.####..#", "#####.##..##..##.", "####.#.##....##.#", "####....#....#...", ".##...#..####..#.", "#####..#......#..", "#..#.....####....", "", "#####.#..##.##.", "........#......", "......##.###...", "#####....#..#.#", ".##....#######.", "####.#..#.##...", ".##.#.######.##", "....#....###..#", "#..#####....##.", ".##.##..######.", "......#.#.##.#.", "####..#..####..", ".##...#..##..##", "#..##.#.###.#.#", "#..###..#..#.##", ".##.#..##..#.#.", ".##.#...#..#.#.", "", ".#.#..#.#.##.#.", "##########..###", "####..####..###", ".###..###.##.##", "##############.", "#.##..##.####.#", "##..##..######.", "", "##..#.####.#.", "....#.#..#.#.", "....#.#..#.#.", "##..#.####.#.", ".##.#..##..#.", ".#.#.#.##.#.#", "#.#.#......#.", "#..######.###", "..#.##....##.", ".#.####..####", "....#..##..#.", "", "....#####....", "#######.####.", ".#####.##..##", "#.##.#..#..#.", "#.###.#..####", "..#...##.####", ".#.#..#.#####", ".#.#..#.#####", "..#...##.####", "#.###....####", "#.##.#..#..#.", ".#####.##..##", "#######.####.", "....#####....", "....#####....", "", ".......##", ".##..##..", ".##..##..", ".......##", "#....##.#", "#..##.#.#", "#####...#", "####..###", "....#.#..", "#..#..#.#", "........#", "#####.###", "....#..#.", "", "#...##.", "#....##", "#####..", "#.###.#", ".###..#", ".#.#..#", "#.###.#", "#####..", "#....##", "#...##.", "#...##.", "", "#.......####..###", ".#.#..#.#........", "##.#..#.####..###", "...####...#....#.", "#.#....#.#......#", "#...##...#..##..#", "##.####.##......#", "###....###..##..#", ".########.##..##.", "", "#..#...####", "#..##.#####", "#..##.#..#.", "#..##.#..#.", "#..##.#####", "#..#...####", "##########.", ".....#..#..", "#..#.#.#.##", "#...#.#.##.", "#..#.#.###.", "....####...", ".....#.#..#", ".....##.##.", ".##.##.##.#", ".....######", ".##.#..##..", "", "##.#....#..#.#.", "####.##.#...##.", "..##..###.##.##", "........##..##.", "...###.#..#...#", "..#.##..#.#####", "..####..##.####", "...#...##.#.#..", "..###.###.#....", "##...##.#.#....", "###..#.###...##", "#####..####.##.", "...#...##.#.###", "..#....########", "...#.#######.##", "..##.#.#...##..", "..##.#.#...#...", "", "..#.##.#...", ".#.#.......", "########.##", "..#..###..#", "....#..###.", "....#..###.", "..#..###..#", "#######..##", ".#.#.......", "..#.##.#...", ".#.#.#.#.##", ".#...#.#.#.", "#####.#.##.", "##...###..#", "##...###..#", "", ".#.....###.#.....", "#.###...#.#......", "...#...##....#..#", "...#...##....#..#", "#.###...#.#......", ".#......##.#.....", "#.#..########....", "..##.##.#####.##.", "#...##.#.##.#.##.", "#....#..#....#..#", ".#.###.##...#####", "...##..#.........", ".#..####.##.#....", "......#.##...####", "#..#######..#.##.", "", "..##...#.#..#.#", "...#.#.#......#", ".##..###......#", ".##..##.#....#.", "#.#...##..##..#", "#..#..###.##.##", "#.##..#.##..##.", "####..##......#", "#.###.##.####.#", "####.#..#....#.", ".####..#......#", "...##.##.####.#", "#.####.#..##..#", ".##.####..##..#", "..#.####..##..#", "", ".##..###..#.....#", ".##.###.....#.##.", ".##.###.....#.##.", ".##..#.#..#.....#", ".##......###..#.#", "#..#.###.###..##.", "......####.####.#", "#..#.####..#..#..", ".##.....##.##.###", "", "....##...", "##.####.#", "##..##..#", "##.####.#", "##......#", "####..##.", "###.##.##", "##......#", "###....##", "...#..#..", "##..##..#", "...#..#..", "..######.", "###....##", "##.####.#", "...####..", "..######.", "", ".#....#..", ".##..##..", ".######..", "#.#..#.##", "#...#..##", "#.####.##", "#..##..##", ".##..##..", ".#.##.#..", ".#....#..", ".##..##..", "#.#..#.##", "##....###", "###..####", ".#....#..", "", ".....#.##.#", "........#.#", "...###..###", "#.#.###.#.#", "...#.#....#", "..#.##.###.", "..###....#.", "###.##.###.", "###.##.###.", "", "..###.#..#.###...", "..###......###...", "#....#....#....##", ".#..#.####.#..#..", "#.##..#..#..##.##", "...#.######.#..##", "....##....##.....", "...##########....", "##..###..###..###", "#.#.#......#.#.##", ".#.##########.#..", "#..###....###..##", "..#....##....#...", "", ".#....##.##..##.#", ".#.####.#..##..#.", ".#.##..#........#", "..##.###..#..#..#", "..#...###.#..#.##", "#..#...##.####.##", "#.#...#.###...##.", "##.##..###.##.###", "...#.##..........", "...#.##..........", "##.##..###.##.###", "", ".###.##.###.#..##", "..#.#..#.#...##.#", "....#..#.....#.#.", "..##....##..#.#.#", "..##....##..#.#.#", "....#..#.....#.#.", "..#.#..#.#...##.#", ".###.##.###.##.##", "#....##....#####.", ".##......##.#.##.", ".##......##..###.", ".##.#..#.##.###.#", "#####..#####.####", "...######...#.#.#", "#..##..##..##.###", "", ".....#.....", "..#.#.#####", "###..##....", "##..#.#.##.", "..######..#", "...#..#....", "#####..####", "##.#....##.", "...#..##..#", "####.#..##.", "##..##.....", "...##.##..#", "..###..#..#", "#####...##.", "......##..#", "###...##..#", "....#.##.##", "", "..####.#.#....###", "##...##..###.##.#", "###.##.#..#....#.", "###.##.#..#....#.", "##...##..###.##.#", "..####.#.#..#.###", ".......######.#..", "..#.##.....#.....", "..#.##.##.#.####.", "", "##..#.#.###.#", "##..#.#.###.#", "#.#..###..##.", "...#.#...##.#", "###.#.##..#.#", ".#..####.#.##", ".#####.##..#.", ".######.#####", "#..........#.", "#..........#.", ".######.#####", ".#####.##..#.", ".#..####.#.##", "###.#.##.##.#", "...#.#...##.#", "", "...##.##.#.####", ".#.#...#..#.##.", ".#..#..####....", "#####.#.#.##..#", ".....###.#.#..#", "......##.#.#..#", "#####.#.#.##..#", "", "#....######..##", "#####.....#.#..", "..##..#.#..#.##", "..##..##..###..", "..##.....##.###", "#....###.###.##", "##..##.#.#.##..", "", "##..##.###..###", "##..##.###..###", "......#.####..#", "..##.###.#.####", "#....###...#.##", "##..####..#.#..", ".####.#.....#.#", "", "###.####.##.#", "........#..#.", "..####.......", "##....##....#", "#.#..#.#.##.#", "##.##.###..##", "##.##.##....#", "#.####.#....#", ".#.##.#..##..", "", "####....#.#..###.", ".##.#..##...#..##", ".##.#..##...#..##", "####....#.#..###.", "#####.#.#.##.....", "..#.....#....###.", "#..#.#...##.#..##", "#..#####.##...#.#", "######.#...#.#...", "", ".#..#.#...#..", "##..##.####..", "..##...#..#..", ".#..#...#..#.", ".####....##..", "#....##..####", ".####.#.###..", "......#.##.##", "..##..#...#..", "#....#.####..", "..##....#####", "", "#...#.#..##.#", "#...#.#..##.#", "###..##......", "#########...#", ".#..#.#.##...", "#..####...#..", "#..##..#..##.", "#....##.....#", "#....##.....#", "#..##..#..##.", "#..####...#..", ".#..#...##...", "#########...#", "###..##......", "#...#.#..##.#", "", "#.#...#", "...####", "#.#.#..", "####...", "#....##", "##.##..", "##.##..", "", ".##......##..", "#..#.....##..", "....##...##..", "#..#.#...##..", "#..##.#.####.", "#..#.#...##..", ".##...#..##..", "#..###.##..##", "....##.#....#", "....#.....#..", "#..#.##.####.", "######...##..", "####..#.#..#.", "....#####..##", ".##.#.##....#", "#..##.#......", "#..#.###....#", "", "...#....#....#.", "#.#......#.#..#", ".#...##...#.#..", "#.###..###.#...", "#.#......#.##.#", "##...##...#..#.", ".#..#..#..#....", "#..........#.#.", ".#.#.##.#.#.#..", ".#.#.##.#.#.#..", "#..........#.#.", "", "##.####.##.####.#", "..#.##.####.##.#.", ".#.####.##.####.#", "#..#..#....#..#..", "#..#..#....#..#..", "##.#..#.##.#..#.#", "#.##..##..##..##.", "####..######..###", "###.##.####.##.##", "....##......##...", "#.##..##..##..##.", "#...##......##...", "#.##..##..##..##.", "", "#....#####.##..##", "......#..##.#####", "########.#.###.##", "#.##.###.......##", "..##...##..##....", "......####.#.####", ".......#..###....", "####.#.#.###...##", "###########..#...", ".........#...#.##", "......#.#....#...", "", ".##.##.#.", "#.#.##.##", "#.......#", "#.......#", "#.#.##.##", ".##.##.#.", ".###..###", "#..#..##.", ".#.####..", "####.....", "#....#...", "....#...#", ".####.###", ".#...#...", "#.#######", "#...#..##", "#.#.#..##", "", ".##.#####..", "..#.#.##...", "###.###.#..", "###.##...#.", ".#.#...##..", "...#...#.#.", "##.###....#", "##.##.....#", "...#...#.#.", ".#.#...##..", "###.##...#.", "###.###.#..", "..#.#.##...", ".##.#####..", "..#......##", "##.#.#####.", "##.#.#####."};
    return input;
}