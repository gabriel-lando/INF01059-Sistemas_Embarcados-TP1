#define nroVertices 4

void Dijkstra(unsigned long int matriz[nroVertices][nroVertices]){
	int visitados[nroVertices] = { 0 };
    int i = 0, j = 0;
    int n = nroVertices;
	for(i = 1; i < n; i++){
		int min = -1;
		unsigned long int MinValor = -1;

		for(j = 1; j < n; j++){
			if( !visitados[j] && matriz[j][0] < MinValor ){
				 min = j;
				 MinValor = matriz[j][0];
			}
		}

		visitados[min] = 1;

		for(j = 1; j < n; j++){
			if( (matriz[min][0] + matriz[min][j]) < matriz[j][0] ){
				matriz[j][0] = matriz[min][0] + matriz[min][j];
			}
		}
	}
}

int main(){

	unsigned long int Matriz[nroVertices][nroVertices] = {{ 51, 87, 59, 16},
                                                        { 69, 94, 48, 41 },
                                                        { 44, 99, 90, 2},
                                                        { 56, 65, 23, 30 }};


	Dijkstra(Matriz);

	return 0;
}
