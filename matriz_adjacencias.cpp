#include <iostream>
using namespace std;

int main(){
    int n, m; // numero de vertices; numero de arestas do grafo
 
    cin >> n >> m;
  
    while(!cin.eof()){

        int** M = new int*[n+1]; // matriz de adjacencia
        int** W = new int*[n+1]; // matriz do fecho transitivo
        for(int i = 1; i <= n; i++){
            M[i] = new int[n+1];
            W[i] = new int[n+1];
        }
  
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                M[u][v] = W[u][v] = 0;
            }
        }
     
        // leitura do grafo
        int u, v;
        for(int i = 0; i < m; i++){
            cin >> u >> v; // lendo as arestas do grafo
            M[u][v] = W[u][v] = 1;
        }
  
        // Implementacao do algoritmo de Warshall
        for(int k = 1; k <= n; k++){
            for(int u = 1; u <= n; u++){
                for(v = 1; v <= n; v++){
                    cout <<endl << u <<" " << v << "  : " << W[u][v] << " || "<< u ;
                    cout <<" " << k << "  : " << W[u][k] << " && "<< k <<" " << v;
                    cout << "  : " << W[k][v];
                    W[u][v] = W[u][v] || (W[u][k] && W[k][v]);
                    cout << " - " << W[u][v];
                    
                }
            }
        }
        cout << endl;
  
        cout << "Matriz de adjacencia" << endl;
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                cout << M[u][v] << " ";
            }
            cout << endl;
        }
  
        cout << "Fecho transitivo de cada vertice" << endl;
        for(int u = 1; u <= n; u++){
            cout << "Vertice " << u << ": ";
            for(int v = 1; v <= n; v++){
                if(W[u][v]){
                    cout << v << " ";
                }
            }
            cout << endl;
        }
     
        for(int u = 0; u <= n; u++){
        delete M[u];
        delete W[u];
        }
        delete[] M;
        delete[] W;
     
        cin >> n >> m;
    }
    return 0;
}
