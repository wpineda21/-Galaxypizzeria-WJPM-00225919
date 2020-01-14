#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void Welcome();
void HomeDelivery();
void RestaurantOrder();

struct homedeliv{
string CustomeName;
string HomeAddress;
int Homephone;
int LunchPlate,Entry,Drinks;
float Amount,PaymentType;  
};
struct homedeliv order[10];
int DelivOrders=0;

struct restaurantdeliv{
string customname;
int LunchPlate,people,Entry,Drinks;
float Amount,PaymentType;  
};
struct restaurantdeliv Deliv[10];
int Restaurantorder=0;

int main(){
Welcome();
    return 0;
}

void Welcome(){
int opt;
bool OUT = true;
char password2[12];
char user2[12];
char password[12]={"ide"};
char user[12]={"william21"};

cout<<""<<endl;
cout<<"Bienvenido Pizzeria ""Galaxy"""<<endl;
cout<<""<<endl;
cout<<"El Mejor Sabor  de la Galaxia" <<endl;
cout<<"ingrese su usuario De trabajo"<<endl;
cin>>user2;
cout<<"ingrese su contra porfavor"<<endl;
cin>>password2;

if((strcmp(password2,password)==0) && (strcmp(user2,user)==0)){

do{
cout<<""<<endl;
cout<<"Galaxy un sabor astral"<<endl;
cout<<""<<endl;
cout<<"Que desea hacer en esta Ocasion"<<endl;
cout<<"1) Agregar  1 pedido a domicilio................"<<endl;
cout<<"2) Agregar  1 Encargo a Restaurante............."<<endl;
cout<<"3) Ver Pedidos a Domicilio......................"<<endl;
cout<<"4) Ver Encargos en el Restaurante................"<<endl;
cout<<"5) Ver Total de ventas..........................."<<endl;
cout<<"6) Salir........................................."<<endl;
cin>>opt;

switch (opt){
    case 1: HomeDelivery();
            break;
    case 2: ;
    break;
    case 3: ;
    break;
    case 4: ;
    break;
    case 5: ;
    break;
    case 6: OUT=false;
    break;
default:
    break;
}


}while(OUT);

    }
}

void HomeDelivery(){
    if (DelivOrders<10){
    cin.ignore();
    cout<<"Porfavor Ingrese el nombre del cliente"<<endl;    
    getline(cin,order[DelivOrders].CustomeName);    
    cout<<"Porfavor Ingrese la direccion del cliente"<<endl;    
    getline(cin,order[DelivOrders].HomeAddress);  
    cout<<"Porfavor Ingrese el telefono de casa del cliente"<<endl;    
    cin>>(cin,order[DelivOrders].Homephone); 
    cout<<""<<endl;
    cout<<"Un Menu fuera de la  Galaxia"<<endl;
    cout<<"seleccione una opcion a su gusto"<<endl;
    cout<<"1)pizza..............."<<endl;
    cout<<"2)pasta..............."<<endl;
    cout<<"3)ensalada............"<<endl;
    cout<<"Porfavor Ingrese La seleccion del plato del cliente"<<endl;    
    cin>>(cin,order[DelivOrders].LunchPlate);       
    cout<<"tambien tenemos ricas entradas "<<endl;
    cin.ignore();
    cout<<"4)Alitas marcianas....(Alas de pollo)...."<<endl;
    cout<<"5)Aros de saturno.....(Aros de cebolla con queso)"<<endl;
    cout<<"Porfavor Ingrese La seleccion de entrada del cliente"<<endl;    
    cin>>(cin,order[DelivOrders].Entry); 
    cout<<"porfavor escoja una bebida"<<endl;  
    cout<<"1) gaseosa espacial"<<endl;
    cout<<"2) te de marte" <<endl;
    cout<<"Porfavor Ingrese La seleccion de bebida del cliente"<<endl;    
    cin>>(cin,order[DelivOrders].Entry); 
    cin.ignore();
    cout<<"su total a pagar es "<<endl;
    }
}

void RestaurantOrder(){
    if (DelivOrders<10){
    cin.ignore();
    cout<<"nombre de quien realizo la reserva"<<endl;    
    getline(cin,Deliv[Restaurantorder].people);   
    cout<<"Personas por mesa"<<endl;    
    cin>>(cin,Deliv[Restaurantorder].CustomeName); 
    cout<<"Plato principal"<<endl;    
    getline(cin,Deliv[Restaurantorder].LunchPlate); 
    cout<<"entradas"<<endl;    
    getline(cin,Deliv[Restaurantorder].Entry); 
    

}


