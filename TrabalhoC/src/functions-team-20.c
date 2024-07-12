/**
* @file functions-team-20.c
* @brief Protótipos
* @author Team20
* @version 2.0
*/
#include <stddef.h>
#include "functions-team-20.h"


/**
* Esta função calcula a multiplicação de todos os elementos no vetor.
* @param vetor Um vetor de tipo inteiro.
* @param tamanho O tamanho do vetor.
* @code 
*    multiplicacaoVetor(vetor, tamanho);
*    int vetor[] = {2, 4, 3, 5, 2, 2, 3, 4, 7, 9};
*    int tamanho = TAMANHO_VETOR;
* @endcode
* @return O resultado da multiplicação.
* @code
*    int resultado = multiplicacaoVetor(vetor, tamanho);
* @endcode
*/
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
/**
* Esta função identifica o máximo de todos os elementos do vetor.
* @param vetor Um vetor de tipo inteiro.
* @param tamanho O tamanho do vetor.
* @code
*    valorMaximo(vetor, tamanho);
*    int vetor[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
*    int tamanho = TAMANHO_VETOR;
* @endcode
* @return O valor máximo entre todos os elementos do vetor.
* @code
*    int maximo = valorMaximo(vetor, tamanho);
* @endcode
* @warning Esta função não lida com valores NaN ou infinitos.
*/

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
/**
* Esta função retorna a soma dos valores do vetor que são divisíveis por três.
* @param vetor Um vetor de tipo inteiro.
* @param tamanho O tamanhor do vetor.
* @code
*	int vetor[] = {1, 6, 3, 9, 5, 7, 8, 3, 2};
*	int tamanho = TAMANHO_VETOR;
* @endcode
* @return A soma dos valores do vetor que são divisíveis por três.
* @code
*	int resultado = somaDivisivelPorTres(vetor, tamanho); 
* @endcode
* @note Se o vetor estiver vazio, a soma será zero.
*/

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

/**
 * Esta função faz a devolução do vetor ordenado por ordem crescente dos seus valores simétricos.
 * @param vetor Um vetor de tipo inteiro.
 * @param tamanho O tamanho do vetor.
 * @code
 *    ordenarcrescenteSimetricos(vetor, tamanho);
 *    int vetor[] = {2, 4, 1, 3, 5, 6, 2, 5, 2, 1};
 *    int tamanho = TAMANHO_VETOR;
 * @endcode
 * @note O vetor original não é modificado. 
 */
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

/**
 * Esta função recebe dois ponteiros para inteiros e troca os valores
 * armazenados nas posições apontadas por esses ponteiros.
 *
 * @param a Ponteiro para o primeiro valor a ser trocado.
 * @param b Ponteiro para o segundo valor a ser trocado.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para gerar permutações

/**
 * Esta função recebe um vetor de inteiros e o tamanho do vetor,
 * em seguida, gera permutações aleatórias dos elementos do vetor.
 *
 * @param vetor Um vetor de inteiros a ser permutado.
 * @param n O tamanho do vetor.
 *
 * Exemplo de uso:
 * @code
 *    criarPermutation(vetor, tamanho);
 *    int vetor[] = {1, 2, 3, 4, 5, 6 ,7 ,8 ,9, 1};
 *    int tamanho = TAMANHO_VETOR;
 * @endcode
 */
void criarPermutation(int vetor[], int n) {
    int i;
    for (i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&vetor[i], &vetor[j]);
    }
}

//Faz a permutação na matriz

/**
 * Esta função realiza permutações nas linhas de uma matriz usando um vetor base.
 * @param vetor Um vetor de tipo inteiro.
 * @param matriz Uma matriz para armazenar as linhas permutadas.
 *
 * @code
 *    fazerpermutacaoMatriz(vetor, matriz);
 *    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2};
 *    int matriz[TAMANHO_VETOR][TAMANHO_VETOR];
 * @endcode
 */
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

/**
 * Esta função calcula o logaritmo natural de todos os elementos no vetor.
 * @param vetor Um vetor de tipo inteiro.
 * @param tamanho O tamanho do vetor.
 * @code
 *    calcularLogNaBaseNatural(vetor, tamanho);
 *    int vetor[] = {1, 2, 4, 8, 1, 2, 3, 4, 5, 6};
 *    int tamanho = TAMANHO_VETOR;
 * @endcode
 */
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
/**
*
* Esta função imprime uma descrição detalhada do programa, incluindo a entrada esperada e as opções disponíveis no menu.
*/
void mostrarAjuda() {
    printf("\n---------------------------------------------------- Pagina de Ajuda ---------------------------------------------------\n\n");
    printf("Este programa solicita 10 numeros inteiros no intervalo de -10 a 16, e organiza-os em um vetor 1x10.\nEm seguida apresenta um menu que oferece varias opcoes\nSendo a primeira opcao calcular a multiplicacao dos elementos no vetor\nA segunda opcao ver o maximo dos elementos do vetor\nA terceira opcao a soma dos valores do vetor divisiveis por tres\nA quarta opcao ordenadar o vetor por ordem crescente dos seus valores simetricos\nA quinta opcao a construção de uma matriz 10x10 onde da segunda linha para a frente sao permutacoes da primeira linha\nA sexta opcao o calculo do logaritmo de todos os elementos no vetor\n.gvg.\nA oitava opcao ler um novo vetor 1x10 e misturar a metade do vetor inicial com o vetor criado\nA nona opcao calcular o maximo divisor comum de cada dois numero seguidos\nA decima opcao gerar um vetor novo 1x10 aleatorio e calcular o produto do vetor inical com o vetor aleatorio\nE por fim a decima primeira opcao o calculo da matriz transposta referida na decima opcao.\n\n");
    printf("----------------------------------------------------  Fim da pagina  ---------------------------------------------------\n");
}
//
//8-Leitura de um novo vetor, e devolução de um  vetor que  mistura  metade do primeiro vetor e metade do segundo;
//
/**
 * Esta função lê um novo vetor e retorna um vetor que mistura metade do primeiro vetor e metade do segundo.
 * @param vetor Um vetor original de inteiros.
 * @param vetor_novo Um vetor novo lido a partir da entrada do usuário.
 * @param vetorMisturado O vetor resultante que mistura metade do primeiro vetor e metade do segundo.
 * @code
 *    misturarVetores(vetor, vetor_novo, vetorMisturado);
 *    int vetor[TAMANHO_VETOR] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 *    int vetor_novo[TAMANHO_VETOR];
 *    int vetorMisturado[TAMANHO_VETOR];
 * @endcode
 */
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
/**
 * Esta função calcula o máximo divisor comum (MDC) de dois números.
 * @param a Primeiro número inteiro.
 * @param b Segundo número inteiro.
 * @return O valor do MDC entre a e b.
 * @code
 *    int resultado = calcularMDC(12, 18);
 * @endcode
 */
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

