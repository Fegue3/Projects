#include <stddef.h>
#include "functions-team-20.h"
//1-Cálculo	da multiplicação de todos os elementos no vetor;
//
int multiplicacaoVetor(int vetor[], int tamanho) 
{
    int multiplicacao = 1;

    for (int i = 0; i < tamanho; i++) {
        multiplicacao *= vetor[i];
    }
	printf("\nMultiplicacao dos numeros: %d\n", multiplicacao);
}
//
//2-Identificação do máximo de todos os elementos do vetor;
//
int valorMaximo(int vetor[], int tamanho) 
{
    // O máximo vai começar por ser o primeiro elemento do vetor
    int maximo = vetor[0];
	
    for (int i = 1; i < tamanho; ++i) {
        if (vetor[i] > maximo) {
            maximo = vetor[i];
        }
    }

     printf("\nO valor maximo do vetor: %d\n", maximo);
}
//
//3-Devolução da soma dos valores do vetor que são divisíveis por três;
//
int somaDivisiveisPorTres(int vetor[], int tamanho) 
{
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 3 == 0) {
            soma += vetor[i];
        }
    }
    printf("Soma dos valores divisiveis por 3: %d\n", soma);
}
//
//4-Devolução do vetor ordenado por ordem crescente dos seus valores simétricos;
//
void ordenarcrescenteSimetricos(int vetor[], int tamanho) 
{
    int simetricos[tamanho]; // Vetor para armazenar os simétricos
    for (int i = 0; i < tamanho; i++) {
        simetricos[i] = -vetor[i];
    }

    // Ordena os valores simétricos em ordem crescente
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (simetricos[j] > simetricos[j + 1]) {
                int temp = simetricos[j];
                simetricos[j] = simetricos[j + 1];
                simetricos[j + 1] = temp;
            }
        }
    }

    // Mostra o resultado
    printf("Vetor ordenado dos valores simetricos:\n ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", simetricos[i]);
    }
    printf("\n");
}
//
//5-Construção de uma matriz 10 por 10, em que cada linha é composta pelo vetor lido(primeira linha) e por permutações dos seus valores(outras linhas);
//

//Trocar a posição de 2 valores
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para gerar permutações
void criarPermutation(int vetor[], int n) {
    int i;
    for (i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&vetor[i], &vetor[j]);
    }
}

