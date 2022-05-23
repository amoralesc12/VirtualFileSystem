#pragma once

class FileDirectory
{
private:
	struct EntradasDire_Arch
	{
		char nombreEDA[30];
		bool tipoArch_Dire; //1: archivo  0: directorio
		char fechaCreacion[8];
		unsigned int  volumen; //tama�o

		// PUNTERO Bloque de Datos, SOLO PARA LA IMPORTACION DE ARCHIVOS

		unsigned int punteroBD[12];
		unsigned int punteroBIndirectos[3]; // [0] : Nivel 1; [1] : Nivel 2; [2] : Nivel 3



	};
};

