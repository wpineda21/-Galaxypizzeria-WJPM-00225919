#include <iostream>  // libreria de entrada  y salida  de datos     
#include <string.h>  // libreria que permite el manejoy manipulacion  de cadenas 
#include <time.h>    // libreria para el uso de numeros aleatorios
#include <vector>    // Incluyendo Libreria para manejo de listas;  
#include <algorithm> // Libreria de Manejo de listas   
#include <math.h>    // libreria que permite el uso de ceiling
using namespace std;


//Declaracion de Enums
 enum Entry  {trash1,BreadGarlic,Pizzarolls,Cheesesticks};
 enum Food   {trash2,Pizza,Paste,Lasagna};
 enum drinks {trash3,Beer,Soda,Icetea};

//declaracion de Estructuras de Registros
struct  SpecificationAddres {
        string Suburb,Municipality,StateDepartament;
        long int HouseNumber; 
    };typedef SpecificationAddres Addres;

struct homedeliv{
        Entry entry;
        Food  food;
        drinks drinkin;
        Addres HomeAdd;               
        string CustomeName;
        int Var1=0;
        long int Homephone;
        //float Amount,PaymentType;
        int comida=0;  
}; vector <homedeliv> Home;

struct restaurantdeliv{
       /// Enums MainFood2;
        string PeopleName;
        int people,NumberOrder,Var2;
        // float Amount,PaymentType;  
    };vector <restaurantdeliv> Restaurant;




//Prototipos de funciones
void PrintMenu(),EmployeMenu(), CancelOrder();
void HomeDelivery(), RestaurantDelivery();
void HomeOrders(),RestaurantOrders();
void ModifyHomeDeliveryOrders();
void OutHomeOrders();
//Funcion Principal solo contiene otra funcion para optimizacion del main
int main(){
    PrintMenu();
    return 0;
}

//Imprime el menu principal
void PrintMenu(){
    int opt2;
    bool OUT = true;
    do{

        cout<<"1.  Agregar orden a domicilio                           "<<endl;  
        cout<<"2.  Agregar orden en restaurante                        "<<endl;  
        cout<<"3.  Ver ordenes a domicilio                             "<<endl;  
        cout<<"4.  Ver ordenes en restaurante                          "<<endl;  
        cout<<"5.  Despachar ordenes a domicilio                       "<<endl;  
        cout<<"6.  Despachar ordenes a restaurante                     "<<endl; 
        cout<<"7.  Ver tiempo promedio de espera domicilio             "<<endl;  
        cout<<"8.  Ver tiempo promedio de espera restaurante           "<<endl;     
        cout<<"9.  Cancelar orden (domicilio o restaurante, solo admin)"<<endl; 
        cout<<"10. Calcular total de ventas                            "<<endl;  
        cout<<"11. Cambiar de usuario                                  "<<endl;  
        cout<<"12. Salir                                               "<<endl; 
        cin>>opt2;

    switch (opt2){
        case 1: HomeDelivery();break;
        case 2: RestaurantDelivery();break;
        case 3: HomeOrders();break;
        case 4: //RestaurantOrders();break;
        case 5: OutHomeOrders();break;
        case 6: //AdminMenu(); break;
        case 7: //AdminMenu(); break;
        case 8: //AdminMenu(); break;
        case 9: //AdminMenu(); break;
        case 10: CancelOrder(); break;
        case 11: //AdminMenu(); break;
        case 12: OUT=false;break;
        default:cout<<"Seleccion una  Opcion Valida" <<endl;break;
    }
    }while(OUT);
}


