#include <iostream>
#include <stdlib.h>

using namespace std;

class TicTacToe
{
	char Tablero[3][3];

public:
	TicTacToe();
	void LimpiarTablero();
	void Pintar();
	bool PonerFicha(char ficha, int fila, int columna);
	bool ComprobarFila(char ficha, int fila);
	bool ComprobarColumna(char ficha, int columna);
	bool ComprobarDiagonal(char ficha, int fila, int columna);
	bool TableroCompleto();
	void PedirPosicion(char ficha, int &fila, int &columna);

};


TicTacToe::TicTacToe()
{
	LimpiarTablero();
}

void TicTacToe::Pintar()
{
	for (int i=0; i<3; i++)
	{
    	for (int j=0; j<3; j++)
    	{
        	cout << Tablero [i][j];
        	if (j<2)
            	cout << " | ";
        	else
            	cout << endl;
    	}
    	if (i<2)
        	cout << "--+---+--" << endl;
	}
}

bool TicTacToe::PonerFicha(char ficha, int fila, int columna)
{
	bool comprobacion = false;
	if (Tablero[fila][columna] == ' ')
	{
    	Tablero[fila][columna] = ficha;
    	comprobacion = true;
	}
	return comprobacion;
}

void TicTacToe::PedirPosicion(char ficha, int &fila, int &columna)
{
	do
	{
    	cout << "Introduzca la fila: ";
    	cin >> fila;
    	if (fila > 4 || fila < 0)
            cout << "La fila introducida no es correcta." << endl;
	}
	while (fila > 4 || fila < 0);
	fila--;
	do
	{
    	cout << "Introduzca la columna: ";
    	cin >> columna;
    	if (columna > 4 || columna < 0)
            cout << "La columna introducida no es correcta." << endl;
	}
	while (columna > 4 || columna < 0);
	columna--;
}

bool TicTacToe::ComprobarFila(char ficha, int fila)
{
    bool victoria=false;
    if (Tablero[fila][0] && Tablero[fila][1] && Tablero[fila][2] == ficha)
        victoria=true;
    return victoria;
}

bool TicTacToe::ComprobarColumna(char ficha, int columna)
{
    bool victoria=false;
    if (Tablero[0][columna] == ficha && Tablero[1][columna] == ficha && Tablero[2][columna] == ficha)
        victoria=true;
    return victoria;
}

bool TicTacToe::ComprobarDiagonal(char ficha, int fila, int columna)
{
    bool victoria=false;
    if (Tablero[0][0] == ficha && Tablero[1][1] == ficha && Tablero[2][2] == ficha)
        victoria=true;
    if (Tablero[0][2] == ficha && Tablero[1][1] == ficha && Tablero[2][0] == ficha)
        victoria=true;
    return victoria;
}

void TicTacToe::LimpiarTablero()
{
	system ("cls");
	for (int i=0; i<3; i++)
    	for (int j=0; j<3; j++)
        	Tablero[i][j] = ' ';
}

bool TicTacToe::TableroCompleto()
{
	int j,i=0;
	bool lleno=true;
	while (i<3 && lleno)
	{
    	j=0;
    	while (j<3 && lleno)
    	{
    	    if (Tablero[i][j] == ' ')
                lleno=false;
            else
                j++;
    	}
    	i++;
	}
	return lleno;
}

int main()
{
	int playagain=1, turno = 0;
	char ficha;
	TicTacToe juego;
	TicTacToe.TicTacToe();
	do
	{
    	if (turno%2 == 0)
    	{
        	ficha = 'X';
        	cout << "Le toca al jugador 1 (X)" << endl;
        	juego.PedirPosicion(char ficha, int &fila, int &columna);
        	juego.PonerFicha(char ficha, int fila, int columna);
        	juego.ComprobarFila(char ficha, int fila);
        	juego.ComprobarColumna(char ficha, int columna);
        	juego.ComprobarDiagonal(char ficha, int fila, int columna);

    	}
    	else
    	{
        	ficha = 'O';
        	cout << "Le toca al jugador 2 (O)" << endl;
        	juego.PedirPosicion(char ficha, int &fila, int &columna);
        	juego.PonerFicha(char ficha, int fila, int columna);
        	juego.ComprobarFila(char ficha, int fila);
        	juego.ComprobarColumna(char ficha, int columna);
        	juego.ComprobarDiagonal(char ficha, int fila, int columna);
    	}
    	turno++;
	}
	while (!juego.TableroCompleto());
	do
    {
        cout << "Desea volver a jugar?" << endl;
        cout << "1. Si\n2. No"; << endl;
        cin >> playagain;
        if (playagain != 1 && playagain != 2)
            cout << "La eleccion no es valida.0" << endl;
        if (playagain == 1)
            TicTacToe.LimpiarTablero();
    }while (playagain != 1)
	cout << "Gracias por jugar!";
	return 0;
}

