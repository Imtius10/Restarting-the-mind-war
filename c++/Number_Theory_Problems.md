# Number Theory - 25 Problems for Competitive Programming

> LeetCode + Codeforces | Beginner to Hard

---

## Section A: GCD, LCM & DIVISORS (Easy - Medium)

### Problem 1.1 - GCD of Two Numbers
- **Difficulty:** Easy
- **Task:** Given two integers A and B, find their GCD (Greatest Common Divisor).
- **Input:** `A = 12, B = 18`
- **Output:** `6`
- **Constraints:** `1 <= A, B <= 10^9`
- **Hint:** Use Euclidean Algorithm
- **Tags:** gcd, euclidean

### Problem 1.2 - LCM of Two Numbers
- **Difficulty:** Easy
- **Task:** Given two integers A and B, find their LCM (Least Common Multiple).
- **Input:** `A = 4, B = 6`
- **Output:** `12`
- **Formula:** `LCM(A,B) = (A * B) / GCD(A,B)`
- **Tags:** lcm, gcd

### Problem 1.3 - GCD of Array
- **Difficulty:** Easy
- **Task:** Given array of integers, find GCD of all elements.
- **Input:** `arr = [2, 4, 6, 8]`
- **Output:** `2`
- **Tags:** gcd, array

### Problem 1.4 - Find All Divisors
- **Difficulty:** Easy
- **Task:** Find all divisors of N.
- **Input:** `N = 36`
- **Output:** `[1, 2, 3, 4, 6, 9, 12, 18, 36]`
- **Constraints:** `1 <= N <= 10^9`
- **Hint:** Iterate till sqrt(N)
- **Tags:** divisors, sqrt decomposition

### Problem 1.5 - Count Divisors
- **Difficulty:** Easy
- **Task:** Given N, find count of divisors.
- **Input:** `N = 12`
- **Output:** `6` (divisors: 1,2,3,4,6,12)
- **Constraints:** `1 <= N <= 10^6`
- **Tags:** divisors, sieve

### Problem 1.6 - Sum of All Divisors
- **Difficulty:** Easy
- **Task:** Find sum of all divisors of N.
- **Input:** `N = 12`
- **Output:** `28` (1+2+3+4+6+12)
- **Constraints:** `1 <= N <= 10^9`
- **Tags:** divisors, mathematics

### Problem 1.7 - Common Divisors
- **Difficulty:** Easy
- **Link:** https://codeforces.com/problemset/problem/1203/C
- **Task:** Given array, find count of numbers that divide all elements.
- **Input:** `arr = [4, 8, 16]`
- **Output:** `3`
- **Tags:** gcd, divisors

### Problem 1.8 - Euclidean GCD Extended
- **Difficulty:** Medium
- **Task:** Given A and B, find GCD and coefficients x,y such that: `A*x + B*y = GCD(A,B)`
- **Input:** `A = 35, B = 15`
- **Output:** `GCD=5, x=1, y=-2`
- **Tags:** extended euclidean, modular inverse

---

## Section B: PRIME NUMBERS & SIEVE (Easy - Hard)

### Problem 1.9 - Check if Prime
- **Difficulty:** Easy
- **Task:** Check if N is prime.
- **Input:** `N = 17`
- **Output:** `true`
- **Constraints:** `1 <= N <= 10^9`
- **Hint:** Check divisibility till sqrt(N)
- **Tags:** primality test

### Problem 1.10 - Sieve of Eratosthenes
- **Difficulty:** Medium
- **Task:** Find all primes up to N.
- **Input:** `N = 30`
- **Output:** `[2, 3, 5, 7, 11, 13, 17, 19, 23, 29]`
- **Constraints:** `1 <= N <= 10^6`
- **Tags:** sieve, prime generation

### Problem 1.11 - Count Primes (LeetCode #204)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/count-primes/
- **Task:** Count primes less than N.
- **Input:** `N = 10`
- **Output:** `4` (primes: 2, 3, 5, 7)
- **Constraints:** `0 <= N <= 5 * 10^6`
- **Tags:** sieve, counting

### Problem 1.12 - Smallest Prime Factor
- **Difficulty:** Medium
- **Task:** Find smallest prime factor for every number from 2 to N.
- **Input:** `N = 10`
- **Output:** `[0,0,2,3,2,5,2,7,2,3,2]`
- **Constraints:** `2 <= N <= 10^6`
- **Tags:** sieve, spf

### Problem 1.13 - Prime Factorization (Basic)
- **Difficulty:** Medium
- **Task:** Find prime factorization of N.
- **Input:** `N = 60`
- **Output:** `[2, 2, 3, 5]` (60 = 2^2 * 3 * 5)
- **Constraints:** `1 <= N <= 10^9`
- **Tags:** factorization

