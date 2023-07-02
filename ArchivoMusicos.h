#ifndef ARCHIVOMUSICOS_H_INCLUDED
#define ARCHIVOMUSICOS_H_INCLUDED


class ArchivoMusicos{
    private:
        char nombre[30];
    public:
        ArchivoMusicos(const char *n){strcpy(nombre,n);}
    ///ALTA
        void agregarMusico();
    ///BAJA
        Musicos leerMusico(int pos);
        int buscarMusico(int dni);
        bool bajaLogica();
    ///MODIFICACION
        bool modificarFecha();
    ///LISTAR
        void buscarporDNI();
        bool modificarRegistro(Musicos obj, int pos);
        void mostrarMusicos();



};


    void ArchivoMusicos::agregarMusico(){
        Musicos obj;
        FILE *aMus;
        aMus=fopen(nombre, "ab");
        if(aMus==NULL){
            cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
            return;
        }int dni;
        cout<<"DNI: ";
        cin>>dni;
        if(buscarMusico(dni)>=0){
            cout<<"ESE DNI YA FUE INGRESADO"<<endl;
            system("pause");
            return;
            }
        obj.Cargar(dni);
        fwrite(&obj, sizeof (Musicos),1,aMus);
        fclose(aMus);
    }

    bool ArchivoMusicos::bajaLogica(){
    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI A DAR DE BAJA: ";
    cin>>DNI;
    int pos=buscarMusico(DNI);
    if(pos==-1){
        cout<<"NO EXISTE MUSICO CON ESE DNI"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj=leerMusico(pos);
    if(obj.getEstado()==false){
        cout<<"EL MUSICO INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    obj.setEstado(false);
    bool aux=modificarRegistro(obj,pos);
    return aux;
    }

    void ArchivoMusicos::mostrarMusicos(){
        Musicos obj;
        FILE *aMus;
        aMus=fopen(nombre,"rb");
        if(aMus==NULL){
            cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
            return;
        }
        while(fread(&obj,sizeof obj,1,aMus)==1){
         if(obj.getEstado()==true)
        obj.Mostrar();
            cout<<endl;
            cout<<"---------------------------"<<endl;
            cout<<endl;
            }
        fclose(aMus);
    }


    Musicos ArchivoMusicos::leerMusico(int pos){
        Musicos obj;
        if(pos<0){
            obj.setDNI(-3);
            return obj;
        }
        FILE *aMus;
        aMus=fopen(nombre,"rb");
        if(aMus==NULL){
            obj.setDNI(-2);
            return obj;
        }
        fseek(aMus,sizeof obj*pos,0);
        int aux=fread(&obj,sizeof obj,1,aMus);
        fclose(aMus);
        if(aux==0){
            obj.setDNI(-1);
        }
        return obj;
    }

    int ArchivoMusicos::buscarMusico(int dni){
        Musicos obj;
        int pos=0;
        FILE *aMus;
        aMus=fopen(nombre,"rb");
        if(aMus==NULL){
            return -2;
        }
    while(fread(&obj,sizeof obj,1,aMus)==1){
        if(obj.getDNI()==dni){
            fclose(aMus);
            return pos;
        }
        pos++;
    }
    fclose(aMus);
    return -1;
    }

    void ArchivoMusicos::buscarporDNI(){
    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI: ";
    cin>>DNI;
    int pos=buscarMusico(DNI);
    obj=leerMusico(pos);
    if(obj.getDNI()>0){
        obj.Mostrar();
    }else if(obj.getDNI()==-3 || obj.getDNI()==-1){
        cout<<"EL DNI NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }

    }

    bool ArchivoMusicos::modificarFecha(){
    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI DEL CLIENTE A MODIFICAR: ";
    cin>>DNI;
    int pos=buscarMusico(DNI);
    if(pos==-1){
        cout<<"NO EXISTE MUSICO CON ESE DNI"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj=leerMusico(pos);
    if(obj.getEstado()==false){
        cout<<"EL CLIENTE INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    Fecha fechaModificada;
    cout<<"INGRESE LA NUEVA FECHA: ";
    fechaModificada.Cargar();
    obj.setFechaMusico(fechaModificada);
    bool aux=modificarRegistro(obj,pos);
    return aux;
    }

    bool ArchivoMusicos::modificarRegistro(Musicos obj,int pos){
    FILE *aMus;
    aMus=fopen(nombre,"rb+");
    fseek(aMus, sizeof obj*pos,0);
    bool aux=fwrite(&obj, sizeof obj,1,aMus);
    fclose(aMus);
    return aux;

    }



#endif // ARCHIVOMUSICOS_H_INCLUDED
