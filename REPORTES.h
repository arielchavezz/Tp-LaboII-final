#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED



void cargarCadena(char *pal,int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class Nuevo{
private:
    int id;
    int paisOrigen;
    char nombre[30];
    bool estado;
    Fecha anioOrigen;
public:
        void setID(const int i){id=i;}
        void setPaisOrigen(const int p){paisOrigen=p;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setEstado(bool e){estado=e;}
        void setAnioOriogen(Fecha a){anioOrigen=a;}

        int getID(){return id;}
        int getPaisOrigen(){return paisOrigen;}
        const char* getNombre(){return nombre;}
        bool getEstado(){return estado;}
        Fecha getAnioOrigen(){return anioOrigen;}

        void Mostrar(){
        cout<<"ID: "<<id<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"PAIS DE ORIGEN: "<<paisOrigen<<endl;
        cout<<"ANIO DE ORIGEN: ";
        anioOrigen.mostrarOrigen();}
};

class NuevoArchivo{
private:
    char nombre[30];
public:
    NuevoArchivo(const char *n){
    strcpy(nombre,n);}
    Nuevo leerRegistro(int pos){
        Nuevo reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Nuevo);
    }
};

int encontrar(const char *nombre){
Paises obj;
ArchivoPaises ArchiP("paises.dat");

int tam = obj.contarRegistros();

for(int i=0;i<tam;i++){
    obj=ArchiP.leerRegistro(i);
    if(strcmp(nombre,obj.getNombre())==0){
        return obj.getID();
    }
}
return 0;

}

void puntoA(){
char nombre[30];
cout<<"INGRESE UN NOMBRE DE PAIS: "<<endl;
cargarCadena(nombre,29);
Genero obj;
ArchivoGenero ArchiG("generos.dat");

Nuevo aux;
FILE *aNuevo;
    aNuevo=fopen("nuevo.dat","wb");
    if(aNuevo==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }

int tam=obj.contarRegistros();

for(int i=0;i<tam;i++){
    obj=ArchiG.leerRegistro(i);
    if(encontrar(nombre)==obj.getPaisOrigen()){
      aux.setID(obj.getID());
      aux.setPaisOrigen(obj.getPaisOrigen());
      aux.setNombre(obj.getNombre());
      aux.setEstado(obj.getEstado());
      aux.setAnioOriogen(obj.getAnioOrigen());
      fwrite(&aux,sizeof aux, 1,aNuevo);
    }
}
fclose(aNuevo);

}
void MostrarArchivo(){
    puntoA();
        Nuevo obj;
        FILE *aNuevo;
        aNuevo=fopen("nuevo.dat","rb");
        if(aNuevo==NULL){
            cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
            return;
        }
        while(fread(&obj,sizeof obj,1,aNuevo)==1){
         obj.Mostrar();
            cout<<endl;
            cout<<"---------------------------"<<endl;
            cout<<endl;
            }
        fclose(aNuevo);
}

///PUNTO 2///
int encontrarMayor(int *vInstrumento,int tam){
int mayor=vInstrumento[0];
int posMayor=0;
for(int i=0;i<tam;i++){
if(vInstrumento[i] > mayor){
    mayor=vInstrumento[i];
    posMayor=i;
}}
return posMayor;
}

void puntoB(){
int vInstrumento[15]={0};
int mayor;
Musicos obj;
ArchivoMusicos ArchiM("musicos.dat");

int tam=obj.contarRegistros();

for(int i=0;i<tam;i++){
    obj=ArchiM.leerMusico(i);
    if(obj.getClaustro()==1){
        vInstrumento[obj.getInstrumento()-1]++;
    }
}

mayor=encontrarMayor(vInstrumento,15);
cout<<"EL INSTRUMENTO CON MAS MUSICOS DEL CLAUSTRO DOCENTES ES: "<<mayor+1<<endl;

}

    ///PUNTO 3///
void puntoC(){
Nuevo obj;
NuevoArchivo ArchiN("nuevo.dat");
int pos=0;
int tam=ArchiN.contarRegistros();

Nuevo *vNuevo;
vNuevo = new Nuevo[tam];
for(int i=0;i<tam;i++){
    obj=ArchiN.leerRegistro(i);
    vNuevo[pos++]=obj;
}
for(int j=0;j<tam;j++){
    cout<<"ID: "<<vNuevo[j].getID()<<endl;
    cout<<"NOMBRE: "<<vNuevo[j].getNombre()<<endl;
    cout<<"PAIS DE ORIGEN: "<<vNuevo[j].getPaisOrigen()<<endl;
    cout<<"ANIO DE ORIGEN: "<<vNuevo[j].getAnioOrigen().getAnio()<<endl;
}

delete vNuevo;

}




#endif // REPORTES_H_INCLUDED
