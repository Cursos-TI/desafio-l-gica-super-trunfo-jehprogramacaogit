#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função que calcula os indicadores derivados
void calcularIndicadores(Carta *carta) {
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0;

    if (carta->populacao > 0)
        carta->pibPerCapita = carta->pib / carta->populacao;
    else
        carta->pibPerCapita = 0;
}

// Função para exibir os dados principais da carta
void exibirCarta(Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n\n", carta.pibPerCapita);
}

int main() {
    // Cadastro manual das duas cartas
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.0, 230.0, 10};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1200.0, 150.0, 8};

    // Cálculo de indicadores
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibindo as cartas
    printf("=== Carta 1 ===\n");
    exibirCarta(carta1);

    printf("=== Carta 2 ===\n");
    exibirCarta(carta2);

    // Atributo de comparação escolhido: População
    printf("Comparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    // Comparação usando if-else
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta1.populacao < carta2.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
