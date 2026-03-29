//
// Created by User on 29/03/2026.
//

#include "SobreCargaOperadores.hpp"
void operator <<(ofstream &output,struct Cliente &cliente) {
    output<<setw(8)<<cliente.dni<<setw(2)<<""
        <<setw(60)<<left<<cliente.nombre
        <<setw(10)<<right<<cliente.telefono<<fixed<<setprecision(2)<<setw(10)<<cliente.montoTotal
        <<setw(25)<<"Productos entregados:";
    for (int i=0;i<=cliente.cantidadProductosEntrgados;i++) {
        output<<setw(8)<<cliente.productosEntregados[i].codigo;
    }
    if (cliente.cantidadProductosEntrgados==0) {
        output<<setw(50)<<"NO SE LE ENTREGARON PRODUCTOS";
    }
    output<<endl;
}
void operator <<(ofstream &output,struct Producto &producto) {
    output<<setw(8)<<producto.codigo<<setw(2)<<""<<setw(60)<<left<<producto.descripcion
        <<setw(10)<<right<<fixed<<setprecision(2)<<producto.precio<<setw(10)<<producto.stock<<endl
        <<setw(25)<<left<<"Clientes atendidos:";

    if (producto.cantidadClientesServidos==0) {
        output<<setw(25)<<right<<"NO SE ATENDIERON PEDIDOS";
    }else {
        for (int i=0;i<producto.cantidadClientesServidos;i++) {
            output<<setw(10)<<producto.clientesServidos[i];
        }
    }
    output<<endl;
    output<<setw(25)<<left<<"Clientes no atendidos:";
    if (producto.cantidadClientesNoServidos==0) {
        output<<setw(25)<<"NO HAY CLIENTES SIN ATENDER";
    }else {
        for (int i=0;i<producto.cantidadClientesNoServidos;i++) {
            output<<setw(10)<<producto.clientesNoServidos[i];
        }
    }


    output<<endl;
}
bool operator += (struct Producto *productos,struct Pedido &pedido) {
   int numero_producto=buscar_producto(productos,pedido.CodigoProducto);
    if (productos[numero_producto].stock>0) {
        int numero_cliente=productos[numero_producto].cantidadClientesServidos;
        productos[numero_producto].clientesServidos[numero_cliente]=pedido.dniCliente;
        productos[numero_producto].cantidadClientesServidos++;
    }else {
        int numero_cliente=productos[numero_producto].cantidadClientesNoServidos;
        productos[numero_producto].clientesNoServidos[numero_cliente]=pedido.dniCliente;
        productos[numero_producto].cantidadClientesNoServidos++;
    }
    pedido.precioProducto=productos[numero_producto].precio;
    if (productos[numero_producto].stock>0) {
        productos[numero_producto].stock--;
        return true;
    }else {
        return false;
    }
}
int buscar_producto(struct Producto *&productos,const char *codigo) {
    for (int i=0;strcmp(productos[i].codigo,"XXXXXXX")!=0;i++) {
        if (strcmp(productos[i].codigo,codigo)==0) return i;
    }
    return -1;
}
void operator += (struct Cliente *clientes,struct Pedido &pedido) {
    int numero_cliente=buscar_cliente(clientes,pedido.dniCliente);
    int numero_producto =clientes[numero_cliente].cantidadProductosEntrgados;
    clientes[numero_cliente].productosEntregados[numero_producto].precio=pedido.precioProducto;
    strcpy(clientes[numero_cliente].productosEntregados[numero_producto].codigo,pedido.CodigoProducto);
    clientes[numero_cliente].montoTotal+=pedido.precioProducto;
    clientes[numero_cliente].cantidadProductosEntrgados++;
}
int buscar_cliente(struct Cliente *&clientes,int dniCliente) {
    for (int i=0;clientes[i].dni!=0;i++) {
        if (dniCliente==clientes[i].dni) return i;
    }
    return -1;
}
bool operator >> (ifstream &input, struct Pedido &pedido) {
    input.getline(pedido.CodigoProducto,8,',');
    if (input.eof()) return false;
    input>>pedido.dniCliente;input.get();
    return true;
}
bool operator >> (ifstream &input,struct Producto &producto) {
    input.getline(producto.codigo,8,',');
    if (input.eof()) return false;
    input.getline(producto.descripcion,60,',');
    input>>producto.precio;input.get();
    input>>producto.stock;input.get();
    producto.cantidadClientesNoServidos=0;
    producto.cantidadClientesServidos=0;
    return true;
}
bool operator >> (ifstream &input, struct Cliente &cliente) {
    input>>cliente.dni;
    if (input.eof()) return false;
    input.get();
    input.getline(cliente.nombre,60,',');
    input>>cliente.telefono;input.get();
    cliente.cantidadProductosEntrgados=0;
    cliente.montoTotal=0;
    return true;
}
