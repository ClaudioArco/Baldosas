#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <set>

using namespace std;

struct estado {
    int fila;
    int columna;
};

struct nodo {
    estado st;
    int value;
    vector<vector<int> > mapa;
    list<pair<int, int> > secuencia;
};

struct ComparaEstados
{
	bool operator()(const estado &a, const estado &n) const
	{
		if ((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
			(a.fila == n.fila and a.columna == n.columna))
			return true;
		else
			return false;
	}
};

bool matrizVacia(vector<vector<int> > baldosas){
    bool vacia = true;
    for(int i = 0; i < baldosas.size(); i++){
        for(int j = 0; j < baldosas[0].size(); j++){
            if(baldosas[i][j] != 0){
                vacia = false;
            }
        }
    }

    return vacia;
}

void setupMap8(nodo &origen, nodo &destino){
    int rows = 8;
    int columns = 8;
    
    vector<vector<int> > baldosas;
    vector<int> fila;
    fila.push_back(0);
    fila.push_back(0);
    fila.push_back(0);
    fila.push_back(1);
    fila.push_back(2);
    fila.push_back(2);
    fila.push_back(3);
    fila.push_back(2);

    fila.push_back(0);
    fila.push_back(0);
    fila.push_back(1);
    fila.push_back(0);
    fila.push_back(1);
    fila.push_back(0);
    fila.push_back(2);
    fila.push_back(2);

    fila.push_back(1);
    fila.push_back(2);
    fila.push_back(3);
    fila.push_back(2);
    fila.push_back(2);
    fila.push_back(0);
    fila.push_back(0);
    fila.push_back(0);

    fila.push_back(0);
    fila.push_back(0);
    fila.push_back(0);
    fila.push_back(0);
    fila.push_back(3);
    fila.push_back(3);
    fila.push_back(2);
    fila.push_back(2);

    fila.push_back(0);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(2);
    fila.push_back(2);
    fila.push_back(0);
    fila.push_back(0);
    fila.push_back(2);

    fila.push_back(1);
    fila.push_back(3);
    fila.push_back(0);
    fila.push_back(0);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(3);

    fila.push_back(0);
    fila.push_back(2);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(0);
    fila.push_back(1);

    fila.push_back(0);
    fila.push_back(2);
    fila.push_back(1);
    fila.push_back(0);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(0);
    fila.push_back(0);

    int util = 0;

    for(int i = 0; i < rows; i++){
        vector<int> row;
        row.clear();
        for(int j = 0; j < columns; j++){
            row.push_back(fila[util]);
            util++;
        }
        baldosas.push_back(row);
    }

    origen.st.fila = 7;
    origen.st.columna = 1;

    origen.mapa = baldosas;
    
    destino.st.fila = 0;
    destino.st.columna = 5;

}

void setupMap4(nodo &origen, nodo &destino){

    int rows = 4;
    int columns = 4;

    vector<vector<int> > baldosas;
    vector<int> fila;
    fila.push_back(0);
    fila.push_back(2);
    fila.push_back(2);
    fila.push_back(2);

    fila.push_back(0);
    fila.push_back(1);
    fila.push_back(2);
    fila.push_back(2);

    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(2);
    fila.push_back(1);

    fila.push_back(2);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(1);

    int util = 0;

    for(int i = 0; i < rows; i++){
        vector<int> row;
        row.clear();
        for(int j = 0; j < columns; j++){
            row.push_back(fila[util]);
            util++;
        }
        baldosas.push_back(row);
    }

    origen.st.fila = 3;
    origen.st.columna = 0;

    origen.mapa = baldosas;
    
    destino.st.fila = 0;
    destino.st.columna = 3;

}

void setupMap4b(nodo &origen, nodo &destino){

    int rows = 4;
    int columns = 4;

    vector<vector<int> > baldosas;
    vector<int> fila;
    fila.push_back(0);
    fila.push_back(2);
    fila.push_back(2);
    fila.push_back(2);

    fila.push_back(0);
    fila.push_back(1);
    fila.push_back(2);
    fila.push_back(2);

    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(2);
    fila.push_back(2);

    fila.push_back(2);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(2);

    int util = 0;

    for(int i = 0; i < rows; i++){
        vector<int> row;
        row.clear();
        for(int j = 0; j < columns; j++){
            row.push_back(fila[util]);
            util++;
        }
        baldosas.push_back(row);
    }

    origen.st.fila = 3;
    origen.st.columna = 0;

    origen.mapa = baldosas;
    
    destino.st.fila = 0;
    destino.st.columna = 3;

}

void setupMap4c(nodo &origen, nodo &destino){

    int rows = 4;
    int columns = 4;

    vector<vector<int> > baldosas;
    vector<int> fila;
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(2);

    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(2);

    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(2);

    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(1);
    fila.push_back(1);

    int util = 0;

    for(int i = 0; i < rows; i++){
        vector<int> row;
        row.clear();
        for(int j = 0; j < columns; j++){
            row.push_back(fila[util]);
            util++;
        }
        baldosas.push_back(row);
    }

    origen.st.fila = 3;
    origen.st.columna = 0;

    origen.mapa = baldosas;
    
    destino.st.fila = 0;
    destino.st.columna = 3;

}

void printMatriz(vector<vector<int> > baldosas){
    for(int i = 0; i < baldosas.size(); i++){
        for(int j = 0; j < baldosas[0].size(); j++){
            cout << " " << baldosas[i][j];
        }

        cout << endl;
    }
}

void printSolucion(list<pair<int, int> > plan, vector<vector<int> > mapa){

    list<pair<int, int> >::iterator it;

    for(it = plan.begin(); it != plan.end(); ++it){
        cout << " (" << (*it).first << ", " << (*it).second << ") " ;
        mapa[(*it).first][(*it).second] -= 1;
        //printMatriz(mapa);
        //cout << endl;
    }


}


int main() {

    vector<vector<nodo> > baldosas;
    nodo origen, destino;
    //setupMap4(origen, destino);
    //setupMap4b(origen, destino);
    //setupMap4c(origen, destino);
    setupMap8(origen, destino);

    printMatriz(origen.mapa);
    
    list<pair<int, int> > plan;

    clock_t tantes;
    clock_t tdespues;

    tantes = clock();

	// Borro la lista
	//cout << "Calculando plan\n";
	plan.clear();
	set<estado, ComparaEstados> Cerrados; // Lista de Cerrados
	stack<nodo> Abiertos;				  // Lista de Abiertos

	nodo current;
	current.st = origen.st;
    current.mapa = origen.mapa;
	current.secuencia.empty();
    current.secuencia.push_back(pair<int,int>(current.st.fila, current.st.columna));
    current.mapa[current.st.fila][current.st.columna] -= 1;

	Abiertos.push(current);

    bool solucion = false;

	while (!Abiertos.empty() and solucion == false)
	{

        //printMatriz(current.mapa);
        //cout << endl;

        if(matrizVacia(current.mapa) == true and (current.st.fila == destino.st.fila and current.st.columna == destino.st.columna)){
            solucion = true;
           
        } else {

            Abiertos.pop();
            Cerrados.insert(current.st);

            // Generar descendiente de girar a la derecha
            nodo movDerecha = current;
            movDerecha.mapa = current.mapa;
            if(current.st.columna < current.mapa[0].size() - 1 ){
            
                if(movDerecha.mapa[current.st.fila][current.st.columna + 1] > 0){

                    movDerecha.st.columna++;
                    movDerecha.mapa[movDerecha.st.fila][movDerecha.st.columna] -= 1;
                        
                    if (Cerrados.find(movDerecha.st) == Cerrados.end())
                    {
                        movDerecha.secuencia.push_back(pair<int, int>(movDerecha.st.fila, movDerecha.st.columna));
                        Abiertos.push(movDerecha);
                    }
                }

            }

            // Generar descendiente de girar a la izquierda 
            nodo movIzquierda = current;
            movIzquierda.mapa = current.mapa;
            if(current.st.columna > 0){
                if(movIzquierda.mapa[current.st.fila][current.st.columna - 1] > 0){
                
                    movIzquierda.st.columna--;
                    movIzquierda.mapa[movIzquierda.st.fila][movIzquierda.st.columna] -= 1;

                    if (Cerrados.find(movIzquierda.st) == Cerrados.end())
                    {
                        movIzquierda.secuencia.push_back(pair<int, int>(movIzquierda.st.fila, movIzquierda.st.columna));
                        Abiertos.push(movIzquierda);
                    }
                }
            }

            // Generar descendiente de avanzar
            nodo movDelante = current;
            movDelante.mapa = current.mapa;
            if(current.st.fila > 0) {
                if (movDelante.mapa[current.st.fila - 1][current.st.columna] > 0){
                
                    movDelante.st.fila--;
                    movDelante.mapa[movDelante.st.fila][movDelante.st.columna] -= 1;

                    if (Cerrados.find(movDelante.st) == Cerrados.end())
                    {
                        movDelante.secuencia.push_back(pair<int, int>(movDelante.st.fila, movDelante.st.columna));
                        Abiertos.push(movDelante);
                    }
                }
            }

            // Generar descendiente de ir hacia atras
            nodo movDetras = current;
            movDetras.mapa = current.mapa;
            if(current.st.fila < current.mapa.size() - 1) {

                if (movDetras.mapa[current.st.fila + 1][current.st.columna] > 0){
                
                    movDetras.st.fila++;
                    movDetras.mapa[movDetras.st.fila][movDetras.st.columna] -= 1;

                    if (Cerrados.find(movDetras.st) == Cerrados.end())
                    {
                        movDetras.secuencia.push_back(pair<int, int>(movDetras.st.fila, movDetras.st.columna));
                        Abiertos.push(movDetras);
                    }
                }
            }

            // Tomo el siguiente valor de la Abiertos
            if (!Abiertos.empty())
            {
                current = Abiertos.top();
            }
        }
	}

    tdespues = clock();
    cout << "Tiempo: " << "\t" << (double)(tdespues - tantes) / CLOCKS_PER_SEC << endl;

    if (matrizVacia(current.mapa) and current.st.fila == destino.st.fila and current.st.columna == destino.st.columna)
	{
        //cout << "Solucion: " << endl;
		plan = current.secuencia;
		printSolucion(plan, origen.mapa);

	} else {
        //cout << "No se ha encontrado plan " << endl;
    }

   


}