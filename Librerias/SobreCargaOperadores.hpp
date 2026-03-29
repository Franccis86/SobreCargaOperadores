//
// Created by User on 29/03/2026.
//

#ifndef LABORATORIO1_SOBRECARGAOPERADORES_HPP
#define LABORATORIO1_SOBRECARGAOPERADORES_HPP
#include "Funciones.h"
#include "Estructuras.h"
void operator <<(ofstream &output,struct Producto &producto);
void operator <<(ofstream &output,struct Cliente &cliente);
bool operator += (struct Producto *productos,struct Pedido &pedido);
bool operator >> (ifstream &input,struct Cliente &cliente);
bool operator >> (ifstream &input,struct Producto &producto);
bool operator >> (ifstream &input, struct Pedido &pedido);
int buscar_cliente(struct Cliente *&clientes,int dniCliente);
void operator += (struct Cliente *clientes,struct Pedido &pedido);
int buscar_producto(struct Producto *&productos,const char *codigo);

#endif //LABORATORIO1_SOBRECARGAOPERADORES_HPP
