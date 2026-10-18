#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Pokemon {
    string numero;
    string nombre;
    string tipo1;
    string tipo2;
    string hp;
    string ataque;
    string defensa;
};


string aMinusculas(string texto) {
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
    return texto;
}

int main() {
  
    ifstream archivo("pokedex.csv");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo pokedex.csv" << endl;
        return 1;
    }

    vector<Pokemon> pokedex;
    string linea;

   
    getline(archivo, linea);


    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Pokemon p;

   
        getline(ss, p.numero, ',');
        getline(ss, p.nombre, ',');
        getline(ss, p.tipo1, ',');
        getline(ss, p.tipo2, ',');
        getline(ss, p.hp, ',');
        getline(ss, p.ataque, ',');
        getline(ss, p.defensa, ',');

        pokedex.push_back(p);
    }
    archivo.close();


    string busqueda;
    cout << "Ingresa lo que quieres buscar (nombre, numero, tipo, vida, etc.): ";
    getline(cin, busqueda);

  
    string query = aMinusculas(busqueda);
    bool encontrado = false;

    
    for (int i = 0; i < pokedex.size(); i++) {
        Pokemon p = pokedex[i];

        if (aMinusculas(p.numero).find(query) != string::npos ||
            aMinusculas(p.nombre).find(query) != string::npos ||
            aMinusculas(p.tipo1).find(query) != string::npos ||
            aMinusculas(p.tipo2).find(query) != string::npos ||
            aMinusculas(p.hp).find(query) != string::npos ||
            aMinusculas(p.ataque).find(query) != string::npos ||
            aMinusculas(p.defensa).find(query) != string::npos) {

            cout << "\n----------------------------------------" << endl;
            cout << "Numero  : " << p.numero << endl;
            cout << "Nombre  : " << p.nombre << endl;
            cout << "Tipo 1  : " << p.tipo1 << endl;
            cout << "Tipo 2  : " << p.tipo2 << endl;
            cout << "HP      : " << p.hp << endl;
            cout << "Ataque  : " << p.ataque << endl;
            cout << "Defensa : " << p.defensa << endl;
            cout << "----------------------------------------" << endl;

            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "\nNo se encontro ningun Pokemon con ese dato." << endl;
    }

    return 0;
}