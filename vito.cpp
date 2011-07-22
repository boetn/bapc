#include <iostream>
#include <climits>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rel;

//int dist(int pos)
//{
//    int d=0;
//    for (int j=1; j<(int)rel.size(); j++)
//        d += abs(pos-rel[j]);
//    return d;
//}

int solve()
{
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string line;
        int d;
        getline(cin, line);
        stringstream ss(line);

        rel.clear();
        while (ss >> d)
            rel.push_back(d);

        cout << solve() << endl;
    }
    
    return 0;
}
