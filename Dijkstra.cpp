#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct destino{
    int v, p;
};

bool operator<(destino a, destino b){return a.p > b.p;}

int main(){

    int n, m, it = 0;
    cin >> n >> m;

    vector<vector<destino>> graph(n);
    map<int, string> nombres;
    map<string, int> nombres1;
    map<string, string> padres;
    set<string> nm;

    for(int i = 0; i < m; i++){
        int w;
        string o, d;
        cin >> o >> d >> w;
        if(nm.find(o) == nm.end()){
            nm.insert(o);
            nombres[it] = o;
            nombres1[o] = it;
            it++;
        }
        if(nm.find(d) == nm.end()){
            nm.insert(d);
            nombres[it] = d;
            nombres1[d] = it;
            it++;
        } 
        graph[nombres1[o]].push_back({nombres1[d], w});
    }

    priority_queue<destino> cola;
    string ini;
    cin >> ini;
    cola.push(destino{nombres1[ini], 0});

    vector<int> visited(n, -1);

    while(!cola.empty()){
        destino act = cola.top();
        cola.pop();

        if(visited[act.v] == -1){
            visited[act.v] = act.p;   
            for(destino vecino : graph[act.v]){
                int nw = vecino.p + act.p;
                if(nw < visited[vecino.v] || visited[vecino.v] == -1){
                    padres[nombres[vecino.v]] = nombres[act.v];
                    cola.push(destino {vecino.v, nw});
                }             
            }
        }
    }

    string fin;
    cin >> fin;
    it = nombres1[fin];
    cout << nombres[it] << " <- ";
    while(it != nombres1[ini]){
        cout << padres[nombres[it]] << " <- ";
        it = nombres1[padres[nombres[it]]];
    }
}
