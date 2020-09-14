#include "MiLibreria.hpp"
MiClase::MiClase() { }
void MiClase::Inicializar(int _Contador) {
 this->_Contador = _Contador;
}
void MiClase::Contar(int Paso) {
 _Contador += Paso;
}
int MiClase::Contador() {
 return _Contador;
}
