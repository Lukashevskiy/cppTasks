#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n;
    ifstream cin("input.txt");
    cin >> n;

    int* mas = new int[n];

    for(int i = 0; i < n; i++){
        mas[i] = 0;
    }

    int b = 1;
    int a;
    while(!cin.fail()){
        int c;
        cin >> a >> c;
        a -= 1;
        c -= 1;
        if(mas[a] == 0 && mas[c] == 0){
            mas[a] = b;
            mas[c] = b;
            b++;
        }else if(mas[a] == 0 && mas[c] != 0){
            mas[a] = mas[c];
        }else if(mas[a] != 0 && mas[c] == 0){
            mas[c] = mas[a];
        }else{
            int g = mas[a];
            for(int i = 0; i < n; i++){
                if(mas[i] == g){
                    mas[i] = mas[c];
                }
            }
        }
        //cout << a << " - " << mas[a] << ", " << c << " - " << mas[c] << endl;
    }

    for(int i = 0; i < n; i++){
       if(mas[i] == 0){
            mas[i] = b;
            b++;
       }
    }

    set<int> uniqmas;
    for(int i = 0; i < n; i++){
        uniqmas.insert(mas[i]);
    }
    ofstream cout("output.txt");
    cout << uniqmas.size();

    return 0;
}
