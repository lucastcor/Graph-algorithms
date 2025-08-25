#include <iostream>
#include <vector>
#include <set> 
using namespace std;
 
 
int main(){
    int N,R,N2,R2;
    N=R=N2=R2=0;
    set<int> vertices,vertices2;
    int grau[10000],grau2[10000]; // degrees
    fill(begin(grau), end(grau), 0);
    fill(begin(grau2), end(grau2), 0);

    vector<vector<int>> grf(10000), grf2(10000); //graphs
    //insertion of graph
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
    cout << "insert the graph 2 v e, when finished insert 0 0" << endl;
    cin >> a >> b;
    while(a){ //inserting graph 2
        grf2[a].push_back(b);
        grf2[b].push_back(a);
        vertices2.insert(a);
        vertices2.insert(b);
        R2++;
        cin >> a >> b;
    }
    for(int v: vertices){ //counting degrees graph 1
        int cont= grf[v].size();
        grau[cont]+=1;
    }
    for(int v: vertices2){ //counting degrees graph 2
        int cont= grf2[v].size();
        grau2[cont]+=1;
    }
    bool grauok=true;
    for(int i=0; i<10000; i++){ //comparing degrees
        if(grau[i]!=grau2[i]) {grauok=false; break;}
    }
    cout << "Graph 2 inserted" << endl;
    
    bool iso=true;
    if(grauok==true) cout << "Same degrees" << endl;
    else {
        cout << "Degrees diferent" << endl;
        iso=false;
    }
    if(vertices.size()==vertices2.size()) cout <<"same vertex count" << endl;
    else {
        cout << "Vertex count diferent" << endl;
        iso=false;
    }
    if(R==R2) cout << "Same edges count" << endl;
    else{
        cout << "Edges count diferent" << endl;
        iso=false;
    } 
    if(iso) cout << "Isomorphic Graphs" << endl;
    else cout << "Not Isomorphic graphs" << endl;

    

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