#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 0;
    fstream file;
    string word, t, q, filename;
    int r = 12, g = 13, b = 14;

    // filename of the file
    filename = "02_input.txt";

    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    int cur = 0, red = 0, green = 0, blue = 0, pos = 1;
    while (file >> word)
    {
        // displaying content
        if (word == "Game")
        {
            file >> word;
            word.pop_back();
            cur = stoi(word);
            pos = 1;
            red = green = blue = 0;
        }
        else
        {
            int val = stoi(word);
            file >> word;
            if (word[0] == 'r')
            {
                red = val;
            }
            else if (word[0] == 'g')
            {
                green = val;
            }
            else
            {
                blue = val;
            }
            if (red > r || green > g || blue > b)
                pos = 0;
            if (word[word.size() - 1] != ',' && word[word.size() - 1] != ';' && pos)
                ans += cur;
        }
    }
    cout << ans << endl;
    return 0;
}