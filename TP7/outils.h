/* outils.h */

#ifndef __OUTILS__
#define __OUTILS__

#include <stdbool.h>
#include <inttypes.h>

// Definition du type enumere' option_t
typedef enum {
	MONOTONE_CR,
	MONOTONE_DECR,
	ALEATOIRE
} option_t;

void initialiser(int64_t n, int64_t vec[n], option_t opt);
void afficherVecteur(int64_t n, int64_t vec[n]);
bool verifier(int64_t n, int64_t vec[n]);

#endif

