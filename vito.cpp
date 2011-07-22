#include <iostream>
#include <climits>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rel;

int solve()
{
    int dist=INT_MAX;
    for (int i=0; i<30000; i++) {
        int curr=0;
        for (int j=1; j<(int)rel.size(); j++)
            curr += abs(i-rel[j]);
        if (curr<=dist)
            dist = curr;
        else //returnen als afstand weer stijgt
            return dist;
    }
    return dist;
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
