#include <bits/stdc++.h>

#define inputFile "hourglass.inp"
#define outputFile "hourglass.out"

using namespace std;

vector<vector<int>> a;

void Input()
{
    ifstream f;
    f.open(inputFile);

    a.resize(6);
    for (int r = 0; r < 6; ++r)
    {
        a[r].resize(6);

        for (int c = 0; c < 6; ++c)
        {
            int x;
            f >> x;
            a[r][c] = x;
        }
    }

    f.close();
}

int MaxSum()
{
    int sumMax = INT_MIN;
    int s; // temp sum
    for (int r = 0; r < a.size() - 2; ++r)
    {
        for (int c = 0; c < a[r].size() - 2; ++c)
        {
            s = 0;
            s += a[r][c] + a[r][c + 1] + a[r][c + 2]
                + a[r + 1][c + 1]
                + a[r + 2][c] + a[r + 2][c + 1]+ a[r + 2][c + 2];

            if (s > sumMax) sumMax = s;    
        }
    }
    return sumMax;
}

void Output()
{
    int res = MaxSum();

    ofstream f;
    f.open(outputFile);

    f << res;

    f.close();
}

int main()
{
    Input();
    Output();

    return 0;
}