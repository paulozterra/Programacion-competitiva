#include <bits/stdc++.h>
using namespace std;
void solve(vector<int>pub,vector<int>tem){
    set<int>s; // se creara un set para almacenar publicaciones nuevas
    // basicamente la idea es que no necesitamos mover manualmente las posiciones y publicaciones.
    // ->si existe una nueva publicacion que no se ha agregado antes ( el motivo del set) entonces
    // la ultima publicacion sera eliminada
    // ->Si no existe no se hace nada
    int matriz[pub.size()];
    for(int i=0;i<pub.size();i++){ //complejidad O(n)
        matriz[i]=-1; // aca haremos las modificaciones de las publicaciones
        s.insert(i+1); // ingresamos los valores de las publicaciones
    }
    int t3=pub.size(); // guardamos la posicion de la "ultima publicacion" para actulizar nuestra matriz
    for(int i=0;i<tem.size();i++){  // complejidad O(m)
        int t=s.size(); // guardamos el tamaño del set antes de ingresar una nueva publicacion
        s.insert(tem[i]); // agregamos al set
        if(s.size()!=t){ // si el tamaño cambia la ultima publicacion fue desplazada
            matriz[t3-1]=i+1; // debemos actualizar la matriz
            t3--;
        }

    }
    for(int k=0;k<pub.size();k++){
        cout<<matriz[k]<<" "; // imprimir
    }
    cout<<endl;
}

int main() {
    int test = 0;
    int n = 0;
    int m = 0;
    int temp = 0;
    cin >> test;
    vector<int> pub;
    vector<int> tem;
    for (int i = 0; i < test; i++) { //O(test*n) o O(test*m)
        cin >> n >> m;
        for (int k = 0; k < n; k++) { //O(n)
            pub.push_back(n - k - 1);  //llenado de publicaciones predeterminadas
        }
        for (int j = 0; j < m; j++) { //O(m)
            cin >> temp;
            tem.push_back(temp); //llenado de nuevas publicaciones
        }
        solve(pub, tem); // complejidad lineal dependiendo de quien es mayor entre n y m
        pub.clear();
        tem.clear();
    }
    //complejidad al tener el for de los test y luego en el solve tenemos otro for para n y m
    //la complejidad sera de O(test*n) o O(test*m)
    return 0;
}
