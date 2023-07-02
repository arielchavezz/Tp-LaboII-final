#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

bool copiaMusicos(){
    Musicos obj;
    FILE *aMus, *aBak;
    aMus=fopen("musicos.dat", "rb");
    if(aMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    aBak=fopen("musicos.bak", "wb");
    if(aBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(aMus);
        return false;
    }
    while(fread(&obj, sizeof obj, 1,aMus)==1){
        fwrite(&obj, sizeof obj, 1,aBak);
    }
    fclose(aBak);
    fclose(aMus);
    return true;
}
bool copiaGeneros(){
    Genero reg;
    FILE *aGen, *aGenBak;
    aGen=fopen("generos.dat", "rb");
    if(aGen==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    aGenBak=fopen("generos.bak", "wb");
    if(aGenBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(aGen);
        return false;
    }
    while(fread(&reg, sizeof reg, 1,aGen)==1){
        fwrite(&reg, sizeof reg, 1,aGenBak);
    }
    fclose(aGenBak);
    fclose(aGen);
    return true;
}

bool copiaInstrumento(){
    Instrumento cos;
    FILE *aIns, *aInsBak;
    aIns=fopen("instrumentos.dat", "rb");
    if(aIns==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    aInsBak=fopen("instrumentos.bak", "wb");
    if(aInsBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(aIns);
        return false;
    }
    while(fread(&cos, sizeof cos, 1,aIns)==1){
        fwrite(&cos, sizeof cos, 1,aInsBak);
    }
    fclose(aInsBak);
    fclose(aIns);
    return true;
}


bool copiaPaises(){
    Paises pai;
    FILE *aPai, *aPaiBak;
    aPai=fopen("paises.dat", "rb");
    if(aPai==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    aPaiBak=fopen("paises.bak", "wb");
    if(aPaiBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(aPai);
        return false;
    }
    while(fread(&pai, sizeof pai, 1,aPai)==1){
        fwrite(&pai, sizeof pai, 1,aPaiBak);
    }
    fclose(aPaiBak);
    fclose(aPai);
    return true;
}


bool restaurarMusicos(){
    Musicos obj;
    FILE *aBak, *aMus;
    aMus=fopen("musicos.dat", "wb");
    if(aMus==NULL){
        return false;
    }
    aBak=fopen("musicos.bak", "rb");
    if(aBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(aMus);
        return false;
    }
    while(fread(&obj, sizeof obj, 1 , aBak)==1){
        fwrite(&obj, sizeof obj, 1 , aMus);
    }
    fclose(aBak);
    fclose(aMus);
    return true;
}
bool restaurarGeneros(){
    Genero reg;
    FILE *aGenBak, *aGen;
    aGen=fopen("generos.dat", "wb");
    if(aGen==NULL){
        return false;
    }
    aGenBak=fopen("generos.bak", "rb");
    if(aGenBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(aGen);
        return false;
    }
    while(fread(&reg, sizeof reg, 1 , aGenBak)==1){
        fwrite(&reg, sizeof reg, 1 , aGen);
    }
    fclose(aGenBak);
    fclose(aGen);
    return true;
}
bool restaurarInstrumentos(){
    Instrumento cos;
    FILE *aInsBak, *aIns;
    aIns=fopen("instrumentos.dat", "wb");
    if(aIns==NULL){
        return false;
    }
    aInsBak=fopen("instrumentos.bak", "rb");
    if(aInsBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(aIns);
        return false;
    }
    while(fread(&cos, sizeof cos, 1 , aInsBak)==1){
        fwrite(&cos, sizeof cos, 1 , aIns);
    }
    fclose(aInsBak);
    fclose(aIns);
    return true;
}

bool restaurarPaises(){
    Paises pai;
    FILE *aPaiBak, *aPai;
    aPai=fopen("paises.dat", "wb");
    if(aPai==NULL){
        return false;
    }
    aPaiBak=fopen("paises.bak", "rb");
    if(aPaiBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(aPai);
        return false;
    }
    while(fread(&pai, sizeof pai, 1 , aPaiBak)==1){
        fwrite(&pai, sizeof pai, 1 , aPai);
    }
    fclose(aPaiBak);
    fclose(aPai);
    return true;
}

bool datosInico(){
    Musicos obj;
    Genero reg;
    Instrumento cos;
    Paises pai;
    FILE *aMus, *aGen, *copMus, *copGen,*aPai,*copPai,*aIns,*copIns;

    /// DATOS MUSICOS ///

    copMus=fopen("datosInicioMusicos.dat", "rb");
    if(copMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    aMus=fopen("musicos.dat", "wb");
    if(aMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(copMus);
        return false;
    }
    while(fread(&obj, sizeof obj, 1,copMus)==1){
        fwrite(&obj, sizeof obj, 1,aMus);
    }
    fclose(aMus);
    fclose(copMus);

    /// DATOS GENEROS ///

    copGen=fopen("datosInicioGeneros.dat", "rb");
    if(copGen==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    aGen=fopen("generos.dat", "wb");
    if(aGen==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(copGen);
        return false;
    }
    while(fread(&reg, sizeof reg, 1,copGen)==1){
        fwrite(&reg, sizeof reg, 1,aGen);
    }
    fclose(aGen);
    fclose(copGen);

    /// DATOS INSTRUMENTOS ///

    copIns=fopen("datosInicioInstrumentos.dat", "rb");
    if(copIns==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    aIns=fopen("instrumentos.dat", "wb");
    if(aIns==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(copIns);
        return false;
    }
    while(fread(&cos, sizeof cos, 1,copIns)==1){
        fwrite(&cos, sizeof cos, 1,aIns);
    }
    fclose(aIns);
    fclose(copIns);

    /// DATOS PAISES ///

    copPai=fopen("datosInicioPaises.dat", "rb");
    if(copPai==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    aPai=fopen("paises.dat", "wb");
    if(aPai==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(copPai);
        return false;
    }
    while(fread(&pai, sizeof pai, 1,copPai)==1){
        fwrite(&pai, sizeof pai, 1,aPai);
    }
    fclose(aPai);
    fclose(copPai);

    return true;
}

#endif // CONFIGURACION_H_INCLUDED
