/*
 */ 

#include <stdio.h>
/* Author: Simon Manning */


int main(void)
{ 

	char user_entry[200]; /* set character array to max of 200 for keyboard entry */
	int next_value = 0;   /* next spot i
n char array */
	int i = 0, k = 0;     /* while loops start positions */
	int c;               /* store next char */
	int key = 0; 	     /* key to store 8bit key */	
	int keyCopy;         /* copy of key to use OR */
	char bitInput = '0'; /* store input for 8bitkey */
	#ifdef PROMPT
	printf("Enter clear text to be encrypted, followed by the enter/return key: ");
	#endif
	while (c != '\n'){
		c = getchar(); /* reads next character of input and stoes in c */
		user_entry[next_value++] = (char)tolower(c);  
		/* sets next value in char array to lower case of next char */  
	}
	#ifdef PROMPT
	printf("Text entered is: %s", user_entry);  /* Print text entered by user */
	printf("Hex encoding is: ");
	while(user_entry[i] != '\n') { 
		if( (i)%10 == 0){		/* making spacing 10 hexidecimals per row */
			printf("\n");
		}
		printf("%02x ", user_entry[i++]); /* print hexidecimal of each entry of cleartext */ 
	}
	printf("\nenter 4-bit key: ");
	#endif
	while(bitInput != '\n') {
		key <<= 1;         /* shift 8bit to the left 1 */
		key += (bitInput - '0'); /* add bit input to 8bit key*/
 		bitInput = getchar(); /* read next 4bit key entry */
	}
	keyCopy = key; /*make copy of key*/
	key <<= 4; /* shift 8bit key left 4 */
	key = keyCopy | key; /* OR the copy of key and key to get final 8bit key */
		
	#ifdef PROMPT
	printf("Hex ciphertext is: ");
	#endif 
	while(user_entry[k] != '\n') {
		/*if((k%10) == 0) {       
			printf("\n");
		}*/
		printf("%02x ", (key ^ user_entry[k++])); /* XOR key with each cleartext entry */
	}
	printf("\n");

	return 0;
}
		
		

		

