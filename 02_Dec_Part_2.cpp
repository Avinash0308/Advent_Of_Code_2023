#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 0;
    fstream file;
    string word, t, q, filename;

    // filename of the file
    filename = "02_input.txt";

    // opening file
    file.open(filename.c_str());
    // extracting words from the file
    int red = 0, green = 0, blue = 0;
    while (file >> word)
    {
        // displaying content
        if (word == "Game")
        {
            file >> word;
            red = green = blue = 0;
        }
        else
        {
            int val = stoi(word);
            file >> word;
            if (word[0] == 'r')
            {
                red = max(val,red);
            }
            else if (word[0] == 'g')
            {
                green = max(val,green);
            }
            else
            {
                blue = max(val,blue);
            }
            if (word[word.size() - 1] != ',' && word[word.size() - 1] != ';' )
                ans += red*green*blue;
        }
    }
    cout << ans << endl;
    return 0;
}