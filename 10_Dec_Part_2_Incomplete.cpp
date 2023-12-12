#include <bits/stdc++.h>
using namespace std;

void get_input(vector<string> &v);
pair<int, int> find_s(vector<string> &v);
void solve(vector<string> &input);
vector<pair<int, int>> find_pairs(char c);

int main()
{
    vector<string> input;
    get_input(input);
    solve(input);
    return 0;
}

void solve(vector<string> &input)
{
    int n = input.size(), m = input[0].size(), ans = 0;
    pair<int, int> point = find_s(input);
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    queue<vector<int>> q;
    q.push({point.first, point.second, 0});
    while (!q.empty())
    {
        vector<int> cur = q.front();
        q.pop();
        int u = cur[0], v = cur[1], val = cur[2];
        if (u < 0 || u >= n || v < 0 || v >= m || input[u][v] == '@')
            continue;
        if (input[u][v] == '.')
        {
            dis[u][v] = 0;
        }
        else if (dis[u][v] <= val)
            continue;
        else
        {
            dis[u][v] = val;
            vector<pair<int, int>> next_point = find_pairs(input[u][v]);
            for (int dir = 0; dir < next_point.size(); dir++)
                q.push({u + next_point[dir].first, v + next_point[dir].second, val + 1});
        }
    }
    cout<<ans<<endl;
}

vector<pair<int, int>> find_pairs(char c)
{
    if (c == '|')
        return {{-1, 0}, {1, 0}};
    if (c == '-')
        return {{0, -1}, {0, 1}};
    if (c == 'L')
        return {{-1, 0}, {0, 1}};
    if (c == 'J')
        return {{-1, 0}, {0, -1}};
    if (c == '7')
        return {{0, -1}, {1, 0}};
    if (c == 'F')
        return {{0, 1}, {1, 0}};
    if (c == 'S')
    {
        return {{-1, 0}, {1, 0}};
    }
}

pair<int, int> find_s(vector<string> &v)
{
    int n = v.size(), m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'S')
                return {i, j};
        }
    }
    return {n - 1, m - 1};
}

