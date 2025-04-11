#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
#define int long long
bool prime[MAX + 1];
vector<int> primes;

void sieve(int n) {
    fill(prime, prime + n + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }
}

bool solve(int n) {
    int size = primes.size();
    for (int i = 0; i < size; ++i) {
        int p1 = primes[i];
        int p1_square = p1 * p1;

        int rem = n - p1_square;
        if (rem <= 0) break;

        double sqrem = sqrt(rem);
        if (sqrem == (int)sqrem && (int)sqrem != 2 && (int)sqrem != p1 && prime[(int)sqrem]) {
            return true;
        }
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve(MAX);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        if (n <= 4) {
            cout << "NO" << endl;
            continue;
        }
        n -= 4;

        if (solve(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
