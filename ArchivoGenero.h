#ifndef ARCHIVOGENERO_H_INCLUDED
#define ARCHIVOGENERO_H_INCLUDED

class ArchivoGenero{
    private:
        char nombre[30];
    public:
        ArchivoGenero(const char *g){strcpy(nombre,g);}
        ///ALTA
        void agregarGenero();
        ///BAJA
        Genero leerGenero(int pos);
        Genero leerRegistro(int pos);
        int buscarGenero(int id);
        bool bajaLogica();
        ///MODIFICACION
        bool modificarFecha();
        ///LISTAR
        void buscarPorID();
        bool modificarRegistro(Genero reg,int pos);
        void mostrarGenero();
        bool encontro(int tipo);

};



void ArchivoGenero::agregarGenero(){
        Genero reg;
        FILE *aGen;
        aGen=fopen(nombre, "ab");
        if(aGen==NULL){
            cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
            return;
        }
        reg.Cargar();
        fwrite(&reg, sizeof (Genero),1,aGen);
        fclose(aGen);

    }

    void ArchivoGenero::mostrarGenero(){
        Genero reg;
        FILE *aGen;
        aGen=fopen(nombre,"rb");
        if(aGen==NULL){
            cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
            return;
        }
        while(fread(&reg,sizeof reg,1,aGen)==1){
         if(reg.getEstado()==true)
        reg.Mostrar();
            cout<<endl;
            cout<<endl;
            cout<<"---------------------------"<<endl;
            cout<<endl;
        }
        fclose(aGen);
    }

    int ArchivoGenero::buscarGenero(int id){
    Genero reg;
        int pos=0;
        FILE *aGen;
        aGen=fopen(nombre,"rb");
        if(aGen==NULL){
            return -2;
        }
    while(fread(&reg,sizeof reg,1,aGen)==1){
        if(reg.getID()==id){
            fclose(aGen);
            return pos;
        }
        pos++;
    }
    fclose(aGen);
    return -1;
    }

    void ArchivoGenero::buscarPorID(){
    Genero reg;
    int id;
    cout<<"INGRESE EL ID: ";
    cin>>id;
    int pos=buscarGenero(id);
    reg=leerGenero(pos);
    if(reg.getID()>0){
        reg.Mostrar();
    }else if(reg.getID()==-3 || reg.getID()==-1){
        cout<<"EL ID NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
}

Genero ArchivoGenero::leerRegistro(int pos){
        Genero reg;
        reg.setID(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Genero)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }


    Genero ArchivoGenero::leerGenero(int pos){
        Genero reg;
        if(pos<0){
            reg.setID(-3);
            return reg;
        }
        FILE *aGen;
        aGen=fopen(nombre,"rb");
        if(aGen==NULL){
            reg.setID(-2);
            return reg;
        }
        fseek(aGen,sizeof reg*pos,0);
        int aux=fread(&reg,sizeof reg,1,aGen);
        fclose(aGen);
        if(aux==0){
            reg.setID(-1);
        }
        return reg;
    }

    bool ArchivoGenero::modificarFecha(){
    Genero reg;
    int id;
    cout<<"INGRESE EL ID DEL GENERO A MODIFICAR: ";
    cin>>id;
    int pos=buscarGenero(id);
    if(pos==-1){
        cout<<"NO EXISTE GENERO CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    reg=leerGenero(pos);
    if(reg.getEstado()==false){
        cout<<"EL GENERO INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    Fecha fechaModificada;
    cout<<"INGRESE LA NUEVA FECHA: ";
    fechaModificada.cargarOrigen();
    reg.setAnioOriogen(fechaModificada);
    bool aux=modificarRegistro(reg,pos);
    return aux;
    }

    bool ArchivoGenero::modificarRegistro(Genero reg,int pos){
    FILE *aGen;
    aGen=fopen(nombre,"rb+");
    fseek(aGen, sizeof reg*pos,0);
    bool aux=fwrite(&reg, sizeof reg,1,aGen);
    fclose(aGen);
    return aux;

    }

    bool ArchivoGenero::bajaLogica(){
    Genero reg;
    int id;
    cout<<"INGRESE EL ID A DAR DE BAJA: ";
    cin>>id;
    int pos=buscarGenero(id);
    if(pos==-1){
        cout<<"NO EXISTE GENERO CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    reg=leerGenero(pos);
    if(reg.getEstado()==false){
        cout<<"EL GENERO INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    reg.setEstado(false);
    bool aux=modificarRegistro(reg,pos);
    return aux;
    }


bool ArchivoGenero::encontro(int tipo){
    Genero reg;
    bool encontrado =true;
   int cantReg=reg.contarRegistros();;
    for(int i=0;i<=cantReg;i++){
        reg=leerRegistro(i);
       if(reg.getID()==tipo){
            encontrado=false;
            }
    }
    return encontrado;
}

#endif // ARCHIVOGENERO_H_INCLUDED
