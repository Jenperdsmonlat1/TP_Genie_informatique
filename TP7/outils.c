/* outils.c 
 * 
 * Compiler avec : 
 * gcc outils.c -Wall -W -std=c99 -I. -c
 * ar cr liboutils.a outils.o
 * ranlib liboutils.a
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <outils.h>
#include <inttypes.h>


// Initialise un vecteur vec[n] en fonction du parametre opt:
//  - MONOTONE_CR   : suite monotone croissante
//  - MONOTONE_DECR :   "      "     decroissante
//  - ALEATOIRE     :   "   de nombres aleatoires
void initialiser(int64_t n, int64_t vec[n], option_t opt)
{
	int64_t i;
	
	switch(opt) {
	case MONOTONE_CR:
		for(i=0 ; i<n ; ++i) vec[i] = i+1;	
		break;
		
	case MONOTONE_DECR:
		for(i=0 ; i<n ; ++i) vec[i] = n-i;	
		break;
	
	case ALEATOIRE:
//		srand(time(NULL));
		for(i=0 ; i<n ; ++i) vec[i] = rand();	
		break;
	}
}

// Affiche un vecteur d'entiers vec[n]
void afficherVecteur(int64_t n, int64_t vec[n])
{
	for(int64_t i=0 ; i<n ; ++i) printf("%"PRIi64"\n", vec[i]);
}

// Verifie qu'un vecteur vec[n] est bien trie'
bool verifier(int64_t n, int64_t vec[n])
{
	for(int64_t i=0 ; i<n-1 ; ++i) {
		if (vec[i] > vec[i+1]) {
			printf("Le vecteur n'est pas trié.\n");
			return false;
		}
	}
	printf("--> Le vecteur est bien trie'.\n");
	return true;
}
