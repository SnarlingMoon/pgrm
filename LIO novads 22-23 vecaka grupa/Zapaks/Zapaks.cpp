#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mak = 1e5+10;
pair<ll, ll> a[mak];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, sk=-1, maz=-1, daudz=0, iep=-1, pos=0;
    bool aug = false, neaug = false, pirm = true;
    a[0].first=-1;
    cin >> N;
    for(ll y=1; y<=N; y++) {
        iep=sk;
        cin >> sk;
        if(y!=1) {
            if(sk>iep && pirm) {
                aug = true;
                pirm = false;
                a[pos].first = iep;
                daudz++;
            }
            else if(sk<iep && aug) {
                aug = false;
                neaug = true;
                a[pos].second = iep;
                pos++;
                a[pos].first = sk;
                daudz++;
            }
            else if(sk>iep && !pirm && neaug) {
                aug = true;
                neaug = false;
                a[pos].second = iep;
                pos++;
                a[pos].first = sk;
                daudz++;
            }
        }
        if(y==N && a[pos].first==-1) {
            a[pos].first = sk;
        }
        if(y==N) {
            a[pos].second = sk;
            pos++;
            daudz++;
        }
    }
    cout << daudz << "\n";
    for(ll u=0; u<pos; u++) {
        if(u==0) {
            cout << a[u].first << " ";
        }
        if(daudz==2) cout << a[u].second << " ";
        if(pos>1) cout << a[u].second << " ";
    }
    return 0;
}
