#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Comida{
    string nombre;
    char tipo;
    float precioUnitario;
};
Comida menuDonas();
Comida menuPlatoFuerte();

struct Pedido{
    string apellido;
    list <Comida> comidas;
    float monto;
};
list<Pedido> pedidosDonas, pedidosPlatosFuertes;
void atender(), gananciasDonas(), gananciasPlatosFuertes();

int main(){
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Atender orden de cliente.\n";
        cout << "2) Ganancias por donas.\n";
        cout << "3) Ganancias por platos fuertes.\n";
        cout << "4) Salir.\nOpcion: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: atender(); break;
            case 2: gananciasDonas(); break;
            case 3: gananciasPlatosFuertes(); break;
            case 4: continuar = false; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    }while(continuar);

    return 0;
}

Comida menuDonas(){
    Comida unaComida;
    unaComida.tipo = 'd';
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "1) Dona sencilla azucar $1.\n";
        cout << "2) Dona sencilla chocolate $1.25.\n";
        cout << "3) Dona rellena coco $1.50.\n";
        cout << "4) Dona rellena moca $1.75.\nOpcion: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: unaComida.nombre = "Dona sencilla azucar";
                unaComida.precioUnitario = 1; continuar = false; break;
            case 2: unaComida.nombre = "Dona sencilla chocolate";
                unaComida.precioUnitario = 1.25; continuar = false; break;
            case 3: unaComida.nombre = "Dona rellena coco";
                unaComida.precioUnitario = 1.50; continuar = false; break;
            case 4: unaComida.nombre = "Dona rellena moca";
                unaComida.precioUnitario = 1.75; continuar = false; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    }while(continuar);
    
    return unaComida;
}

Comida menuPlatoFuerte(){
    Comida unaComida;
    unaComida.tipo = 'p';
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "1) Desayuno $2.50.\n";
        cout << "2) Almuerzo $5.00.\n";
        cout << "3) Cena $3.50.\nOpcion: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: unaComida.nombre = "Desayuno";
                unaComida.precioUnitario = 2.5; continuar = false; break;
            case 2: unaComida.nombre = "Almuerzo";
                unaComida.precioUnitario = 5; continuar = false; break;
            case 3: unaComida.nombre = "Cena";
                unaComida.precioUnitario = 3.5; continuar = false; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    }while(continuar);
    
    return unaComida;
}

void atender(){
    Pedido unPedido;
    cout << "Bienvenido, favor digite su apellido: ";
    getline(cin, unPedido.apellido);
    
    // Preguntar si el cliente desea comprar donas o platos fuertes.
    char opcion = 'f';
    do{
        cout << "Desea comprar donas (d) o platos fuertes (p): ";
        cin >> opcion; cin.ignore();
    }while(opcion != 'd' && opcion != 'p');
    
    // Ingresar todos los alimentos que el cliente desea comprar.
    bool continuar = true;
    do{
        char letra = 's';
        cout << "Desea ordenar algo más? (s/n): ";
        cin >> letra; cin.ignore();
        
        if(letra == 's' && opcion == 'd'){
            Comida unaDona = menuDonas();
            unPedido.comidas.insert(unPedido.comidas.end(), unaDona);
        }
        else if(letra == 's' && opcion == 'p'){
            Comida unPlatoFuerte = menuPlatoFuerte();
            unPedido.comidas.insert(unPedido.comidas.end(), unPlatoFuerte);
        }
        else
            continuar = false;
    }while(continuar);
    
    // Calcular el monto
    float acumulador = 0;
    for(Comida c : unPedido.comidas){
        acumulador += c.precioUnitario;
    }
    unPedido.monto = acumulador;
    cout << "Su monto es de: $" << acumulador << endl;
    // Almacenar el pedido en una estructura dinámica
    if(opcion == 'd')
        pedidosDonas.insert(pedidosDonas.end(), unPedido);
    else
        pedidosPlatosFuertes.insert(pedidosPlatosFuertes.end(), unPedido);
}

void gananciasDonas(){
    float ganancias = 0;
    for(Pedido p : pedidosDonas){
        ganancias += p.monto;
    }
    cout << "Ganancias por donas: $" << ganancias << endl;
}

void gananciasPlatosFuertes(){
    float ganancias = 0;
    for(Pedido p : pedidosPlatosFuertes){
        ganancias += p.monto;
    }
    cout << "Ganancias por platos fuertes: $" << ganancias << endl;
}


  /*  // Recorrer - acceder a los elementos
    cout << "\nContenido vector01: ";
    for (int i = 0; i < vector01.size(); i++)
        cout << vector01[i] << "  ";
        */