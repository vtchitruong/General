#include <bits/stdc++.h>

#define inputFile "maxvalue2.inp"
#define outputFile "maxvalue2.out"

using namespace std;

typedef long long lol;

int n; // number of elements
int m; // number of queries
vector<vector<int>> query;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n >> m;

    int a, b, k;
    query.resize(m);
    for (int i = 0; i < m; ++i)
    {        
        f >> a >> b >> k;
        query[i].push_back(a);
        query[i].push_back(b);
        query[i].push_back(k);
    }

    f.close();
}

lol maxvalue()
{
    vector<lol> s(n + 1, 0); // init

    int a, b, k;
    for (int i = 0; i < query.size(); ++i)
    {
        a = query[i][0];
        b = query[i][1];
        k = query[i][2];

        s[a] += (lol) k; // cast ép kiểu
        if (b + 1 < s.size()) s[b + 1] -= k;
    }

    lol sumMax = 0;
    lol sumTmp = s[0];
    for (int i = 1; i < s.size(); ++i)
    {
        sumTmp += s[i];
        if (sumTmp > sumMax) sumMax = sumTmp;
    }

    return sumMax;
}

void Output()
{
    lol res = maxvalue();

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