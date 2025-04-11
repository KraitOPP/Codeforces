#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 998244353;

int add(int a, int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int sub(int a, int b){ a-=b; if(a<0) a+=MOD; return a; }
int mul(int64 a, int64 b){ return int(a*b%MOD); }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<tuple<int,int,int,int,int>> tests(T);
    int maxN = 0;
    for(int i=0;i<T;i++){
        int N,A,B,C,D;
        cin >> N >> A >> B >> C >> D;
        tests[i]=make_tuple(N,A,B,C,D);
        maxN = max(maxN, N);
    }

    vector<int> S_t(maxN+1,0), S_m(maxN+1,0);

    int W = 2*maxN+1, Z = maxN; 
    vector<int> T2(W,0), newT2(W,0);
    T2[Z + 0] = 1;
    for(int n=1; n<=maxN; n++){
        fill(newT2.begin(), newT2.end(), 0);
        for(int j=-(n-1); j<=(n-1); j++){
            int v = T2[Z + j];
            if(!v) continue;
            newT2[Z + (j-1)] = add(newT2[Z + (j-1)], v);
            newT2[Z + ( j  )] = add(newT2[Z + ( j  )], add(v,v));
            newT2[Z + (j+1)] = add(newT2[Z + (j+1)], v);
        }
        swap(T2, newT2);
        if(n>=1){
            int ways = T2[Z + (-1)];
            S_t[n] = mul(n, ways);
        }
    }

    vector< vector<int> > dp_prev(W, vector<int>(maxN+1,0))
                        , dp_curr(W, vector<int>(maxN+1,0));
    dp_prev[Z + 0][0] = 1;
    for(int i=1; i<=maxN; i++){
        for(int jj=Z-(i); jj<=Z+(i); jj++){
            for(int h=0; h<=i; h++){
                dp_curr[jj][h] = 0;
            }
        }
        for(int j=-(i-1); j<=(i-1); j++){
            int jj = Z + j;
            for(int h=0; h<=(i-1); h++){
                int v = dp_prev[jj][h];
                if(!v) continue;
                dp_curr[Z + (j-1)][h] = add(dp_curr[Z + (j-1)][h], v);
                dp_curr[jj][h] = add(dp_curr[jj][h], add(v,v));
                int nh = max(h, j+1);
                dp_curr[Z + (j+1)][nh] = add(dp_curr[Z + (j+1)][nh], v);
            }
        }
        swap(dp_prev, dp_curr);
        int sm = 0;
        int base = Z + 0;
        for(int h=0; h<=i; h++){
            if(dp_prev[base][h])
                sm = (sm + (int64)h * dp_prev[base][h]) % MOD;
        }
        S_m[i] = sm;
    }

    for(auto &tt: tests){
        int N,A,B,C,D;
        tie(N,A,B,C,D) = tt;
        int64 L = min<int64>(A, D);
        int64 R = min<int64>(B, C);
        int ans = add( mul(L, S_t[N]),
                       mul( (R - L + MOD)%MOD, S_m[N] ) );
        cout << ans << "\n";
    }

    return 0;
}
