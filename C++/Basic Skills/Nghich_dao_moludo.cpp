// tim ham phi(n)

long long phi(int n) {
    long long phi = n;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            phi -= phi / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) phi -= phi / n;
    return phi;
}

// Tim nghich dao modulo

int modulo_rev(int a, int m) {
    return Power(a, Phi(m) - 1, m); // Neu m la so nguyen to thi thay Phi(m - 1) thanh m - 2
}
