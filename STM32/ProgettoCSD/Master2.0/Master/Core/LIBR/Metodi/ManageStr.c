/*
 * ManageStr.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Utente
 */
# include "ManageStr.h"
Stringa_TypeDef str;
Stringa_TypeDef CutString(char* buffer){

	// Troviamo l'indice dei caratteri '+' e '-' nel buffer
	    int plus_index = strchr(buffer, '+') - buffer;
	    int minus_index = strchr(buffer, '-') - buffer;

	    // Estraiamo la stringa contenente il valore della temperatura
	    char temp_str[MAX_BUFFER_LENGTH];
	    strncpy(temp_str, buffer, plus_index);
	    temp_str[plus_index] = '\0';

	    // Estraiamo la stringa contenente il valore dell'umidità
	    char hmdy_str[MAX_BUFFER_LENGTH];
	    strncpy(hmdy_str, buffer + plus_index + 1, minus_index - plus_index - 1);
	    hmdy_str[minus_index - plus_index - 1] = '\0';

	    // Estraiamo la stringa contenente il valore della modalità
	    char modo_str[MAX_BUFFER_LENGTH];
	    strncpy(modo_str, buffer + minus_index + 1, MAX_BUFFER_LENGTH - minus_index - 1);
	    modo_str[MAX_BUFFER_LENGTH - minus_index - 1] = '\0';



	   // Convertiamo le stringhe in valori di tipo float
	   float temp = atof(temp_str);
	   float hmdy = atof(hmdy_str);
	   int modo = atoi(modo_str);

	   str.Temp=temp;
	   str.Hmdy=hmdy;
	   str.Mode = modo;


return str;

}


float AdaptSetPoint(char* buffer){
	 float setPoint;

	    // Rimuovi eventuali spazi bianchi alla fine della stringa
	    char* trimmedBuffer = buffer;
	    int length = strlen(buffer);
	    while (length > 0 && trimmedBuffer[length - 1] == ' ') {
	        trimmedBuffer[length - 1] = '\0';
	        length--;
	    }

	    setPoint = atof(trimmedBuffer);

         return setPoint;


}









