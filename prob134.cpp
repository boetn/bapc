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

#define N 12
#define a(p) (a[x[p]][y[p]])
#define g(p) (a(p)-'A'+1)

void check(int, int);
void solve(int);

string a[5];
int solved = 0;
int x[N];
int y[N];
int used[N];

void check(int c, int p)
{
    a(p) = c;
    used[c-'A'] = 1;
    solve(p + 1);
    used[c-'A'] = 0;
    a(p) = 'x';
}

void solve(int p)
{
    if (p == N) { //finished
        for (int i = 0; i < 5; ++i)
            cout << a[i] << endl;
        solved = 1;
        return;
    }

    if (a(p) != 'x') { //al ingevuld
        solve(p + 1);
        return;
    }

    //4e karakter berekenen als dat nodig is
    char fill = 'x', foll = 'x';
    if (p == 4) fill = foll = 'Z' - g(1) - g(2) - g(3);
    else if (p == 7) fill = foll = 'Z' - g(0) - g(2) - g(5);
    else if (p == 10) fill = 'Z' - g(0) - g(3) - g(6), foll = 'Z' - g(7) - g(8) - g(9);
    else if (p == 11) fill = 'Z' - g(1) - g(5) - g(8), foll = 'Z' - g(4) - g(6) - g(9);

    //4e karakter in orde?
    if (fill != foll || fill < 'A' || (fill > 'L' && fill <= 'Z')) return;

    if (fill == 'x') { //geen 4e karakter, zelf zoeken
        for (int c = 'A'; c <= 'L'; ++c) {
            if (used[c-'A']) continue;
            check(c, p);
            if (solved) return;
        }
    } else {
        if (used[fill-'A']) return;
        check(fill, p);
        if (solved) return;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int pos = 0;
    memset(used, 0, sizeof(used));
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
        for (int j = 0; j < sz(a[i]); ++j)
            if (a[i][j] != '.')
                x[pos] = i, y[pos] = j, ++pos, used[a[i][j] - 'A'] = 1;
    }

    solve(0);

    return 0;
}
