#include <stdio.h>
#include <string.h>


short int intentos;
short int victorias;
char **letrasingresadas;
char* palabraelegida;
char* palabraoculta;

int inicioJuego();
char* imprimirEstado();
int comprobarCaracter(char caracter);
/*
    Aca va el flujo general del juego 
*/
int main(){
    /// TENTATIVA DE GAMELOOP PARA SEGUIR JUGANDO
    int seguirjugando;
    while(seguirjugando){
        
        intentos = 8;
        printf("Bienvenido al juego de ahorcado!\n\n");
        if(inicioJuego()){
            printf("Una victoria  mas para la cuenta, tienes %hd de ellas.\n", ++victorias);
        }
        else {
            printf("No siempre se gana, tienes %hd victorias.\n", victorias);
        }

        printf("Quieres seguir jugando?  s / n:   ");
        char respuesta;
        scanf(" %s", &respuesta);

        if(respuesta != 's'){
            seguirjugando = 0;
        }
    }
    /// FIN DE TENTATIVA DE GAMELOOP
}
/*
    Gameloop de una instancia de partida
*/
int inicioJuego(){
    //Estas dos asignaciones deberian hacerse automaticamente, es una chambonada generar el string oculto y elegido a mano
    //El verdadero comportamiento esperado es tomar una palabra elegida de un array de palabras disponibles
    palabraelegida = strdup("arroz");
    palabraoculta = strdup("-----");

    while(intentos > 0){

        printf(imprimirEstado(), intentos, palabraoculta); //Solo se imprime el estado actual del juego antes de efectuar cualquier cosa


        //Si el palabraoculta es igual a palabraelegida, habremos ganado, se aca
        if(strcmp(palabraoculta, palabraelegida) == 0){
            printf("FELICIDADES, GANASTE CON %hd INTENTOS. \n LA PALABRA ES %s   \n", intentos, palabraelegida);
            return 1;
        }   
        

        
        
        char caracteringresado;
        printf("Ingresa un nuevo caracter:");
        scanf(" %s", &caracteringresado);
        if(comprobarCaracter(caracteringresado) == 0){
            intentos--;
        }

        
        //Recibir caracter comprobarCaracter(caracter);
        //Almacenar caracter y hacer el efecto de destapar el string oculto
    }

    return 0; // Retorno de derrota, se acabo el bucle = se acabaron los intentos, yuca
}

char* imprimirEstado(){
    char* respuesta = "\nIntentos restantes: %hd \n Palabra a adivinar: %s \n \n";
    return respuesta;
}   

int comprobarCaracter(char caracter){
    int estaenpalabra = 0;

    for(int i = 0; i < strlen(palabraelegida); i++){
        if(palabraelegida[i] == caracter){
            estaenpalabra = 1;
            palabraoculta[i] = palabraelegida[i];
        
        }
    }

    return estaenpalabra;
}

