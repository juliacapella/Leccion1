
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <ctype.h>
#include <mysql.h>



int main(int argc, char **argv)
{

    
    
    
    
    int sock_conn, sock_listen, ret;
    struct sockaddr_in serv_adr;
    char peticion[512];
    char respuesta[512];
    // INICIALITZACIONS
    // Obrim el socket
    if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("Error creant socket");
    
    memset(&serv_adr, 0, sizeof(serv_adr));// inicialitza a zero serv_addr
    serv_adr.sin_family = AF_INET;
    
    // asocia el socket a cualquiera de las IP de la m?quina.
    //htonl formatea el numero que recibe al formato necesario
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    // establecemos el puerto de escucha
    serv_adr.sin_port = htons(9200);
    if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0)
        printf ("Error al bind");
    if (listen(sock_listen, 3) < 0)
        printf("Error en el Listen");
    
    int i;
    // Bucle infinito
    for (;;){
        printf ("Escuchando\n");
        
        sock_conn = accept(sock_listen, NULL, NULL);
        printf ("He recibido conexion\n");
        //sock_conn es el socket que usaremos para este cliente
        
        int terminar =0;
        // Entramos en un bucle para atender todas las peticiones de este cliente
        //hasta que se desconecte
        while (terminar ==0)
        {
            // Ahora recibimos la petici?n
            ret=read(sock_conn,peticion, sizeof(peticion));
            printf ("Recibido\n");
            peticion[ret]='\0';
            printf ("Peticion: %s\n",peticion);
            
            // vamos a ver que quieren
            char *p = strtok( peticion, "/");
            int codigo =  atoi (p);
            // Ya tenemos el c?digo de la petici?n
            
            char respuesta[100];
            //C\ufff3digo 1: petici\ufff3n de log in.
            if (codigo ==1)
            {
                char nombre=strtok(peticion,"/");
                int longitud = strlen(nombre);
                 
                // Si tiene un carácter será palíndromo
                if (longitud <= 1) {
                    strcpy(respuesta, "SI");
                    
                }
                else{
                // Comenzamos en el inicio y fin de la cadena
                    int inicio = 0,
                    int fin = longitud - 1;
                    int pali=0;
                 
                    // Mientras el primer y último carácter sean iguales
                    while (cadena[inicio] == cadena[fin] && pali==0){
                    // Aquí sólo resta un carácter por comparar, eso indica que SÍ es palíndroma
                        if (inicio >= fin)
                            pali=1;
                            
                    
                        inicio++;
                        fin--;
                    }
                    if (pali==0){
                        strcpy(respuesta, "NO");
                        
                    }
                    else{
                        strcpy(respuesta, "SI")
                    }
               
                    
            }
            }
            if(codigo==2){
                char convertir=strtok(peticion,"/");
                // Convertir cada char a mayúscula
                    // usando toupper
                    for (int indice = 0; convertir[i] != '\0'; ++i){
                        convertir[i] = toupper(convertir[i]);
                    }
                strcpy(respuesta, convertir);
            }
            write (sock_conn,respuesta, strlen(respuesta));
        }
    }
}
