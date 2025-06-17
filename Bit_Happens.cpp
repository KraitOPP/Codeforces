#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const string B = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

vector<int> db(const string &s) {
    vector<int> v;
    string c;
    for (char x : s)
        if (B.find(x) != string::npos || x == '=')
            c += x;
    int a = 0, b = -8;
    for (char x : c) {
        if (x == '=') break;
        a = (a << 6) + B.find(x);
        b += 6;
        if (b >= 0) {
            v.push_back((a >> b) & 0xFF);
            b -= 8;
        }
    }
    return v;
}

string gn(const vector<int> &d) {
    string s(d.begin(), d.end());
    smatch m;
    if (regex_search(s, m, regex("ABC\\{(\\d+)\\}")))
        return m[1].str();
    return "";
}

int gb(const string &s) {
    auto d = db(s);
    string num = gn(d);
    if (num.empty()) return 0;
    try { return stoi(num); } catch(...) { return 0; }
}

int gp(const string &s) {
    auto d = db(s);
    string num = gn(d);
    if (num.empty()) return 0;
    const int mod = 10007;
    long r = 0;
    for (char c : num)
        r = (r*10 + (c-'0')) % mod;
    return int(r) + 3;
}

int rv(const vector<int> &c, int a) {
    int mem[256] = {};
    uint8_t reg[16] = {};
    bool z = false;
    vector<size_t> stk;
    size_t ip = 0;
    while (ip < c.size()) {
        int op = c[ip++];
        if (op == 0xFF) break;
        switch (op) {
            case 1:
                if (ip+1 < c.size()) {
                    reg[c[ip+1]] = c[ip];
                    ip += 2;
                }
                break;
            case 2:
                if (ip+2 < c.size()) {
                    int x = c[ip], y = c[ip+1], zreg = c[ip+2];
                    if (x<16&&y<16&&zreg<16)
                        reg[zreg] = (reg[zreg] + reg[x]) & 0xFF;
                    ip += 3;
                }
                break;
            case 3:
                if (ip+2 < c.size()) {
                    int x = c[ip], y = c[ip+1], zreg = c[ip+2];
                    if (x<16&&y<16&&zreg<16) {
                        int res = (reg[y] - reg[x]) & 0xFF;
                        z = (res == 0);
                        reg[zreg] = res;
                    }
                    ip += 3;
                }
                break;
            case 4:
                if (ip < c.size()) ip = c[ip];
                break;
            case 5:
                if (ip < c.size()) {
                    size_t tgt = c[ip++];
                    if (z) ip = tgt;
                }
                break;
            case 6:
                if (ip+1 < c.size()) {
                    mem[c[ip+1]] = mem[c[ip]];
                    ip += 2;
                }
                break;
            case 7:
                if (ip+1 < c.size()) {
                    mem[c[ip+1]] = reg[c[ip]];
                    ip += 2;
                }
                break;
            case 8:
                if (ip < c.size()) {
                    stk.push_back(ip+1);
                    ip = c[ip];
                }
                break;
            case 9:
                if (!stk.empty()) {
                    ip = stk.back();
                    stk.pop_back();
                }
                break;
            default:
                ip = c.size();
                break;
        }
    }
    return mem[a & 0xFF];
}

int main(){
    fastio();
    string in;
    if(!getline(cin,in)) return 0;
    auto dec = db(in);
    string js(dec.begin(), dec.end());
    size_t p = js.find("\"n\":");
    int n = 0;
    if(p != string::npos) n = stoi(js.substr(p+4));
    p = js.find("\"data\"",p);
    if(p == string::npos){
        cout<<"0 0 0";
        return 0;
    }
    p = js.find('[',p);
    if(p == string::npos){
        cout<<"0 0 0";
        return 0;
    }
    p++;
    const string COMMON = "Qk02AwAAAAAAADYAAAAoAAAAEAAAABAAAAABABgAAAAAAAADAAATCwAAEwsAAAAAAAAAAAAAzOvv+fL9+Mz02vLa1s/Z2OH8ysz109Hw8u/R1+nS+uva8Obhzufd2tzW09DT5PPiyObN+fzK9Oj14tbpztvJ7OP/9+DZ8dHM7trn+dPx29zU49fY2fnOztT02ejx2/ji2ur1/tDoy8jz3/bS6PzQ+OzSyuHY//Xr/sr30NLf/erM49re+NTv8PHs0u/k6dDy4Nfb2tXL4+XZ49PN4tjh3/br4uHQ6ujn1tzp/vHu//Tt+cjz9eXL0O3X/PDS8Pn2/PDZ6uHr4+vl9/3Vyu3l6/bS+eTly93o6u3W3tjJ68j1/97m3fr9+vPIzNzk08rq/Org+/fw1+T0+d/z1e/e39fV+u/K1+jbzPzlzM7w6tz38NPiyPf2+vn90Nbx3OPn2NLN8OTi9PHl2ubL6P/51tDk9tDz3O/n79D0///W88741fji1/jR7+3t1dnuyNPr7OHj7M3x0+ro4P3w5eL45+vu5d/s9OHW0dPU0N3e4ufQ3uTR7tvk5s3h//D3z/fO+uPd7vbl/v3m7eHj0uT34OnY+Nbs9eH609XX79bLyunNy8zM0N3qy83O5PrS5Pjl4vvS39v//ePM6vTv6e7Jy8/u5cnW9/Dt/8jj4PDj9/Dt0uj52ebR8P/9z8nc/fLb5f/h2OLI6+br6t3U8O3T9srU1Pf07dbS1Of30/7i2Nz93uvY1fLs6Ov03c3f0OLM7ePQ2eDd/Pz55uDK+8nczt3l2/Xj/8nl88rxytT/zfjN09bK0N3P0svt7PDo2fXv3tf04+ba4uzjz93Q39/268vO1NTV+Ov24OjQ+Prv+N3P0eHl3O35z97Z0ePk687i6ebl0dvm2vrs0NHs9+DI6M/079zW7O3Y4f789ezV4ej77fPi5/XU5sjk2d7k2ena8sjl5Oj599zv3ufZ5tblytTY0d/b5+vd583zztLr3vfr+u/j2PrZ0vf3yOTy4NLx8ej/69zS5N7w8srV9//k6Or54NLs++ff38/R383i79Dn+OTy2ubS0e7S39n159Xs";
    int bmp = gb(COMMON);
    for(int i=0;i<n;i++){
        p = js.find('{',p);
        if(p==string::npos) break;
        size_t a = js.find("\"pcap\":",p);
        a = js.find('"',a+6)+1;
        size_t b = js.find('"',a);
        string pcap = js.substr(a,b-a);
        a = js.find("\"myst\":",b);
        a = js.find('"',a+6)+1;
        b = js.find('"',a);
        string myst = js.substr(a,b-a);
        a = js.find("\"memory_address\":",b);
        a += 17;
        int addr = stoi(js.substr(a));
        p = js.find('}',a)+1;
        int r2 = gp(pcap);
        int r3 = rv(db(myst),addr);
        cout<<bmp<<" "<<r2<<" "<<r3;
        if(i+1<n) cout<<"\n";
    }
    if(n==0) cout<<"0 0 0";
    return 0;
}