//Faz a permutação na matriz
void fazerpermutacaoMatriz(int vetor[], int matriz[][TAMANHO_VETOR]) {
    int i, j, k;
    for (i = 0; i < TAMANHO_VETOR; i++) {
        // Se for a primeira linha, copia o vetor
        if (i == 0) {
            for (j = 0; j < TAMANHO_VETOR; j++) {
                matriz[i][j] = vetor[j];
            }
        }
        // Senão, cria permutações nas outras linhas a partir da primeira
        else {
            int permutacao[TAMANHO_VETOR];
            for (k = 0; k < TAMANHO_VETOR; k++) {
                permutacao[k] = matriz[i - 1][k];
            }
            criarPermutation(permutacao, TAMANHO_VETOR);
            for (j = 0; j < TAMANHO_VETOR; j++) {
                matriz[i][j] = permutacao[j];
            }
        }
    }
    // print da matriz
    for (i = 0; i < TAMANHO_VETOR; i++) {
        for (j = 0; j < TAMANHO_VETOR; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//
//6-Cálculo do logaritmo (base natural) de todos os elementos no vetor.
//
void calcularLogNaBaseNatural(int vetor[], int tamanho) 
{
	printf("\nCalculo dos logaritmos: \n");
	for (int i = 0; i < tamanho; ++i) {
		if (vetor[i] > 0) {
            float resultado = log(vetor[i]);
            printf("log(%d) = %.2f\n", vetor[i], resultado);
        } else {
            printf("Nao e possivel calcular o logaritmo %d \n", vetor[i]);
        }
    }
}
//
//7-Página de Ajuda
void mostrarAjuda() {
    printf("\n---------------------------------------------------- Pagina de Ajuda ---------------------------------------------------\n\n");
    printf("Este programa solicita 10 numeros inteiros no intervalo de -10 a 16, e organiza-os em um vetor 1x10.\nEm seguida apresenta um menu que oferece varias opcoes\nSendo a primeira opcao calcular a multiplicacao dos elementos no vetor\nA segunda opcao ver o maximo dos elementos do vetor\nA terceira opcao a soma dos valores do vetor divisiveis por tres\nA quarta opcao ordenadar o vetor por ordem crescente dos seus valores simetricos\nA quinta opcao a construção de uma matriz 10x10 onde da segunda linha para a frente sao permutacoes da primeira linha\nA sexta opcao o calculo do logaritmo de todos os elementos no vetor\n.gvg.\nA oitava opcao ler um novo vetor 1x10 e misturar a metade do vetor inicial com o vetor criado\nA nona opcao calcular o maximo divisor comum de cada dois numero seguidos\nA decima opcao gerar um vetor novo 1x10 aleatorio e calcular o produto do vetor inical com o vetor aleatorio\nE por fim a decima primeira opcao o calculo da matriz transposta referida na decima opcao.\n\n");
    printf("----------------------------------------------------  Fim da pagina  ---------------------------------------------------\n");
}
//
//8-Leitura de um novo vetor, e devolução de um  vetor que  mistura  metade do primeiro vetor e metade do segundo;
//
void misturarVetores(int vetor[], int vetor_novo[], int vetorMisturado[]) {
 

    for (int i = 0; i < TAMANHO_VETOR; i++) {
        do {
            printf("Digite o %d numero inteiro entre -10 e 16 do novo vetor: ", i + 1);
            scanf("%d", &vetor_novo[i]);

            if (vetor_novo[i] < -10 || vetor_novo[i] > 16) {
                printf("Por favor, digite um numero entre -10 e 16.\n");
            }
        } while (vetor_novo[i] < -10 || vetor_novo[i] > 16);
    }

    for (int i = 0; i < TAMANHO_VETOR / 2; i++) {
        vetorMisturado[i] = vetor[i];
    }

    for (int i = TAMANHO_VETOR / 2; i < TAMANHO_VETOR; i++) {
    vetorMisturado[i] = vetor_novo[(i - TAMANHO_VETOR / 2)];
}
printf("Vetor Misturado: ");
for (int i = 0; i < TAMANHO_VETOR; i++) {
    printf("%d ", vetorMisturado[i]);
}
printf("\n");
}


//9-Cálculo do máximo divisor comum de cada dois números seguidos do vetor;
//
// Função para calcular o MDC 
int calcularMDC(int a, int b) {
    int temp;
    int maior;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
        maior = fabs(a); //fabs= módulo
    }
    return maior;
}

// Função para calcular o MDC de cada par consecutivo no vetor
void calcularMDCVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int mdc = calcularMDC(vetor[i], vetor[i + 1]);
        printf("MDC(%d, %d) = %d\n", vetor[i], vetor[i + 1], mdc);
    }
}
//

//10- Geração  de  um  novo  vetor  1x10   aleatório,  cálculo  e  devolução  da matriz 10x10 resultante do produto do vetor inicial com o novo vetor lido;
//
void criarVetorAleatorio(int vetor[], int tamanho, int minimo, int maximo) {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Preenche o vetor com números aleatórios entre minimo e maximo
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (maximo - minimo + 1) + minimo;
    }
    printf("Vetor Aleatorio entre %d e %d: ", minimo, maximo);
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
}

void calcularMatrizProduto(int vetor1[], int vetor2[], int matrizResultado[][TAMANHO_VETOR]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrizResultado[i][j] = vetor1[i] * vetor2[j];
        }
    }
    printf("\nMatriz Resultado:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%3d ", matrizResultado[i][j]);
        }
        printf("\n");
    }
}
//

//10/5
//
void criarVetorAleatorio_semprint(int vetor[], int tamanho, int minimo, int maximo) {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Preenche o vetor com números aleatórios entre minimo e maximo
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (maximo - minimo + 1) + minimo;
    }
}

void calcularMatrizProduto_semprint(int vetor1[], int vetor2[], int matrizResultado[][TAMANHO_VETOR]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrizResultado[i][j] = vetor1[i] * vetor2[j];
        }
    }
    }
//
//11-Cálculo e apresentação da matriz transposta referida no ponto anterior;
//
void transporMatriz(int matriz[][TAMANHO_VETOR], int transposta[][TAMANHO_VETOR]) {
	int linhas = TAMANHO_VETOR;
	int colunas = TAMANHO_VETOR;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
    printf("\nMatriz Transposta:\n");
    for(int i = 0; i<10; i++){
    	for(int j = 0; j<10; j++){
    		printf("%3d", transposta[i][j]);
		}
		printf("\n");
	}
}
//
