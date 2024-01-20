#include <iostream>
#include <vector>

using namespace std;

int n = 1e7; // số phần tử của prime
vector<bool> prime;

// Sàng Eratosthenes lọc ra các số nguyên tố trong phạm vi đến 10 triệu
void sieve()
{
    // Khởi tạo    
    // Giả sử mọi số đều nguyên tố
    prime.resize(n + 1, true);
    
    // 0 và 1 không phải số nguyên tố
    prime[0] = false;
    prime[1] = false;

    // Đánh dấu false cho các bội của số nguyên tố p
    for (int p = 2; p * p <= n; ++p)
    {
        // Nếu p là nguyên tố thì đánh dấu false cho bội của p
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
}

void showAll(int l)
{
    for (int i = 1; i < l; ++i)
    {
        cout << i;
        if (prime[i] == true) cout << ": true";
        cout << endl;
    }
}

int main()
{
    sieve();

    int limit = 100;
    showAll(limit);
    
    int k = 9999991;

    if (prime[k] == true)
        cout << k << " is prime";
    else
        cout << k << " is not prime";  

    return 0;
}