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

// funciones para printear los datos
void print_MACo(short Data[]);
void print_MACd(short Data[]);
void print_Type(short Data[]);
void print_IHLandVersion(short Data[]);

void returnBinarie(short Hexa,short binaries_1[],short binaries_2){
    switch(Hexa)
    {
        case 0x00000000:
            for(short i = 0; i <= 3; ++i) binaries[i] = 0;
            for(short j = 0;  <= 3)
    }
}

void print_priodidad(short Data[])
{
    short binaries_1[4];
    short binaries_2[4];

    returnBinarie(Data[15],binaries_1);

    for(int i = 0; i <= 7; ++i)
        cout << binaries_1[i];

    cout << hex << Data[16];
}





int main()
{
    save_file("00 80 5f 18 10 15 00 a0 24 57 75 ba 08 00 45 00 00","_cabezera.txt");
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
    print_priodidad(Direccion);
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
