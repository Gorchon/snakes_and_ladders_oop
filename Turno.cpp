#include "Turno.hpp"

Turno::Turno() {}

Turno::Turno(std::string turno, std::string jug_actual, std::string ca_old_jugador, std::string va_Dado_Final, std::string tipo_casilla, std::string ca_new_jugador) : turno(turno), jug_actual(jug_actual), ca_old_jugador(ca_old_jugador), va_Dado_Final(va_Dado_Final), tipo_casilla(tipo_casilla), ca_new_jugador(ca_new_jugador) {}

std::ostream& operator<<(std::ostream& out, const Turno& t) {
    out << t.turno << " " << t.jug_actual << " " << t.ca_old_jugador << " " << t.va_Dado_Final << " " << t.tipo_casilla << " " << t.ca_new_jugador;
    return out;
}