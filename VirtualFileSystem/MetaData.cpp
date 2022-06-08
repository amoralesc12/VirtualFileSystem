#include "MetaData.h"

//prueba



MetaData::MetaData(const char*, int)
{
}

MetaData::crearDisco(int entradas, const char* nombreDisco)
{
	meta = new MetaData(nombreDisco, entradas);
	bits = new MapaBits(entradas);
	entradas = new EntradasDirectorios();


	MB_BloqueDirecto dir;
	MB_Indirecto1 indirecto1;
	MB_Indirecto2 indirecto2;
	MB_Indirecto3 indirecto3;


	int directo = 32768 * entradas;
	int ind1 = 2648 * entradas;
	int ind2 = 64 * entradas;


	file = new DataFile(nombreDisco);
	file->open("w");
	file->write(meta->toChar(), 0, sizeof(MetaData));
	file->write(bits->toCharBD(), sizeof(MetaData)+ bits->ind2->getSizeBI2());
	
}
