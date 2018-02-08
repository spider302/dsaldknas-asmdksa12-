#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

// Funcion para guardar datos en un archivo
void save_file(string data,string file);

// Funcion para cargar los datos en un arreglo
void load_data(short* Data,string file,int size);

// Funcion para convertir un arreglo de Hexadecimal a binario
string binToHexa(string sHex);

// Funcion para extraer un hexadecimal del arreglo
string extractHex(const short ValHexa[]);

// Funciones para imprimir la priodidad y tos del paquete.
void print_priodidad(const string &Priodidad);
void print_tos(const string &Tos);

// funciones para printear los datos
void print_MACo(short Data[]);
void print_MACd(short Data[]);
void print_Type(short Data[]);
void print_IHLandVersion(short Data[]);
void print_priodidadAndTos(short Data[]);
void print_longitud(short Data[]);

int main()
{
    save_file("00 80 5f 18 10 15 00 a0 24 57 75 ba 08 00 45 00 00 60 21 08","_cabezera.txt");
    short Direccion[17];
    load_data(Direccion,"_cabezera.txt",17);

    print_MACo(Direccion);
    cout << endl;
    print_MACd(Direccion);
    cout << endl;
    print_Type(Direccion);
    cout << endl;
    print_IHLandVersion(Direccion);
    cout << endl;
    print_priodidadAndTos(Direccion);
    cout << endl;
    print_longitud(Direccion);
    return 0;
}

void save_file(string data,string file)
{
    ofstream make_file("_cabezera.txt");
    make_file << data;
    make_file.close();
}

void load_data(short* Data,string file,int size)
{
    ifstream load_cabe("_cabezera.txt");
    for(short i = 0; i <= size; ++i)
            load_cabe >> hex >> Data[i];
    load_cabe.close();
}

string binToHexa(string sHex)
{
	string sReturn = "";
	for (int i = 0; i < sHex.length (); ++i)
		{
		switch (sHex [i])
			{
			case '0': sReturn.append ("0000"); break;
			case '1': sReturn.append ("0001"); break;
			case '2': sReturn.append ("0010"); break;
			case '3': sReturn.append ("0011"); break;
			case '4': sReturn.append ("0100"); break;
			case '5': sReturn.append ("0101"); break;
			case '6': sReturn.append ("0110"); break;
			case '7': sReturn.append ("0111"); break;
			case '8': sReturn.append ("1000"); break;
			case '9': sReturn.append ("1001"); break;
			case 'a': sReturn.append ("1010"); break;
			case 'b': sReturn.append ("1011"); break;
			case 'c': sReturn.append ("1100"); break;
			case 'd': sReturn.append ("1101"); break;
			case 'e': sReturn.append ("1110"); break;
			case 'f': sReturn.append ("1111"); break;
		}
	}
	return sReturn;
}

string extractHex(const short ValHexa[])
{
	stringstream TempHex;
	TempHex << ValHexa[15];
	string BinArrays ( TempHex.str() );
	// Si al momento de cargar el valor en Hexa a la variable, esta sólo tiene un 0, le agregamos otro
	if(BinArrays == "0")
		BinArrays.append("0");
	BinArrays = binToHexa(BinArrays);
	return BinArrays;
}

void print_priodidad(const string &Priodidad)
{
	if(Priodidad == "111")
    	cout << "Control de red";
    else if(Priodidad == "110")
    	cout << "Control de algo";
    else if(Priodidad == "101")
    	cout << "Critico";
    else if(Priodidad == "100")
    	cout << "Flash outline";
    else if(Priodidad == "011")
    	cout << "Flash";
    else if(Priodidad == "010")
    	cout << "Inmediato";
    else if(Priodidad == "001")
    	cout << "Priodidad";
    else if(Priodidad == "000")
    	cout << "Rutina";
}

void print_tos(const string &Tos)
{
	if(Tos == "1000")
		cout << "Maxima";
	else if(Tos == "0100")
		cout << "Maxima Densidad de flujo";
	else if(Tos == "0010")
		cout << "Maxima Fiabilidad";
	else if(Tos == "0010")
		cout << "Max. Densidad de flujo";
	else if(Tos == "0000")
		cout << "Normal";	
}

void print_MACo(short Data[])
{
    cout << "MACo : " << hex << Data[0]
        << ":" << hex << Data[1] <<
        ":" << hex << Data[2] <<
        ":" << hex << Data[3] <<
        ":" << hex << Data[4] <<
        ":" << hex << Data[5];
}

void print_MACd(short Data[])
{
        cout << "MACd : " << hex << Data[6]
        << ":" << hex << Data[7] <<
        ":" << hex << Data[8] <<
        ":" << hex << Data[9] <<
        ":" << hex << Data[10] <<
        ":" << hex << Data[11];
}

void print_Type(short Data[])
{
    cout << "Tipo :";
    switch(Data[12])
    {
        case 0x08:
            if(Data[13] == 0x00)
                cout << " IP";
            else if(Data[13] == 0x06)
                cout << " ARP";
        break;
        case 0x80:
            if(Data[13] == 0x35)
                cout << " RARP";
        break;
        default:
            cout << " Tipo no encontrado";
    }
}

void print_IHLandVersion(short Data[])
{

    stringstream ss;
    ss<< hex << Data[14]; // int decimal_value
    string res ( ss.str() );
    cout << "Version : " << res[0] << endl;
    cout << "IHL : " << dec << (res[0] - '0') * (res[1] - '0');
}

void print_priodidadAndTos(short Data[])
{
	string Binarie;
    Binarie = extractHex(Data);
	cout << "Presedente : ";
    print_priodidad(Binarie.substr(0,3));
	cout << "\nTos : ";
	print_tos(Binarie.substr(3,4));
}

void print_longitud(short Data[])
{
    short Longitud;
 	stringstream TempHex;
    // Cargamos en ss los en hexa
    TempHex << hex << Data[16] << hex << Data[17];
    TempHex >> Longitud;
    cout << "Tamanio del paquete : " << dec << Longitud << " bits";
}

