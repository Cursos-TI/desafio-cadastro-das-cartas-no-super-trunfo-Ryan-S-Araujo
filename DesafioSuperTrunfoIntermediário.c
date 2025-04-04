#include <stdio.h>

typedef struct {
   char codigo[5];   //Código da cidade (ex: A01, A02)
     int populacao;    //População da cidade
      float area;       //Área da cidade (em Km²)
      floar pin;        //PIB da cidade
     int pontos_turisticos;  //Números de pontos turísticos da cidade
     float densidade_populacional;  //Densidade populacional
   float pib_per_capita;      //PIB per capita
} Cidade;

void cadastrarCidade(Cidade *cidade) {
    //Vamos solicitar dados do usuário

  printf("\nDigite o código da cidade:");
    scanf("%s", cidade->codigo);

  printf("\nDigite a população da cidade:");
    scanf("%d", &cidade->populacao);

  printf("\nDigite a área da cidade (em Km²:");
    scanf("%f", cidade->area);
 
  printf("\nDigite o PIB da cidade:");
    scanf("%f", cidade->pib);

  printf("\nDigite o número de pontos turísticos da cidade:");
    scanf("%d", cidade->pontos_turisticos);

    //vamos calcular densidade populacionao e o PIB per capita

    cidade->densidade_populacional = cidade->populacao / cidade->area;
    cidade->pib_per_capita = cidade->pib * 1000000000 / cidade->populacao;
  
   //Convertendo PIB de bilhoes para reais
}


void exibirCidade(Cidade cidade) {
   //Vamos exibir os dados da cidade

  printf("\nCarta:\n");
    printf("Estado: %s\n", cidade.codigo);
     printf("Código: %s\n", cidade.codigo);
      printf("População: %d\n", cidade.populacao);    
       printf("Área: %.2f km²\n", cidade.area);
      printf("PIB: %.2f bilhões de reais\n", cidade.pib);
     printf("Número de Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidade_populacional);
  printf("PIB per Capita: %.2f reais\n", cidade.pib_per_capita);
}

int main() {
    Cidade cidades[8][4];  // 8 estados com 4 cidades cada

    // Cadastro das cidades
    for (char estado = 'A'; estado <= 'H'; estado++) {
        for (int i = 0; i < 4; i++) {
            printf("\nCadastro da Cidade %c%02d:\n", estado, i + 1);
            cadastrarCidade(&cidades[estado - 'A'][i]);
        }
    }

    // Exibição dos dados cadastrados
    printf("\n---- Dados das Cidades Cadastradas ----\n");
    for (char estado = 'A'; estado <= 'H'; estado++) {
        for (int i = 0; i < 4; i++) {
            exibirCidade(cidades[estado - 'A'][i]);
        }
    }

    return 0;
}
