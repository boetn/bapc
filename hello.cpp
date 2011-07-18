#include <string>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--) {
        string name;
        cin >> name;
        cout << "Hello " << name << "!" << endl;
    }
    
    return 0;
}
