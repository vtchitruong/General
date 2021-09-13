#include <bits/stdc++.h>

#define inputFile "matchstring1.inp"
#define outputFile "matchstring1.out"

using namespace std;

int n;
vector<string> strings;

int q; // number of queries to be matched
vector<string> query;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n;

    for (int i = 0; i < n; ++i)
    {
        string tmp;
        f >> tmp;
        strings.push_back(tmp);
    }

    f >> q;

    for (int i = 0; i < q; ++i)
    {
        string tmp;
        f >> tmp;
        query.push_back(tmp);
    }

    f.close();
}

vector<int> MatchStrings()
{
    map<string, int> m;

    for (int i = 0; i < strings.size(); ++i)
    {
        m[strings[i]]++;
    }

    vector<int> res; // result of matching
    for (int i = 0; i < query.size(); ++i)
    {
        res.push_back(m[query[i]]);
    }

    return res;
}

void Output()
{
    vector<int> result = MatchStrings();

    ofstream f;
    f.open(outputFile);

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
