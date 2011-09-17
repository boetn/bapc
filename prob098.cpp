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


int main()
{
    //freopen("in.txt", "r", stdin);

    int n, first=1;
    while (1) {
        cin >> n;
        if (!n) break;

        if (!first)
            cout << endl;
        else
            first = 0;

        int p1 = 0, p2 = 0;
        while (n--) {
            int num;
            string act;
            cin >> act >> num;

            if (act == "DROP") {
                p1 += num;
                cout << "DROP 2 " << num << endl;
            } else {
                if (p2) {
                    int take = min(num, p2);
                    num -= take;
                    p2 -= take;
                    cout << "TAKE 1 " << take << endl;
                }
                if (num) {
                    cout << "MOVE 2->1 " << p1 << endl;
                    p2 = p1;
                    p1 = 0;
                    cout << "TAKE 1 " << num << endl;
                    p2 -= num;
                }
            }
        }
    }

    return 0;
}
