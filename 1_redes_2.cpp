#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Ip = 0x0800;

int main()
{
    short Direccion[14] = {};

    ifstream load_cabe("_cabezera.txt");
    for(short i = 0; i <= 14; ++i)
            load_cabe >> hex >> Direccion[i];
    load_cabe.close();

    cout << "MACo : ";
    for(short j = 0; j <= 5; ++j)
        cout << hex << Direccion[j] << ":";
    cout << "\nMACd : ";
    for(short j = 6;  j <= 10; ++j)
        cout << hex << Direccion[j] << ":";
    cout << "\nTipo : ";
    switch(Direccion[12])
    {
        case 0x08:
            if(Direccion[13] == 0x00)
                cout << " IP";
            else if(Direccion[13] == 0x06)
                cout << " ARP";
        break;
        case 0x80:
            if(Direccion[13] == 0x35)
                cout << " RARP";
        default:
            cout << " Tipo no encontrado";
    }
    /*ofstream make_cabe("_cabezera.txt");
    make_cabe << hex << 0x10 << " " << hex << 0x80 << " "
              << hex << 0x57 << " " << hex << 0x18 << " "
              << hex << 0x10 << " " << hex << 0x15;
    make_cabe.close();*/

    //ifstream Cabezera("_cabezera.txt");
    // leer
    //getline(Cabezera)

    /*
    cout << hex << MACo;
    string tamano;

    // Crear archivo
    ofstream fs("nombre.txt");
    // Escribir
    fs << "Hola mundo" << endl;
    // Cerrar
    fs.close();

    ifstream fe("nombre.txt");
    // Leer
    getline(fe,tamano);
    cout << tamano << endl;
    fe.close();*/
    return 0;
}
