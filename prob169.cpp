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

#define INF 100000000
typedef pair<int, pair<int, int> > iii;

int dr[] = { -1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main()
{
    //freopen("in.txt", "r", stdin);

    int cases;
    cin >> cases;

    while (cases--) {
        int m, n, d;
        cin >> m >> n >> d;
        string a[m];

        priority_queue<iii, vector<iii>, greater<iii> >q;
        int dist[m][n];

        for (int i = 0; i < m; ++i) {
            cin >> a[i];
            for (int j = 0; j < n; ++j) {
                dist[i][j] = INF;
                if (a[i][j] == 'S') {
                    q.push(mp(0, mp(i, j)));
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            iii curr = q.top();
            q.pop();

            int currdist = curr.st;
            int r = curr.nd.st;
            int c = curr.nd.nd;

            if (currdist > dist[r][c])
                continue;

            int found = 0;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    found = 1;
                    break;
                }

                if (a[nr][nc] == '#')
                    continue;

                int next_dist = a[nr][nc] == '.' ? 1 : d + 1;
                if (dist[nr][nc] > currdist + next_dist) {
                    dist[nr][nc] = currdist + next_dist;
                    q.push(mp(dist[nr][nc], mp(nr, nc)));
                }
            }

            if (found) {
                cout << dist[r][c] + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
