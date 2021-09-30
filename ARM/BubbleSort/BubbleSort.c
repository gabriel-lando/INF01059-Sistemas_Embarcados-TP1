#define TAM 50 //Quantidade de numeros do array.

int main(){
	int i, j, aux;
	int vetor[TAM] = {36, 41, 89, 68, 17, 64, 89, 20, 1, 48, 86, 49, 43, 82, 53, 31, 75, 66, 43, 89, 88, 28, 94, 38, 41, 12, 8, 8, 69, 60, 28, 7, 54, 95, 53, 58, 70, 69, 15, 44, 53, 54, 93, 18, 89, 68, 37, 96, 93, 64};

	for (i = 1; i < TAM; i++) {
		for (j = 0; j < TAM - 1; j++) {
			if (vetor[j] > vetor[j+1]) {
				aux	= vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}

    return 0;
}
