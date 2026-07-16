# Number Theory - Complete Theory & Intuition Guide

> Understand WHY formulas work, not just HOW to use them.

---

## 1. GCD (Greatest Common Divisor) - EUCLIDEAN ALGORITHM

### Intuition
If we can find GCD of smaller numbers, we can find GCD of larger ones.

**Key Insight:** `GCD(a, b) = GCD(b, a % b)`

### Why does a % b work?

Let's trace with example: `GCD(48, 18)`

```
Step 1: 48 = 18 * 2 + 12    (48 % 18 = 12)
Step 2: 18 = 12 * 1 + 6     (18 % 12 = 6)
Step 3: 12 = 6 * 2 + 0      (12 % 6 = 0)
GCD = 6 (last non-zero remainder)
```

**Why?** If d divides both a and b, then d divides (a - b*k) for any k. So d divides a % b too. The common divisors don't change!

### Visual
```
48 = ████████████████████  (48 units)
18 = ███████              (18 units)

48 % 18 = 12:
48 = 18 + 18 + 12
    ███████ ███████ ████

18 % 12 = 6:
18 = 12 + 6
    ████ ██

12 % 6 = 0:
12 = 6 + 6
    ██ ██

GCD = 6 ✓
```

### Code
```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

**Time Complexity:** O(log(min(a, b)))

---

## 2. LCM (Least Common Multiple)

### Formula
```
LCM(a, b) = (a * b) / GCD(a, b)
```

### Intuition
`LCM * GCD = a * b` (always!)

**Why?** Think of prime factorization:
```
a = 2^3 * 3^1 * 5^0
b = 2^1 * 3^2 * 5^1

GCD = min of each power = 2^1 * 3^1 = 6
LCM = max of each power = 2^3 * 3^2 * 5^1 = 360

GCD * LCM = (2^1 * 3^1) * (2^3 * 3^2 * 5^1) = 2^4 * 3^3 * 5^1
a * b = (2^3 * 3^1) * (2^1 * 3^2 * 5^1) = 2^4 * 3^3 * 5^1 ✓
```

### Example: LCM(4, 6)
```
GCD(4, 6) = 2
LCM = (4 * 6) / 2 = 24 / 2 = 12 ✓
(12 is smallest number divisible by both 4 and 6)
```

### Code
```cpp
long long lcm(int a, int b) {
    return (long long)a / gcd(a, b) * b;  // divide first to avoid overflow
}
```

---

## 3. PRIME NUMBERS & SIEVE OF ERATOSTHENES

**Prime:** Number > 1 with exactly 2 divisors (1 and itself)

### Why check till sqrt(n)?

If `n = a * b`, then one of a or b must be <= sqrt(n)

```
Example: n = 36, sqrt = 6
36 = 1*36, 2*18, 3*12, 4*9, 6*6
One factor is always <= 6 ✓
```

### Sieve of Eratosthenes - Step by Step

Find all primes up to 30:

**Step 1:** Start with 2 (first prime)
Mark all multiples of 2: 4,6,8,10,12,14,16,18,20,22,24,26,28,30

```
Index:  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
Value:  F  F  T  T  F  T  F  T  F  T  F  T  F  T  F  T
              2  3  4  5  6  7  8  9 10 11 12 13 14 15
```

**Step 2:** Next unmarked is 3 (prime)
Mark multiples of 3: 6,9,12,15,18,21,24,27,30

**Step 3:** Next unmarked is 5 (prime)
Mark multiples of 5: 10,15,20,25,30

**Step 4:** Continue until sqrt(30) ≈ 5.47

**PRIMES:** 2, 3, 5, 7, 11, 13, 17, 19, 23, 29

### Code
```cpp
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)  // start from i*i!
                isPrime[j] = false;
    return isPrime;
}
```

**Why start from i*i?** All multiples smaller than i*i have been marked by smaller primes!

**Time:** O(n log log n)

---

## 4. MODULAR ARITHMETIC

### Basic Rules
```
(a + b) % m = ((a % m) + (b % m)) % m
(a * b) % m = ((a % m) * (b % m)) % m
(a - b) % m = ((a % m) - (b % m) + m) % m  (add m to handle negative)
```

### Why Modular?
Numbers get huge quickly. We use mod 10^9+7 to keep numbers manageable.

### Binary Exponentiation - Why O(log n)?

To compute `a^n`:
- Naive: multiply a n times = O(n)
- Binary: Use binary representation of n

**Example:** `a^13`
```
13 in binary = 1101 = 8 + 4 + 1

