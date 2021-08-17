#include <iostream>
#include <conio.h>


using std::cout;
#define DB_AMOUNT 100

void imprimirMapa(char*);
void setOn(char*, int);
void setOff(char*, int);

int main() 
{
	char* bitmap;

	//calcular cantidad de bytes para redireccionar 100 bloques
	int cantidadBytes = DB_AMOUNT / 8;

	bitmap = new char[cantidadBytes];

	//inicializar el mb todos los bits en cero
	for (int i = 0; i < cantidadBytes; i++) 
		bitmap[i] = 0;


	cout << "Bitmap:\n";
	imprimirMapa(bitmap);

	cout << "\n";

	setOn(bitmap, 13);
	setOn(bitmap, 28);
	setOn(bitmap, 5);

	cout << "\n";

	cout << "Bitmap:\n";
	imprimirMapa(bitmap);

	cout << "\n\n";

	setOn(bitmap, 11);
	setOn(bitmap, 9);
	setOn(bitmap, 15);

	cout << "\n";

	cout << "Bitmap:\n";
	imprimirMapa(bitmap);

	cout << "\n";
	
	
	setOff(bitmap, 13);
	setOff(bitmap, 28);
	setOff(bitmap, 5);

	cout << "Bitmap:\n";
	imprimirMapa(bitmap);


	_getch();

}

void imprimirMapa(char* bitmap) 
{
	const int SHIFT = 8 * sizeof(char) - 1;
	const char MASK = 1 << SHIFT;

	for (int i = 0; i < DB_AMOUNT / 8; i++) 
	{
		char tmpByte;
		tmpByte = bitmap[i];

		for (int j = 1; j <= SHIFT + 1; j++) 
		{
			cout << (tmpByte & MASK ? '1' : '0');

			tmpByte = tmpByte << 1;

			if (j % 8 == 0)
				cout << ' ';
		}

	}


}

void setOn(char* bitmap, int nBloque)
{

	int posicionEnByte = nBloque / 8;
	int bitInicialEnByte = posicionEnByte * 8;

	for (int i = bitInicialEnByte, shift = 7; i < bitInicialEnByte + 8; i++, shift--)
	{
		if (nBloque == i)
		{
			bitmap[posicionEnByte] = bitmap[posicionEnByte] | (1 << shift);
			cout << "Bit encendido correctamente!\n";
			break;
		}

	}

}

void setOff(char* bitmap, int nBloque) 
{
	int posicionEnByte = nBloque / 8;
	int bitInicialEnByte = posicionEnByte * 8;

	for (int i = bitInicialEnByte, shift = 7; i < bitInicialEnByte + 8; i++, shift--)
	{
		if (nBloque == i)
		{
			bitmap[posicionEnByte] = bitmap[posicionEnByte] & ~(1 << shift);
			cout << "Bit apagado correctamente!\n";
			break;
		}
	}

}