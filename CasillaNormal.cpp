#include "CasillaNormal.hpp"
#include "CCasilla.hpp"
//Construye una Casilla Normal como una Casilla general
CasillaNormal::CasillaNormal() : CCasilla{}
{
}
//Construye una Casilla Normal asignandole un numero especifico
CasillaNormal::CasillaNormal(int numero):CCasilla{}
{
    this->numero = numero;
}