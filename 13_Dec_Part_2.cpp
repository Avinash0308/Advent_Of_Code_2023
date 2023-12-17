#include <bits/stdc++.h>
using namespace std;

vector<string> get_input();
long long int solve(vector<string> &s);
int check_ver(vector<string> &s, int x, int y);
int check_hor(string &a, string &b);

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
        int pos = 0;
        while (pos <= 1 && x >= 0 && y < m)
        {
            pos += check_ver(s, x, y);
            x--, y++;
        }
        if (pos == 1)
            return i + 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x = i, y = i + 1;
        int pos = 0;
        while (pos <= 1 && x >= 0 && y < n)
        {
            pos += check_hor(s[x], s[y]);
            x--, y++;
        }
        if (pos == 1)
            return (i + 1) * 100;
    }
    return 0;
}

int check_hor(string &a, string &b)
{
    int m = a.size(), count = 0;
    for(int i = 0; i<m; i++){
        if(a[i]  != b[i])  count++;
    }
    return count;
}

int check_ver(vector<string> &s, int x, int y)
{
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i][x] != s[i][y]) count++;
    }
    return count;
}

vector<string> get_input()
{
    vector<string> input = {"#.#.##.##.#", "#..#..####.", "#.#####..##", "#.##..####.", "##.#..####.", "..#...#..#.", "##...#....#", "....##....#", "##.##.#..#.", "#..#.##..##", "##.###.##.#", "...#.#.##.#", ".#.#.#.##.#", "##.###.##.#", "#..#.##..##", "", "##.#...#.#.", "##.##..#.#.", ".#.##......", "..######..#", "..######..#", ".#.##......", "##.##..#.#.", "##.#...#.#.", "...##...#..", "...#.###..#", "#..#######.", "..#.##.###.", "..###.##.#.", "..##.##.##.", "..#.#..##..", "", "#.....###..###.", ".###....#..#...", ".#..#.#..##..#.", "##.##.#..##..#.", ".#....#.#..#.#.", ".###.#..#..#..#", "#.###..######..", "#..#...######..", "..#.##.##..##.#", "..#.##.##..##.#", "#......######..", "", ".##.#######", ".##....##.#", "#..#.#.#.##", "#####....##", "####.....##", "#..#.#.#.##", ".##....##.#", ".##.#######", "####.#.###.", "#..#####..#", "......#####", "........###", "#..###.###.", "", "#..##..", "#..#...", "###.#..", "##..###", "####.##", "..#.#..", "..#.###", ".##.##.", ".##.##.", "..#.###", "..#.#..", "", "##.##.#####", "#.####.#.##", "..#..#....#", "#########..", "########.##", "...##...#.#", ".#....#...#", "########..#", "..####.....", "#......###.", "#......###.", "..####.....", "########..#", ".#....#...#", "...##...#..", "########.##", "#########..", "", "...#.#..#....#.", "#.##..##.####.#", ".##.#.##.#..#.#", "#.#.#..##.##.##", "..#.######..###", "...#.###......#", ".##...##......#", "##..#.##.####.#", ".###......##...", "##..#..#..##..#", "####.#..##..##.", ".###..#.######.", "#....##...##...", "#.....#...##...", ".###..#.######.", "", "#..####", ".##.#..", ".##.#.#", "#..####", "#..####", ".##.#.#", ".##.#..", "#..####", ".##...#", "#..###.", "..###..", "", "##.##.....#.#", "##.##.......#", "......#.##...", "##.#.#..#.#..", "##.#..#######", "##...###..#..", "##.##.#..#.##", "####.#...#..#", "###.....####.", "...##....#...", "...##.#.##.##", "....#..#...##", "###...#......", "", "#####.##..#", "#.#..######", ".#.#...####", ".#.#...####", "#.#..######", "###.#.##..#", "...#.######", "##.#...####", "....#..####", ".#.#....##.", ".....#.#..#", "", ".#....#.#..##", ".#....#....##", "..#..#.......", ".##..##...###", "##########..#", ".#.##.#.###.#", "..#..#...#.##", "#.####.##..#.", ".#....#..##..", "#......###.##", ".#.##.#..###.", "...##...####.", ".#....#...#..", "##.##.####.##", "##....##...##", "#.####.####..", "###..#####.##", "", ".##.####....#", ".##.#..####.#", "#####...#.###", ".......#.....", "####.#...##..", ".##....####.#", ".##....######", ".##....######", ".##....####.#", "####.#...##..", ".......#.....", "#####...#.###", ".##.#..####.#", ".##.####....#", ".###..#...##.", "", "#####.#.#.#..#.#.", "#..###.###.##.###", "....#...#..##..#.", "#..####..#....#..", "#..###..#.####.#.", "#####.#.#..##..#.", "#####.#.#####.##.", ".##..###..####..#", "#..#.#..########.", "#..##.#####..####", "####...#..#..#..#", "", "########.....", "...##.....##.", ".........####", "#.#..#.#####.", "#.#######..#.", "#.####.#.#..#", "###..#####.#.", "#.#..#.#..##.", "..####....#.#", "..####...#...", "#.#..#.#.#..#", "#.####.#.....", "#.####.#.....", "", "###....#.##.#.#", "..#....#....###", "#####.#..#.#.##", "##.#.#..##..#..", "..###..##...#..", "#####.##...####", ".....#...##.##.", "###....####..##", "##.###.##.###..", "..##.####.#...#", "###.##...#..###", "..##.#..##.#...", "..##.##.##.#...", "###.##...#..###", "..##.####.#...#", "", ".#......#.#######", "............####.", "....##.....##..##", ".###..###........", "....##....#..##..", "##.#..#.##.######", "...####...#######", "..######..##.##.#", ".########..#.##..", "###....#####.##.#", "#...##...##......", "...#..#...#..##..", "##.####.##.......", ".##....##.#..##..", "#.##..##.#.#.##.#", ".#.#..#.#.##.##.#", ".##.##.##.##.##.#", "", "....#.#.#..#.#.", "####.#..#.#.#..", "#..##.#.#..####", "####..###......", "....###.#.###..", "....#.##....#.#", "#..##.###.####.", "....##.#...#...", "#..#.#.#.#..###", "####.#.#...##..", "####.#.#...##..", "#..#.#.#.#..#.#", "....##.#...#...", "#..##.###.####.", "....#.##....#.#", "....###.#.###..", "####..###......", "", "..#####....#####.", "##..##########..#", ".##.#..####..#.##", "..######..######.", "..######..######.", ".##.#..####..#.##", "##..##########..#", "..#####....#####.", ".....########....", "..#..##....##..#.", ".###.##.##.##.###", ".#.#####..#####.#", "..#....#..#.#..#.", "", ".###.##.###", ".###.##.###", "####....#.#", "#...####...", "####....###", ".#...##...#", "..###..###.", "#..#.##.#..", "#....##....", "", "#.#.#.#....#.", "###..##.##.##", "...##.#....#.", "..##.#.####.#", "##.#.#.#..#.#", ".#..##..##..#", "#.#...#....#.", "...##.#....#.", "...##.#....#.", "#.#...#....#.", ".#...#..##..#", "##.#.#.#..#.#", "..##.#.####.#", "", "#......", ".#.####", "#.#####", ".##...#", "..#....", "###.##.", "##.####", ".#..##.", ".##....", "##..##.", "##..##.", "", "##..#.#..#..###", "##.#......#....", "####....#.#####", ".#.##.##.......", "#..#.#..####..#", "#..#.#..####..#", ".#.##.##.......", "", ".#..###.#", "..#...##.", "#####.#.#", "....#.###", "#.###.#.#", "###.####.", "##..#..#.", ".#.#.....", ".#.#.....", "##..#..#.", "###.####.", "#.###.#.#", "....#.###", "#####...#", "..#...##.", ".#..###.#", ".#..###.#", "", "#.#.#.....###.##.", "#.#.#.....###.##.", "#...#.#.#####..#.", "..#....#.####....", "#.#.##.##..###..#", "#.#....#.#.#.####", ".##.#####........", ".#.#.##..#####..#", ".#.......#.######", "..##.###.##.#####", "####.#..##..#....", "##..#.#.##.##.##.", "#.#..#.#....##..#", "", "#...#.####.#.#.##", "#..#.#.#..##..#.#", ".###...###..#....", "####..###.###..##", "##..##...###.##..", "#.#.##.##..#.#..#", "#.#.##.##.##.#..#", ".##.#.##...###...", ".##.#.##...###...", "#.#.##.##.##.#..#", "#.#.##.##..#.#..#", "", "..........##.", ".##.#.#.####.", "####..###.###", "####.#..#..##", ".##.##.#...#.", "....####...#.", ".##...###..##", "####.###.#.##", "....###.#...#", "#..#.##....#.", "#..#.##.#..#.", "", ".###...#.....", ".###...#.....", "..####.#####.", "...#.##.##.##", "#.###...###..", "####.#.#.###.", "#.#.#.##...##", "#.#.#.##...##", "####.###.###.", "#.###...###..", "...#.##.##.##", "..####.#####.", ".###...#.....", "", ".###..#.#", ".#.#..#.#", ".#.###..#", "##....###", "##....###", ".#.###..#", ".#.#..#.#", ".###..#.#", "..###.#.#", ".##.#.#.#", "####..###", "###..##.#", "#.#.###.#", "###..####", "#.#.#.#.#", "......#..", "#..#####.", "", "#...#..#..###..##", ".#.##.#.##.......", ".##.#.#...#......", "#..#.#...###.##.#", "#.#...###.#######", "####.##..#...##..", "##..#.####.######", "..#.#..#.####..##", "...######.###..##", "####....###......", ".#####.#.##..##..", ".##..#..#........", "####...###...##..", "", "###.##..#", "###.##..#", "###.####.", "##..#####", "#....#..#", "#..##.##.", "..#..####", "", "####......#######", "####..##..#######", ".##.#.##.#.##..##", "###...##...######", "..##..##..##.....", ".#..#....#..#..#.", "####..##..#######", "#..###..###..##..", ".####.##.####..##", ".#..........#..#.", "#..#..##..#..##..", "", "....#..#..#..#..#", "....#..#..#..#..#", "#.#.#.###.#..#.##", "..#..###...##...#", ".#......##....##.", "##..#...#.#..#.#.", "#.#######.##.#.##", "##...##.#..##..#.", "####..#..######..", ".##..#..##.##.##.", "...#...#..####..#", "#####.###......##", ".#####.#.######.#", ".#.....#.#.##.#.#", ".###.......##....", ".#...#....#..#...", ".#.#..##..#..#..#", "", "###...###", "..#.#.#..", "#.#...#.#", "###.#.#.#", "...##.#..", "####..#.#", "..#..#..#", "###....#.", "....#.#..", "....#.#..", "###....#.", "", "..#..###.##", "##.##.###..", "..##....##.", "..##..##.##", "##..##.####", "#####.#....", "##.#....###", "", ".#.#.##.#..", "#....#.##..", "#.#.###.###", "#.##.###.##", ".#.##...###", "#..........", "...##....##", "#...#......", "###.#.#....", "###.#.#....", "#...#......", ".#.##....##", "#..........", ".#.##...###", "#.##.###.##", "", "..####...#.####.#", "#......##..#..#..", "#.#..#.#####..###", "##....#####.##.##", "..####......##..#", "..#..#..#.#.##.#.", "#..##..##.######.", "..####..###....##", "###..#######..###", ".#.##.#.#..#..#..", ".######.##.#..#.#", "", "..##..###..", "..#####....", "...#.#.#.##", "...#.#.####", "..#####....", "..##..###..", "##......##.", "##.#..#.###", "###..##....", "...##..##.#", "##.###.#.#.", "###.#.#....", "..##...#..#", "####.###.##", "....#..#.##", "", "#....##....", "..##....##.", "#.##....##.", ".#...##...#", "#..........", "#####..####", "#....##....", "", "..#..#.", "##.#.##", "#..#...", "#...##.", "...#...", "...#...", "#...##.", "#..#...", "##.#.##", "..#..#.", "....#..", "#.#..##", "##....#", "...#...", "...##..", "", ".####.####.", ".###.......", "..#####..##", "...#.##..#.", "#.#.###..##", ".#..##....#", "..#....##..", "#.#.#.#..#.", "#.#.#.#..#.", "", "...#..####....#..", "....#.###...##...", "###....#...#.#...", "...###...##....##", "##.##..#..###.#..", "#..#.#...#.#...##", "..#....#...#..#..", "..#....#...#..#..", "#....#...#.#...##", "##.##..#..###.#..", "...###...##....##", "###....#...#.#...", "....#.###...##...", "...#..####....#..", "....#..###.#..###", "#.....###....##..", "....####....##...", "", "#.#.#.#..#.#...#.", "#..#.#.#..#...###", "##.#..#.#.....#.#", "###..#..#..#...##", "##..#....#...#.#.", ".##.#....#...##..", ".##......#...##..", "##..#....#...#.#.", "###..#..#..#...##", "##.#..#.#.....#.#", "#..#.#.#..#...###", "#.#.#.#..#.#...#.", ".####...#..##.#..", "####.##.#####.##.", ".####.#####..#.#.", "#...###.......###", "#...###.......###", "", ".#.##.#..##...#", "###..###.##.#..", "#.####.##..#.##", "#.#..#......#..", "#.#..#......#..", "#.####.##..#.##", "###..###.##.#..", "", "...#.##.##.##.#..", "##....######....#", "##..#.##..##.#..#", "###.#.######.#.##", "..#...#.##.#...#.", "...#.#.####.#.#..", "..###.##..##.###.", "....#...##...#...", "..#..##....##..#.", ".#.#.#..##..#.#.#", "##....#.##.#....#", "##.#####..#####.#", "##....#....#....#", "...###.####.###..", "..#####....#####.", "##...#.####.#...#", "########..#######", "", "####.##...##.##.#", "#..##.######..#..", "#..##.######.##..", "..#.#..##########", ".#.#..#.###.##.##", "#.#.#..##...###.#", "#....#..#.#.#....", "#....#..#.#.#....", "#.#.#..##...###.#", ".#.#..#.###.##.##", "..#.#..##########", "#..##.######.##..", "#..##.######..#..", "", "##.#..#", "######.", ".#..#..", ".....##", ".....##", ".#..#..", "######.", "##.#..#", ".###.#.", "..#.##.", "....##.", ".###.#.", "##.#..#", "", "##....###.#..##..", ".#...##.##.##..##", "#...##.###..#..#.", "#..####...#######", "#..####.#.#######", "#...##.###..#..#.", ".#...##.##.##..##", "##....###.#..##..", "###.#.###..#....#", "#...##.#..#..##..", "......#..#..#..#.", ".#.....##...#..#.", "..#...##.##......", "", ".####.#", "...#.##", "#...###", "#.##...", ".##....", "....#..", ".#..#..", ".....##", ".##..##", "#...###", "#...###", "", "##.#.##", "#..#.#.", "#.#..##", "#.##.##", "##..#..", "..#.###", ".#.####", ".#..###", ".#..###", "", "#.##..###.#", "...####.##.", ".#.###.###.", "#.....###..", "..####.####", "....#..#.##", "....#..#.##", "..####.####", "#.....###..", ".#.###.###.", "...####.##.", "#.##..###.#", "#.##..###.#", "...####.##.", ".#.###.###.", "#......##..", "..####.####", "", ".###...#...##", "..##.#...#..#", "....#.##.####", "..#....###.#.", "..###.##.####", "..####..#...#", "..##..#...#..", ".......##..##", "...#.#.####..", "###.#.##.##..", "..#.###.#.#.#", "####.....#.##", "###...#####.#", "...#####.####", "##.#.#####.##", "##.#.#####.##", "...#####.####", "", "#..###.#..##.", ".....#.....##", "####....####.", "....#.....###", "#####.##.#.#.", ".##..#####.##", ".....##..####", "#######..#.##", ".##..##..#...", "#####.#..###.", "#..#.###..###", "#..#.###..###", "#####.##.###.", ".##..##..#...", "#######..#.##", "", "..#..##.....#", "###.#.##.###.", "#.###.#######", "####.#..#....", "####.#..#....", "#.###.#######", "###.#.##.###.", "..#..##.....#", "#.######..##.", ".#.##....##..", "##.#.....##..", "##.#.....##..", ".#.##....##..", "#.######..###", "..#..##.....#", "", "........####...#.", "........####...#.", "#...######.##.##.", ".####.##.#...##.#", "##..###.#......##", "#....##.###.#....", "#######....#.#.##", ".####.#..#.###..#", ".####.##...#.##.#", "", "#####.#.#", "#..##.##.", ".....#...", "#####..#.", ".##.....#", "....#.###", "....#.###", ".##.....#", "#####..#.", ".....#...", "#..##.##.", "#####.#.#", ".##..#...", "..#...#..", ".##.##..#", "....##...", "####...#.", "", "###....", "#.###.#", "###...#", ".#.#.##", "###.###", "###.###", ".#.#.##", "###...#", "#.###.#", "###....", ".#####.", "#..#...", ".####.#", ".####.#", "#..#..#", ".#####.", "###....", "", "......#..####..#.", "##..##.#.####.#.#", "..##...##....##..", "......#..####..#.", "#.##.##..#..#..##", "##..##.#.####.#.#", ".........#####...", ".#..#..###..###..", "#....###..##..###", "#######........##", "#########....####", "########..##..###", ".......##.##.##..", "######.##....##.#", "......###....###.", "......#..####..#.", "##..##.#..##..#.#", "", "..#..####..#.", "..#..#..#..#.", "##.##....##.#", "...########..", "###..###...##", "##.##....##.#", "..#..####..#.", "##....##....#", "..##########.", "##.########.#", "...##.##.##..", "", "..####..####..##.", ".###.####.###.##.", "##.##....##.##..#", ".####....####....", "#.#.#.##.#.#..##.", "#####.##.########", "#...#....#...#..#", "", "..##..#.##.##.##.", "..##..###########", "#....#..##.##.##.", ".####.##.##..##.#", "##..##..########.", "######.##..##..##", "#....##..#.##.#..", "#....###..#..#..#", ".....##.##....##.", "", ".....#...##..####", ".....#...#...####", ".....#...#...####", ".....#...##..####", ".#..####...#...#.", "#########.##..###", "#####.##...##.#.#", "..#.#.##.##...##.", "....###..##.##.##", "#.###..##.#..##.#", ".....########..##", "##..###.##..#####", ".####.#.#..#...##", "##..#..#.###.#.#.", "#.##...##.#.....#", ".#.#.....#.......", "#...#####.######.", "", "#......###.##.#", ".##.##.#.#.##.#", "######...######", ".###.###..####.", "###..####..##..", "###..####..##..", ".###.###..####.", "######...######", ".##.##...#.##.#", "#......###.##.#", "#.#####..##..##", "", "#.##.#.#...", "..##..##...", "#.##.#.####", ".#####.....", "#....##..##", "..##.......", ".####......", "#....#.#.##", "##..###.#..", ".####.#.###", "..##..#....", "#....#.....", ".####.###..", "", "#..###..#.####..#", "#####.##..##..##.", "####.#.##....##.#", "####....#....#...", ".##...#..####..#.", "#####..#......#..", "#..#.....####....", "", "#####.#..##.##.", "........#......", "......##.###...", "#####....#..#.#", ".##....#######.", "####.#..#.##...", ".##.#.######.##", "....#....###..#", "#..#####....##.", ".##.##..######.", "......#.#.##.#.", "####..#..####..", ".##...#..##..##", "#..##.#.###.#.#", "#..###..#..#.##", ".##.#..##..#.#.", ".##.#...#..#.#.", "", ".#.#..#.#.##.#.", "##########..###", "####..####..###", ".###..###.##.##", "##############.", "#.##..##.####.#", "##..##..######.", "", "##..#.####.#.", "....#.#..#.#.", "....#.#..#.#.", "##..#.####.#.", ".##.#..##..#.", ".#.#.#.##.#.#", "#.#.#......#.", "#..######.###", "..#.##....##.", ".#.####..####", "....#..##..#.", "", "....#####....", "#######.####.", ".#####.##..##", "#.##.#..#..#.", "#.###.#..####", "..#...##.####", ".#.#..#.#####", ".#.#..#.#####", "..#...##.####", "#.###....####", "#.##.#..#..#.", ".#####.##..##", "#######.####.", "....#####....", "....#####....", "", ".......##", ".##..##..", ".##..##..", ".......##", "#....##.#", "#..##.#.#", "#####...#", "####..###", "....#.#..", "#..#..#.#", "........#", "#####.###", "....#..#.", "", "#...##.", "#....##", "#####..", "#.###.#", ".###..#", ".#.#..#", "#.###.#", "#####..", "#....##", "#...##.", "#...##.", "", "#.......####..###", ".#.#..#.#........", "##.#..#.####..###", "...####...#....#.", "#.#....#.#......#", "#...##...#..##..#", "##.####.##......#", "###....###..##..#", ".########.##..##.", "", "#..#...####", "#..##.#####", "#..##.#..#.", "#..##.#..#.", "#..##.#####", "#..#...####", "##########.", ".....#..#..", "#..#.#.#.##", "#...#.#.##.", "#..#.#.###.", "....####...", ".....#.#..#", ".....##.##.", ".##.##.##.#", ".....######", ".##.#..##..", "", "##.#....#..#.#.", "####.##.#...##.", "..##..###.##.##", "........##..##.", "...###.#..#...#", "..#.##..#.#####", "..####..##.####", "...#...##.#.#..", "..###.###.#....", "##...##.#.#....", "###..#.###...##", "#####..####.##.", "...#...##.#.###", "..#....########", "...#.#######.##", "..##.#.#...##..", "..##.#.#...#...", "", "..#.##.#...", ".#.#.......", "########.##", "..#..###..#", "....#..###.", "....#..###.", "..#..###..#", "#######..##", ".#.#.......", "..#.##.#...", ".#.#.#.#.##", ".#...#.#.#.", "#####.#.##.", "##...###..#", "##...###..#", "", ".#.....###.#.....", "#.###...#.#......", "...#...##....#..#", "...#...##....#..#", "#.###...#.#......", ".#......##.#.....", "#.#..########....", "..##.##.#####.##.", "#...##.#.##.#.##.", "#....#..#....#..#", ".#.###.##...#####", "...##..#.........", ".#..####.##.#....", "......#.##...####", "#..#######..#.##.", "", "..##...#.#..#.#", "...#.#.#......#", ".##..###......#", ".##..##.#....#.", "#.#...##..##..#", "#..#..###.##.##", "#.##..#.##..##.", "####..##......#", "#.###.##.####.#", "####.#..#....#.", ".####..#......#", "...##.##.####.#", "#.####.#..##..#", ".##.####..##..#", "..#.####..##..#", "", ".##..###..#.....#", ".##.###.....#.##.", ".##.###.....#.##.", ".##..#.#..#.....#", ".##......###..#.#", "#..#.###.###..##.", "......####.####.#", "#..#.####..#..#..", ".##.....##.##.###", "", "....##...", "##.####.#", "##..##..#", "##.####.#", "##......#", "####..##.", "###.##.##", "##......#", "###....##", "...#..#..", "##..##..#", "...#..#..", "..######.", "###....##", "##.####.#", "...####..", "..######.", "", ".#....#..", ".##..##..", ".######..", "#.#..#.##", "#...#..##", "#.####.##", "#..##..##", ".##..##..", ".#.##.#..", ".#....#..", ".##..##..", "#.#..#.##", "##....###", "###..####", ".#....#..", "", ".....#.##.#", "........#.#", "...###..###", "#.#.###.#.#", "...#.#....#", "..#.##.###.", "..###....#.", "###.##.###.", "###.##.###.", "", "..###.#..#.###...", "..###......###...", "#....#....#....##", ".#..#.####.#..#..", "#.##..#..#..##.##", "...#.######.#..##", "....##....##.....", "...##########....", "##..###..###..###", "#.#.#......#.#.##", ".#.##########.#..", "#..###....###..##", "..#....##....#...", "", ".#....##.##..##.#", ".#.####.#..##..#.", ".#.##..#........#", "..##.###..#..#..#", "..#...###.#..#.##", "#..#...##.####.##", "#.#...#.###...##.", "##.##..###.##.###", "...#.##..........", "...#.##..........", "##.##..###.##.###", "", ".###.##.###.#..##", "..#.#..#.#...##.#", "....#..#.....#.#.", "..##....##..#.#.#", "..##....##..#.#.#", "....#..#.....#.#.", "..#.#..#.#...##.#", ".###.##.###.##.##", "#....##....#####.", ".##......##.#.##.", ".##......##..###.", ".##.#..#.##.###.#", "#####..#####.####", "...######...#.#.#", "#..##..##..##.###", "", ".....#.....", "..#.#.#####", "###..##....", "##..#.#.##.", "..######..#", "...#..#....", "#####..####", "##.#....##.", "...#..##..#", "####.#..##.", "##..##.....", "...##.##..#", "..###..#..#", "#####...##.", "......##..#", "###...##..#", "....#.##.##", "", "..####.#.#....###", "##...##..###.##.#", "###.##.#..#....#.", "###.##.#..#....#.", "##...##..###.##.#", "..####.#.#..#.###", ".......######.#..", "..#.##.....#.....", "..#.##.##.#.####.", "", "##..#.#.###.#", "##..#.#.###.#", "#.#..###..##.", "...#.#...##.#", "###.#.##..#.#", ".#..####.#.##", ".#####.##..#.", ".######.#####", "#..........#.", "#..........#.", ".######.#####", ".#####.##..#.", ".#..####.#.##", "###.#.##.##.#", "...#.#...##.#", "", "...##.##.#.####", ".#.#...#..#.##.", ".#..#..####....", "#####.#.#.##..#", ".....###.#.#..#", "......##.#.#..#", "#####.#.#.##..#", "", "#....######..##", "#####.....#.#..", "..##..#.#..#.##", "..##..##..###..", "..##.....##.###", "#....###.###.##", "##..##.#.#.##..", "", "##..##.###..###", "##..##.###..###", "......#.####..#", "..##.###.#.####", "#....###...#.##", "##..####..#.#..", ".####.#.....#.#", "", "###.####.##.#", "........#..#.", "..####.......", "##....##....#", "#.#..#.#.##.#", "##.##.###..##", "##.##.##....#", "#.####.#....#", ".#.##.#..##..", "", "####....#.#..###.", ".##.#..##...#..##", ".##.#..##...#..##", "####....#.#..###.", "#####.#.#.##.....", "..#.....#....###.", "#..#.#...##.#..##", "#..#####.##...#.#", "######.#...#.#...", "", ".#..#.#...#..", "##..##.####..", "..##...#..#..", ".#..#...#..#.", ".####....##..", "#....##..####", ".####.#.###..", "......#.##.##", "..##..#...#..", "#....#.####..", "..##....#####", "", "#...#.#..##.#", "#...#.#..##.#", "###..##......", "#########...#", ".#..#.#.##...", "#..####...#..", "#..##..#..##.", "#....##.....#", "#....##.....#", "#..##..#..##.", "#..####...#..", ".#..#...##...", "#########...#", "###..##......", "#...#.#..##.#", "", "#.#...#", "...####", "#.#.#..", "####...", "#....##", "##.##..", "##.##..", "", ".##......##..", "#..#.....##..", "....##...##..", "#..#.#...##..", "#..##.#.####.", "#..#.#...##..", ".##...#..##..", "#..###.##..##", "....##.#....#", "....#.....#..", "#..#.##.####.", "######...##..", "####..#.#..#.", "....#####..##", ".##.#.##....#", "#..##.#......", "#..#.###....#", "", "...#....#....#.", "#.#......#.#..#", ".#...##...#.#..", "#.###..###.#...", "#.#......#.##.#", "##...##...#..#.", ".#..#..#..#....", "#..........#.#.", ".#.#.##.#.#.#..", ".#.#.##.#.#.#..", "#..........#.#.", "", "##.####.##.####.#", "..#.##.####.##.#.", ".#.####.##.####.#", "#..#..#....#..#..", "#..#..#....#..#..", "##.#..#.##.#..#.#", "#.##..##..##..##.", "####..######..###", "###.##.####.##.##", "....##......##...", "#.##..##..##..##.", "#...##......##...", "#.##..##..##..##.", "", "#....#####.##..##", "......#..##.#####", "########.#.###.##", "#.##.###.......##", "..##...##..##....", "......####.#.####", ".......#..###....", "####.#.#.###...##", "###########..#...", ".........#...#.##", "......#.#....#...", "", ".##.##.#.", "#.#.##.##", "#.......#", "#.......#", "#.#.##.##", ".##.##.#.", ".###..###", "#..#..##.", ".#.####..", "####.....", "#....#...", "....#...#", ".####.###", ".#...#...", "#.#######", "#...#..##", "#.#.#..##", "", ".##.#####..", "..#.#.##...", "###.###.#..", "###.##...#.", ".#.#...##..", "...#...#.#.", "##.###....#", "##.##.....#", "...#...#.#.", ".#.#...##..", "###.##...#.", "###.###.#..", "..#.#.##...", ".##.#####..", "..#......##", "##.#.#####.", "##.#.#####."};
    return input;
}