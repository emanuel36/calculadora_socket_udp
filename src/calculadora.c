#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculadora(char *buffer){
	int i, contador = 0;
	
	//aux1,aux2,aux
	char aux[4096];
	float num1, num2;

	strcpy(aux, buffer);

	for(i = 0; aux[i] != '\0'; i++){
		if(aux[i] == ','){
			aux[i] = '\0';
			break;
		}
		contador++;
	}

	num1 = atof(aux);
	
	contador++;
	strcpy(aux, &buffer[contador]);	

	for(i = 0; aux[i] != '\0'; i++){
		if(aux[i] == ','){
			aux[i] = '\0';
			break;
		}
		contador++;
	}

	num2 = atof(aux);
	
	contador++;
	strcpy(aux, &buffer[contador]);
	char resultado[4096];
	float resul = 0;
	
	if((strcmp(aux, "sum")) == 0){
		resul = num1 + num2;
	}else if((strcmp(aux, "sub")) == 0){
		resul = num1 - num2;
	}else if((strcmp(aux, "mul")) == 0){
		resul = num1 * num2;
	}else if((strcmp(aux, "div")) == 0){
		if(num2 == 0){
			strcpy(buffer, "Operação Inválida!");
		}
		resul = num1 / num2;
	}
	sprintf(resultado, "%.2f" ,resul);
	
	//printf("Resultado do resultado %s\n", resultado);
	if(!((strcmp(aux, "div") == 10) && num2 == 0)){
		strcpy(buffer, resultado);
	}
}