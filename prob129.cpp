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

int distance(string s)
{
    int freq[26];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < sz(s); ++i)
        if (s[i] != ' ')
            freq[s[i] - 'A']++;

    int max = *max_element(freq, freq + 26);

    char e = ' ';
    int cnt = 0;
    for (int i = 0; i < 26; ++i)
        if (freq[i] == max)
            e = 'A' + i, ++cnt;

    if (cnt > 1) return -1;

    int dist = (e - 'E' + 26) % 26;
    return dist;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int ncases;
    cin >> ncases;
    cin.ignore();

    while (ncases--) {
        string s;
        getline(cin, s);

        int d = distance(s);

        if (d == -1) 
        {
            cout << "NOT POSSIBLE" << endl;
            continue;
        }

        cout << d << " ";
        for (int i = 0; i < sz(s); ++i)
            if (s[i] != ' ')
                cout << (char)(((s[i] - 'A' - d + 26) % 26) + 'A');
            else
                cout << " ";
        cout << endl;
    }

    return 0;
}