### Problem 1.14 - Prime Factorization using SPF
- **Difficulty:** Medium
- **Task:** Using smallest prime factor array, factorize N in O(log N).
- **Input:** `N = 360`
- **Output:** `[2, 2, 2, 3, 3, 5]`
- **Constraints:** `1 <= N <= 10^6`
- **Tags:** sieve, spf, factorization

### Problem 1.15 - Count Distinct Prime Factors
- **Difficulty:** Medium
- **Task:** Count number of distinct prime factors of N.
- **Input:** `N = 12`
- **Output:** `2` (prime factors: 2, 3)
- **Constraints:** `1 <= N <= 10^9`
- **Tags:** prime factors, counting

### Problem 1.16 - Almost Prime
- **Difficulty:** Easy
- **Link:** https://codeforces.com/problemset/problem/26/A
- **Task:** Count numbers from 1 to N that have exactly 2 distinct prime factors.
- **Tags:** prime, counting

---

## Section C: MODULAR ARITHMETIC (Medium - Hard)

### Problem 1.17 - Modular Exponentiation
- **Difficulty:** Medium
- **Task:** Calculate `(a^b) % MOD` efficiently.
- **Input:** `a = 2, b = 10, MOD = 10^9+7`
- **Output:** `1024`
- **Constraints:** `0 <= a,b <= 10^9`
- **Hint:** Use binary exponentiation
- **Tags:** binary exponentiation, modular

### Problem 1.18 - Modular Inverse
- **Difficulty:** Medium
- **Task:** Find modular inverse of A under MOD (MOD is prime).
- **Input:** `A = 3, MOD = 10^9+7`
- **Output:** `333333336`
- **Formula:** `inv(A) = A^(MOD-2) % MOD`
- **Tags:** modular inverse, fermat

### Problem 1.19 - Factorial Modulo
- **Difficulty:** Medium
- **Task:** Calculate `N! % MOD`.
- **Input:** `N = 5, MOD = 10^9+7`
- **Output:** `120`
- **Constraints:** `0 <= N <= 10^6`
- **Tags:** factorial, modular

### Problem 1.20 - nCr Modulo
- **Difficulty:** Medium
- **Task:** Calculate `nCr % MOD` where MOD is prime.
- **Input:** `n = 5, r = 2, MOD = 10^9+7`
- **Output:** `10`
- **Formula:** `nCr = n! / (r! * (n-r)!) % MOD`
- **Tags:** combinatorics, modular

### Problem 1.21 - Chinese Remainder Theorem
- **Difficulty:** Hard
- **Task:** Given system of congruences, find X.
- **Output:** `23`
- **Tags:** crt, modular

---

## Section D: OTHER NUMBER THEORY (Medium - Hard)

### Problem 1.22 - Fibonacci Number (LeetCode #509)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/fibonacci-number/
- **Task:** Find Nth Fibonacci number.
- **Input:** `n = 10`
- **Output:** `55`
- **Tags:** fibonacci, dp

### Problem 1.23 - Matrix Exponentiation (Fibonacci)
- **Difficulty:** Hard
- **Task:** Find Nth Fibonacci in O(log N) using matrix exponentiation.
- **Tags:** matrix exponentiation, fast doubling

### Problem 1.24 - Euler Totient Function
- **Difficulty:** Hard
- **Task:** Find count of numbers from 1 to N that are coprime with N.
- **Input:** `N = 12`
- **Output:** `4` (1, 5, 7, 11)
- **Tags:** euler totient, phi

### Problem 1.25 - Totient Function Sum
- **Difficulty:** Hard
- **Task:** Find sum of Euler Totient values from 1 to N.
- **Input:** `N = 6`
- **Output:** `12`
- **Constraints:** `1 <= N <= 10^6`
- **Tags:** sieve, totient, sum

---

## Cheat Sheet - Number Theory Formulas

**GCD:**
```
gcd(a, b) = gcd(b, a % b)
gcd(a, 0) = a
```

**LCM:**
```
lcm(a, b) = (a / gcd(a,b)) * b
```

**Prime Check (basic):**
```cpp
for (i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
```

**Sieve:**
```cpp
is_prime[0] = is_prime[1] = false;
for (i = 2; i * i <= n; i++)
    if (is_prime[i])
        for (j = i*i; j <= n; j += i)
            is_prime[j] = false;
```

**Modular Exponentiation:**
```
power(base, exp, mod):
    result = 1
    while (exp > 0):
        if (exp % 2 == 1)
            result = result * base % mod
        base = base * base % mod
        exp /= 2
    return result
```

**Modular Inverse (prime mod):**
```
inv(a) = power(a, MOD-2, MOD)
```

**Euler Totient:**
```
phi(n) = n * product((p-1)/p) for all prime factors p of n
```
