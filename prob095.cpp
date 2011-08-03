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
    int n;
    cin >> n;

    while (n--) {
        char s[1000010];
        list<char> keys;
        list<char>::iterator curr = keys.begin();

        cin >> s;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '<') {
                if (curr != keys.begin())
                    --curr;
            } else if (s[i] == '>') {
                if (curr != keys.end())
                    ++curr;
            } else if (s[i] == '-') {
                if (curr != keys.begin()) {
                    list<char>::iterator temp(curr);
                    temp--;
                    keys.erase(temp);
                }
            } else
                keys.insert(curr, s[i]);
        }

        foreach (keys, k)
            cout << *k;
        cout << endl;
    }

    return 0;
}