/**
 * Esta função calcula o máximo divisor comum (MDC) de cada par consecutivo no vetor.
 *
 * @param vetor Um vetor de tipo inteiro.
 * @param tamanho O tamanho do vetor.
 * @code
 *    calcularMDCVetor(vetor, tamanho);
 *    int vetor[] = {2, 4, 6, 3, 4, 2, 7, 1, 5, 1};
 *    int tamanho = TAMANHO_VETOR;
 * @endcode
 */
void calcularMDCVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int mdc = calcularMDC(vetor[i], vetor[i + 1]);
        printf("MDC(%d, %d) = %d\n", vetor[i], vetor[i + 1], mdc);
    }
}
//

//10- Geração  de  um  novo  vetor  1x10   aleatório,  cálculo  e  devolução  da matriz 10x10 resultante do produto do vetor inicial com o novo vetor lido;
//

/**
 * Esta função gera um vetor aleatório de inteiros dentro de um intervalo especificado.
 * @param vetor Um vetor de inteiros a ser preenchido com números aleatórios.
 * @param tamanho O tamanho do vetor.
 * @param minimo O valor mínimo permitido para os números aleatórios.
 * @param maximo O valor máximo permitido para os números aleatórios.
 * @code
 *    criarVetorAleatorio(vetor, 10, -5, 5);
 *    int vetor[10];
 *    int tamanho = TAMANHO_VETOR;
 * @endcode
 */
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

/**
 * Esta função recebe dois vetores de inteiros e calcula a matriz resultante do
 * produto de seus elementos. Cada elemento da matriz é o produto de um elemento
 * do primeiro vetor com um elemento correspondente do segundo vetor.
 *
 * @param vetor1 Um vetor de inteiros.
 * @param vetor2 Um segundo vetor de inteiros.
 * @param matrizResultado Uma matriz 2D para armazenar o resultado do produto.
 * @code
 *    calcularMatrizProduto(vetor1, vetor2, matrizResultado);
 *    int vetor1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 *    int vetor2[10] = {2, 4, 6, 8, 10, 7, 5, 6, 7, 6};
 *    int matrizResultado[10][10];
 * @endcode
 */
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

/**
 *
 * Esta função gera um vetor de inteiros aleatórios, onde cada elemento está dentro do intervalo [minimo, maximo]. Os valores gerados são armazenados no vetor fornecido, mas não há impressão na tela.
 *
 * @param vetor Um vetor de inteiros a ser preenchido com números aleatórios.
 * @param tamanho O tamanho do vetor.
 * @param minimo O valor mínimo permitido para os números aleatórios.
 * @param maximo O valor máximo permitido para os números aleatórios.
 * @code
 *    criarVetorAleatorio_semprint(vetor, 10, -5, 5);
 *    int vetor[10];
 * @endcode
 */
void criarVetorAleatorio_semprint(int vetor[], int tamanho, int minimo, int maximo) {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Preenche o vetor com números aleatórios entre minimo e maximo
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (maximo - minimo + 1) + minimo;
    }
}

/**
 * Esta função recebe dois vetores de inteiros e calcula a matriz resultante do
 * produto de seus elementos. Cada elemento da matriz é o produto de um elemento
 * do primeiro vetor com um elemento correspondente do segundo vetor.
 *
 * @param vetor1 Um vetor de inteiros.
 * @param vetor2 Um segundo vetor de inteiros.
 * @param matrizResultado Uma matriz 2D para armazenar o resultado do produto.
 * @code
 *    calcularMatrizProduto_semprint(vetor1, vetor2, matrizResultado);
 *    int vetor1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 *    int vetor2[10] = {2, 4, 6, 8, 3, 2, 5, 4, 3, 2};
 *    int matrizResultado[10][10];
 * @endcode
 */
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

/**
 * Esta função recebe uma matriz e calcula sua matriz transposta. 
 *
 * @param matriz Uma matriz de inteiros.
 * @param transposta Uma matriz para armazenar a matriz transposta.
 * @code
 *    transporMatriz(matriz, transposta);
 *    int matriz[10][10] = {.............}
 *    int transposta[10][10];
 * @endcode
 */
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
