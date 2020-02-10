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

struct HomeRegister{
        Entry entry;
        Food  food;
        drinks drinkin;Addres HomeAdd;               
        string CustomeName;
        long int Homephone;
        int Var1=0,comida1=0,comida2=0,comida3=0;
        float platofuerte=0,bebidas=0,entrada=0,tiempo=0,v2=15,tiempo2=0,tiempo3=0;

}; typedef  HomeRegister Home;

struct RestaurantRegister{
        Entry EntryRestaurant;
        Food FoodRestaurant;
        drinks DrinskRestaurant;
        string PeopleName;
        int people=0,NumberOrder=0,Var2=0,entryR=0,plateR=0,drinkR=0,comida1R=0,comida2R=0,comida3R=0;
        int tiempo1R=0,Tiempo2R=0,Tiempo3R=0;
 
};typedef RestaurantRegister Restaurant;

//inicializando Las listas enlazadas
vector <Home> list;
vector <Restaurant> list2;

//variables globales
float fe=0,Norden=0,Norden1=0;
float b1=0,c1=0,d1=0,g1=0,h1=0,h2=0;


//Prototipos de funciones
void PrintMenu(),EmployeMenu(), CancelOrderWorker(),CancelOrderAdmin();
void auxery(), RestaurantDelivery(),MenuAdmin();
void HomeOrders(),RestaurantOrders();
void auxeryOrders();
void AgregarHome();
void OutHomeOrders();
bool comprobar(char r);
float TimeOrders(float a,float b, float c,int V2);
float TimeOrders(float a,float b,float c);
float TotalyTimeOrders1(float x),TotalyTimeOrders2(float x);

//Funcion Principal solo contiene otra funcion para optimizacion del main
int main(){
    PrintMenu();
    return 0;
}

//Imprime el menu principal
void PrintMenu(){
    Home HomeData;
    Restaurant restaurant;
    int opt2=0;
    bool OUT = true;
    do{
        cout<<"Menu VERSION EMPLEADO                                   "<<endl;
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
        cout<<"12. Salir                                             \n"<<endl; 
        cin>>opt2;

        switch (opt2){
        
        case 1: AgregarHome();break;
        case 2: RestaurantDelivery();break;
        case 3: HomeOrders();break;
        case 4: cin.ignore();RestaurantOrders();break;
        case 5: OutHomeOrders();break;
        case 6: //AdminMenu(); break;
        case 7: TotalyTimeOrders1(HomeData.tiempo2); break;
        case 8: TotalyTimeOrders2(restaurant.Tiempo2R); break;
        case 9: CancelOrderWorker(); break;
        case 10: break;
        case 11: MenuAdmin(); break;
        case 12: OUT=false;break;
        default:cout<<"Seleccion una  Opcion Valida" <<endl;break;
    }
    }while(OUT);
}


