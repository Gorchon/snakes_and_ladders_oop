#include "CCasilla.hpp"
#include "Ctesconf.hpp"

//Constructor por default de Casilla
CCasilla::CCasilla()
{
}

//Constructor de casilla de numero(val) y de tipo(tipo)
CCasilla::CCasilla(int val, std::string tipo)
{
    this->numero = val;
    this->tipo = tipo;
}

//Consulta el número de la Casilla
int CCasilla::getNumeroCasilla()
{
    return this->numero;
}

//Consulta el tipo de la Casilla
std::string CCasilla::getTipo()
{
    return this->tipo;
}

//Dado el tipo de Casilla Actual, determina cual sería la siguiente (después del PREMIO O CASTIGO)
//Valida que no se salga del tablero
int CCasilla::getSiguienteCasilla()
{
    int casilla_final;

    casilla_final = this->numero + this->premio_castigo;

    return casilla_final < MAX_CASILLAS ? casilla_final : MAX_CASILLAS;
}

//Muestra en Consola la casilla actual
void CCasilla::print()
{
    std::cout << this-> numero << " " << this->tipo << " " << this->premio_castigo << "\n";
}