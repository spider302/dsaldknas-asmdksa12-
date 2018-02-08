#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Funcion para guardar datos en un archivo
void save_file(string data,string file);

// Funcion para cargar los datos en un arreglo
void load_data(short* Data,string file,int size);

// funciones para printear los datos
void print_MACo(short Data[]);
void print_MACd(short Data[]);
void print_Type(short Data[]);

int main()
{
    save_file("00 80 5f 18 10 15 00 a0 24 57 75 ba 08 00","_cabezera.txt");
    short Direccion[14];
    load_data(Direccion,"_cabezera.txt",14);
    
    print_MACo(Direccion);
    cout << endl;
    print_MACd(Direccion);
    cout << endl;
    print_Type(Direccion);
    return 0;
}

void save_file(string data,string file)
{
    ofstream make_file(file);
    make_file << data;
    make_file.close();
}

void load_data(short* Data,string file,int size)
{
    ifstream load_cabe(file);
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
