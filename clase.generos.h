#ifndef CLASE_GENEROS_H_INCLUDED
#define CLASE_GENEROS_H_INCLUDED

class Genero{
    private:
        int ID;
        int paisOrigen;
        char nombre[30];
        bool estado;
        Fecha anioOrigen;
    public:
        void setID(const int i){ID=i;}
        void setPaisOrigen(const int p){paisOrigen=p;}
        void setNombre( char *n){strcpy(nombre,n);}
        void setEstado(bool e){estado=e;}
        void setAnioOriogen(Fecha a){anioOrigen=a;}

        int getID(){return ID;}
        int getPaisOrigen(){return paisOrigen;}
         char* getNombre(){return nombre;}
        bool getEstado(){return estado;}
        Fecha getAnioOrigen(){return anioOrigen;}


        void Cargar();
        void Mostrar();
        int contarRegistros();


};


    void Genero::Cargar(){
        ArchivoPaises ArchiPai("paises.dat");
        cout<<"ID DE GENERO MUSICAL: ";
       ID=contarRegistros()+1;
        cout<<ID<<endl;
        cout<<"NOMBRE: ";
        cin>>nombre;
        cout<<"PAIS DE ORIGEN: ";
        cin>>paisOrigen;
        while(ArchiPai.encontro(paisOrigen)){
            cout<<"VALOR INGRESADO INCORRECTO"<<endl;
            cout<<"PAIS DE ORIGEN: ";
            cin>>paisOrigen;
            ArchiPai.encontro(paisOrigen);
        }
        cout<<"ANIO DE ORIGEN: ";
        anioOrigen.cargarOrigen();
        estado=true;
    }

    void Genero::Mostrar(){
        cout<<"ID DE GENERO MUSICAL: "<<ID<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"PAIS DE ORIGEN: "<<paisOrigen<<endl;
        cout<<"ANIO DE ORIGEN: ";
        anioOrigen.mostrarOrigen();

}
    int Genero::contarRegistros(){
        FILE *p;
        p=fopen("generos.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Genero);
    }



#endif // CLASE_GENEROS_H_INCLUDED
