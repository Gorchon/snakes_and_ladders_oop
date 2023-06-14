#include "Game.hpp"
#include "Ctesconf.hpp"
#include "Tablero.hpp"
#include "CDado.hpp"
#include "Jugador.hpp"
#include <string>
#include <sstream>
#include "Turno.hpp"

// Constructor por default --------------------------------
Game::Game()
{}

// Construye un juego configurado para dado aleatorio/no aleatorio e I/O - Consola o Archivo -----
Game::Game(std::string tf, bool swa, bool swio)
{
    this->t    = Tablero(tf);
    this->d    = CDado(swa);
    this->swio = swio;          //Switch IO: false = keyboard : true = input file

    for (auto i=0; i < MAX_JUGADORES;i++) {
        this->j[i] = Jugador(i+1);
    }
}

// Imprime un mensaje en Consola/Archivo -------------------
void Game::outMsg(std::string msg)
{
    if (!swio) {
        std::cout << msg << "\n";
    }
    else {
        fo << msg << "\n";
    }
}

// Arranca y simula el Juego --------------------------------------
void Game::start()
{
    std::string key;
    int caOldJugador;
    int turno{1};
    int jug_actual{1};
    int vaDadoFinal;
    int posFinal;
    std::string tipo_casilla;
    bool finalGame{false};

    outMsg("Press C to continue next turn, or E to end the game");

    while (!finalGame && turno <= MAX_TURNOS) {
        key = getInput();

        if (key == "C") {

            std::stringstream ss;

            vaDadoFinal = this->d.getValorDado();

            caOldJugador = j[jug_actual-1].getCasilla_actual();

            posFinal = caOldJugador+vaDadoFinal < MAX_CASILLAS ? caOldJugador+vaDadoFinal : MAX_CASILLAS;
        
            tipo_casilla = t.getCasilla(posFinal).getTipo();
            j[jug_actual-1].setCasilla_actual(t.getCasilla(posFinal).getSiguienteCasilla());

            
            Pturno = new Turno(std::to_string(turno), std::to_string(jug_actual), std::to_string(caOldJugador), std::to_string(vaDadoFinal), tipo_casilla, std::to_string(j[jug_actual-1].getCasilla_actual()));
            ss << *Pturno;

            //Turno ImplentacionTurno(std::to_string(turno), std::to_string(jug_actual), std::to_string(caOldJugador), std::to_string(vaDadoFinal), tipo_casilla, std::to_string(j[jug_actual-1].getCasilla_actual()));
            //ss << ImplentacionTurno;
            outMsg(ss.str());
            ss.str("");
            delete (Pturno);
            //outMsg<(std::to_string(>turno) + " " + std::to_string(jug_actual)+ " " +  std::to_string(caOldJugador)+" "+ std::to_string(vaDadoFinal) + " " + tipo_casilla +" "+std::to_string(t.getCasilla(j[jug_actual-1].getCasilla_actual()).getNumeroCasilla())) ;

//          std::cout << turno << " " << jug_actual << " " << caOldJugador << " " << vaDadoFinal << " " << tipo_casilla << " " << t.getCasilla(j[jug_actual-1].getCasilla_actual()).getNumeroCasilla() << "\n";

            if (j[jug_actual-1].getCasilla_actual()==MAX_CASILLAS)
            {
                outMsg("--GAME OVER--");
                outMsg("Player " + std::to_string(jug_actual)+" is the winner!!!");
//              std::cout << "--GAME OVER--" << "\n";
//              std::cout << "Player " << jug_actual << " is the winner!!!\n";
                finalGame=true;
            }
            else
            {
                turno++;
                jug_actual = (jug_actual % MAX_JUGADORES) + 1;
            }
        }
        else {
            if (key=="E") {
                outMsg("--GAME OVER--");
                outMsg("Thanks for playing");
//              std::cout << "--GAME OVER--" << "\n";
//              std::cout << "Thanks for playing \n";
                finalGame=true;
            }
            else {
                outMsg("Invalid option, please press C to continue next turn or E to end the game");
//              std::cout << "Invalid option, please press C to continue next turn or E to end the game\n";
            }
        };
    };
    if (swio) {
        fi.close();
        fo.close();
    };
}
