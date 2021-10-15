#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define INF 999999999

void split_for_two_ints(string& str, pair<int,int>& xy){
    string ans;
    ans = "";
    for(register int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            xy.first = stoi(ans);
            ans = "";
        }else{
            ans += str[i];
        }
    }
    xy.second = stoi(ans);

}


void alg_Floyd(vector<vector<int> >& d, int n){
    int a =  0;

    for (register int k=0; k<n; ++k){
        if(k % (n/10) == 0){
            cout << a*10 << "%" <<endl;
            a++;
        }
        for (register int i=0; i<n; ++i){

            int bufik = d[i][k];

            for (register int j=0; j<n; ++j){
                int bufkj = d[k][j];

                if (bufik < INF && bufkj < INF)
                    d[i][j] = min (d[i][j], bufik + bufkj);
            }
        }
    }
}

int main(int args, char* argv[])
{
    ifstream fin(argv[1]); //ввод файла из консоли
   // ifstream fin("facebook_combined.txt"); //тут если загрузить файл в папку
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);

    if(!fin.is_open()){
        cout << "cock";
        cout << endl;
        return 0;
    }else{

        vector< pair<int, int> > pair_merge;

        string str = "";
        int maxNode = 0;
        while(getline(fin, str)){

            pair<int, int> buffer_pair;

            split_for_two_ints(str, buffer_pair);
            maxNode = max(maxNode, max(buffer_pair.first, buffer_pair.second));
            pair_merge.push_back(buffer_pair);
        }
        maxNode++;

        vector<vector<int> > table_merge(maxNode);
        for(register int i = 0; i < maxNode; i++){
            table_merge[i].resize(maxNode, INF);
        }
        for(register int i = 0; i < maxNode; i++){
            table_merge[i][i] = 0;
        }

        for(register int i = 0; i < pair_merge.size(); i++){
            table_merge[pair_merge[i].first][pair_merge[i].second] = 1;
            table_merge[pair_merge[i].second][pair_merge[i].first] = 1;
        }

        alg_Floyd(table_merge, maxNode);

        ofstream fout("output.txt");
        for(int i = 0; i < maxNode; i++){
            string str;
            str = "";
            for(int j = 0; j < maxNode; j++){
                str += to_string(table_merge[i][j]) + " ";
            }
            str += "\n";
            fout << str;
        }


    }

    return 0;
}

