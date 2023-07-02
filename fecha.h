#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes,anio;

    public:
        ///SETS
        void setDia(int x){if (x>0 && x<32) dia=x;}
        void setMes(int x){if (x>0 && x<13) mes=x;}
        void setAnio(int x) {anio=x;}
        ///GETS
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ///FECHA ACTUAL
        time_t t = time(nullptr);
        tm* fS = localtime(&t);
        int dia_actual = fS->tm_mday;
        int mes_actual = fS->tm_mon + 1;
        int anio_actual = fS->tm_year + 1900;

        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"\t\t\tMES: ";
            cin>>mes;
            cout<<"\t\t\tANIO: ";
            cin>>anio;
        while(!(anio < anio_actual || (anio == anio_actual && mes < mes_actual) || (anio == anio_actual && mes == mes_actual && dia < dia_actual))){
            cout<<"LA FECHA ES INCORRECTA INGRESE UNA FECHA VALIDA"<<endl;
            cout<<"\tDIA: ";
            cin>>dia;
            cout<<"\tMES: ";
            cin>>mes;
            cout<<"\tANIO: ";
            cin>>anio;


        }
    }
   void cargarOrigen(){
    cin>>anio;
    while(!(anio>=1500 && anio<=anio_actual)){
          cout<<"ANIO INCORRECTO"<<endl;
          cout<<"ANIO DE ORIGEN: ";
          cin>>anio;
          }
}

        void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
   }

    void mostrarOrigen(){
    cout<<anio;
    }

};

#endif // FECHA_H_INCLUDED
