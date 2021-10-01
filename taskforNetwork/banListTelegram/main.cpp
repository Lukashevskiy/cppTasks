#include <iostream>
#include <fstream>
#include <string>

using namespace std;

pair<string, int> sizeOfMask(string str){
    string ans = "";
    string ans1 = "";
    bool flag = false;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '/'){
            flag = true;
            continue;
        }
        if(flag){
            ans += str[i];
        }else{
            ans1 += str[i];
        }
    }
    return make_pair(ans1,stoi(ans));
}

unsigned int poW(int n, int i){
    unsigned int ans = 1;
    for(;i>0;i--){
        ans *= n;
    }
    return ans;
}

int main(int args, char* argv[]){
    ifstream fin(argv[1]);
    unsigned int answer = 0;
    if(fin.is_open()){
        string str;
        while(fin >> str){
            pair<string, int> a;
            a = sizeOfMask(str);
            answer += poW(2,32-a.second);
            cout << a.first << " ------ " << poW(2,32-a.second) << endl;
        }
        cout << "*------------------------------TOTAL------------------------------*" << endl;
        cout << answer << " - ip's blocked\n";
        cout << "*-----------------------------------------------------------------*" << endl;

    }else{
        cout << "Check our file";
    }

    return 0;
}
