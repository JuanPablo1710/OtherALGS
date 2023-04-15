#include <iostream>
#include <vector>
using namespace std;

struct element{
    string name;
    int weight;
    int cost;
};

int main(){

    int n, m;
    cin >> n >> m;
    vector<element> elements;

    for(int i = 0; i < n; i++){
        int w, c;
        string nm;
        cin  >> nm >> w >> c;

        element nv;
        nv.weight = w;
        nv.cost = c;
        nv.name = nm;
        elements.push_back(nv);
    }

    int table [n][m];

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            
            int prevM = 0;
            if(i > 0) prevM = table[i-1][j-1];

            if(elements[i].weight > j){
                table[i][j-1] = prevM;
                continue;
            }

            int remS = 0;
            if(elements[i].weight < j && i != 0) remS = table[i-1][j-elements[i].weight];

            int val = max(prevM, elements[i].cost + remS);

            table[i][j-1] = val;
        }

        cout << endl;
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            
            cout << table[i][j-1] << " ";
        }

        cout << endl;
    }

    return 0;
}
