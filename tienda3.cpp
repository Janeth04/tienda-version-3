#include <conio.h>
#include <iostream>
#include <locale>
#include <cstdlib>
using namespace std;
struct libro{
     double nombre;
     struct libro *precio, *exis;
};
typedef struct libro *ABB;
ABB crearLibro(int x)
{
     ABB nuevoLibro = new(struct libro);
     nuevoLibro->nombre = x;
     nuevoLibro->precio = NULL;
     nuevoLibro->exis = NULL;

     return nuevoLibro;
}
void insertar(ABB &arbol, char x)
{
     if(arbol==NULL)
     {
           arbol = crearLibro(x);
     }
     else if(x < arbol->nombre)
          insertar(arbol->precio, x);
     else if(x > arbol->nombre)
          insertar(arbol->exis, x);
}
void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->precio, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nombre <<endl;

     verArbol(arbol->exis, n+1);
}


int main()
{
    ABB arbol = NULL;   

    int n;  // numero de libros del arbol
    double x;
    string nombre;
    string autor;
    int precio;
    cout << " Numero de libros del arbol:  ";
    cin>>n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " clave " <<i+1 << ": ";
        cin>>x;
        cout<<"nombre" <<endl;
        getline(cin, nombre);
        getline(cin, nombre);
        cout<<"precio" <<endl;
       //getline(cin, precio);
       cin>>precio;
       cout<<"autor"<<endl;
        getline(cin, autor);
        getline(cin, autor);
        insertar( arbol, x);
    }

    cout << "\n Mostrando ABB \n\n";
   verArbol( arbol, 0);
    system("pause");
    return 0;

}

