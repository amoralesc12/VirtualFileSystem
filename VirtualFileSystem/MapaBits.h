#pragma once
#include "DataFile.h"
#include "MetaData.h"

class MapaBits{	
public:	
	
	/*TODO DEBE SER DINAMICO*/
	//TOTAL DE BYTES POR CADA MAPA DE BITS

	class MB_BloqueDirecto {
		friend class MapaBits;
		MB_BloqueDirecto();
		char* bloqueDirecto;

		char* toCharBD();
		void fromCharBD(char*);
		int getSizeBD();
	};

	class MB_Indirecto1
	{

		MB_Indirecto1();
		MB_Indirecto1(int);
		char* indirecto1;

		char* toCharIn1();
		void fromCharIn1(char*);
		int getSizeBI1();
	};


	class MB_Indirecto2 {
	public:
		MB_Indirecto2();
		MB_Indirecto2(int);
		char* indirecto2;

		char* toCharIn2();
		void fromCharIn2(char*);

		int getSizeBI2();
	};


	class MB_Indirecto3
	{
	public:
		MB_Indirecto3();
		MB_Indirecto3(int);
		char* indirecto3;

		char* toCharIn3();
		void fromCharIn3(char*);

		int getSizeBI3();
	};



	MapaBits();
	MapaBits(int);
	void leerMapaBits(char, int, int, int, int);
	
	char* toChar();
	char* toCharBD();
	char* toCharIn1();
	char* toCharIn2();
	char* toCharIn3();

	int getSizeBD();
	int getSizeBI1();
	int getSizeBI2();
	int getSizeBI3();

	void fromChar(char*);
	int getSizeOf();
	void  imprimirMapa();
	void crearMapaBits();

	char* ptrsCombinados;
	char* bloque1, * bloque2, * bloque3, * bloque4;

	DataFile* file;
	MB_BloqueDirecto* dir;
	MB_Indirecto1* ind1;
	MB_Indirecto2* ind2;
	MB_Indirecto3* ind3;



	//DataFile
};


