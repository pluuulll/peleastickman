Cómo compilar y ejecutar

1. Guarda el archivo:

Guarda el código en un archivo llamado:
peleastickman.cpp

2. Abre la terminal y compila el juego:

g++ peleastickman.cpp -o peleastickman.exe

Este comando compila el programa y genera el ejecutable peleastickman.exe.

3. Ejecuta el juego:
   
./peleastickman.exe



Cómo jugar:
Durante la partida, controlarás a tu personaje stickman y deberás elegir una acción en cada turno: 

1 → Atacar: Inflige daño al enemigo con tu palo. 
2 → Defender: (Visual por ahora, pronto tendrá efecto real). 
3 → Curarse: Recupera entre 10 y 20 puntos de vida. 

El enemigo responde automáticamente usando una IA básica que puede atacar o curarse. El primer jugador que gane 2 rounds será el campeón del combate.
