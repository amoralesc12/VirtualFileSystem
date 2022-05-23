#pragma once
class MapaBits 
{
	//TODO DEBE SER DINAMICO
	class MB_Directo
	{
		char* puntero;
		
		char* toChar();
		void fromChar(char*);
	};

	class MB_IndirectoN1
	{
		char* puntero;

		char* toChar();
		void fromChar(char*);
	};

	class MB_IndirectoN2
	{
		char* puntero;

		char* toChar();
		void fromChar(char*);
	};

	class MB_IndirectosN3
	{
		char* puntero;

		char* toChar();
		void fromChar(char*);
	};

	//TOTAL DE BYTES POR CADA MAPA DE BITS
	char* toChar();
	void fromChar(char*);
};

