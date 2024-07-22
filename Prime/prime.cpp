#include <iostream>

using namespace std;

// Hàm kiểm tra tính nguyên tố
bool isPrime(int n)
{
    // Số âm, 0, 1 không là nguyên tố
    if (n < 2) return false;

    // 2 và 3 là nguyên tố
    if (n < 4) return true;

    // Hoặc chia hết cho 2, hoặc chia hết cho 3 thì không là nguyên tố
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;
    
    // Kiểm tra n có chia hết cho 5, 7, 11, 13, 17, 19, v.v...
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
    }

    return true;
}


int main()
{
    // Các số cần kiểm tra tính nguyên tố
    int numbers[] = {-1, 0, 1, 2, 3, 4, 5, 100000031, 100000032, 100000033, 100000037, 100000039};
    
    // Số phần tử của mảng numbers
    int size = 12; 

    // In ra kết quả
    for (int i = 0; i < size; i++)
    {
        bool check = isPrime(numbers[i]);

        cout << numbers[i] << ": " << check << endl;
    }

    return 0;
}