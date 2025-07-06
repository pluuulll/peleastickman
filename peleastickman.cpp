#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Jugador {
    string nombre;
    int vida;
    int victorias;
};

// Mostrar barra de vida
void mostrarVida(const Jugador& j) {
    cout << j.nombre << " [";
    for (int i = 0; i < j.vida / 10; ++i) cout << "#";
    for (int i = 0; i < 10 - j.vida / 10; ++i) cout << ".";
    cout << "] " << j.vida << " HP" << endl;
}

// Mostrar personajes stickman
void mostrarPersonajes() {
    cout << "\n    PLAYER 1        VS        ENEMIGO\n";
    cout << "     O-|-<                    >-|–O   \n";
    cout << "     / \\                      / \\     \n";
}

// Turno del jugador
void turnoJugador(Jugador& player, Jugador& enemigo) {
    int opcion;
    cout << "\n🎮 Turno de " << player.nombre << endl;
    cout << "1. Atacar\n2. Defender\n3. Curarse\n> ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "💥 " << player.nombre << " ataca con un palo volador!\n";
            enemigo.vida -= 15 + rand() % 6; // 15-20 daño
            break;
        case 2:
            cout << "🛡️ " << player.nombre << " se defiende. (efecto visual, sin impacto real aún)\n";
            break;
        case 3: {
            int curar = 10 + rand() % 11; // 10 a 20
            player.vida += curar;
            if (player.vida > 100) player.vida = 100;
            cout << "✨ " << player.nombre << " se cura " << curar << " puntos de vida.\n";
            break;
        }
        default:
            cout << "❌ Opción inválida. Pierdes el turno.\n";
            break;
    }
}

// Turno enemigo con IA aleatoria
void turnoEnemigo(Jugador& enemigo, Jugador& player) {
    int accion = rand() % 2;
    if (accion == 0) {
        cout << "💥 " << enemigo.nombre << " contraataca brutalmente!\n";
        player.vida -= 10 + rand() % 11;
    } else {
        int curar = 5 + rand() % 11;
        enemigo.vida += curar;
        if (enemigo.vida > 100) enemigo.vida = 100;
        cout << "✨ " << enemigo.nombre << " se cura " << curar << " puntos.\n";
    }
}

// Jugar un round
int jugarRound(Jugador& j1, Jugador& j2) {
    j1.vida = 100;
    j2.vida = 100;
    cout << "\n🎬 --- INICIA ROUND ---\n";
    while (j1.vida > 0 && j2.vida > 0) {
        mostrarPersonajes();
        mostrarVida(j1);
        mostrarVida(j2);
        turnoJugador(j1, j2);
        if (j2.vida <= 0) break;
        turnoEnemigo(j2, j1);
    }

    if (j1.vida > 0) {
        cout << "\n✅ " << j1.nombre << " gana el round!\n";
        return 1;
    } else {
        cout << "\n❌ " << j2.nombre << " gana el round!\n";
        return 2;
    }
}

// Función principal
int main() {
    srand(time(0));

    Jugador jugador1 = {"PLAYER 1", 100, 0};
    Jugador enemigo = {"ENEMIGO", 100, 0};

    int rondasGanadasJ1 = 0, rondasGanadasJ2 = 0;

    while (rondasGanadasJ1 < 2 && rondasGanadasJ2 < 2) {
        int ganador = jugarRound(jugador1, enemigo);
        if (ganador == 1) rondasGanadasJ1++;
        else rondasGanadasJ2++;

        cout << "\n📊 Marcador: " << jugador1.nombre << " " << rondasGanadasJ1
             << " - " << enemigo.nombre << " " << rondasGanadasJ2 << "\n";
        cout << "---------------------------\n";
    }

    cout << "\n🏆 ¡Juego terminado! ";
    if (rondasGanadasJ1 == 2)
        cout << "🎉 " << jugador1.nombre << " es el campeón!\n";
    else
        cout << "💀 " << enemigo.nombre << " es el campeón!\n";

    return 0;
}
