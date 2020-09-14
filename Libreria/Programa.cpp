#include "MiLibreria.hpp"
#include <iostream>
using namespace std;
int main() {
 MiClase mc;
 mc.Inicializar();
 mc.Contar(10);
 for(int i = 0; i < 100; i++) mc.Contar(i);
 cout << "Contador = " << mc.Contador() << endl;
 mc.Inicializar(1000);
 cout << "Contador = " << mc.Contador() << endl;
 return 0;
}
