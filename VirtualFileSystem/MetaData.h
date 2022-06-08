#pragma once
#include "MapaBits.h"
class MetaData
{
private:
	char nombreDisco[20];
	char fechaCreacion[8];
	int EntradasDirectorios(); // la cantidad
	 
	unsigned int tamanioBloque; //tamaño
	int cantBD;
	int cantBI_Nivel1;
	int cantBI_Nivel2;
	int cantdBI_Nivel3;

	void guardarMapaBits();
	int getSizeOf();
	void read(const char* _nombre);
	const char* getName();

	void print();

public:
	MetaData();
	MetaData(const char*, int);
	DataFile* file;
	MetaData* meta;
	MapaBits* bits;
	
	crearDisco(int, const char*);


	char* toChar();
	void fromChar(char*);



};

