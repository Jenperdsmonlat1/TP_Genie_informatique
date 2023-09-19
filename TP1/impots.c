#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {

	float result;
	unsigned int salaire;

	if (argc < 2) {

		printf("[+]: Erreur, vous devez saisir: ./impots <salaire>\n");
		return -1;
	} else {

		salaire = atoi(argv[1]);
		if (salaire <= 9690) result = 0;
		else if (salaire > 9690 && salaire <= 26764) result = salaire * 0.14;
		else if (salaire > 26764 && salaire <= 71754) result = (26764 - 9690) * 0.14 + (salaire - 26764) * 0.3;
		else if (salaire > 71754 && salaire <= 151956) result = (26764 - 9690) * 0.14 + (71754 - 26764) * 0.3 + (salaire - 71754) * 0.41;
		else result = (26764 - 9690) * 0.14 + (71754 - 26764) * 0.3 + (151956 - 71754) * 0.41 + (salaire - 151956) * 0.45;
	}

	printf("[+]: Vous devez payer %.2f€ d'impôts\n", result);

	return 0;
}
