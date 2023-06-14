#include "GameManual.hpp"

// Constructor por default --------------------------------
GameManual::GameManual(std::string tf, bool swa, bool swio):Game(tf, swa, swio)
{}

// Obtiene la entrada de Consola (manualmente)/Archivo -------------------
std::string GameManual::getInput()
{
    std::string key;
    if (!swio) {
            std::cin >> key;
    }
    else {
        std::getline(fi,key);
    }
    return key;
}