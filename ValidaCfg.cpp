#include "ValidaCfg.hpp"
#include "Ctesconf.hpp"
#include  "InvalidConfigurationException.hpp"


void validaCasillas(int numCasillas)
{
    std::string error_message;
    if (numCasillas < 2 || numCasillas > MAX_CASILLAS) {
        error_message = "Invalido numero de casillas" + std::to_string(numCasillas);
        throw InvalidConfigurationException(error_message);
    }
}

void validaJugadores(int numJugadores)
{
    std::string error_message;
    if (numJugadores < 2 || numJugadores > MAX_JUGADORES) {
        error_message = "Invalido numero de casillas" + std::to_string(numJugadores);
        throw InvalidConfigurationException(error_message);
    }
}   

void validaTurnos(int numTurnos)
{
    std::string error_message;
    if (numTurnos < 1 || numTurnos > MAX_TURNOS) {
        error_message = "Invalido numero de casillas" + std::to_string(numTurnos);
        throw InvalidConfigurationException(error_message);
    }
}

void validaCfg(int numCasillas, int numJugadores, int numTurnos)
{
    validaCasillas(numCasillas);
    validaJugadores(numJugadores);
    validaTurnos(numTurnos);
}