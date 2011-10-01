// includes {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
// }}}
// defines {{{
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define all(c) (c).begin(),(c).end()
#define foreach(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
// }}}

#define MAX 100100

vector<int> g[MAX];
int dist[MAX];
queue<int> toVisit;

int bfs(int start)
{
    int last;
    memset(dist, -1, sizeof(dist));
    toVisit.push(start);
    dist[start] = 0;

    while (!toVisit.empty()) {
        int curr = toVisit.front();
        toVisit.pop();
        last = curr;

        foreach (g[curr], n) {
            if (dist[*n] != -1)
                continue;
            toVisit.push(*n);
            dist[*n] = dist[curr] + 1;
        }
    }

    return last;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int ncases;
    cin >> ncases;

    while (ncases--) {
        int numV;
        cin >> numV;

        for (int i = 0; i < numV; ++i)
            g[i].clear();

        for (int i = 0; i < numV - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        int last = bfs(0);
        last = bfs(last);

        cout << (dist[last] + 1) / 2 << endl;;
    }

    return 0;
}
