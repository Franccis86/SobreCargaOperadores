//
// Created by AlienCoders on 22/12/2025.
//

#ifndef ADEL_P2_2026_SOL_LAB01_2023_2_ESTRUCTURAS_H
#define ADEL_P2_2026_SOL_LAB01_2023_2_ESTRUCTURAS_H

struct Producto{
    char codigo[8];
    char descripcion[60];
    double precio;
    int stock;
    int clientesServidos[20];
    int clientesNoServidos[20];
    int cantidadClientesServidos;
    int cantidadClientesNoServidos;
};

struct ProductoEntregado{
    char codigo[8];
    double precio;
};

struct Cliente{
    int dni;
    char nombre[60];
    int telefono;
    struct ProductoEntregado productosEntregados[20];
    int cantidadProductosEntrgados;
    double montoTotal;
};

struct Pedido{
    char CodigoProducto[8];
    int dniCliente;
    double precioProducto;
};

#endif //ADEL_P2_2026_SOL_LAB01_2023_2_ESTRUCTURAS_H