//esta funcion pide los datos para una Orden  a Domicilio.
void HomeDelivery(){
    homedeliv HomeDeliv;
    bool keep = true;
    bool continuar=true;
    int opt=0,opt1,opt2=0,opt3=0;
    char f;

    cin.ignore();
    srand(time(0));
    HomeDeliv.Var1 = 1 + rand() % (50000 - 1000);  
    

    cout<<"Porfavor Ingrese el nombre del cliente: ";                getline(cin,HomeDeliv.CustomeName);    
//    cout<<"Porfavor Ingrese la direccion del cliente"<<endl;  
//    cout<<"Numero de casa "<<endl;                                   cin>>(cin,HomeDeliv.HomeAdd.HouseNumber);
//    cin.ignore();  
//    cout<<"Nombre de colonia "<<endl;                                getline(cin,HomeDeliv.HomeAdd.Suburb);  
//    cout<<"Nombre  de Municipalidad "<<endl;                         getline(cin,HomeDeliv.HomeAdd.Municipality);
//    cout<<"Departamento Nacional  "<<endl;                           getline(cin,HomeDeliv.HomeAdd.StateDepartament);    
//    cout<<"Porfavor Ingrese el telefono de casa del cliente"<<endl;  cin>>(cin,HomeDeliv.Homephone); 
//    cin.ignore(); 
    cout<<""<<endl;
    
    do{
    cout<<"*********Menu de Comida*********"<<endl;
    cout<<"1)Ver Entradas.................."<<endl;
    cout<<"2)Ver Platos Fuertes............"<<endl;
    cout<<"3)Ver Bebidas..................."<<endl;
    cout<<"4)Regresar Menu Principal.......\n"<<endl;
    cin>>opt;
    switch (opt){

        case 1: 
                cout<<"Entradas:                       "<<endl;
                cout<<"Nombre                          Precio"<<endl;
                cout<<"a)Orden de pan con ajo............$3.99 "<<endl;
                cout<<"b)Orden de pizza rolls............$4.99 "<<endl;
                cout<<"c)Orden de palitos de queso.......$3.75 "<<endl;
                cin>>opt1;

                switch (opt1){
                case 1 : cout<<"Breadgarlic $3.50"<<endl;
                         HomeDeliv.entry = BreadGarlic;  
                         HomeDeliv.comida ++;  
                            break;

                case 2: cout<<"Pizzarrols $3.50"<<endl;
                        HomeDeliv.entry = Pizzarolls; 
                        HomeDeliv.comida++;
                         break;    
                case 3: cout<<"Cheesesticks $3.50"<<endl;                
                        HomeDeliv.entry = Cheesesticks;  
                        HomeDeliv.comida ++;
                        break;       
                }   

            break;
        case 2: cout<<"Nombre               Precio"<<endl;
                cout<<"0)Pizza................$13.99 "<<endl;
                cout<<"1)Pasta................$5.55  "<<endl;
                cout<<"2)Lasgna...............$6.25  "<<endl;   
                cout<<"3)Porfavor Ingrese La seleccion del plato del cliente"<<endl;
                cin>>opt2;
                switch (opt2){

                case 0: cout<<"pizza           "<<endl;
                        HomeDeliv.food = Pizza;  
                        break;
                case 1: cout<<"Pasta           "<<endl;
                        HomeDeliv.food = Paste;  break;    
                case 2: cout<<"Lasgna          "<<endl;                
                        HomeDeliv.food = Lasagna;  
                        break;       
                }     

        case 3: cout<<"porfavor escoja una bebida"<<endl;  
                cout<<"Nombre               Precio"<<endl;
                cout<<"0)Cerveza..............$1.99  "<<endl;
                cout<<"1)Soda.................$0.95  "<<endl;
                cout<<"2)Té helado............$1.15  "<<endl;
                cout<<"Porfavor Ingrese La seleccion de bebida del cliente"<<endl;break;
                cin>>opt3;
                switch (opt3){

                case 0: cout<<"Cerveza         "<<endl;
                        HomeDeliv.drinkin = Beer;  
                        break;
                case 1: cout<<"Soda            "<<endl;
                        HomeDeliv.drinkin = Soda;  break;    
                case 2: cout<<"Te helado       "<<endl;                
                        HomeDeliv.drinkin = Icetea;  
                        break;       
                }     

        case 4: keep=false; break;
    }
        }while(keep);
                cout<<"No. de orden:  "            <<endl;      cout<<HomeDeliv.Var1<<endl;       
                cout<<"su total a pagar es "       <<endl;
                Home.insert(Home.end(), HomeDeliv);
                cout <<"Pedido ingresado exitosamente!\n";
                cin.ignore();
}


//Esta funcion pide los datos para una orden de restaurante
void RestaurantDelivery(){
    
    restaurantdeliv RESTAURANT;
    cin.ignore();
    srand(time(0));
    RESTAURANT.Var2 = 1 + rand() % (50000 - 1000);  
    cout<<"Porfavor Ingrese el nombre del cliente: ";                getline(cin,RESTAURANT.PeopleName);    
    cout<<"Porfavor Ingrese el No. de personas para la mesa: "<<endl;cin>>(cin,RESTAURANT.people); 
    cout<<""<<endl;
    cout<<"seleccione una opcion a su gusto"<<endl;
    cout<<" tenemos ricas entradas "<<endl;
    cout<<"Nombre                          Precio"<<endl;
    cout<<"Orden de pan con ajo............$3.99 "<<endl;
    cout<<"Orden de pizza rolls............$4.99 "<<endl;
    cout<<"Orden de palitos de queso.......$3.75 "<<endl;
    cout<<"Porfavor Ingrese La seleccion de entrada del cliente"<<endl;
    cout<<"Nombre               Precio"<<endl;
    cout<<"Pizza................$13.99 "<<endl;
    cout<<"Pasta................$5.55  "<<endl;
    cout<<"Lasgna...............$6.25  "<<endl;
    cout<<"Porfavor Ingrese La seleccion del plato del cliente"<<endl;   
    cout<<"porfavor escoja una bebida"<<endl;  
    cout<<"Nombre               Precio"<<endl;
    cout<<"Cerveza..............$1.99  "<<endl;
    cout<<"Soda.................$0.95  "<<endl;
    cout<<"Té helado............$1.15  "<<endl;
    cout<<"Porfavor Ingrese La seleccion de bebida del cliente"<<endl;
    cout<<"No. de orden:  "            <<endl;                        cout<<RESTAURANT.Var2<<endl;       
    cout<<"su total a pagar es "       <<endl;
    Restaurant.insert(Restaurant.end(),RESTAURANT);
    cout << "Pedido ingresado exitosamente!\n";
    cin.ignore();
}