a^1 = a
a^2 = a * a
a^4 = a^2 * a^2
a^8 = a^4 * a^4

a^13 = a^8 * a^4 * a^1

Only log2(13) = 4 multiplications!
```

**Visual:**
```
13 = 1101 (binary)
     ||||
     |||+-- a^1 (multiply if bit=1)
     ||+--- a^2 (square each step)
     |+---- a^4
     +----- a^8
```

### Code
```cpp
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;  // if odd
        base = base * base % mod;  // square
        exp >>= 1;  // shift right
    }
    return result;
}
```

---

## 5. MODULAR INVERSE

### Problem
We want `(a / b) % m`, but can't divide directly!

### Solution
Multiply by modular inverse instead: `(a / b) % m = (a * b^(-1)) % m`

### Fermat's Little Theorem
If m is prime: `a^(m-1) ≡ 1 (mod m)`

Therefore: `a^(m-2) ≡ a^(-1) (mod m)`

**So:** `b^(-1) = b^(m-2) % m` (when m is prime)

### Example
Find `3^(-1) mod (10^9+7)`
```
3^(-1) = 3^(10^9+5) % (10^9+7) = 333333336
Verify: 3 * 333333336 % (10^9+7) = 1 ✓
```

---

## 6. nCr (Combination)

### Formula
```
nCr = n! / (r! * (n-r)!)
```

### Problem
Factorials get huge, division doesn't work with mod

### Solution
`nCr % m = n! * (r!)^(-1) * ((n-r)!)^(-1) % m`

### Steps
1. Precompute factorials: `fact[i] = fact[i-1] * i % m`
2. Precompute inverse factorials using Fermat's theorem
3. Answer each query in O(1)

### Visual (Pascal's Triangle)
```
       1
      1 1
     1 2 1
    1 3 3 1
   1 4 6 4 1
  1 5 10 10 5 1

C(n,r) = C(n-1,r-1) + C(n-1,r)
Each number = sum of two above it
```

---

## 7. EULER TOTIENT FUNCTION - PHI(n)

### Definition
`phi(n)` = count of numbers from 1 to n that are coprime with n

### Example: phi(12)
```
Numbers 1-12: 1,2,3,4,5,6,7,8,9,10,11,12
Coprime with 12: 1,5,7,11 (GCD=1)
phi(12) = 4
```

### Formula
```
phi(n) = n * product((p-1)/p) for all prime factors p

phi(12) = 12 * (1-1/2) * (1-1/3)
         = 12 * 1/2 * 2/3
         = 4 ✓
```

### Code
```cpp
int eulerTotient(int n) {
    int result = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
```

---

## 8. EXTENDED EUCLIDEAN ALGORITHM

### Finds
x, y such that `a*x + b*y = gcd(a, b)`

### Why Useful?
- Modular inverse: if gcd(a,m)=1, then a*x + m*y = 1, so a*x ≡ 1 (mod m)
- Solving linear Diophantine equations

### Example: 35x + 15y = gcd(35,15)

**GCD(35,15):**
```
35 = 15*2 + 5
15 = 5*3 + 0
GCD = 5
```

**Back-substitute:**
```
5 = 35 - 15*2
So x=1, y=-2
Verify: 35*1 + 15*(-2) = 35 - 30 = 5 ✓
```

---

## Summary Table

| Algorithm | Time | Use When |
|-----------|------|----------|
| GCD (Euclidean) | O(log n) | Need common divisor |
| LCM | O(log n) | Need common multiple |
| Sieve | O(n log log n) | Need primes up to n |
| Prime Check | O(sqrt n) | Single number check |
| Binary Exponent | O(log n) | Large powers with mod |
| Modular Inverse | O(log n) | Division with mod |
| nCr | O(1) query | Combinations with mod |
| Euler Totient | O(sqrt n) | Coprime counting |

### Key Formulas to Remember
- `GCD(a,b) = GCD(b, a%b)`
- `LCM(a,b) = a*b / GCD(a,b)`
- `a^(m-1) ≡ 1 (mod m)` [Fermat, m prime]
- `a^(-1) ≡ a^(m-2) (mod m)` [Fermat inverse]
- `phi(n) = n * ∏(1 - 1/p)` [p = prime factors]
