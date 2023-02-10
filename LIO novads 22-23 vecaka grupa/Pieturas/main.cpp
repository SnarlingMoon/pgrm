#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, pair<int, int>> blk;
typedef long long ll;

const int mak = 1e5+5;

vector<blk> kaim[mak];
ll dist[mak], bil[mak];
bool kras[mak];

void shortestPath(ll sak, ll beig) {
	priority_queue<blk, vector<blk>, greater<blk>> pq;
	pq.push(make_pair(0, make_pair(0, sak)));
	dist[sak] = 1;
	bil[sak] = 0;
	while (!pq.empty()) {
		int u = pq.top().second.second;
		pq.pop();
		for (auto i : kaim[u]) {
            if(i.second.first == 0  &&  dist[i.first] > dist[u]+1) {
                dist[i.first] = dist[u]+1;
                bil[i.first] = bil[u];
                pq.push(make_pair(bil[i.first], make_pair(dist[i.first], i.first)));
            }
            else if(i.second.first == 1  &&  bil[i.first]>bil[u]+1) {
                dist[i.first] = dist[u]+1;
                bil[i.first] = bil[u]+1;
                pq.push(make_pair(bil[i.first], make_pair(dist[i.first], i.first)));
            }
		}
	}
	if(kras[sak]==kras[beig]) cout << (bil[beig]/2) << " " << (bil[beig]/2) << " " << dist[beig] << "\n";
    else if(kras[sak]==0) cout << (bil[beig]/2)+1 << " " << (bil[beig]/2) << " " << dist[beig] << "\n";
    else cout << (bil[beig]/2) << " " << (bil[beig]/2)+1 << " " << dist[beig] << "\n";
}

int main()
{
    ll P, Z, N, V;
    cin >> P >> Z >> N;
    for(int i=0; i<N; i++) {
        ll sak, beg;
        cin >> sak >> beg;
        if(sak<=Z) kras[sak]=0;
        else kras[sak]=1;
        if(beg<=Z) kras[beg]=0;
        else kras[beg]=1;
        if(sak>beg) swap(sak, beg);
        if(sak<=Z && beg>Z) {
            kaim[sak].push_back(make_pair(beg,make_pair(1, 1)));
            kaim[beg].push_back(make_pair(sak,make_pair(1, 1)));
        }
        else {
            kaim[sak].push_back(make_pair(beg,make_pair(0, 1)));
            kaim[beg].push_back(make_pair(sak,make_pair(0, 1)));
        }
    }
    cin >> V;
    for(int i=0; i<V; i++) {
        for(int u=0; u<=P; u++) {
            dist[u]=INF;
            bil[u]=INF;
        }
        ll sak, beig;
        cin >> sak >> beig;
        shortestPath(sak, beig);
    }
	return 0;
}
