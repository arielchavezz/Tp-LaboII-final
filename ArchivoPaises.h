#ifndef ARCHIVOPAISES_H_INCLUDED
#define ARCHIVOPAISES_H_INCLUDED

class ArchivoPaises{
    private:
        char nombre[30];
    public:
        ArchivoPaises(const char *n){strcpy(nombre,n);}
        ///ALTA
        void agregarPais();
        ///BAJA
        Paises leerPais(int pos);
        Paises leerRegistro(int pos);
        int buscarPais(int id);
        bool bajaLogica();
        ///MODIFICAR
        bool modificarNombre();
        ///LISTAR
        void buscarPorID();
        bool modificarRegistro(Paises pai,int pos);
        void mostrarPais();
        bool encontro(int pais);
};

void ArchivoPaises::agregarPais(){
        Paises pai;
        FILE *aPai;
        aPai=fopen(nombre, "ab");
        if(aPai==NULL){
            cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
            return;
        }
        pai.Cargar();
        fwrite(&pai, sizeof (Paises),1,aPai);
        fclose(aPai);

    }

void ArchivoPaises::mostrarPais(){
        Paises pai;
        FILE *aPai;
        aPai=fopen(nombre,"rb");
        if(aPai==NULL){
            cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
            return;
        }
        while(fread(&pai,sizeof pai,1,aPai)==1){
         if(pai.getEstado()==true)
        pai.Mostrar();
            cout<<endl;
            cout<<endl;
            cout<<"---------------------------"<<endl;
            cout<<endl;
        }
        fclose(aPai);
    }

void ArchivoPaises::buscarPorID(){
    Paises pai;
    int id;
    cout<<"INGRESE EL ID: ";
    cin>>id;
    int pos=buscarPais(id);
    pai=leerPais(pos);
    if(pai.getID()>0){
        pai.Mostrar();
    }else if(pai.getID()==-3 || pai.getID()==-1){
        cout<<"EL ID NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
}

int ArchivoPaises::buscarPais(int id){
    Paises pai;
        int pos=0;
        FILE *aPai;
        aPai=fopen(nombre,"rb");
        if(aPai==NULL){
            return -2;
        }
    while(fread(&pai,sizeof pai,1,aPai)==1){
        if(pai.getID()==id){
            fclose(aPai);
            return pos;
        }
        pos++;
    }
    fclose(aPai);
    return -1;
}

Paises ArchivoPaises::leerRegistro(int pos){
        Paises pai;
        pai.setID(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return pai;
        fseek(p, sizeof(Paises)*pos,0);
        fread(&pai, sizeof pai,1, p);
        fclose(p);
        return pai;
    }

Paises ArchivoPaises::leerPais(int pos){
        Paises pai;
        pai.setID(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return pai;
        fseek(p, sizeof(Paises)*pos,0);
        fread(&pai, sizeof pai,1, p);
        fclose(p);
        return pai;
    }

bool ArchivoPaises::modificarNombre(){
    Paises pai;
    int id;
    cout<<"INGRESE EL ID DEL PAIS A MODIFICAR: ";
    cin>>id;
    int pos=buscarPais(id);
    if(pos==-1){
        cout<<"NO EXISTE PAIS CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    pai=leerPais(pos);
    if(pai.getEstado()==false){
        cout<<"EL PAIS INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    char n[30];
    cout<<"INGRESE EL NUEVO MONBRE: ";
    cin>>n;
    pai.setNombre(n);
    bool aux=modificarRegistro(pai,pos);
    return aux;
}

bool ArchivoPaises::modificarRegistro(Paises pai,int pos){
    FILE *aPai;
    aPai=fopen(nombre,"rb+");
    fseek(aPai, sizeof pai*pos,0);
    bool aux=fwrite(&pai, sizeof pai,1,aPai);
    fclose(aPai);
    return aux;
}

bool ArchivoPaises::bajaLogica(){
    Paises pai;
    int id;
    cout<<"INGRESE EL ID A DAR DE BAJA: ";
    cin>>id;
    int pos=buscarPais(id);
    if(pos==-1){
        cout<<"NO EXISTE PAIS CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    pai=leerPais(pos);
    if(pai.getEstado()==false){
        cout<<"EL PAIS INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    pai.setEstado(false);
    bool aux=modificarRegistro(pai,pos);
    return aux;
    }

bool ArchivoPaises::encontro(int pais){
    Paises pai;
    bool encontrado =true;
   int cantReg=pai.contarRegistros();;
    for(int i=0;i<=cantReg;i++){
        pai=leerRegistro(i);
       if(pai.getID()==pais){
            encontrado=false;
            }
    }
    return encontrado;
}
#endif // ARCHIVOPAISES_H_INCLUDED
