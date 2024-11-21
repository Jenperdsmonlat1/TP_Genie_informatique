#ifndef _STRUCTURE_H
#define _STRUCTURE_H


#include <stdint.h>

typedef struct {
    
    char jour[8], date[8], horaire[8];
} creneau_t;

typedef struct {
    
    char nom[12];
    uint16_t dispo;
} participant_t;

#endif
