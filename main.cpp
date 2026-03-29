#include <iostream>
#include "Librerias/Utils.h"
#include "Librerias/SobreCargaOperadores.hpp"
int main() {
    int dios=1000;
    ifstream input;apertura_archivo_entrada(input,"../Archivos/Clientes.csv");
    struct Cliente clientes[200];
    int i=0;
    while (true) {
        if ((input>>clientes[i])==false) {
            clientes[i].dni=0;
            break;
        }
        i++;
    }
    struct Producto productos[200];
    int j=0;
    ifstream input2;apertura_archivo_entrada(input2,"../Archivos/Productos.csv");
    while (true) {
        if ((input2>>productos[j])==false) {
            strcpy(productos[j].codigo,"XXXXXXX");
            break;
        }
        j++;
    }

    ofstream output; apertura_archivo_salida(output,"../Archivos/ReporteCliente");

    ifstream input3;apertura_archivo_entrada(input3,"../Archivos/Pedidos.csv");
    struct Pedido pedido;
    while (true) {
        if ((input3>>pedido)==false) break;
        clientes += pedido;
        productos += pedido;
    }
    for (int i=0;clientes[i].dni!=0;i++) {
        output<<clientes[i];
    }
    for (int i=0;strcmp(productos[i].codigo,"XXXXXXX")!=0;i++) {
        output<<productos[i];
    }

    return 0;
}
