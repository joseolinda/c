#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimir_submatriz(int **matriz, int inicioLinha, int inicioColuna, int fimLinha, int fimColuna) {
    for (int i = inicioLinha; i < fimLinha; i++) {
        for (int j = inicioColuna; j < fimColuna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

/*
int e_super_legal(int **matriz, int inicioLinha, int inicioColuna, int fimLinha, int fimColuna) {
	return matriz[inicioLinha][inicioColuna] + matriz[fimLinha][fimColuna] <= matriz[inicioLinha][fimColuna] + matriz[fimLinha][inicioColuna];
}
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    int L, C;
    
    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &L, &C);
    int matriz[L][C];
    
    
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    int totalmente_super_legal = 1;
    int maior = 0;

    int *p_matriz[L];
    for (int i = 0; i < L; i++) {
        p_matriz[i] = matriz[i];
    }


    for (int inicioLinha = 0; inicioLinha < L - 1; inicioLinha++) {
        for (int inicioColuna = 0; inicioColuna < C - 1; inicioColuna++) {
            
            for (int fimLinha = inicioLinha + 2; fimLinha <= L; fimLinha++) {
                for (int fimColuna = inicioColuna + 2; fimColuna <= C; fimColuna++) {
                    // Extrair e verificar as submatriz
                    imprimir_submatriz(p_matriz, inicioLinha, inicioColuna, fimLinha, fimColuna);
                    int dp = p_matriz[inicioLinha][inicioColuna] + p_matriz[fimLinha][fimLinha];
                    int ds = p_matriz[inicioLinha][fimColuna] + p_matriz[fimLinha][inicioColuna];
                    printf("DP: %d + %d = %d   DS: %d + %d = %d\n\n", p_matriz[inicioLinha][inicioColuna], p_matriz[fimLinha][fimLinha], dp, p_matriz[inicioLinha][fimColuna], p_matriz[fimLinha][inicioColuna], ds);
                    int dimensao = fimLinha * fimColuna;
                    // int super = p_matriz[inicioLinha][inicioColuna] + matriz[fimLinha][fimColuna] <= matriz[inicioLinha][fimColuna] + matriz[fimLinha][inicioColuna];
                    if ( dp <= ds ) {
                    	if (maior < dimensao) maior = dimensao;
                    	printf("Essa submatriz é superlegal.\n\n");
					} else {
						totalmente_super_legal = 0;
						printf("Essa submatriz NÃO é superlegal.\n\n");
					}
                }
            }
        }
    }
    
    if (totalmente_super_legal == 1) maior = L * C;
    
    printf("Maior quantidade de elementos da maior submatriz superlegal: %d", maior);

    printf("\n\n");
    imprimir_submatriz(p_matriz, 0, 0, 3, 3);
    
    free(p_matriz);

    return 0;
}
