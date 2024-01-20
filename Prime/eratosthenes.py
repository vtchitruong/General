import math

n = 10000000 # số phần tử của prime
prime = []

# Sàng Eratosthenes lọc ra các số nguyên tố trong phạm vi đến 10 triệu
def sieve():
    # Khởi tạo    
    # Giả sử mọi số đều nguyên tố
    global n
    global prime
    prime = [True for i in range(n + 1)]   

    # 0 và 1 không phải số nguyên tố
    prime[0] = False
    prime[1] = False

    # Đánh dấu False cho các bội của số nguyên tố p
    for p in range(2, math.floor(math.sqrt(n)) + 1):
        # Nếu p là nguyên tố thì đánh dấu False cho bội của p
        if prime[p] == True:
            for i in range(p * p, n + 1, p):
                prime[i] = False


def show_all(l):
    for i in range(l):
        print(i, end='')
        if prime[i] == True:
            print(': True', end='')
        print()


if __name__ == '__main__':
    sieve()

    limit = 100
    show_all(limit)

    k = 9999991

    if prime[k] == True:
        print(f'{k} is prime')
    else:
        print(f'{k} is not prime')