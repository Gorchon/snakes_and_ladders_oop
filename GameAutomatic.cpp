#include "GameAutomatic.hpp"

// Constructor por default --------------------
GameAutomatic::GameAutomatic(std::string tf, bool swa, bool swio):Game(tf, swa, swio)
{}

// Obtiene la entrada automaticamente (del mismo software) -------------------
std::string GameAutomatic::getInput()
{
    return "C";
}
