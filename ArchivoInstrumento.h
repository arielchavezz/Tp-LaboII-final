#ifndef ARCHIVOINSTRUMENTO_H_INCLUDED
#define ARCHIVOINSTRUMENTO_H_INCLUDED

class ArchivoInstrumento{
    private:
        char nombre[30];
    public:
        ArchivoInstrumento(const char *i){strcpy(nombre,i);}
        ///ALTA
        void agregarInstrumento();
        ///BAJA
        Instrumento leerInstrumento(int pos);
        Instrumento leerRegistro(int pos);
        int buscarInstrumento(int id);
        bool bajaLogica();
        ///MODIFICAR
        bool modificarNombre();
        ///LISTAR
        void buscarPorID();
        bool modificarRegistro(Instrumento cos,int pos);
        void mostrarInstrumento();
        bool encontro(int instrumento);
};

void ArchivoInstrumento::agregarInstrumento(){
        Instrumento cos;
        FILE *aIns;
        aIns=fopen(nombre, "ab");
        if(aIns==NULL){
            cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
            return;
        }
        cos.Cargar();
        fwrite(&cos, sizeof (Instrumento),1,aIns);
        fclose(aIns);
}

void ArchivoInstrumento::mostrarInstrumento(){
        Instrumento cos;
        FILE *aIns;
        aIns=fopen(nombre,"rb");
        if(aIns==NULL){
            cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
            return;
        }
        while(fread(&cos,sizeof cos,1,aIns)==1){
         if(cos.getEstado()==true)
        cos.Mostrar();
            }
        fclose(aIns);
}

void ArchivoInstrumento::buscarPorID(){
    Instrumento cos;
    int id;
    cout<<"INGRESE EL ID: ";
    cin>>id;
    int pos=buscarInstrumento(id);
    cos=leerInstrumento(pos);
    if(cos.getID()>0){
        cos.Mostrar();
    }else if(cos.getID()==-3 || cos.getID()==-1){
        cout<<"EL ID NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
}

int ArchivoInstrumento::buscarInstrumento(int id){
    Instrumento cos;
        int pos=0;
        FILE *aIns;
        aIns=fopen(nombre,"rb");
        if(aIns==NULL){
            return -2;
        }
    while(fread(&cos,sizeof cos,1,aIns)==1){
        if(cos.getID()==id){
            fclose(aIns);
            return pos;
        }
        pos++;
    }
    fclose(aIns);
    return -1;
}
Instrumento ArchivoInstrumento::leerRegistro(int pos){
        Instrumento cos;
        cos.setID(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return cos;
        fseek(p, sizeof(Instrumento)*pos,0);
        fread(&cos, sizeof cos,1, p);
        fclose(p);
        return cos;
    }

Instrumento ArchivoInstrumento::leerInstrumento(int pos){
        Instrumento cos;
        if(pos<0){
            cos.setID(-3);
            return cos;
        }
        FILE *aIns;
        aIns=fopen(nombre,"rb");
        if(aIns==NULL){
            cos.setID(-2);
            return cos;
        }
        fseek(aIns,sizeof cos*pos,0);
        int aux=fread(&cos,sizeof cos,1,aIns);
        fclose(aIns);
        if(aux==0){
            cos.setID(-1);
        }
        return cos;
}

bool ArchivoInstrumento::bajaLogica(){
    Instrumento cos;
    int id;
    cout<<"INGRESE EL ID A DAR DE BAJA: ";
    cin>>id;
    int pos=buscarInstrumento(id);
    if(pos==-1){
        cout<<"NO EXISTE INSTRUMENTO CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    cos=leerInstrumento(pos);
    if(cos.getEstado()==false){
        cout<<"EL INSTRUMENTO INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    cos.setEstado(false);
    bool aux=modificarRegistro(cos,pos);
    return aux;
    }

bool ArchivoInstrumento::modificarRegistro(Instrumento cos,int pos){
    FILE *aIns;
    aIns=fopen(nombre,"rb+");
    fseek(aIns, sizeof cos*pos,0);
    bool aux=fwrite(&cos, sizeof cos,1,aIns);
    fclose(aIns);
    return aux;
}

bool ArchivoInstrumento::modificarNombre(){
    Instrumento cos;
    int id;
    cout<<"INGRESE EL ID DEL INSTRUMENTO A MODIFICAR: ";
    cin>>id;
    int pos=buscarInstrumento(id);
    if(pos==-1){
        cout<<"NO EXISTE INSTRUMENTO CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    cos=leerInstrumento(pos);
    if(cos.getEstado()==false){
        cout<<"EL INSTRUMENTO INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    char n[30];
    cout<<"INGRESE EL NUEVO MONBRE: ";
    cin>>n;
    cos.setNombre(n);
    bool aux=modificarRegistro(cos,pos);
    return aux;
}
bool ArchivoInstrumento::encontro(int instrumento){
    Instrumento cos;
    bool encontrado =true;
   int cantReg=cos.contarRegistros();
    for(int i=0;i<=cantReg;i++){
        cos=leerRegistro(i);
       if(cos.getID()==instrumento){
            encontrado=false;
            }
    }
    return encontrado;
   }
#endif // ARCHIVOINSTRUMENTO_H_INCLUDED
