/**
 *  @file   main-team-20.c
 * @brief   Ficheiro principal 
 * @author  Team20
 * @version 2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TAMANHO_VETOR 10
#include <string.h>
#include "functions-team-20.h"

/**
 * Esta função inicia a execução do programa, interagindo com o usuário para obter um vetor de números inteiros e realizar operações matemáticas com base nas escolhas do usuário
 * @param argc Número de argumentos de linha de comando.
 * @param argv Argumentos de linha de comando.
 * @return 0 se o programa for executado com sucesso.
 */
 

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
            mostrarAjuda();
            return 0;
        } else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
            printf("Versão 1.0\n");
            return 0;
        }
}
    int numeros[TAMANHO_VETOR]; //Primeiro Vetor
    int novo_vetor[TAMANHO_VETOR]; //Função 8
    int mistura_vetor[TAMANHO_VETOR]; //Função 8
    int vetor2[TAMANHO_VETOR]; //Função 10
    int produtomatriz[TAMANHO_VETOR][TAMANHO_VETOR]; //Função 10
    int transposta[TAMANHO_VETOR][TAMANHO_VETOR]; //Função 11
    int i, validar_entrada, escolha;
    int matriz[TAMANHO_VETOR][TAMANHO_VETOR];
    int voltarMenu = 1;
    //Validação de entrada
	do{
		printf("Pressione 1 para entrar no programa\n");
		scanf("%d", &validar_entrada);
	}while(validar_entrada != 1);
	
    for (i = 0; i < TAMANHO_VETOR; i++) {
        do {
            printf("Digite o %d numero inteiro entre -10 e 16: ", i + 1);
            scanf("%d", &numeros[i]);

            if (numeros[i] < -10 || numeros[i] > 16) {
                printf("Por favor, digite um numero entre -10 e 16.\n");
            }
        } while (numeros[i] < -10 || numeros[i] > 16);
    }while(voltarMenu)
    do {
        // Exibe o menu
        printf("Menu:\n");
        printf("1-Calculo da multiplicacao de todos os elementos no vetor:\n");
        printf("2-Identificacao do maximo de todos os elementos do vetor:\n");
        printf("3-Devolucao da soma dos valores do vetor que sao divisiveis por tres:\n");
        printf("4-Devolucao do vetor ordenado por ordem crescente dos seus valores simetricos:\n");
        printf("5-Construcao de uma matriz 10 por 10, em que cada linha e composta pelo vetor lido(primeira linha) e por permutacoes dos seus valores(outras linhas):\n");
        printf("6-Calculo do logaritmo (base natural) de todos os elementos no vetor:\n");
        printf("7-Página de Ajuda\n");
        printf("8-Leitura de um novo vetor, e devolucao de um  vetor que  mistura  metade do primeiro vetor e metade do segundo;\n");
        printf("9-Calculo do maximo divisor comum de cada dois numeros seguidos do vetor;\n");
        printf("10-Geracao  de  um  novo  vetor  1x10   aleatorio,  calculo  e  devolucao  da matriz 10x10 resultante do produto do vetor inicial com o novo vetor lido;\n");
        printf("11-Calculo e apresentacao da matriz transposta referida no ponto anterior;\n");

        // Solicita a escolha do usuário
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        // Processa a escolha do usuário
        switch (escolha) {
            case 1:
            	multiplicacaoVetor(numeros, TAMANHO_VETOR);
                break;
            case 2:
                valorMaximo(numeros, TAMANHO_VETOR);
                break;
            case 3:
                somaDivisiveisPorTres(numeros,TAMANHO_VETOR);
                break;
            case 4:
                ordenarcrescenteSimetricos(numeros, TAMANHO_VETOR);
                break;
            case 5:
            	fazerpermutacaoMatriz(numeros, matriz);
            	break;
            case 6:
            	calcularLogNaBaseNatural(numeros, TAMANHO_VETOR);
            	break;
            case 7:
            	mostrarAjuda();
            	break;
            case 8:
            	misturarVetores(numeros, novo_vetor, mistura_vetor);
            	break;
            case 9:
            	calcularMDCVetor(numeros, TAMANHO_VETOR);
            	break;
            case 10:
            	criarVetorAleatorio(vetor2, TAMANHO_VETOR, -10, 16);
            	calcularMatrizProduto(numeros,vetor2,produtomatriz);
            	break;
            case 11:
            	criarVetorAleatorio_semprint(vetor2, TAMANHO_VETOR, -10, 16);
            	calcularMatrizProduto_semprint(numeros,vetor2,produtomatriz);
            	transporMatriz(produtomatriz, transposta);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        printf("\nDeseja voltar ao menu= (1 - Sim / 0 - Nao):\n");
        scanf("%d", &voltarMenu);
		
    } while (voltarMenu != 0 && voltarMenu != 1);
}

