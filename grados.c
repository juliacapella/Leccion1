#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc, char *argv[]) {
	
	int sock_conn, sock_listen, ret;
	struct sockaddr_in serv_adr;
	char peticion[512];
	
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
	serv_adr.sin_port = htons(9100);
	if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0)
		printf ("Error al bind");
	if (listen(sock_listen, 3) < 0)
		printf("Error en el Listen");
	
	int i;
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
			
			char *p = strtok( peticion, "/");
			printf ("Peticion: %s\n",p);
			
			int codigo =  atoi (p);
			
			// Ya tenemos el c?digo de la petici?n
			if (codigo ==0) //petici?n de desconexi?n
				terminar=1;
			
			if (codigo==1){
				p=strtok(peticion, "/");
				int grados=atoi(p);
				char respuesta[10];
				float nuevo=(grados-32)*5/9;
				sprintf(respuesta, "%g",nuevo);
				
				printf ("Respuesta: %s\n", respuesta);
				sprintf(respuesta, "%s%s", respuesta, "\n");
				
				// Enviamos respuesta
				write (sock_conn,respuesta, strlen(respuesta));
				
			}
			if (codigo==2){
				p=strtok(peticion, "/");
				int grados=atoi(p);
				char respuesta[10];
				float nuevo=(grados*9/5)+32;
				sprintf(respuesta, "%g",nuevo);
				printf ("Respuesta: %s\n", respuesta);
				sprintf(respuesta, "%s%s", respuesta, "\n");
				
				// Enviamos respuesta
				write (sock_conn,respuesta, strlen(respuesta));
				
			}
		}
}}

