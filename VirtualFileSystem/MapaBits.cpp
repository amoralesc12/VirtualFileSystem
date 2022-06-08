#include "MapaBits.h"

MapaBits::MB_Indirecto2::MB_Indirecto2(int numBI2) {
	indirecto2 = new char[numBI2 + 1];
	for (int i = 0; i < numBI2; i++)
	{
		indirecto2[i] = '0';
	}
	indirecto2[numBI2] = '\0';
}

char* MapaBits::MB_Indirecto2::toChar()
{
	MB_Indirecto2* ind;
	return ind->indirecto2;
}

void MapaBits::MB_Indirecto2::fromChar(char* leer)
{
	indirecto2 = leer;

}


MapaBits::MapaBits(char nombre[20]) {
	file = new DataFile(nombre);
	ptrsCombinados = new char[bloque1+bloque2+bloque3+bloque4+1];
}


MapaBits::MapaBits(char nombre[20])
{
	
	

}
void MapaBits::leerMapaBits(char nombre[20], int MBD, int MBI1, int MBI2, int MBI3)
{
	int posicionActual = sizeof(MetaData);
	file->open("r");

	MapaBits* encontrar = new MapaBits(nombre);

	encontrar->bloque1 = (((MBD / 8) % 2 == 0) ? MBD / 8 : MBD / 8 + 1);
	encontrar->bloque2 = (((MBI1 / 8) % 2 == 0) ? MBI1 / 8 : MBI1 / 8 + 1);
	encontrar->bloque3 = (((MBI2 / 8) % 2 == 0) ? MBI2 / 8 : MBI2 / 8 + 1);
	encontrar->bloque4 = (((MBI3 / 8) % 2 == 0) ? MBI3 / 8 : MBI3 / 8 + 1);


	encontrar->fromChar(file->read(posicionActual,encontrar->getSizeOf));
	posicionActual += sizeof(MetaData);
	bool encontrado;

	while (!file->iseof())
	{
		encontrar->imprimirMapa();
		encontrado = true;
		return;

		encontrar->fromChar(file->read(posicionActual, encontrar->getSizeOf()));
		posicionActual += encontrar->getSizeOf();
	}

	if (encontrado==false)
	{
		cout << "Disco No Encontrado";

	}



}

MapaBits::MapaBits()
{
	
}

MapaBits::MapaBits(int)
{
	
}

char* MapaBits::toChar()
{
	return ptrsCombinados;
}

char* MapaBits::toCharBD()
{
	
	return dir->bloqueDirecto;

}

char* MapaBits::toCharIn1()
{
	return ind1->indirecto1;
	
}



char* MapaBits::toCharIn2()
{
	
	return ind2->indirecto2;
	
}

char* MapaBits::toCharIn3()
{
	return  ind3->indirecto3;
}

int MapaBits::getSizeBI2()
{
	
	
}

void MapaBits::fromChar(char* _combinados)
{
	ptrsCombinados = _combinados;
	ptrsCombinados[getSizeOf()] = '\0';

}

void MapaBits::imprimirMapa()
{

	cout << "Mapa {" + ptrsCombinados + "}\n";
}

void MapaBits::crearMapaBits()
{
	file->open("r");

	MapaBits* nuevo = new MapaBits(bloque1*8, bloque2*8, bloque3*8, bloque4*8);
	file->write(nuevo->toChar(),sizeof(MetaData), nuevo->getSizeOf());
	file->close();
}

char* MB_BloqueDirecto::toCharBD()
{
	return 
}

int MapaBits::MB_BloqueDirecto::getSizeBD()
{
	return 
}



char* MapaBits::MB_Indirecto1::toCharIn1()
{
	return indirecto1;
}
char* MapaBits::MB_Indirecto2::toCharIn2()
{
	return indirecto2;
}

char* MapaBits::MB_Indirecto3::toCharIn3()
{
	return indirecto3;
}


