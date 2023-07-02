#ifndef CLASE_MUSICO_H_INCLUDED
#define CLASE_MUSICO_H_INCLUDED

class Musicos{
    private:
        int DNI,claustro,instrumento,tipoMusica;
        char nombre[30],apellido[30],email[30],telefono[30];
        float matricula;
        bool estado;
        Fecha fechaMusico;
    public:
       void setDNI(const int d){DNI=d;}
       void setClaustro(const int c){claustro=c;}
       void setInstrumento(const int i){instrumento=i;}
       void setTipoMusica(const int tm){tipoMusica=tm;}
       void setNombre(const char *n){strcpy(nombre,n);}
       void setApellido(const char *a){strcpy(apellido,a);}
       void setEmail(const char *e){strcpy(email,e);}
       void setTelefono(const char *t){strcpy(telefono,t);}
       void setMatricula(const float m){matricula=m;}
       void setEstado( bool es){estado=es;}
       void setFechaMusico(Fecha f){fechaMusico=f;}

      int getDNI(){return DNI;}
      int getClaustro(){return claustro;}
      int getInstrumento(){return instrumento;}
      int getTipoMusica(){return tipoMusica;}
      const char* getNombre(){return nombre;}
      const char* getApellido(){return apellido;}
      const char* getEmail(){return email;}
      const char* getTelefono(){return telefono;}
      float getMatricula(){return matricula;}
      bool getEstado(){return estado;}
      Fecha getFechaMusico(){return fechaMusico;}



    void Cargar(int dni);
    void Mostrar();
    void mostrarEsp();
    int contarRegistros();
};

void Musicos::Cargar(int dni=-1){
    ArchivoInstrumento ArchiIns("instrumentos.dat");
    ArchivoGenero ArchiGen("generos.dat");
    if(dni==-1){
    cout<<"DNI: ";
    cin>>DNI;
    }else{
        DNI=dni;
    }
    cout<<"NOMBRE: ";
    cin>>nombre;
    cout<<"APELLIDO: ";
    cin>>apellido;
    cout<<"EMAIL: ";
    cin>>email;
    cout<<"TELEFONO: ";
    cin>>telefono;
    cout<<"CLAUSTRO(1:docente ,2 alumno, 3 no docente, 4 graduado): ";
    cin>>claustro;
    while(!(claustro>0 && claustro<5)){
        cout<<"VALOR DE CLAUSTRO ES INCORRECTO"<<endl;
        cout<<"CLAUSTRO: ";
        cin>>claustro;
        }
    cout<<"INSTRUMENTO PRINCIPAL: ";
    cin>>instrumento;
    while(ArchiIns.encontro(instrumento)){
        cout<<"VALOR INGRESADO INCORRECTO"<<endl;
        cout<<"INSTRUMENTO: "<<endl;
        cin>>instrumento;
        ArchiIns.encontro(instrumento);
            }


    cout<<"TIPO DE MUSICA: ";
    cin>>tipoMusica;
    while(ArchiGen.encontro(tipoMusica)){
        cout<<"VALOR DE TIPO DE MUSICA ES INCORRECTO"<<endl;
        cout<<"TIPO DE MUSICA: ";
        cin>>tipoMusica;
        ArchiGen.encontro(tipoMusica);
    }
    cout<<"FECHA DE INSCRIPCION:   ";
    fechaMusico.Cargar();
    cout<<"MATRICULA: ";
    cin>>matricula;
    while(matricula<=-1){
        cout<<"VALOR DE MATRICULA INCORRECTA"<<endl;
        cout<<"MATRICULA: ";
        cin>>matricula;
    }
    estado=true;
    }

    void Musicos::Mostrar(){
    cout<<"DNI: "<<DNI<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"EMAIL: "<<email<<endl;
    cout<<"TELEFONO: "<<telefono<<endl;
    cout<<"CLAUSTRO(1:docente ,2 alumno, 3 no docente, 4 graduado): "<<claustro<<endl;
    cout<<"INSTRUMENTO PRINCIPAL(numero entre 1 y 15): "<<instrumento<<endl;
    cout<<"TIPO DE MUSICA(número entre 1 y 10): "<<tipoMusica<<endl;
    cout<<"FECHA DE INSCRIPCION: ";
    fechaMusico.Mostrar();
    cout<<"MATRICULA: "<<matricula<<endl;

}


int Musicos::contarRegistros(){
        FILE *p;
        p=fopen("musicos.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Musicos);
    }


#endif // CLASE_MUSICO_H_INCLUDED
