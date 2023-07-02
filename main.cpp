#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const char *ARCHIVO_MUSICOS="musicos.dat";
const char *ARCHIVO_GENEROS="generos.dat";
const char *ARCHIVO_INSTRUMENTO="instrumentos.dat";
const char *ARCHIVO_PAISES="paises.dat";

#include "fecha.h"
#include "clase.instrumento.h"
#include "ArchivoInstrumento.h"
#include "clase.paises.h"
#include "ArchivoPaises.h"
#include "clase.generos.h"
#include "ArchivoGenero.h"
#include "clase.musico.h"
#include "ArchivoMusicos.h"
#include "REPORTES.h"
#include "configuracion.h"



int main(){
    ArchivoMusicos obj(ARCHIVO_MUSICOS);
    ArchivoGenero reg(ARCHIVO_GENEROS);
    ArchivoInstrumento cos(ARCHIVO_INSTRUMENTO);
    ArchivoPaises pai(ARCHIVO_PAISES);

    int opc;
    bool quit=false;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1 - MENU MUSICOS"<<endl;
        cout<<"2 - MENU GENEROS"<<endl;
        cout<<"3 - MENU INSTRUMENTOS"<<endl;
        cout<<"4 - MENU PAISES"<<endl;
        cout<<"5 - REPORTES"<<endl;
        cout<<"6 - CONFIGURACION"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"0 - FIN DEL PROGRAMA"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                while(!quit){
                    system("cls");
                    cout<<"MENU MUSICOS"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"1 - AGREGAR MUSICOS"<<endl;
                    cout<<"2 - LISTAR MUSICO POR DNI"<<endl;
                    cout<<"3 - LISTAR TODOS LOS MUSICOS"<<endl;
                    cout<<"4 - MODIFICAR FECHA DE INSCRIPCION"<<endl;
                    cout<<"5 - ELIMINAR REGISTRO DE MUSICO"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
                    cout<<"INGRESE UNA OPCION: ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1: obj.agregarMusico();
                                system("pause");
                                break;
                        case 2: obj.buscarporDNI();
                                system("pause");
                                break;
                        case 3: obj.mostrarMusicos();
                                system("pause");
                                break;
                        case 4:if(obj.modificarFecha()){
                                    cout<<"MUSICO MODIFICADO CORRECTAMENTE"<<endl;
                                }else{
                                    cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
                                }
                                system("pause");
                                break;
                        case 5:if(obj.bajaLogica()){
                                    cout<<"MUSICO DADO DE BAJA CORRECTAMENTE"<<endl;
                                }else{
                                    cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
                                }
                                system("pause");
                                break;

                        case 0: quit=true;
                            break;
                        default:cout<<"OPCION INCORRECTA"<<endl;
                                break;
                                }
                      }
                      quit=false;
                        break;
            case 2:
                while(!quit){
                        system("cls");
                    cout<<"MENU GENEROS"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"1 - AGREGAR GENERO"<<endl;
                    cout<<"2 - LISTAR GENERO POR ID"<<endl;
                    cout<<"3 - LISTAR TODO"<<endl;
                    cout<<"4 - MODIFICAR ANIO DE ORIGEN"<<endl;
                    cout<<"5 - ELIMINAR REGISTRO"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
                    cout<<"INGRESE UNA OPCION: ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1:
                            reg.agregarGenero();
                            system("pause");
                                break;
                        case 2:
                            reg.buscarPorID();
                            system("pause");
                                break;
                        case 3:
                            reg.mostrarGenero();
                                system("pause");
                                break;
                        case 4:if(reg.modificarFecha()){
                                    cout<<"ANIO DE ORIGEN MODIFICADO CORRECTAMENTE"<<endl;
                                }else{
                                    cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
                                }
                                system("pause");
                                break;
                        case 5:if(reg.bajaLogica()){
                                    cout<<"REGISTRO ELIMINADO"<<endl;
                                }else{
                                    cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
                                }
                                system("pause");
                                break;
                        case 0: quit=true;
                                break;
                        default:cout<<"OPCION INCORRECTA"<<endl;
                                break;
                                }
                    }
                    quit=false;
                        break;

             case 3:
                 while(!quit){
                        system("cls");
                    cout<<"MENU INSTRUMENTOS"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"1 - AGREGAR INSTRUMENTO"<<endl;
                    cout<<"2 - LISTAR INSTRUMENTO POR ID"<<endl;
                    cout<<"3 - LISTAR TODO"<<endl;
                    cout<<"4 - MODIFICAR NOMBRE"<<endl;
                    cout<<"5 - ELIMINAR REGISTRO"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
                    cout<<"INGRESE UNA OPCION: ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1:cos.agregarInstrumento();
                                system("pause");
                                break;
                        case 2:cos.buscarPorID();
                                system("pause");
                                break;
                        case 3:cos.mostrarInstrumento();
                                system("pause");
                                break;
                        case 4:if(cos.modificarNombre()){
                                    cout<<"NOMBRE MODIFICADO CORRECTAMENTE"<<endl;
                                }else{
                                    cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
                                }
                                system("pause");
                                break;
                        case 5:if(cos.bajaLogica()){
                                    cout<<"INSTRUMENTO DADO DE BAJA CORRECTAMENTE"<<endl;
                                }else{
                                    cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
                                }
                                break;
                        case 0: quit=true;
                                break;
                        default:cout<<"OPCION INCORRECTA"<<endl;
                                break;
                                }
                    }
                    quit=false;
                        break;
            case 4:
                 while(!quit){
                        system("cls");
                    cout<<"MENU PAISES"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"1 - AGREGAR PAIS"<<endl;
                    cout<<"2 - LISTAR PAIS POR ID"<<endl;
                    cout<<"3 - LISTAR TODO"<<endl;
                    cout<<"4 - MODIFICAR NOMBRE"<<endl;
                    cout<<"5 - ELIMINAR REGISTRO"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
                    cout<<"INGRESE UNA OPCION: ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1:pai.agregarPais();
                                system("pause");
                                break;
                        case 2:pai.buscarPorID();
                                system("pause");
                                break;
                        case 3:pai.mostrarPais();
                                system("pause");
                                break;
                        case 4:if(pai.modificarNombre()){
                                    cout<<"NOMBRE MODIFICADO CORRECTAMENTE"<<endl;
                                }else{
                                    cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
                                }
                                system("pause");
                                break;
                        case 5:if(pai.bajaLogica()){
                                    cout<<"PAIS DADO DE BAJA CORRECTAMENTE"<<endl;
                                }else{
                                    cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
                                }
                                system("pause");
                                break;
                        case 0: quit=true;
                                break;
                        default:cout<<"OPCION INCORRECTA"<<endl;
                                break;
                                }
                    }
                    quit=false;
                        break;
            case 5:
                 while(!quit){
                        system("cls");
                    cout<<"MENU REPORTES"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"1 - "<<endl;
                    cout<<"2 - "<<endl;
                    cout<<"3 - "<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
                    cout<<"INGRESE UNA OPCION: ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1:MostrarArchivo();
                        system("pause");
                                break;
                        case 2:puntoB();
                        system("pause");
                                break;
                        case 3:puntoC();
                        system("pause");
                                break;

                        case 0: quit=true;
                                break;
                        default:cout<<"OPCION INCORRECTA"<<endl;
                                break;
                                }
                    }
                    quit=false;
                        break;
             case 6: while(!quit){
                        system("cls");
                    cout<<"MENU CONFIGURACION"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"1 - COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS"<<endl;
                    cout<<"2 - COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS"<<endl;
                    cout<<"3 - COPIA DE SEGURIDAD DEL ARCHIVO DE INSTRUMENTOS"<<endl;
                    cout<<"4 - COPIA DE SEGURIDAD DEL ARCHIVO DE PAISES"<<endl;
                    cout<<"5 - RESTAURAR EL ARCHIVO DE MUSICOS"<<endl;
                    cout<<"6 - RESTAURAR EL ARCHIVO DE GENEROS"<<endl;
                    cout<<"7 - RESTAURAR EL ARCHIVO DE INSTRUMENTOS"<<endl;
                    cout<<"8 - RESTAURAR EL ARCHIVO DE PAISES"<<endl;
                    cout<<"9 - ESTABLECER DATOS DE INICIO"<<endl;
                    cout<<"------------------------"<<endl;
                    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
                    cout<<"INGRESE UNA OPCION: ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1:if(copiaMusicos()){
                        cout<<"COPIA DE SEGURIDAD DE MUSICOS REALIZADA"<<endl;
                        }else{
                        cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD DE MUSICOS"<<endl;
                        }
                                system("pause");
                                break;
                        case 2:if(copiaGeneros()){
                        cout<<"COPIA DE SEGURIDAD DE GENEROS REALIZADA"<<endl;
                        }else{
                        cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD DE LOS GENEROS"<<endl;
                        }
                                system("pause");
                                break;
                        case 3:if(copiaInstrumento()){
                        cout<<"COPIA DE SEGURIDAD DE INSTRUMENTO REALIZADA"<<endl;
                        }else{
                        cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD DE LOS INSTRUMENTOS"<<endl;
                        }
                                system("pause");
                                break;
                        case 4:if(copiaPaises()){
                        cout<<"COPIA DE SEGURIDAD DE PAISES REALIZADA"<<endl;
                        }else{
                        cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD DE LOS PAISES"<<endl;
                        }
                                system("pause");
                                break;

                        case 5:if(restaurarMusicos()){
                        cout<<"RESTAURACION DE DATOS DE LOS MUSICOS REALIZADA"<<endl;
                        }else{
                        cout<<"NO SE PUDO REALIZAR LA RESTAURACION DE LOS MUSICOS"<<endl;
                        }
                                system("pause");
                                break;
                        case 6:if(restaurarGeneros()){
                        cout<<"RESTAURACION DE DATOS DE LOS GENEROS REALIZADA"<<endl;
                        }else{
                        cout<<"NO SE PUDO REALIZAR LA RESTAURACION DE LOS GENEROS"<<endl;
                        }
                                system("pause");
                                break;
                        case 7:if(restaurarInstrumentos()){
                        cout<<"RESTAURACION DE DATOS DE LOS INSTRUMENTOS REALIZADA"<<endl;
                        }else{
                        cout<<"NO SE PUDO REALIZAR LA RESTAURACION DE LOS INSTRUMENTOS"<<endl;
                        }
                                system("pause");
                                break;
                        case 8:if(restaurarPaises()){
                        cout<<"RESTAURACION DE DATOS DE LOS PAISES REALIZADA"<<endl;
                        }else{
                        cout<<"NO SE PUDO REALIZAR LA RESTAURACION DE LOS PAISES"<<endl;
                        }
                                system("pause");
                                break;


                        case 9:if(datosInico()){
                        cout<<"DATOS DE INICIO REALIZADO"<<endl;
                        }else{
                        cout<<"NO SE PUDO REALIZAR LOS DATOS INICIO"<<endl;
                        }
                                system("pause");
                                break;
                        case 0: quit=true;
                                break;
                        default:cout<<"OPCION INCORRECTA"<<endl;
                                break;
                                }
                    }
                    quit=false;
                        break;
             case 0: return 0;
                    break;
             default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
                cout<<endl;
                system("pause");
    }
    return 0;
}
