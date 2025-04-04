#include <stdio.h>

typedef struct {
    char codigo[5];        // Código identificador da cidade (ex: A01, B02)
       unsigned long int populacao; // População da cidade (usando unsigned long int para números maiores)
         float area;            // Área da cidade em km²
           float pib;             // PIB da cidade em bilhões de reais
            int pontos_turisticos; // Número de pontos turísticos da cidade
          float densidade_populacional; // Densidade populacional (habitantes por km²)
       float pib_per_capita; // PIB per capita da cidade (em reais)
    float super_poder;    // "Super Poder" da cidade (soma dos atributos relevantes)
} Cidade;

// Função para cadastrar os dados de uma cidade
void cadastrarCidade(Cidade *cidade) {
    // Solicita o código da cidade
    printf("\nDigite o código da cidade (ex: A01, B02): ");
      scanf("%s", cidade->codigo);

    // Solicita a população da cidade
    printf("Digite a população da cidade: ");
      scanf("%lu", &cidade->populacao); // Usando %lu para receber um unsigned long int

    // Solicita a área da cidade
    printf("Digite a área da cidade (em km²): ");
      scanf("%f", &cidade->area);

    // Solicita o PIB da cidade
    printf("Digite o PIB da cidade (em bilhões de reais): ");
      scanf("%f", &cidade->pib);

    // Solicita o número de pontos turísticos
    printf("Digite o número de pontos turísticos da cidade: ");
      scanf("%d", &cidade->pontos_turisticos);

    // Calculando a densidade populacional e o PIB per capita
    cidade->densidade_populacional = cidade->populacao / cidade->area;
    cidade->pib_per_capita = cidade->pib * 1000000000 / cidade->populacao;  // PIB per capita em reais

    // Calculando o Super Poder
    cidade->super_poder = cidade->populacao + cidade->area + cidade->pib + cidade->pontos_turisticos 
                          + cidade->pib_per_capita + (1 / cidade->densidade_populacional); // Quanto menor a densidade, maior o "poder"
}

// Função para exibir as informações de uma cidade
void exibirCidade(Cidade cidade) {
    printf("\nInformações da Cidade %s:\n", cidade.codigo);
      printf("População: %lu habitantes\n", cidade.populacao);
       printf("Área: %.2f km²\n", cidade.area);
        printf("PIB: %.2f bilhões de reais\n", cidade.pib);
        printf("Número de Pontos Turísticos: %d\n", cidade.pontos_turisticos);
       printf("Densidade Populacional: %.2f habitantes/km²\n", cidade.densidade_populacional);
      printf("PIB per Capita: %.2f reais\n", cidade.pib_per_capita);
    printf("Super Poder: %.2f\n", cidade.super_poder);
}

// Função para comparar os atributos de duas cidades
void compararAtributos(Cidade c1, Cidade c2) {
    printf("\nComparação entre as Cartas:\n");

    // Comparando a população
    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);

    // Comparando a área
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);

    // Comparando o PIB
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);

    // Comparando os pontos turísticos
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos);

    // Comparando a densidade populacional (quanto menor a densidade, melhor)
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional);

    // Comparando o PIB per capita
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita);

    // Comparando o Super Poder
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.super_poder > c2.super_poder);
}

int main() {
    Cidade carta1, carta2;

    // Cadastrando a primeira carta (cidade)
    printf("\nCadastro da Carta 1:\n");
    cadastrarCidade(&carta1);

    // Cadastrando a segunda carta (cidade)
    printf("\nCadastro da Carta 2:\n");
    cadastrarCidade(&carta2);

    // Exibindo as informações das duas cartas
    printf("\n---- Dados da Carta 1 ----");
    exibirCidade(carta1);

    printf("\n---- Dados da Carta 2 ----");
    exibirCidade(carta2);

    // Realizando a comparação dos atributos das duas cartas
    compararAtributos(carta1, carta2);

    return 0;
}
