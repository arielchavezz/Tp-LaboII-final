#ifndef CLASE_INSTRUMENTO_H_INCLUDED
#define CLASE_INSTRUMENTO_H_INCLUDED

class Instrumento{
    private:
        int ID;
        char nombre[30];
        int clasificacion;
        bool estado;
    public:
        void setID(int i){ID=i;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setClasificacion(int c){clasificacion=c;}
        void setEstado(bool e){estado=e;}

        int getID(){return ID;}
        const char* getNombre(){return nombre;}
        int getClasificacion(){return clasificacion;}
        bool getEstado(){return estado;}

        void Cargar();
        void Mostrar();
        int contarRegistros();
        void cargarCadena(char *pal,int tam);
};

    void Instrumento::Cargar(){
        cout<<"ID: ";
        ID=contarRegistros()+1;
        cout<<ID<<endl;
        cout<<"NOMBRE: ";
        cargarCadena(nombre,29);
        cout<<"CLASIFICACION: ";
        cin>>clasificacion;
        estado=true;
    }

    void Instrumento::Mostrar(){
        cout<<"ID: "<<ID<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CLASIFICACION: "<<clasificacion<<endl;
        cout<<"---------------------------"<<endl;

    }

    int Instrumento::contarRegistros(){
        FILE *p;
        p=fopen("instrumentos.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Instrumento);
    }

    void Instrumento::cargarCadena(char *pal,int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

#endif // CLASE_INSTRUMENTO_H_INCLUDED