//esta funcion pide los datos para una Orden  a Domicilio.
void AgregarHome(){
    //Home     HomeData;
    Home HomeData;
    bool keep = true;
    bool continuar=true;
    int opt=0,opt1=0,opt2=0,opt3=0,v1=0;
    char f;
    Norden++;
    cin.ignore();
    srand(time(0));
    HomeData.Var1 = 1 + rand() % (50000 - 1000);  

    cout<<"Porfavor Ingrese el nombre del cliente: ";                getline(cin,HomeData.CustomeName);    
    cout<<"Porfavor Ingrese la direccion del cliente"<<endl;  
    cout<<"Numero de casa "<<endl;                                   cin>>(cin ,  HomeData.HomeAdd.HouseNumber);
    cin.ignore();  
    cout<<"Nombre de colonia "<<endl;                                getline(cin  ,  HomeData.HomeAdd.Suburb);  
    cout<<"Nombre  de Municipalidad "<<endl;                         getline(cin   ,  HomeData.HomeAdd.Municipality);
    cout<<"Departamento Nacional  "<<endl;                           getline(cin   , HomeData.HomeAdd.StateDepartament);    
    cout<<"Porfavor Ingrese el telefono de casa del cliente"<<endl;  cin>>(cin     , HomeData.Homephone); 
    cin.ignore(); 
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
                cout<<"1)Orden de pan con ajo............$3.99 "<<endl;
                cout<<"2)Orden de pizza rolls............$4.99 "<<endl;
                cout<<"3)Orden de palitos de queso.......$3.75 "<<endl;
                cin>>opt1;  

                switch (opt1){
               // case 0: cout<<"seleccione otra opcion"<<endl;break;    
                case 1 : cout<<"Breadgarlic $3.50"<<endl;
                         HomeData.entry = BreadGarlic ; //= cout<<"Breadgarlic";  
                         HomeData.entrada ++;
                         HomeData.comida1 ++;
                          break;
                case 2: cout<<"Pizzarrols $3.50"<<endl;
                        HomeData.entry = Pizzarolls; //=cout<<"picza"; 
                        HomeData.entrada ++;
                        HomeData.comida2 ++;
                         break;
                case 3: cout<<"Cheesesticks $3.50"<<endl;                
                        HomeData.entry = Cheesesticks; //= cout<<"cheese";
                        HomeData.entrada ++; 
                        HomeData.comida3 ++;   
                        break;       
                }  
            break;
        case 2: cout<<"Nombre                 Precio"<<endl;
                cout<<"1)Pizza................$13.99 "<<endl;
                cout<<"2)Pasta................$5.55  "<<endl;
                cout<<"3)Lasgna...............$6.25  "<<endl;   
                cout<<"Porfavor Ingrese La seleccion del plato del cliente"<<endl;
                cin>>opt2;
                switch (opt2){

                case 1: cout<<"pizza           "<<endl;
                        HomeData.food = Pizza;
                        HomeData.platofuerte++;  
                        break;
                case 2: cout<<"Pasta           "<<endl;
                        HomeData.food = Paste; 
                        HomeData.platofuerte++;
                         break;    
                case 3: cout<<"Lasgna          "<<endl;                
                        HomeData.food = Lasagna;  
                        HomeData.platofuerte++;
                        break;       
                }     
                break;                
        case 3: cout<<"porfavor escoja una bebida"<<endl;  
                cout<<"Nombre               Precio"<<endl;
                cout<<"1)Cerveza..............$1.99  "<<endl;
                cout<<"2)Soda.................$0.95  "<<endl;
                cout<<"3)Té helado............$1.15  "<<endl;
                cout<<"Porfavor Ingrese La seleccion de bebida del cliente"<<endl;
                cin>>opt3;
                switch (opt3){
                case 1: cout<<"Cerveza         "<<endl;
                        HomeData.drinkin = Beer; 
                        HomeData.bebidas++; 
                        break;
                case 2: cout<<"Soda            "<<endl;
                        HomeData.drinkin = Soda;  
                        HomeData.bebidas++; 
                        break;    
                case 3: cout<<"Te helado       "<<endl;                
                        HomeData.drinkin = Icetea;  
                        HomeData.bebidas++; 
                        break;       
                }     
        break;
        case 4: keep=false; break;
    }
        }while(keep);
                HomeData.tiempo  = TimeOrders(HomeData.entrada,HomeData.platofuerte,HomeData.bebidas,HomeData.v2);
                HomeData.tiempo2 = TotalyTimeOrders1(HomeData.tiempo);
                cout<<"No. de orden:  "            <<endl;      cout<< HomeData.Var1<<endl;       
                list.insert(list.end(),HomeData);
                cout<<"Tiempo estimado de espera de la Orden: "<<HomeData.tiempo<<" : minutos"<<endl;
                cout<<"tiempo aproximado de espera  "<<HomeData.tiempo2<<"minutos"<<endl;
                cout <<"Pedido ingresado exitosamente!\n";
                cin.ignore();
    
}


