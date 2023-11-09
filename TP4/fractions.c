#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct fraction {
    int denominateur;
    int numerateur;
} fraction_t;


int main() {
    
    char *operator;
    int t, pgcd;
    fraction_t first_frac, second_frac, result, copy_frac;

    printf("[+]: Saisissez une fraction: ");
    scanf("%d/%d", &first_frac.numerateur, &first_frac.denominateur);

    assert(first_frac.denominateur != 0);

    printf("[+]: Saisissez la seconde fraction: ");
    scanf("%d/%d", &second_frac.numerateur, &second_frac.denominateur);
    assert(second_frac.denominateur != 0);

    printf("[+]: Saisissez un opérateur: ");
    scanf("%s", operator);
    assert(strlen(operator) == 1);
    printf("operateur: %s", operator);

    if (strcmp(operator, "+") == 0) result = (fraction_t){((first_frac.numerateur * second_frac.denominateur) + (second_frac.numerateur * first_frac.denominateur)), (first_frac.denominateur * second_frac.denominateur)};
    else if ((strcmp(operator, "-") == 0)) result = (fraction_t){((first_frac.numerateur * second_frac.denominateur) - (second_frac.numerateur * first_frac.denominateur)), (first_frac.denominateur * second_frac.denominateur)};
    else if ((strcmp(operator, "*") == 0)) result = (fraction_t){(first_frac.numerateur * second_frac.numerateur), (first_frac.denominateur, second_frac.denominateur)};
    else if ((strcmp(operator, "/") == 0)) result = (fraction_t){(first_frac.numerateur * second_frac.denominateur), (first_frac.denominateur * second_frac.numerateur)};
    else printf("Erreur.\n");

    copy_frac = (fraction_t){result.denominateur, result.numerateur};
    printf("[+]: Vous avez saisit: %d/%d\n", copy_frac.numerateur, copy_frac.denominateur);
    
    do {

        t = copy_frac.denominateur;
        copy_frac.denominateur = copy_frac.numerateur % copy_frac.denominateur;
        copy_frac.numerateur = t;
    } while (copy_frac.denominateur != 0);

    pgcd = copy_frac.numerateur;
    printf("[+]: PGCD: %d\n", pgcd);
    printf("[+]: La fraction simplifié est: %d/%d\n", (result.denominateur/pgcd), (result.numerateur/pgcd));
    return 0;
}
