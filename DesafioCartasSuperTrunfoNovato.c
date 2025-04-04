#include <stdio.h>

typedef struct {
    char codigo[5];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

void cadastrarCidade(Cidade *cidade) {
    printf("\nDigite o código da cidade:");
    scanf("%s", cidade->codigo);

    printf("\nDigite a população da cidade:");
    scanf("%d", &cidade->populacao);

    printf("\nDigite a área da cidade:");
    scanf("%f", &cidade->area);

    printf("\nDigite o PIB da cidade:");
    scanf("%f", &cidade->pib);

    printf("\nDigite o número de pontos turísticos da cidade:");
    scanf("%d", &cidade->pontos_turisticos);
}

void exibirCidade(Cidade cidade) {
    
    printf("\nDados da Cidade %s:\n", cidade.codigo);
    printf("\nPopulação: %d\n", cidade.populacao);
    printf("\nÁrea: %.2f km²\n", cidade.area);
    printf("\nPIB: R$ %.2f bilhões\n", cidade.pib);
    printf("\nPontos turísticos: %d\n", cidade.pontos_turisticos);
}

int main() {
    Cidade cidades[8][4]; 

    
    for (char estado = 'A'; estado <= 'H'; estado++) {
        for (int i = 0; i < 4; i++) {
            printf("\nCadastro da Cidade %c%02d:\n", estado, i + 1);
            cadastrarCidade(&cidades[estado - 'A'][i]);
        }
    }


    printf("\n---- Dados das Cidades Cadastradas ----\n");
    for (char estado = 'A'; estado <= 'H'; estado++) {
        for (int i = 0; i < 4; i++) {
            exibirCidade(cidades[estado - 'A'][i]);
        }
    }

    return 0;
}
