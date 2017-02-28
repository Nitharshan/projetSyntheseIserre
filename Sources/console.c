#include "console.h"
#include "stdlib.h"

/*
 * Affiche la cha�ne de caract�res pass�e en param�tre dans la console
 */

void afficher_chaine(char* chaine, int retourLigne) {
	debug_printf("%s", chaine);
	if (retourLigne)
		debug_printf("\n");
}

/*
 * Affiche la cha�ne de caract�res pass�e en param�tre dans la console
 * si erreur retourne -1
 */
void afficher_chaine_buffer(char *buffer, uint8_t buffer_length,
		int retourLigne) {
	for (int i = 0; i < buffer_length; i++) {
		debug_putchar(*buffer++);
	}

	if (retourLigne)
		debug_printf("\n");
}

/*
 * Affiche la cha�ne de caract�res pass�e en param�tre dans la console
 * si erreur retourne -1
 */
void afficher_hex(char *chaine, int retourLigne) {
	debug_printf("%X", chaine);

	if (retourLigne)
		debug_printf("\n");
}

/*
 * Affiche l'entier pass� en param�tre dans la console
 * si erreur retourne -1
 */
void afficher_entier(int entier) {
	debug_printf("%i", entier);
	debug_printf("\n");
}

/*
 * Lire cha�ne de caract�res de l'utilisateur.
 * La cha�ne lue est stock�e dans le pointeur pass� en param�tre.
 */
uint8_t lire_chaine(char *question, char *input_buffer, uint8_t max) {
	uint8_t nombre_carac = 0;
	int last = 0x0;
	char *buf = input_buffer;

	afficher_chaine(question, 0);

	while (1) {
		last = debug_getchar();
		debug_putchar(last);
		if (last == 0xd) {
			return nombre_carac;
		}
		nombre_carac++;
		if (nombre_carac > max) {
			debug_printf("\nVous avez saisi trop de caracteres! (Max %d)\n",
					max);
			return 0xff;
		} else {
			*buf = (char) last;
			buf++;
		}
	}
}

/*
 * Lire l'entier et l'affiche si echo_true est � vrai sinon retourne � la ligne
 */
int lire_entier() {
	char* input;
	debug_scanf("%i", &input);

	if (echo_true)
		debug_printf("%i", input); // echo

	debug_printf("\n");

	return (int) input;
}

/*
 * Lire le caract�re entr�e dans la console et l'affiche dans la console
 */
char lire_caractere() {
	debug_printf("\n");
	return (char) debug_getchar();
}
/*
 * Retourne la taille allou� par un pointeur
 */
uint8_t allocated_size(char * ptr) {
	return (uint8_t) ((strlen(ptr) + 1) * sizeof(char));
}



