#include "matrizDispersa.h"

using namespace std;


 DisperseMatrix::DisperseMatrix() {
<<<<<<< HEAD
    vector<int> valores;
    vector<int> filas;
    vector<int> columnas;
    int m = 0 , n = 0;
 }

 DisperseMatrix::DisperseMatrix(int **&matriz, int fil, int col) // Arreglo de 2 dimensiones
{   vector<int> valores;
    vector<int> filas;
    vector<int> columnas;
=======
     valores;
     filas;
     columnas;
     nFilas = 0 , nColumnas = 0;
 }

 DisperseMatrix::DisperseMatrix(int **&matriz, int fil, int col) // Arreglo de 2 dimensiones
{   vector<int> valores;
    vector<int> filas;
    vector<int> columnas;
>>>>>>> izquierdo
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matriz[i][j] != 0)
            {
                valores.push_back(matriz[i][j]);
                filas.push_back(i);
                columnas.push_back(j);
            }
        }
    }

    // Debugging Zone
    cout << "Valores" << endl;
    for (int h = 0; h < valores.size(); h++)
    {
        cout << valores[h] << " ";
    }
    cout << endl;

    cout << "Filas" << endl;
    for (int h = 0; h < filas.size(); h++)
    {
        cout << filas[h] << " ";
    }
    cout << endl;

    cout << "Columnas" << endl;
    for (int h = 0; h < columnas.size(); h++)
    {
        cout << columnas[h] << " ";
    }
    cout << endl;

}

DisperseMatrix::DisperseMatrix(const vector<vector<int>> &matriz , int m , int n) // constructor funcional 
{ // vector de vectores
<<<<<<< HEAD
    vector<int> valores;
    vector<int> filas;
    vector<int> columnas;
    int nfilas = m ;
    int nColumnas = n ; 
=======
     valores;
     filas;
     columnas;
     nFilas = m ;
     nColumnas = n ; 
>>>>>>> izquierdo
    int fila, columna;
    for (fila = 0; fila < matriz.size(); fila++)
    {
        for (columna = 0; columna < matriz[fila].size(); columna++)
        {
            if (matriz[fila][columna] != 0)
            { 
                valores.push_back(matriz[fila][columna]);
                filas.push_back(fila);
                columnas.push_back(columna);
            }
        }
    }
}
 vector<vector<int>> DisperseMatrix::rebuild(){ 
         vector<vector<int>> result(nFilas,vector<int>(nColumnas,0)); // crea un matriz de 0 del tamaño original
         for (int i = 0; i < valores.size(); i++)
         {  
            int valor = valores[i];
            int fila = filas[i];
            int columna = columnas[i];
            result[fila][columna] = valor; // agrega los valores en las posicion original
         }
       
            return result;
    }
 int DisperseMatrix::get(int i, int j){
    bool flag = false;
    int e, ans;
    for( e = 0 ; e < valores.size() && !flag ; e++){ //busca si las cordenadas tienen un valor diferente de 0
        if(filas[e] == i){
            if(columnas[e] == j){
                flag = true;
            }
        }
    } 
    if(flag == false){ // si no es un valor diferente de 0 retorna 0 y si la posicion no existe imprime posicion invalida
            if(i < nFilas && j < nColumnas){
                ans = 0;
            } else {
                cout << "Posicion invalida" << endl;
            }
    } else {
        ans = valores[e-1];  // imprime el valor correspondiente a la posicion encontrada
    }
    return ans;  
 }
 vector<int> DisperseMatrix::getRowVec(int fila){ 
    vector<int> result; 
    if(fila >= nFilas){
        cout << "fila invalido" << endl;
    }
    int i;
    for ( i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if(fila == filas[i]){
            result.push_back(valores[i] ) ;
        }
    }
    return result;
 }
 vector<int> DisperseMatrix::getColVec(int columna){
     vector<int> result;
     int i;
     if(columna >= nColumnas){
        cout << "columna invalido" << endl;
    }
     for ( i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
     {   
        if (columnas[i] == columna)
        {
            result.push_back(valores[i]);
        }
        
     }
     return result;
 }