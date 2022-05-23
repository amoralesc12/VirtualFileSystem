#pragma once
class MetaData
{
private:
	char nDisco[20];
	char fechaCreacion[8];

	int EntradasDirectorios; // la cantidad
	 
	unsigned int tamBloque; //tamaño
	int cantBD;
	int cantBI_Nivel1;
	int cantBI_Nivel2;
	int cantdBI_Nivel3;

public:
	MetaData();

	char* toChar();
	void fromChar(char*);



};