//Esta funcion pide los datos para una orden de restaurante
void RestaurantDelivery(){ 
    Restaurant restaurant;
    cin.ignore();
    srand(time(0));
    restaurant.Var2 = 1 + rand() % (50000 - 1000);  
    bool keep = true,continuar=true;
    int opt=0,opt1=0,opt2=0,opt3=0,v1=0;

    Norden1++;

    cout<<"Porfavor Ingrese el nombre del cliente: ";                getline(cin,restaurant.PeopleName);    
    cout<<"Numero de personas en la mesa :           "               <<endl;  cin>>restaurant.people;

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
                cout<<"1)Orden de pan con ajo............$3.99 "<<endl;
                cout<<"2)Orden de pizza rolls............$4.99 "<<endl;
                cout<<"3)Orden de palitos de queso.......$3.75 "<<endl;
                cin>>opt1;  

                switch (opt1){
                case 1 : cout<<"Breadgarlic $3.50"<<endl;
                         restaurant.EntryRestaurant = BreadGarlic ; 
                         restaurant.entryR ++;   
                         restaurant.comida1R ++;
                        break;
                case 2: cout<<"Pizzarrols $3.50"<<endl;
                        restaurant.EntryRestaurant = Pizzarolls; 
                        restaurant.entryR ++;
                        restaurant.comida2R ++;
                         break;
                case 3: cout<<"Cheesesticks $3.50"<<endl;                
                        restaurant.EntryRestaurant = Cheesesticks; 
                        restaurant.entryR ++; 
                        restaurant.comida3R ++;   
                        break;       
                }  
            break;
        case 2: cout<<"Nombre                 Precio"<<endl;
                cout<<"1)Pizza................$13.99 "<<endl;
                cout<<"2)Pasta................$5.55  "<<endl;
                cout<<"3)Lasgna...............$6.25  "<<endl;   
                cout<<"Porfavor Ingrese La seleccion del plato del cliente"<<endl;
                cin>>opt2;
                switch (opt2){

                case 1: cout<<"pizza       $13.99  "<<endl;
                        restaurant.FoodRestaurant = Pizza;
                        restaurant.plateR++;  
                        break;
                case 2: cout<<"Pasta         5.55 "<<endl;
                        restaurant.FoodRestaurant = Paste;
                        restaurant.plateR++;  
                        break;    
                case 3: cout<<"Lasgna       6.25  "<<endl;                
                        restaurant.FoodRestaurant = Lasagna;
                        restaurant.plateR++;  
                        break;       
                }     
                break;                
        case 3: cout<<"porfavor escoja una bebida"<<endl;  
                cout<<"Nombre               Precio"<<endl;
                cout<<"1)Cerveza..............$1.99  "<<endl;
                cout<<"2)Soda.................$0.95  "<<endl;
                cout<<"3)Té helado............$1.15  "<<endl;
                cout<<"Porfavor Ingrese La seleccion de bebida del cliente"<<endl;
                cin>>opt3;
                switch (opt3){
                case 1: cout<<"Cerveza     $1.99"<<endl;
                        restaurant.DrinskRestaurant = Beer; 
                        restaurant.drinkR++; 
                        break;
                case 2: cout<<"Soda        $0.95"<<endl;
                        restaurant.DrinskRestaurant = Soda; 
                        restaurant.drinkR++; 
                        break;    
                case 3: cout<<"Te helado    $1.15"<<endl;                
                        restaurant.DrinskRestaurant = Icetea; 
                        restaurant.drinkR++; 
                        break;       
                }     
        break;
        case 4: keep=false; break;
    }
        }while(keep);
                restaurant.tiempo1R = TimeOrders(restaurant.entryR,restaurant.plateR,restaurant.drinkR);
                restaurant.Tiempo2R = TotalyTimeOrders2(restaurant.tiempo1R);
                cout<<"No. de orden:  "            <<endl;      cout<< restaurant.Var2<<endl;       
                list2.insert(list2.end(),restaurant);
                cout<<"Tiempo estimado de espera de la Orden: "<<restaurant.tiempo1R<<" : minutos"<<endl;
                cout<<"Tiempo aproximado de espera   "<<restaurant.Tiempo2R<<" Minutos"<<endl;
                cout <<"Pedido ingresado exitosamente!\n";
                cin.ignore();
    
}

