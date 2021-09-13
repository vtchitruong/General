#include <bits/stdc++.h>

#define inputFile "leftshift2.inp"
#define outputFile "leftshift2.out"

using namespace std;

int n;
int d;
vector<int> a;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n >> d;

    for (int i = 0; i < n; ++i)
    {
        int x;
        f >> x;
        a.push_back(x);
    }

    f.close();
}

// Approach 1
void LeftShift()
{
    for (int step = 0; step < d; ++step)
    {
        a.push_back(a[0]);
        a.erase(a.begin());
    }
}

// Approach 2
vector<int> LeftShift2()
{
    vector<int> res; // result

    d = d % n;

    for (int i = d; i < n; ++i)
    {
        res.push_back(a[i]);
    }

    for (int i = 0; i < d; ++i)
    {
        res.push_back(a[i]);
    }

    return res;
}

void Output()
{
    // LeftShift();

    vector<int> result = LeftShift2();

    ofstream f;
    f.open(outputFile);

    /*
    for (int i = 0; i < a.size(); ++i)
    {
        f << a[i];
        if (i != a.size() - 1) f << ' ';
    }
    */

    for (int i = 0; i < result.size(); ++i)
    {
        f << result[i];
        if (i != result.size() - 1) f << ' ';
    }

    f.close();
}

int main()
{
    Input();
    Output();

    return 0;
}