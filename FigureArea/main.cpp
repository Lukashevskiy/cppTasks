#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int args, char* argv[])
{

    ifstream cin(argv[1]);
    if(!cin.is_open()){
        cout << "GO CHECK YOUR FILEPATH AND RERUN";
    }else{

        int n;
        cin >> n;
        vector< pair<int, int> > xy;
        for(int i = 0; i < n+1; i++){
            int a, b;
            cin >> a >> b;
            xy.push_back(make_pair(a,b));
           // cout << a << " " << b << endl;
        }
        int a = 0,b = 0;
        for(int i = 1; i < xy.size(); i++){
            a += xy[i-1].first * xy[i].second;
            b += xy[i-1].second * xy[i].first;
        }

        cout.precision(2)   ;
        cout << fixed << abs(a-b)/2.0 << endl;

    }

    return 0;
}