//Recorre y Muestra todos los pedidos a Domicilio
void HomeOrders(){
    Home Element;
        cout << "\nPedidos a domicilio: "<<Norden<<"\n";    
        for( auto iter = list.begin(); iter != list.end(); ++iter){
        cout <<"Nombre del cliente :                    "<< iter->CustomeName  <<"           "<<endl;
        cout <<"Numero de casa :                        "<<iter->HomeAdd.HouseNumber << "  "<<endl;
        cout <<"Colonia        :                        "<<iter->HomeAdd.Suburb          << "  "<<endl;
        cout <<"Municipios     :                        "<<iter->HomeAdd.Municipality    << "  "<<endl;
        cout <<"Departamento   :                        "<<iter->HomeAdd.StateDepartament<< "  "<<endl;
        cout <<"Numero de Entradas Ordenadas :          "<<iter->entrada<< "  "<<endl;
        cout <<"Numero de Plato fuertes Ordenados :     "<<iter->platofuerte<< "  "<<endl;
        cout <<"Numero de bebbidas Ordenadas :          "<<iter->bebidas<< "  "<<endl;
        cout<<"Tiempo de espera de la orden :           "<<iter->tiempo<<" Minutos "<<endl;
        cout <<"No. de Orden    :  "<<iter->Var1                    << "  \n"<<endl;
    }  
}


void RestaurantOrders(){    
 Restaurant Elment1;
        cout << "\nPedidos actuales en Restaurante: "<<Norden1<<"\n";    
        for( auto iter = list2.begin(); iter != list2.end(); ++iter){
        cout <<"Nombre del cliente :                    "<<iter->PeopleName <<"           "<<endl;
        cout <<"Numero de personas en la mesa :         "<<iter->people << "  "<<endl;
        cout <<"Numero de Entradas Ordenadas :          "<<iter->entryR<< "  "<<endl;
        cout <<"Numero de Plato fuertes Ordenados :     "<<iter->plateR<< "  "<<endl;
        cout <<"Numero de bebbidas Ordenadas :          "<<iter->drinkR<< "  "<<endl;
        cout<<"Tiempo de espera de la orden :           "<<iter->tiempo1R<<" Minutos "<<endl;
        cout <<"No. de Orden    :  "<<iter->Var2                    << "  \n"<<endl;
    }  
}

void OutHomeOrders(){      

    Home OutHome = list.front();
    for (int i=0; i <=list.size(); i++){
    cout << "Cliente:  " <<OutHome.CustomeName<< " su pedido esta listo\n";
}
}

float TimeOrders(float a,float b,float c,int V2){
    float x=0,y=0,z=0,suma=0,suma1=0,suma2=0;
    x=a*1.10;
    y=b*1.5;
    z=c*1.35;
    suma=((x+y+z)+V2);
    suma1=ceil(suma);                                                   
return suma1;
}

float TimeOrders(float a,float b,float c){
    float x=0,y=0,z=0,suma=0,suma1=0,suma2=0;
    x=a*1.10;
    y=b*1.5;
    z=c*1.35;
    suma=(x+y+z);
    suma1=ceil(suma);                                                   

return suma1;
}

float TotalyTimeOrders1(float  x){
    cout<<"Tiempo de espera promedio a domicilio pizzeria "<<endl;
    cout<<"No. de ordenes:   "<<Norden<<endl;
    cout<<"tiempo de espera:  "<<c1<<" minutos"<<endl;
    g1+=x;
    c1=g1/Norden;
    return c1;
}

float TotalyTimeOrders2(float x){
    cout<<"Tiempo de espera promedio en Restaurante pizzeria "<<endl;
    cout<<"No. de ordenes:   "<<Norden1<<endl;
    cout<<"tiempo de espera:  "<<h2<<" minutos"<<endl;
    h1+=x;
    h2=h1/Norden1;
    return h2; 
 }

void auxeryOrders(){

}


