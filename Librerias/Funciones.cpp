//
// Created by User on 29/03/2026.
//

#include "Funciones.h"

void apertura_archivo_entrada(ifstream &input, const char *file_name) {
    input.open(file_name);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo entrada"<<file_name << endl;
        exit(1);
    }
}
void apertura_archivo_salida(ofstream &output, const char *file_name) {
    output.open(file_name);
    if (!output.is_open()) {
        cout<<"Error al abrir el archivo de saldia"<<file_name << endl;
        exit(1);
    }
}