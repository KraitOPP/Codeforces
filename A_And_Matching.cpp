#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define vi vector<int>
#define inp for(int i=0;i<n;i++) cin>>arr[i]
#define vll vector<ll>
#define vvi vector<vector<int> >
#define vpii vector<pii >
#define mp make_pair
#define f first
#define s second

const int MOD = 1e9 + 7;
const int INF = 1e9;

// Function to print a vector
template <typename T>
void printVector(const vector<T>& v) {
    for (const auto& element : v) {
        cout << element << ' ';
    }
    cout << endl;
}

// Function to print a set
template <typename T>
void printSet(const set<T>& s) {
    for (const auto& element : s) {
        cout << element << ' ';
    }
    cout << endl;
}

// Function to print a map
template <typename K, typename V>
void printMap(const map<K, V>& m) {
    for (const auto& [key, value] : m) {
        cout << key << " -> " << value << endl;
    }
}

void solve() {
    // Write your code here
    int n,k;
    cin>>n>>k;
    vpii vec;
    int x = k,y = n-1-k;
    int i;
    if(k == 0){
        for(int i=0;i<n/2;i++) cout<<i<<" "<<n-1-i<<endl;
        return;
    }
    if(k == 3 && n == 4) {
        cout<<-1<<endl;
        return;
    }
    if(k == n-1){
        cout<<"0 4"<<endl;
        cout<<"1 3"<<endl;
        cout<<n-2<<" "<<n-1<<endl;
        for(int i=2;i<n/2;i++){
            cout<<i<<" "<<n-1-i<<endl;
        }
        return;
    }
    cout<<n-1<<" "<<k<<endl;
    cout<<0<<" "<<(n-1-k)<<endl;
    for(int i=1;i<n/2;i++){
        if(i != k && i != (n-1-k) && (n-1-i) != k && (n-1-i) != (n-1-k)) cout<<i<<" "<<n-1-i<<endl;
    }

}

signed main() {
    fastio;
    int t = 1;
    cin >> t; // Uncomment if multiple test cases
    // int cnt = 1;
    while (t--) {
        // cout<<cnt++<<"->";
        solve();
    }
    return 0;
}