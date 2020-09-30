#include <bits/stdc++.h>

using namespace std;

int pos[] = {2, 4, 10, 13, 18, 20, 8, 1, 1, 8, 9, 10, 31, 11};

int main()
{
    ifstream in("secret.txt");
    ofstream ou("secret_out.txt");
    string line;
    string res = "";
    int cnt = 0;
    while (in >> line)
    {
        line = line + '\n';
        if (line.length() % 5 && line.find("Q_bug") == string::npos)
            continue;
        ou << line;
        res += line[pos[cnt]];
        ++cnt;
    }
    cout << res << '\n';
    return 0;
}