void CancelOrderWorker(){
int opt3;
bool OUT = true;
 string name;
    char password2[12];
    char user2[12];
    char password[12]={"ide"};
    char Adminuser[12]={"william21"};

    cout<<"ingrese su usuario De Administrado por Favor: "<<endl;cin>>user2;
    cout<<"ingrese su contrasena porfavor: "<<endl;cin>>password2;
    if((strcmp(password2,password)==0) && (strcmp(user2,Adminuser)==0)){
    cin.ignore();
    cout << "Nombre de la orden que quiere buscar para eliminar : ";
    getline(cin, name);
    for(auto iter = list.begin(); iter != list.end(); ++iter){
        if(iter->CustomeName == name){
            iter = list.erase(iter);
            cout << "Articulo eliminado exitosamente.\n";
            break;
        }
    }
    }
}


void MenuAdmin(){
    Home HomeData;
    Restaurant restaurant;
    int opt2=0;
    bool OUT = true;
    char password2[12];
    char user2[12];
    char password[12]={"ide"};
    char Adminuser[12]={"william21"};

    cout<<"ingrese su usuario De Administrado por Favor: "<<endl;cin>>user2;
    cout<<"ingrese su contrasena porfavor: "<<endl;cin>>password2;
    if((strcmp(password2,password)==0) && (strcmp(user2,Adminuser)==0)){
    cin.ignore();    
    do{
        cout<<"Menu VERSION ADMINISTRADOR                              "<<endl;
        cout<<"1.  Agregar orden a domicilio                           "<<endl;  
        cout<<"2.  Agregar orden en restaurante                        "<<endl;  
        cout<<"3.  Ver ordenes a domicilio                             "<<endl;  
        cout<<"4.  Ver ordenes en restaurante                          "<<endl;  
        cout<<"5.  Despachar ordenes a domicilio                       "<<endl;  
        cout<<"6.  Despachar ordenes a restaurante                     "<<endl; 
        cout<<"7.  Ver tiempo promedio de espera domicilio             "<<endl;  
        cout<<"8.  Ver tiempo promedio de espera restaurante           "<<endl;     
        cout<<"9.  Cancelar orden                                      "<<endl; 
        cout<<"10. Calcular total de ventas                            "<<endl;  
        cout<<"11. Cambiar de usuario(Regresar a Modo usuario)         "<<endl;  
        cout<<"12. Salir                                             \n"<<endl; 
        cin>>opt2;

        switch (opt2){
        
        case 1: AgregarHome();break;
        case 2: RestaurantDelivery();break;
        case 3: HomeOrders();break;
        case 4: RestaurantOrders();break;
        case 5: OutHomeOrders();break;
        case 6: //AdminMenu(); break;
        case 7: TotalyTimeOrders1(HomeData.tiempo2); break;
        case 8: TotalyTimeOrders1(restaurant.Tiempo2R);break;
        case 9: CancelOrderAdmin(); break;
        case 10:  break;
        case 11: PrintMenu(); break;
        case 12: OUT=false;break;
        default:cout<<"Seleccion una  Opcion Valida" <<endl;break;
    }
    }while(OUT);
}
}

void CancelOrderAdmin(){
int opt3;
char s;
bool OUT = true;
 string name;

    cout<<"Desea Borrar una orden (s/n) o Regresar al menu ?"<<endl;
    cin>>s;
   
    if (s == 's'||'S'){
    cout << "Nombre de la orden que quiere buscar para eliminar : ";
    getline(cin, name);
    cin.ignore();
    for(auto iter = list.begin(); iter != list.end(); ++iter){
        if(iter->CustomeName == name){
            iter = list.erase(iter);
            cout << "Articulo eliminado exitosamente.\n";
            break;
        }
    }
    }else{
    cout<<"Regresando al menu"<<endl;
    MenuAdmin();
}
}

bool comprobar(char r){
     int n=int(r);
     if (n>=48 and n<=57) {
        cout << "la tecla pulsada es un numero." << endl;
        cout << "Vuelve a ingresar el dato : ";
        cin >>r;
        comprobar(r);
     }
     else {
        cout << "Verificado" << endl;
        MenuAdmin();
     }
}


