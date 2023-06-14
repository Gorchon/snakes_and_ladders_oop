#include "Tablero.hpp"
#include "CasillaEscalera.hpp"
#include "CasillaSerpiente.hpp"
#include "Ctesconf.hpp"
#include "CasillaNormal.hpp"
#include <fstream>

// Crea un Tablero de sólo casillas Normales --------------
Tablero::Tablero()
{
    for (auto i=0; i < MAX_CASILLAS; i++)
    {
        c[i] = CasillaNormal(i+1);
    }
}

// Cargar un Tablero desde un archivo ----------------------
Tablero::Tablero(std::string f)
{
    std::ifstream tf{f};

    if (tf) {
        std::string casilla;

        for (auto i=0; i < MAX_CASILLAS; i++) {
            std::getline(tf,casilla);

            if (casilla == "N") {
                this->setCasilla(CasillaNormal(i+1), i+1);
            };

            if (casilla == "L") {
                this->setCasilla(CasillaEscalera(i+1), i+1);
            };

            if (casilla == "S") {
                this->setCasilla(CasillaSerpiente(i+1), i+1);
            };   
        }
        tf.close();
    }
    else {
        std::cerr << "Archivo de tablero no existente...\n";
    }
}

// Muestra el tablero casilla x casilla --------------------
void Tablero::print() {
    for (auto i=0; i < MAX_CASILLAS; i++)
    {
        c[i].print();
    }
}

//Inserta una casilla en una posición i -------------------
void Tablero::setCasilla(CCasilla c, int i)
{
    this->c[i-1] = c;
}

// Devuelve la casilla en la posición i --------------------
CCasilla Tablero::getCasilla(int i)
{
    return this->c[i-1];
}