//Recorre y Muestra todos los pedidos a Domicilio
void HomeOrders(){

    cout << "\nPedidos a domicilio: ";    
    for (int i = 0; i <= Home.size(); i++){
        cout <<"Nombre del cliente : "<<Home[i].CustomeName             << "  "<<endl;
    //  cout <<"Numero de casa :     "<<Home[i].HomeAdd.HouseNumber     << "  "<<endl;
    //  cout <<"Colonia        :     "<<Home[i].HomeAdd.Suburb          << "  "<<endl;
    //  cout <<"Municipios     :     "<<Home[i].HomeAdd.Municipality    << "  "<<endl;
    //  cout <<"Departamento   :     "<<Home[i].HomeAdd.StateDepartament<< "  "<<endl;
        cout <<"Entradas Ordenadas:  "<<Home[i].comida                   << "  "<<endl;
        cout <<"Entradas Ordenadas: "<<endl;
        switch (Home[i+1].entry) {
        case BreadGarlic: cout<<"Bread garlic 3.50$"<<endl;break;
        case Pizzarolls: cout<<"pizzarolls 3.50$"<<endl;break;
        case Cheesesticks: cout<<"cheeseticks 3.50$"<<endl;break;
        }
    
    //cout <<"Pizzas Ordenadas:    "<<Home[i].LunchPlate               << "  "<<endl;
    //cout <<"Bebidas Ordenads:    "<<Home[i].Drinks                   << "  "<<endl;

        cout <<"No. de Orden    :    "<<Home[i].Var1                    << "  \n"<<endl;
    }   
}

void RestaurantOrders(){
    
   /* cout << "\nPedidos en Restaurante : ";    
    for (int i = 0; i < Restaurant.size(); i++){
        cout <<"Nombre del cliente :         "<<Restaurant[i].PeopleName  << "  "<<endl;
        cout <<"Numero de Personas en mesa : "<<Restaurant[i].people      << "  "<<endl;
        cout <<"Entradas Ordenadas:          "<<Restaurant[i].Entry2      << "  "<<endl;
        cout <<"Pizzas Ordenadas:            "<<Restaurant[i].MainPlate   << "  "<<endl;
        cout <<"Bebidas Ordenads:            "<<Restaurant[i].Drinks2     << "  "<<endl;
        cout <<"No. de Orden    :            "<<Restaurant[i].Var2        << "  \n"<<endl;
    }*/   

}

void OutHomeOrders(){
homedeliv outorder = Home.front();

   for (int i=0; i <= Home.size(); i++){
    cout << "Cliente:  " << Home[i].CustomeName<< " su pedido esta listo\n";

}
}


void ModifyHomeDeliveryOrders(){
/*    string CLientName;
    cin.ignore();
    cout << "Ingrese el nombre del client a buscar : ";
    getline(cin, CLientName);


    for(int i = 0; i < tamano; i++){
    if (CLientName.compare(h1.CustomeName)==0){

        cout<<"Nombre del cliente  "<<h1.CustomeName<<endl;
        cout<<"Numero de casa "<<h2.HomeAdd.HouseNumber<<endl;  
        cout<<"Nombre de  colonia "<<h2.HomeAdd.Suburb<<endl;  
        cout<<"Nombre de Municipalidad "<<h2.HomeAdd.Municipality<<endl;
        cout<<"Departamento Nacional  "<<h2.HomeAdd.StateDepartament<<endl; 
        cout<<"telefono de casa del cliente  "<<h3.Homephone<<endl; 
        cout<<"seleccion del plato del cliente "<<h4.LunchPlate<<endl;   
        cout<<"seleccion de entrada del cliente  "<<h5.Entry<<endl; 
        cout<<"De bebida del cliente   "<<h6.Drinks<<endl;

    }else{
        cout<<"Ingrese el nombre nuevamente"<<endl;
    }
}*/
}




void CancelOrder(){
int opt3;
bool OUT = true;
    char password2[12];
    char user2[12];
    char password[12]={"ide"};
    char Adminuser[12]={"william21"};

    cout<<"ingrese su usuario De Administrado por Favor: "<<endl;cin>>user2;
    cout<<"ingrese su contrasena porfavor: "<<endl;cin>>password2;
    if((strcmp(password2,password)==0) && (strcmp(user2,Adminuser)==0)){
    do{
        cout<<"que orden desea borrar: "<<endl;

}while(OUT);
    }
}
float TotalyTimeOrders(float  x){
int b1=0,c1=0,d1=0;
b1=x+x;
c1=Norden;
d1=(b1);

return d1;
}