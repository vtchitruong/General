#include <bits/stdc++.h>

#define inputFile "prime2.inp"
#define outputFile "prime2.out"

using namespace std;

const int M = 1E8;

int q; // number of values to be tested
vector<int> value;

bitset<M> prime;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> q;

    int v;
    for (int i = 0; i < q; ++i)
    {
        f >> v;
        value.push_back(v);
    }

    f.close();
}

void Init()
{
    prime.set(); // set bit 1 for all
    
    prime[1] = 0; // 1 is not prime
}

void Sieve() // Sieve of Eratosthenes
{
    Init();

    // duyệt từ 2 đến căn của n
    for (int i = 2; i * i <= M; ++i)
    {
        // nếu i nào là nguyên tố, thì đánh dấu các bội của i là bit 0, tức không phải nguyên tố
        if (prime[i])
        {
            for (int k = i * 2; k <= M; k += i)
            {
                prime[k] = 0;
            }
        }
    }
}

bool isPrime(int n)
{
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0) return false;
    
    int sqn = sqrt(n);
    for (int i = 2; i <= sqn; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void Output()
{
    vector<string> res;
    bool r;
    for (int i = 0; i < value.size(); ++i)
    {
        if (value[i] < M) // call Sieve for small value
        {
            r = prime[value[i]];
            if (r)
                res.push_back("Prime");
            else
                res.push_back("Not prime");
        }
        else
        {
            if (isPrime(value[i])) // call isPrime for big value
                res.push_back("Prime");
            else
                res.push_back("Not prime");
        }        
    }

    ofstream f;
    f.open(outputFile);

    for (int i = 0; i < res.size(); ++i)
    {
        f << res[i];
        if (!(i == res.size() - 1)) f << '\n';
    }

    f.close();
}

int main()
{
    Input();

    Sieve();
    Output();

    return 0;
}