void get_input(vector<string> &v)
{
    v = {"7-L7|F--F7F-|-FF--|FFL|7.FFL7|FL-F|-LL77FFJFL-7.FF-J.F77.7.F7F777-77.FF-LF7F.JJ.F7|-|.FFJF7..77F7|-7-FF7.|-F77L-|-|-77.F77FLJ7.F-LL--F7FL7.J", "|7F|-7.FJLLJL7LL-JLJ7JFF.JL|7.7LFF.||||F7-J7.LL--J7L7JL7.|.LFF-7-7.|7--.||FF7-LFJF-.||-7FJ.FL|-F|L-J--7J7FF-7-L7L-7-|JF7-7-|FFFJ|.L7F|JL-77.", "7FL|-7.L-|L7.|J|J-|J|LLF.|7|LL7J.-LJ-7FFJ|LF|.F|.|J-7.|.|F7.7F7-F7-L||..FLFL|J7..|J.FL-JJJF-7LJ.FL7F7|JF-.--F7LF-LJ---|JJ.-J7||F-..JJL-7|.F7", "||7L-|-J-F-|-|-JJ7L.7-7JLJFL|.J7|LJJ.F|L7--LJL|J-|FFJ-|FLJJ7||J|||JFJFFJ7F|F|-LL-7-J7|.L||L.77.J7.L7-FF|-7JL||.J7|J.J|.LLJ|..L-J7J.FL.LF-..-", "FJ-FJ|.|J.F-7JJJLLJ7L7F..L|7F7--7F|7F---JJFL...-J|L7J7-|JL-7-|L-JJ7JL-L.L|-7|F.L777FLF.LFJL7LLL-|-JJL-.L-|J.F77JF77F|-L7J.F7.L7.JL-FJ..FJF-J", "L|J|LJ.|F-7-|7-F7J-LL---FF--J|F7LJLL-L-7|J7J.F7FF|J|7-JL7J|LFJ.|.||.-|.FJLL|-7.F7LJ-7|F.|JFJ.L7-L7J-7L-JLL7FF7|F7L-J.F.F-7|.FJL7LFJ|FL-J7J.|", ".|F|F|F-||JF7J.FL|FJ.F|-LJF7.L7---FJJ|L7|F7-L|--7JLJJ7.-|.F|J..F7-F-..FL--.J.LF-|-J.F7.FJ|L--FJFL-7JF.L-FLJ.|F7-77-|..F-..FJJJ||.||LL|L|J.7|", "LF-FLL7||77JL.7.L|J-F.|7|-LJJ..FJ.J|LLF-L-|7-|F-J7.|.LFLL-|JLL|-|7L|-7||7JF7FLLJ|.|F|LJ77F7-LL-J.L|7|..F|J.77LLL--F-L-F|.FFJ-77L7J|.||FFJ.F|", "L--F-|LJJ.|7|F|FF77.77F7-J.|.F-J-JF7JLFJ.L|7-L|7.|7L7-L|.FF7F.|7.L.L|.JJFF--F-L7LF--77|LF-J7-LLLL-77J-7-7LF|L7.FL77-|7|L-LJ||L|JJF-LF-L7|FFJ", "||LJF|FL7F|7FF7J.LJ-F||L7..FJJ7.77|JJLF77LJ.|F||-L--|7.LF7|FJ.L7F|7.|7.F7JJ7F7.7-L7FJ-JFL-||7LJ-L7LJ..|.L7-7||.-7LJ|F7F7|.L|JJFJJ|J.|7L|F||7", "FJJ|7L-7J7LF-|||7.L||.FJ7-F-.JJFFFF---J||J|FF7-LJ.||.FFJ|.|JF.LJLF7F||FJ||JF||..LFJ|J.F|77LF-77LJJF|LJ-7JJF|-L7L|J|7.FF77F.|.L|..|7.|7FFLJ-7", "L|.--J|LF77LJ|LLJ7|LL7|-LF7LF|7LF7L---7L7-FFJ|7|77F7-F7FL7.FF7J7.|L7F7L7L7F7|L-7FL7|7.FF77F|FJJFL----|-JLF-7-.7.LJ.LL-L7F--|77L-----J7||L..L", "FJ7.L-77LLL.--J.|.7|.F7JFJ|7F7JLF7JF7FJFJ7|L7L7FF7|L7F7JLFFFJL-7-L7||L7|FJ||L7FJF7||7F7||F7||JL77F|-|F7J.-..L-F7JFF.FLLL7-||-F7-|7.L.L7FL7-J", ".FJFLL-7.L-F|---7-|FFFF7L7L-J|LF|L-J|L7|F7F7|FJFJ|L7LJ|L7-FL-7FJFFJ||FJ||L|L7|L-J|||FJ||LJLJL-7-F-7.F||-L.F--J||-7.F7-|L|LFJJ|7LFL-FFLJ7L|LL", "7J.7JLFF||.|L-7|.F||-FJL7L7F-J.L|F-7L7||||||||FJFJFJF-JF7-F7J||F7L7||L7||FJFJL-7FJ|||FJL7F----J-|FJFFJL7J.F|7FJL7F7||F7-F-7JF||F-JF|L|FJ-7|7", "LL7L-FJJLF..F|F77FF7JL7FJFJL-7-LLJFJFJ|||LJLJLJFJ||FJJF-7FJL-J||L7|LJFJ||L7||F-J|FJ|||F-J|F--7F-JL7FJF-J-F7F7L7FJ|LJLJ|F-7.FJ|-JJLFL-F7L-J-|", "FJF7--J...F-JL-7FF||LL|L7L7F-J.F-7L7L7||L-7F7F7|F-JL-7|FJL---7||FJ|F-JFJL7|L7L-7||FJ||L-7||F-JL-7FJ|FJ7F7|LJ|-|L7L-7F-J|FJ7|JL.LF-7.|L7..F-7", "77|L-7FFJ-7LFF-F-7||F7L7|F|L--7L7|7L7LJL7FJ|||LJL-7F-J||F7-F7|||L7||F7L-7||FJF-J|||FJL7F||||F7F7||FJL7FJ|L7FJFJFJF7||F7||FF77-7FF-7J-7L-JJF|", "L|J.|L|-7-L7|J7L7LJLJL-J|FJF--JL||F7L-7FJL7|LJF-77|||FJ||L7|LJLJFJ|LJL7FJLJL7L-7||||F-JFJ||LJLJLJ|L7FJL7SFJL7L7|FJLJLJLJL7|L-7F-7.||.LJ7---7", "||L7LJ|F-7F-JLJ-L------7LJFJF7F-JLJ|F7|L7FJL77L7|FJL7L7||FJL-7F7L7L7F-J|F7F-JF7|||LJL77L7||F---7FJ7||F7|||F-JFJLJF-7F7F7FJL-7|L7L77.|JL|7J-F", "F-|-J-L-FJJ.--J-LF-7F7FL-7L7||L---7LJ|L7|L-7L7FJ|L-7|J|||L--7LJL7|FJ|F7LJ|L-7|||||F--JF-J||L--7LJF7||||||||F7L7F-JLLJLJLJF7FJL-JFJJ7LL-LJFF-", "|F|..F|-77L77LF-7L7|||F7FL7LJ|F7F7L-7L7||F7L7||FJF-J|FJ||F--JF7.||L7||L7FJF-J|||LJL7F7L-7LJF--JF7|||||||||LJL7|L7F7F7F7F7||L7F--J|7F7J.L-L|.", "|7|.|-|L|JFL|7L7|FJ||||L7FJF-J|LJL7.L7LJLJL-J||L7L-7|L7|||F-7|L-JL-JLJFJL7|F-J|L7F-J|L-7L-7L-7FJ|||||||||L7F-J|FJ|||||||||L7||7F-7--JL|.|-|7", "|.F.7||7|J-JLJ.||L7LJ|L7||FJF7L--7|F7L-7F----JL7|F7|L7|||LJFJL-------7L-7|||F-JFJ|F7L-7L-7|F-JL7LJLJ||LJL7||F7|L7||||||||L7LJL7L7|7-LFJFFFJJ", "|7JL.|L-J|LF-.FJL7L-7L-JLJL7|L7.FJ||L-7|L--7F--J||||FJ|LJF-JF7F-7F7F7L-7|||||F-JFJ|L7FJF7LJL-77L--7FJ|F--J|||||FJ||||||||FJF-7L-J|7JFLL-JLL|", "LJ7LFJ|L|7L7--L-7L--JF--7F7|L7L7L7|L-7||F--JL--7|||||-L-7L-7|LJFJ||||F-J||||LJF-JFJFJL-JL7F--JF-7FJ|FJL-7FJLJ||L-J||LJLJLJFJ7|F-7|7-7-J|7JJL", "L7FF-7F.|.FL-JLFJF---JF7LJ|L7L7L7||F7||||F7|F--JLJ||L7F7|F-JL7FJFJ||||F7LJ|L-7L-7|FJ|F---JL7F7L7|L7|L7F-J|F--JL7F-J|F-----JF7LJ-||JF|J-LJF-7", "FLL7|LF---LJ7JLL7|F---JL--JFJFJFJ|||LJ||||L7L7F--7|L7||||L--7|L-JFJ||LJL-7L7FJF-J||F7L----7||L7|L-J|FJL--JL--7FJ|F-JL------JL--7LJFJLL7.LFJ|", "L7LFJL|LJ-F|77.|LJL-------7L7L7|FJ|L7FJ||L7L7LJF7||FJ||LJF--JL--7|J|L-7F7|FJL7L--J||L7F-7FJ||FJL--7|L7F------JL7||F-----7F-----J-F7-7F7J||.J", "LJL-7LL|--F7|F7F---------7L7L-JLJFJ|||7||FJFJF-J|||L7|L-7|F7F7F-JL7L7FJ||||F7L7F--J|FJL7|L7LJL7F7FJ|.|L------7F|||L----7|L7F-7|F7||F7-77FF-7", "|LFJL.F77L|L-J|L--------7|FJF---7|F7||FJ|L7L7L-7||L7||F-J||LJ|L--7L7||FJ||LJ|7||F7FJL--J|7|F-7|||L7|FJF-7F---JFJLJF7F7FJL-J|FJFJLJLJ|FJF-JL|", "F|JLFL7J7|L--7|7F7LF--7.||L7|F-7|||LJ|L7L7L7L7F||L7|||L-7||F-JF7FJFJ||L7LJF-JFJLJ|L7F---JFJL7LJ||FJ||FJJLJF7LFJF7FJLJLJF--7||L|F7F7FJJ-JJF.F", "|-F-7-J--JL|-|L7|L7L-7|FJL7||L7LJ|L-7|FJFJ-|FJFJL-J|||F7|LJL-7||L7L-JL7L-7L7FJF--JF||F7-FJF7|F7||L7LJL-7F7|L-JFJLJ7F7F7|F-J|L-J|LJ||J|-LL|JJ", "JLJ.||.-7J|F7L7|L7|F7|LJF7|LJLL-7L7FJLJFJF7|L7L---7||||LJF---J|L7L---7L7FJFJL7L7F-7||||FJFJLJ|||L7L-7F-J|||F--JF7F7|LJLJL--JF7FJF7LJ7-77||L|", "|7LL|7-J-F-JL-JL7|||||F-J|L-7F-7L7|L--7|7|||FJF7F7||||L7FJF7F7L7|F7F7|FJL7|F7|FJ|FJ||||L7|F7L|||FJF7||F7|||L--7|||||F--7F7F-J|L-JL7JL-7-L|F7", "|-F-||7LJL-7F7F7LJLJLJ|F7L7FJ|FJ7||F7FJL7|||L7|||LJLJL7||FJLJ|FJ||||||L7FJLJ|||FJ|FJ|||FJ|||FJ||L7|||||LJ||F--J|LJLJL-7LJ|L-7L7F7FJ.|7J7LJ77", "-7L.L.J7F|FLJLJL7F7F-7||L-JL-JL7FJLJ|L7FJ|LJFJ||L---7FJ||L-7FLJ|||||||FJL-7FJ|||FJ|-|||L7||||FJ|FJ|||||F7LJL---JF----7|F7L--J|LJLJFFF7-J--JJ", "|F.FJFL7FFJ|F---J|LJJLJL--7F--7|L--7L-JL7|F7L-J|F-7FJL7||F7L7F--J|LJ||L7F7||FJLJ|FJFJ||FJ||LJ|FJL7||||||L--7F7F7L---7LJ|L-----7.LF-7||JJF|J7", "L77|JL-J-JLF|F7F7|F7F----7LJF-JL7F7L--7FJLJL7F-J|L||F7|||||FJL--7L-7||JLJLJ||F--JL7L7|LJFJ|F7LJF7LJ||LJL-7LLJLJL---7L-7|F-----JF7L7LJ|JFL|J|", "|LFL7L7.|7|.LJLJ|||LJF7F7L7|L7F7LJ|F--J|F7F-JL-7|FJLJ||||||L-7F-JF7|||F----J|L-7F-JFJL-7L7LJL7FJL--JL7JF7L7F-7F---7L7FJ|L--7F-7|L7|F-JF7JJL7", "L7J---7-F77FJ7|LLJL--JLJL7L-7LJL-7|L--7|||L-7F-J|L7F-JLJLJ|F-JL7FJLJLJL7F7F7L-7|L7JL7F7L7L7F-JL7F7F7FJFJL-JL7LJF-7L7LJFJF--J|FJL7||||F77.|F|", "LJLFFLJLLL|7FF-7F--7F77F7L-7|LF--JL---JLJ|F-JL-7|FJL--7F-7|L7F-JL-7F---J||||F7|L7|F-J||FJFJL--7||||||.L----7|F-J|L-JF7|FJ|F-J|F7|LJL7|||FFJ.", "|L7-LJJ||.L7-L7|L-7LJL-JL--JL-JF7F-----7FJL---7|||F7F7|L7LJFJL--7FJ|F7F7|||||LJJLJ|F7|LJ|L7F--JLJ||||F-----J|L7F77F-J|||F7|F-J|||F-7LJL-7|L-", "|-7..L7----J77|L--JF7F--------7|||F----J|F--7FJLJ||||||FJF-JJ|F-JL7||LJLJ||LJF7F--J||L---7||F---7LJLJL-----7|FJ|L-JF-J|||LJL--JLJL7L7F--JJL|", "77.|--J|F--7JFJF-7FJLJF------7||LJL--7F7LJF7|L--7||||LJ|FJF-7FJF7FJLJF7F-JL--J|L--7|L7F7FJ||L-7FJF7FF7F77F7LJL-JF--JFFJLJF7F-7F-7FJFLJF|7|.L", "||F|7JF77J.|FL-JJLJ||FJF7F--7LJ|F----J|L-7||L-7FJLJLJF-JL-JFJL7||L-7FJ|L-7F-7FJ7F-J|7||||-||7FJL-JL-JLJL-JL7F---J.F7FJF7FJLJ-|L7|L---77|-|JJ", "F|F|777L--|7F7.F7F-7FJFJLJF7L7FJL-----JF-J|L-7LJF-7F7L-7F-7L7JLJ|F7|L7L--J|FJ|7FJF7|FJ||L7LJFJF7F----7F7F-7|L-----JLJFJ|L---7|FJ|F-7FJJ|-JJ.", "-7|LJL-7.FF7|L7|||FJL-JF7FJ||LJF-------JF-JF7L77|FJ|L7FJ|FJFJF--J||||L-7F7|L7L7|FJ|||FJL7|F7L7|||F---J|LJFJ|F7F7F-7F7||L-7F7||||LJ-LJJL-77J.", "L.|-|-LF-7||L7LJLJL-7F-JLJFJF-7|F7F7F7F7|F-JL7L-JL-JFJL-JL7|LL7F-J||F--J||L7L7|LJJ||||F-JLJ|7||LJL--7FJF-JFLJ||LJ7LJLJF7JLJLJLJF--7F|.-JJL77", "|-F-|.FL7LJL-JF----7|L---7L7L7|LJLJLJLJLJL--7|F7F7F7L7F--7||F-JL-7LJL7F7||FJFJL7F-J||||F7F7L7LJF7LF7||7L-7F7F|L-------JL--7F---JF7L7-L7.FL77", "JF----F-JF-7F7|.F--JL7-F7L7L7|L7F7FF-7F7F---JLJ||||L-J|F-JLJL-7F7|LF-J|||LJFL7FJL-7|||||||L7|F-JL-J|||F-7LJL7L--------7F7FJL7F--JL-J7-7-7FJ7", "LF|JLLL7FJ|||||FJF--7|FJL7|FJ|FJ||FJFLJLJF----7LJ|L7F-J|F7.F--J||L7L--J|L---7||F--J|||||||JLJL7F7F7LJ|L7L---JF7F7F7F7|LJLJ7FJL--7F--7F7.|J-J", "F|.|.LLLJF-J|LJ|FJ|FJLJF7LJL7|L7||L------JF---JF7L-J|F7LJL7L-7FJ|FJF---JF7F-J||L7F7|||||||F---J||||F7|-L-7F--JLJLJLJL7F7F7FJF7F-JL7FJ||7J..|", "JLFFJ.FLFJF7L7-LJF-JF--JL7F7|L7LJL-----7F7L----JL---J|L7F-JF-J|FJL7L-7F7||L7JLJFJ|||||||||L-7F7|LJLJLJF--J|F7F--7F7F7LJLJLJFJLJJ-FJL7|L7.F7|", "|-J..F7LL7|L7L7F7L-7|F--7LJ|L-JF7F----7LJL------7F-7FJL|L77L-7||F7L-7||||L7L--7L7|LJ||||||F-J|||FF----JF--J|LJF7LJLJL------JLF-7FL7FJ|FJ7F77", "|JJF7.F-FLJFJFJ|L--J||F7L--JF7FJ||F--7L--------7|L7|L-7L7L-7FJ|||L-7|LJ||FJF7FJFJ|F-J||||||F7|LJFJF7F7FJ7F7L-7|L---7.F----7F7L7L7FJL7|L77||7", "|L-JJLF-L7-L-J-L----JLJL---7|LJFLJL7LL-------7FJ|FJ|F-JFJF7||FJ||F-JL7JLJ|FJ|L7L7|L--J||LJLJLJF-JFJLJ||F-JL-7LJF7F7L7|F---J||FJFJ|F-JL7L-JL7", "-F-F7|.LLF7JF-7F7F-7F7F7F--JL7F--7JL-7F-----7LJJLJFJL-7|FJLJ||FLJ|F7FJFF-JL7|FJ|LJLF7.LJLF7F-7|F7L7F-J|L--7LL7FJ||L7LJ|FF-7|LJFJL|L7F7|F--7|", "FJ7|F7.77LF7L7|||L7LJLJ|L--7FJL-7L---J|F----JF7-F7L---JLJFF-J|F7-LJ||JLL7F7|LJJ7F--J|F--7|||FJLJL-JL--JF--JF7|L7|L7|F7L-JFJ|F7L--JFJ|LJL-7||", "7LL|7FF77.|L7|||L-JF7F7L-7JLJJF7L-----JL----7||FJL--7F7F-7L-7LJ|7JFJL7JFJ||L-7|FL--7|L-7||LJL7|F7FF7F7FJF--J||FJL-JLJL--7L7||L7F-7L-JF---JLJ", "F7LJL-JF--L7LJLJF--JLJL-7L---7||LF7F7F7F----J||L7F--J|LJFJLLL7FJ.FL7FJFJFJL--JF----JL-7||L-7FJFJ|FJLJLJFJF--JLJF-------7L7LJL7|L7|F-7L--7F-7", "7JJ..F|77.LL7F--JLF7F7F7|F--7LJL-JLJLJLJ.F---JL-J|F77|F-JJ|LLLJJ.F-J|FL-JJJJ-|L7F--7F7||L7FJL7L7||F--7FJLL-7|F-JF-7F7F7L7L7F7||FJ|||L7F-J|FJ", "L7.|-7J.7J-FJL7F--JLJLJLJ|F-JF---7F7JF7F-JF-----7LJL-J|J|LF.FLJ-L|F7L7JL7.|J|F7LJF7LJ|||FJL-7L-J|LJF7LJF--7L7|F-JFLJLJL-JLLJLJ|L7LJF-JL--J|J", "|LFF.FJF|LFL--JL-7F-7F---JL--J|F7LJL-J||F-JF---7L7F---JF7JLL7-J-.LJL-JJ.FJ---JFF-JL--J|||F-7L7F7L7FJ|F7L-7L-J|L-7F7F7-F-----7LL7L-7L7F7F7FJ-", "JLFJLJFJJJFF-7F--JL7LJF7F7F---7||F---7||L--JF--JFJL--7||L-7L|77|.|JJLJ-|77L-77FL7F---7||||FJLLJL7|L7LJ|F7L---JF-J||||FJF7F--JFF|F7L7LJ||LJ77", "|-L7.FFFF-F|FJL----JFFJLJ|L--7|||L--7|LJF--7L-7-L7F-7L-JF7|FJ-77-L|-|JL|LLFJFF-7LJ|F-JLJLJL-77F7||FJF7LJ|F--7FJF7|LJLJFJ|L7F-7FJ|L7L-7|L--77", "|..LFFF|JLFJL--7F7F7FJF-7L---JLJL---JL7FJF7L-7L77LJJL---JLJ7LFJ|L-7FJ|||7FF77L7|F7FJF7F-7F--JFJ|||L-JL-7LJF7|L-JLJF---J.L7LJFJL7|7|F7|L7F-J7", "FFF7LJJLJLL---7LJ||LJFJFJF7F7F7F7F---7|L-J|F7L-JF-7.F7F77|-FF7.JJFL.L7----|L7FJLJ|L7|LJFJL7F7L7|||F7LF7L--J|L7F7F7L---7F7L--JLFJ|FJ|||LLJ|.7", "-J-J|.FLFF---7L-7LJF7|7L7|LJLJLJ||F--JL--7LJL7F7|FJFJLJL777FJL7|7|J-L.L|JFL7|L7F-JJLJJFJF7LJ|.|||||L7||F7F7L7|||||F7F-J|||F-7LL7|L7|LJ|LLJFJ", "|.|777|.|L-7FJF7L--J||F-J|F----7LJL---7F7L---J|LJL-JF---JF7|F-JFFJ--F77J.FFJL-JL---7F7L-JL-7L-J|||L7LJLJLJL-JLJLJLJLJF7|L7|FJFLLJFLJ.FLF-F|.", "|FF-J7|FF7FJL7||LF77LJL--JL---7|F7LF--J|L--7F-JF-7F7L7|F7|||L-7F|L-JLJ|F-|L7F-7F7F7LJL----7L--7LJL7L---------7F7F7F--J||FJ||F7J-|JJ-|-7|-LJ7", "|FL-LFF7||L-7||L-J|F7F7F-7F7F-JLJ|FJF7FJF--J|F-J7LJL7|FJLJLJF7L-7J.|.LL--L7LJFJ|LJL--7F--7L---JF-7L---7F-----J|||||F--J||FJLJL7F7J7.|.--FJ.J", "LL.F|F|LJ|F7||L--7LJ|||L7LJ|L---7|L-JLJFJF--JL7F7F-7LJL--7F-JL--JF-.-L777||L|L-JF7-F7LJF-JF7F7FJL|F7F7LJF--7F7|||LJ|F--JLJF7F7LJL-7-77JLJJ7|", "F7-LF-|F7LJLJL--7L-7||L7L-7L----JL-----JL|F-7FJ|||FJLF-7FJL---7.LFF7F|.L-F7-F--7||FJL7JL7FJ||LJF-J|||L7FJF-J|||LJF7LJF----JLJ|F7F-JFJ7LF|.F-", "LL7-L-LJL---7F-7L-7||L7|F-JF--7F-7F------JL7LJFJ||L-7|FJ|F--7FJ7F7J|FL-JJL7FL-7|||L7FJF7||FJL-7L7FJ||FJ|FJF7|LJF7||F7L------7LJLJF|J||F-FJ77", "|LJ7J-|FF---J|FJF7LJL-JLJF7|F-J|.||F----7F7L7F|FJ|F-J||FJL-7LJJJF.|-L7F|.LFF--JLJL-J|FJLJ||F-7|FJ||LJL-JL-JLJF7|||||L--7F7F-JF7F7FF-J.||..JJ", "LFJF.F7-L---7|L7|L7F7F7F7||||F7|FJ|L---7LJL7L-JL-JL7FJLJF--JF7FF|FJ7FL---FJL-7F7F7F7LJF-7||L7LJ|FJF---------7|LJLJ|L--7||LJF7|LJ|7L|7.-L-7.|", "|LFFFJL-----J|FJ||LJLJ||LJ||||LJL-JF7F7L--7|F7F--7FJ|F-7L---JL---7J|7.FJJL|J.LJ|||||F7L7|||FJF-J||L--------7|L---7L7F-JLJF7|||F-JJFJL7|J.J7F", "|F|.L-------7||FJF----JL-7LJLJF77F7|LJL7F7|||||F-JL-JL7|F--------J7L|7|L77||-FLLJLJ||L7|||||JL--JF7F7F7F---JL7F7FJFJL--7FJLJLJL-7F7J.F7L|-||", "L--.LF------J|LJFJF-7F7F-JF7-FJL-JLJ-F7LJLJ|||||F-7F7FJ|L-----7F77LF7777L-L-7-.|JF-J|FJ|||||F--7||LJ|||L--7F7LJLJ|L----J|F---7F-JF7F-JL-7.LF", "LLJ..L-7F-7F7L7.L-JFJ|||F-J|FJF7F7F--JL7LF7||LJ||L||LJFJF7F-7FJ|L7F||F77F||.|JFJJL--JL-JLJLJL-7L7L-7||L---J|L--7F7F7F7F7|L7F7LJF7||L7F--J7|J", "F|FJJJ-LJ7||L-J7F-7L-JLJ|F7LJFJ||LJF--7L-J||L-7|L7|L-7L-J||JLJ||FJ-||||F7-7.LFJ|7FF-7F7F7F-7F7L7|-FJ|L-----JF--J|||LJ|||L7LJL-7|||L-JL-7-LL7", "F--7-F.F--JL--7-L7L-----J||F-J7LJF-JF7|F7FJ|F7|L7|L7FJF7FJL-7F7||F7|LJLJL-77F-77F7L7|||||L7LJ|FJL7L7L------7L---J||F-J||FJF---J|LJF--7FJ7J|F", "|FLL-JFL7F7F7FJF7L7F-7F-7|||F----JF7||LJ|L7LJLJFJ|FJL-J|L--7||||||||F-----JFL7|FJL-J||LJ|JL-7||F7L7L-----7JL--7F7LJL-7||L7|F7F7|F-JF7LJ-F.FJ", "F7|.LFJLLJ||LJFJL7LJFJL7||||L-----JLJL-7L7L7FF7L-JL----JF-7|||LJLJLJ|JF-7F7F7||L--7FJL-7|F7FJ|LJL7|F7F--7L---7LJL7F--J||F|LJLJLJL--JL---77J7", "FL-77|.77.|L7LL-7|F7L7FJLJLJF7F-7F7F7F7L7L7L-JL7F---7F-7L7|LJL----7FJFJFJ|||||||F7||F--J|||L7L---JLJ||F7L---7L--7|L-7J||FJF---7F7F------JJ|F", "||L-|J.FF7L-JFF7|LJL7||F--7FJLJFJ|||LJL-J|L----JL7F-JL7L-JL7F--7F-JL7L7|FJ|||||FJ|||L-7FJ||LL----7F7LJ||F--7|F--JL-7L-JLJFJLF7LJLJF7F--7LF-7", "-7|7|.F-JL-7LFJ|L7F-JLJL-7LJF-7|FJ|L-------------JL-7FL--7FJ|F-JL--7L7|||FJ|LJ|L7LJL7FJ|FJ|F-----J|L--JLJF-JLJ-F7F7L--7F7L--JL---7|LJF7|7--J", ".L-L..L---7|-|FJFJL7F7F-7L--JFJ|L7|F---7F7F7F7F7F7F7L7F-7|L-JL7F--7L7||||L7L-7|-L-7FJL7||FJ|F7F--7|F-----JF---7|LJL--7|||F7F7F7F-J|F-J|L7LFJ", ".FJL77F||7||FJL7L7FJ||L7|F--7L7L-JLJF-7||LJLJLJLJLJL7|L7||F---JL-7|FJLJ|L7L7FJ|F7FJL7J|||L7LJLJF7LJL------JF-7LJF--7FJ||||LJ|||L--JL77L-J7J7", "F-7F7F77F-J||F-JFJ|FJL-JLJF7L7|F-7F-JFJLJ-F7F----7F7LJFJLJL7JF7F7|||F--JFJFJL7|||L-7L7|LJFJ-F--JL---7F--7F-JFJF-JF7LJLLJ||F-J||F-7F7L----7.-", "LLF|||L7L-7|||F7|FJL--7F--JL7LJL7||F-JF7F7||L7F--J||-FJF7F7L7|LJLJLJL7F7L7|F7||||F7L7||F-JF7L------7LJF7LJF7L-JF-JL7F7F7||L-7|LJFJ||F7F--J77", "LF-JLJFJF7|||||LJL--7FJL---7L---JLJ|F7|LJLJL-JL-7FJL-JFJ||L-JL-7F7F-7|||FJ||||||LJL-JLJL-7||F----7FL--JL--JL7F7|F--J||||LJF7|L7|L-J|||L--77|", "|L-7F7|FJLJ|||L--7F-JL7F---JJF-----J|LJF7F7F----JL----JFJL7F7F7LJLJFJLJ|L7LJ|||L--7F----7LJ|L-7F7L7FF------7LJLJL---JLJL--J|L7L7F77LJ|F7FJ7|", "|FLLJ||L--7LJ|FF-JL--7LJF-7|FJF7F7F-JF-JLJLJF7F7F7F--7JL-7LJ|||F-7FJF--JJL7FJ||F--JL---7L--JF7LJL7L7L----7.L7F7F-7F---7F7F7|LL7LJL--7LJ||-J7", "F|JLFJ|FF7L-7L7L-7F--JF7L7|FJFJLJLJF7L-7F-7FJLJLJLJF-JF7FJF-J||L7||FJF77FFJ|FJ|L--7F7F-JF--7||F-7|FJF----JF7LJ|L7|L--7|||||L7FJF7F--J.LLJL||", "LJFFL7|FJL--JFJF-JL7JFJ|FJLJFJJF---JL--J|FJL--7F-7FJF7||L7L--J|.|||L7|L7FJFJL7L7F7LJ|L-7L7FJ||L7|||-L7F7F7|L-7|FJ|F--JLJLJL7||FJ|L-7-|J||--7", "F77F-JLJF-7F7L-JF-7L7|FJL---JF7L-7F-7F7FJL7F7-|L7LJ||LJ|.L7F--JFJLJFJ|FJL7|F7|FJ||LFJF7L7|L7||FJLJL7FJ|||||F-J||FJ|F7JF7F7JLJ||J|F7L--77|.LF", "FLL|F7F7L7LJL7F7|FL7LJ|F7F7LFJL7FLJFJ|||F-J|L7L7L7F7L-7|F7|L-7FL7F-JFJL7-||||||FJ|FJFJL-JL7||||F-7FJL-JLJLJL7|LJL7LJL-JLJL--7|L7||L-7FJ7F7L|", "|7LLJ||L7|F-7||||F-JF7LJLJL-JF-JF7LL-J|||F7L7L7|FJ|L7FJLJLJF-JF7|L-7L-7|FJLJLJ|L7|L7|FF7-L|LJ|LJFJL7F-7F7F-7L7|F7L-7F7F----7||FJLJ7-LJL7JLFJ", "|FFF-J|FLJL7LJ|LJL--JL------7||FJL----J|LJ|FJFJ|L-JFJL--7F7L7FJLJF-J|FJLJF--7FJFJL-JL-JL7FJF-JF-JF-JL7LJ|L7L7L-JL7L|||L---7LJ|L7J-7J.||..FL|", ".|JL-7|F---JF7L7F-7F-7F--7.FJL-JF7F--7FJF-JL7|FJF--JLF-7LJ|FJL--7L--7L-7FJF7LJJL--7F7F7FJL7|F7L-7|F-7|F7L-J.L----JFJ||F---JF7L-JL7JF7.FJFF-J", "FLFL-||L-7F-JL-JL7LJFJL-7|FJF-7FJ||F-JL7|.F7||L7|F7F7|FJF7||-F7||F7FJF7||FJL7-F7F7LJ||LJ|7||||FFJ|L7|LJL-7F------7L-J|L----JL---7JJ|FF||LJ|J", "--LL-LJF7LJF---7FL-7L---JLJFJ-||-LJL7F7||FJ||L7|LJ||||L7||||FJ|FJ|LJFJLJLJF-JFJ|||F7|L7F7FJ||L7L7|FJL7F-7LJF7F-7FJF77|F7F--7F---J|.|F-LJJF-.", "|.7JLLFJL7.L--7L---JF7F7F-7L-7|L7F--J||||L7||FJL-7||||FJ||||L7|L7|F7L--7F-JF7L7||||||FJ||L7|L7|.||L-7||FJF-J||F|L-JL7|||L-7|L----777.|-L7F|7", "|-J.|LL-7L7F7FJF7F7FJLJ|L7L7FJ|FJL7F7|||L7||||F7FJLJ|||FJ||L7|L-JLJ|F--JL7FJ|FJ||LJ||L7||FJ|FJL7|L7FJ||L7L-7|L7L----J|||F-J|F7F-7L-7FFF7|.-7", "|7FF77||L7LJLJFJLJ|L7F7|FJFJL7||F-J|||LJFJ||||||L7F-J|||J||FJL-7F7FJL7F-7|L7||FJL77||FJ||L7|L-7||||L7|L7L--JL7L-----7|||L-7|||L7L--J7-J7L7-|", "F-||.FF-LL-7F7|F--JFJ|LJL7|F7|LJL-7||L7FL7|LJLJL-JL7FJ|L7||L7F7LJ|L-7|L7LJFJLJ|F7L7LJL-JL7|L--JLJFJFJL7L-7F-7|F7F---J||L--JLJL7L--7J-JF7-7.|", "-.LJ7F.LLF7LJ||L7F7L7L7F7|||LJF---J||FJF-J|F7.F----JL7|FJ||FJ||F7L7J|L7L7FJF--J||FJLF----JL7F7LF-JFJF-JF7LJFJLJ|L--7FJL---77|LL---J-|F-J-L7J", "LFL-|L7-FJL-7LJFJ||FJFJ|||LJF-JF7F-J|L7L-7LJL7|F-7F7FJ|L7||L7|||L7L7|FJFJL7L-7FJ|L-7|F-7F7FJ|L-JF7L7|F7|L7FJF7FJF--JL7F-7FJ-JJ.||7.FL|7|.FJJ", ".|7F|-7JL--7L--JFJ|L7|FJLJF7L--J||F-JFJF-JF--J||FJ||L7L-JLJFJ||L7L-JLJFJF-JF7LJJL7FJLJFJ||L7L--7||FJLJ|L7|L-J|L7L---7||LLJJ7JFFJ|L.F-L|-LJL.", "..--7.J|F--JF-7FJFJFJ||F--J|F---J|L7FJ7L-7L-7|LJL7|L7L---7FJFJL7L----7L7L--JL--7J||F7FJFJ|FJF--J|LJF-7|FJ|F--JFL7F--J|L--7J||L7.|JFL7.LJ.FF-", "77.J.L|7L7F7|-LJ|L7|-LJL--7LJF7F-JFJ|JF--JF7L7LF-J|-L7F--JL7|F7L-7F7FJJL7F-7F-7|FJLJ|L7|FJL7L7F7L--JFJ|L7|L-7.F7|L--7|F--JJL--|-|FF-F|J.F|J7", "F7.|7.F--J|||-L7F7LJF-----JF7||L7-L7|FJF-7|L7|FJF7L-7|L--7J|LJ|F-J|LJF-7LJFJL7LJL7F7|LLJL7FJFJ||F7F-J.L7||F7L-J|L7F-J|L7L|.LJ-7.F|J-|J|7FJ7|", "LJ.FF-L--7|LJ..FJL--JF7F7F7||||FJF-J|L7L7||.||L7||F-J|F-7|FJF-JL-7L-7L7L--JF7L--7|||L7-F-J|.L7||||L7F7FJ|LJ|F-7L7|L7-L7L-7-|.F|-JJFFJF-L--J-", "FFF|.FJJJLJ.|7FL-7F7FJ||||||LJ|L7L--J-|FJ|L7||.||||F-JL7||L7|.F7-|F7L7L--7FJ|F-7|LJ|FJFJF7L-7|||||FJ||L7L7-|L7L7|L7L-7|F-J||7-L.J-L|.|.L|-|7", "F|LJ.L.LFL7-JJ|||LJ|L7||LJLJF-JFJF----JL7L-J|L7||LJ|F7FJLJFJL-J|FJ|L7L7F-JL7|L7|L-7||JL7||F7||||||L-J|-L7L7|FJ-LJFJF-JLJJJ|LJ-L7JF.L7-.FJFF-", "..7L-7F7LLF-|FFL7J.L7|||F--7L7FJ7L7F7F-7L7F-JFJLJF-J||L-7FJF--7|L7|LL7|L--7|L7|L-7|||F-J|LJ||LJ||L7F7L-7L-JLJF7F7L7L---7J.|F|7.7.LF-JJFLF7J.", "L-F7F7-|---J.F.LJ.F.LJLJL-7L-J|F-7LJ|L7|FJL7FJ|F7L-7|L7FJ|FJF-J|FJL-7||F--J|FJL77LJLJ|F7L-7LJF-JL7|||F7L-----J||L-JF--7L--7JLFLL7J.F|..L--J.", "LLLL|J-J-7L--J-L--L-LJLF--JF7FJL7|F7|FJ||F7|L-7||F-J|-|L7|L7L--J|F7FJLJL7F7||F7L7F---J|L-7L7JL7F-J||||L---7F7FJ|F-7L-7|F--J7L|L-F--J---7LJ.|", "F-JL|L7LJJ..J..F..|J|JLL---J||F-JLJLJ|FJLJ||F-J|LJF7L7L7|L7L---7|||L--7FJ|||||L7|L-7F-JF7L7L-7|L7FJ||L---7LJLJL|L7|F7|LJ7FL7.-|.7FJJJ.|77|LJ", "|.|.J-F7|LF7.FFJ7FJ|.F-F7F--J|L7F-7F7|L7F7||L7JL-7||FJLLJ.|F7F7|LJ|F-7|L-J|||L7||F-JL-7|L-JF-JL-JL7||F-7FJF7LF7|FJ||LJ|L77LL7.LJJLF77-L7-7LF", "7F777LF-7--7L-|7|7|-FF7||L7F7L7|L7|||L7|||||FJF--J||L----7|||||L7FJL7LJ|F-J||FJ||L7F7FJL7F7L-----7|||L7||7|L-J|||7LJJF-FJFF.|-LL7-7JFJ|.F||J", "|J|L7FLL77-|L||L7LL--F7||.|||FJL7|||L7|||||||FJF--J|F--7FJ|||||FJ|F7L--7|F7|||FJ|FJ||L7J|||F-7F7FJ||L7||L-JF7FJ|L-77|F|LLFJ-F.LL.F77|.LF7L7.", "|F-.7J-LL|LJ7F|-J7|7L|LJL-J|LJF-J||L7LJ||||||L7L7F-JL7FJL7||LJLJFJ||F7FJLJ||LJL7||FJ|FJFJ||L7||LJJ||-LJ|F7FJ||7L-7|---L--L77.F.LF7L7JL-F7-|7", "J7-7|LF.JJ7F7-L7L77-FJF7F-7L-7|F7||FJF-J|||||JL-JL-7FJL--J|L---7L-J|||L7J.LJF--J||L7LJLL7||FJ|L-7FLJ.F-J||L7|L-7LLJ|LF7|L-JF-|.||J|L7.|L7FL|", "LF7|J.|7JLF|J.||7|J7L7|||F|F-JLJLJ|L7L-7|LJLJ|LF---JL--7F-JF7F7L-7FJ|L7L7JJLL-7FJ|FJF---J||L7|F7L-7F-JF7|L7||F7|-JLFLJ-J7.FL-|-JJ-7-|.L|FJ7|", "F7J7-LF7L-F|FF-J-F.-L|||L7LJJJ.|JLL7|F-JL7JLL-FL---7F--J|F7|||L7FJ|FJL|FJJJLJFJ|L||JL7F-7||FJ|||F-JL-7|LJFJ|||||7||.LL.||.FFLJJ|F-----JJ|-7J", "-L---JF7|.LJ--JL|..LL||L-JJJ...|-|FLJ|F7FJ.|L-F7F--JL--7||||LJ-||LLJ|.LJJJ-F-L7|FJ|-L||FJ|LJL|||L-7-LLJJLL7|LJLJ7FLJ7|F-J77J7|.LL7|7L|.|LL||", "|FFL-7|.F--7L-J7.F7.LLJ-LJ|F|F7|F-F--J|||7L-FFJLJF7F-7FJ||LJJ|JLJ-|-L.||-F.|J7|||FJ-FLJ|FJF--J||F-J-|J||LFJL7J|-77JL|FF7JJL7F|-.|-J7JL7L-777", "L|J|7|FJ7.F|F7FJF7J|.L|.LF7|||||JFL-7FJLJJJ-FL7F7|||FJL7|L7JJLFL|L7J.FJ.7LFL7-LJLJ.|.|LLJ|L7F7||L77FL-|-.L-7|-7|L-7-|7L7L-|-L7|7F.FL7L7FJ|-7", ".JJ|FL7LL7-J7JJ.L-.|77F7FLFF-LLJ.F||LJJ.|-F7JJ||||LJL7FJL-JJ.-FLF-L-JJ|7L7L7L.|.LJFJ7LFJ-FJLJ|||FJ-7-F|JF||LJ-.F|J|LF|F|7-L7.L-L7.|.L-JJ.|J|", "F|7LLJJJL|FL|.|-7FF||||LJ7JF-L--7FJL7LLF|7LFJFLJ|L--7||JJ||.7.FJLLJ|.--JFJ.JF-J-7FL7|FL--F-7L||||J.|.F7LFLLJJ7-7|7|7LLJ.---|-7J.L7F|7F|.L7.J", "-L-|.FF7.-JJ|7.FFJ-LL7J|.F-JJL--F7JFJJ7|.|F|F7JF|F7FJLJF-LJ.7-J7FJ.7J-JF7JF-J||LFLJLL7L|7J.L-LJ||--JJ7--LL7||F--|J7J7.L-7|7LF7.F.F.JF|J7LJF|", "L-77.F7-JJ.LL---F77JLJF7-|.|LFJ.||-FJJ|JF|-7||LFJ|||7.|--|F7L-J-|FLJ|FF||FLL-FJ.|JJ|L7-777FL7|.LJ7.|7.|-LLFFJ|.||FLJFF7|7L--|.|L-|7FJJFJF-L7", "L-LJF||-JF77-|JJ.LJL-JLJ.FJJ7|-|L|FF--F-FJLLF-.L-JLJJ.FJ.|JL7F-7FJF-|7F.J-L|||F7JF77FJ-LF7|JF7.|JL--7.F7-F|JJL--|7.F|LLJ-J.||FL-|.J-J|L.|FF|", "LFL||LLJL7|||J.|FL-F-FJ|-|-|-J-L7.-7.FL7L--777FJ|JLJ.FL---J7.L.FF--7L7L|.LL--||-F-JJ7FLLF-|.FL-|.7..|FFJF7J.|L|-77F-|L7F7LF-7J|.J77JF7|7.L7J", "FF-L|-J7..FFJ77F|J|L7LFLJLLF-77.F|JJFL|JFJ.J|FJ7|.|LFJJ77F7-J-7JL--|7|J|F-.|7L|L-7|L-77FJ-|F||.L-.--LLJ-.J.F|.--LFJ.|J|J|..-J7F7JF7--.FL7-|.", "FL77J|J|FFL7|J7J|.-LJ7.L77L|L|F-7.|JF-|7L77|||L7|F|JL7JLJ7.7FF.F7J.F-JF7|.F-LJL7JJL--77L---7LF-|..|.J.L|77.|J7F77JFJ|.|F7.|-L|FJ7L7FLFJ.L.-J", "FJLJ--JLL|-|JJL-LJL-JL7-LLJLFL.F-7LFJ.FJLF7-J--JJJJ.L-F-JL-|JJ-FJ-L7J-|L--LJJLLL-JJL-L--L|JJLL--F-JJL7J|--|7-J-L7LF-L7JL7-F-FJLJ-LJJJLL7--JJ"};
}