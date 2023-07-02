#ifndef CLASE_PAISES_H_INCLUDED
#define CLASE_PAISES_H_INCLUDED

class Paises{
    private:
        int ID;
        char nombre[30];
        char continente[30];
        bool estado;
    public:
        void setID(int i){ID=i;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setContinente(const char *c){strcpy(continente,c);}
        void setEstado(bool e){estado=e;}

        int getID(){return ID;}
        const char* getNombre(){return nombre;}
        const char* getContinente(){return continente;}
        bool getEstado(){return estado;}

        void Cargar();
        void Mostrar();
        int contarRegistros();
        void cargarCadena(char *pal,int tam);
};


    void Paises::Cargar(){
        cout<<"ID: ";
        ID=contarRegistros()+1;
        cout<<ID<<endl;
        cout<<"NOMBRE: ";
        cargarCadena(nombre,29);
        cout<<"CONTINENTE: ";
        cargarCadena(continente,29);
        estado=true;
    }

    void Paises::Mostrar(){
        cout<<"ID: "<<ID<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CONTINENTE: "<<continente<<endl;
    }

     int Paises::contarRegistros(){
        FILE *p;
        p=fopen("paises.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Paises);
    }

    void Paises::cargarCadena(char *pal,int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


#endif // CLASE_PAISES_H_INCLUDED
