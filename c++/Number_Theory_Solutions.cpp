// ============================================================
// NUMBER THEORY - 25 Solutions (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// ============================================================
// SECTION A: GCD, LCM & DIVISORS
// ============================================================

// Problem 1.1 - GCD of Two Numbers
// Euclidean Algorithm: O(log(min(a,b)))
int gcd(int a, int b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

// Problem 1.2 - LCM of Two Numbers
// LCM(a,b) = (a / GCD(a,b)) * b
long long lcm(int a, int b) {
    return (long long)a / gcd(a, b) * b;
}

// Problem 1.3 - GCD of Array
int findGCD(vector<int>& nums) {
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++)
        result = gcd(result, nums[i]);
    return result;
}

// Problem 1.4 - Find All Divisors
vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

// Problem 1.5 - Count Divisors
int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) count++;
        }
    }
    return count;
}

// Problem 1.6 - Sum of All Divisors
long long sumOfDivisors(int n) {
    long long sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i;
        }
    }
    return sum;
}

// Problem 1.7 - Common Divisors (CF 1203C)
int commonDivisors(vector<int>& arr) {
    int g = arr[0];
    for (int i = 1; i < arr.size(); i++)
        g = gcd(g, arr[i]);
    return countDivisors(g);
}

// Problem 1.8 - Extended Euclidean GCD
// Returns {gcd, x, y} such that a*x + b*y = gcd
tuple<int,int,int> extendedGCD(int a, int b) {
    if (b == 0) return {a, 1, 0};
    auto [g, x1, y1] = extendedGCD(b, a % b);
    return {g, y1, x1 - (a / b) * y1};
}

// ============================================================
// SECTION B: PRIME NUMBERS & SIEVE
// ============================================================

// Problem 1.9 - Check if Prime (Basic)
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// Problem 1.10 - Sieve of Eratosthenes
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    return isPrime;
}

// Problem 1.11 - Count Primes (LeetCode #204)
int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < n; i++)
        if (isPrime[i])
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
    return count(isPrime.begin(), isPrime.end(), true);
}

// Problem 1.12 - Smallest Prime Factor
vector<int> smallestPrimeFactor(int n) {
    vector<int> spf(n + 1);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= n; i++)
        if (spf[i] == i)
            for (int j = i * i; j <= n; j += i)
                if (spf[j] == j) spf[j] = i;
    return spf;
}

// Problem 1.13 - Prime Factorization (Basic)
vector<int> primeFactorize(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

// Problem 1.14 - Prime Factorization using SPF
vector<int> factorizeWithSPF(int n, vector<int>& spf) {
    vector<int> factors;
    while (n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}

// Problem 1.15 - Count Distinct Prime Factors
int countDistinctPrimeFactors(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) count++;
    return count;
}

// ============================================================
// SECTION C: MODULAR ARITHMETIC
// ============================================================

// Problem 1.17 - Modular Exponentiation (Binary Exponentiation)
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// Problem 1.18 - Modular Inverse (Fermat's Little Theorem)
long long modInverse(long long a, long long mod) {
    return power(a, mod - 2, mod);
}

// Problem 1.19 - Factorial Modulo
long long factorialMod(int n, long long mod) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result = result * i % mod;
    return result;
}

// Problem 1.20 - nCr Modulo
long long nCr(int n, int r, long long mod) {
    if (r > n) return 0;
    vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
    for (int i = 2; i <= n; i++)
        fact[i] = fact[i-1] * i % mod;
    invFact[n] = modInverse(fact[n], mod);
    for (int i = n - 1; i >= 0; i--)
        invFact[i] = invFact[i+1] * (i+1) % mod;
    return fact[n] * invFact[r] % mod * invFact[n-r] % mod;
}

// ============================================================
// SECTION D: FIBONACCI & OTHERS
// ============================================================

// Problem 1.22 - Fibonacci (DP)
int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Problem 1.23 - Matrix Exponentiation for Fibonacci
typedef vector<vector<long long>> Matrix;
Matrix multiply(Matrix& A, Matrix& B, long long mod) {
    Matrix C(2, vector<long long>(2));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}
Matrix matPow(Matrix base, long long exp, long long mod) {
    Matrix result = {{1,0},{0,1}};
    while (exp > 0) {
        if (exp & 1) result = multiply(result, base, mod);
        base = multiply(base, base, mod);
        exp >>= 1;
    }
    return result;
}
long long fibonacciMatrix(long long n, long long mod) {
    if (n <= 1) return n;
    Matrix base = {{1,1},{1,0}};
    Matrix result = matPow(base, n - 1, mod);
    return result[0][0];
}

// Problem 1.24 - Euler Totient Function
int eulerTotient(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

// ============================================================
// MAIN - Testing
// ============================================================
int main() {
    cout << "=== Number Theory Solutions ===" << endl;

    cout << "GCD(12, 18) = " << gcd(12, 18) << endl;
    cout << "LCM(4, 6) = " << lcm(4, 6) << endl;

    vector<int> arr = {4, 8, 16};
    cout << "Common Divisors = " << commonDivisors(arr) << endl;

    auto divs = findDivisors(36);
    cout << "Divisors of 36: ";
    for (int d : divs) cout << d << " ";
    cout << endl;

    cout << "Is 17 prime? " << (isPrime(17) ? "Yes" : "No") << endl;
    cout << "Count primes < 10: " << countPrimes(10) << endl;

    cout << "2^10 % MOD = " << power(2, 10, MOD) << endl;
    cout << "ModInv(3) = " << modInverse(3, MOD) << endl;
    cout << "5C2 = " << nCr(5, 2, MOD) << endl;

    cout << "Fibonacci(10) = " << fibonacci(10) << endl;
    cout << "Fibonacci Matrix(10) = " << fibonacciMatrix(10, MOD) << endl;
    cout << "Euler Totient(12) = " << eulerTotient(12) << endl;

    return 0;
}
