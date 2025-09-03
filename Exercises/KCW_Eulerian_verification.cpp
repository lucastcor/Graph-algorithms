#include <iostream>
#include <vector>
#include <set> 
using namespace std;
 
void insert(vector<vector<int>>& grf, set<int> &vertices, int &R){
    cout << "insert the graph 1 v e, when finished insert 0 0" << endl;
    int a, b;
    cin >> a >> b;
    while(a){ //inserting graph 1
        grf[a].push_back(b);
        grf[b].push_back(a);
        vertices.insert(a);
        vertices.insert(b);
        cin >> a >> b;
        R++;
    }
}
void verif_completo(int n, int grau[] ){
    if(grau[n-1]==n-1 && n>1){
        cout << "Grafo Completo" << endl;
    }
}
void verif_ciclo(int n, int grau[]){
    if(grau[2]==n){
        cout << "Grafo é Ciclo" << endl;
    }
}
void verif_roda(int n, int grau[]){
    if(grau[3]==n-1 && grau[n-1]==1){
        cout << "Grafo é roda" << endl;
    }
}
int verificacao(int n, int grau[], int i){
    for(int j=1; j<n; j++){
        if(grau[j]%2!=0){
            i++;
        }
    }
    return i;
}

void verif_euclidiano(int n, int grau[]){
    int i=0;
    i=verificacao(n, grau, i);
    if(i==0){
        cout << "Grafo é um ciclo Euclidiano" << endl;
    }
    else{
        if(i==2){
            cout << "Grafo é um caminho Euleriano" << endl;
        }
        else{
            cout << "Grafo não é Euclidiano" << endl;
        }
    }
}
 
int main(){
    int N,R;
    set<int> vertices;
    int grau[10000],grau2[10000]; // degrees
    fill(begin(grau), end(grau), 0);
    fill(begin(grau2), end(grau2), 0);

    vector<vector<int>> grf(10000);
    insert(grf, vertices,R);
    for(int v: vertices){ //counting degrees graph 1
        int cont= grf[v].size();
        grau[cont]+=1;
    }
    N=vertices.size();
    verif_completo(N, grau);
    verif_ciclo(N, grau);
    verif_roda(N, grau);
    verif_euclidiano(N, grau);
    /* printar grafo
    for(int i=0; i<N; i++){
        cout << "vertice " << i+1 << ": ";
        for(int j=0; j<grf[i].size(); j++){
            cout << i+1 << ": ";
            cout<< grf[i][j] << " ";
        }
    }
    */

    return 0;
}