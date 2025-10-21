#include <stdio.h>
#include <string.h>

// Definição da estrutura de carta
typedef struct {
    char nome[30];
    int populacao;      // milhões
    int area;           // mil km2
    int densidade;      // hab/km2
    int pib;            // bilhões US$
    int expectativa;    // anos
} Carta;

// Função para mostrar os atributos disponíveis
void mostrarAtributos(int excluir) {
    printf("Escolha um atributo para comparação:\n");
    if (excluir != 1) printf("1 - População (maior vence)\n");
    if (excluir != 2) printf("2 - Área (maior vence)\n");
    if (excluir != 3) printf("3 - Densidade Demográfica (menor vence)\n");
    if (excluir != 4) printf("4 - PIB (maior vence)\n");
    if (excluir != 5) printf("5 - Expectativa de Vida (maior vence)\n");
    printf("Opção: ");
}

// Função para obter valor do atributo
int obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.densidade;
        case 4: return c.pib;
        case 5: return c.expectativa;
        default: return -1;
    }
}

// Função para mostrar nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "Densidade Demográfica";
        case 4: return "PIB";
        case 5: return "Expectativa de Vida";
        default: return "Inválido";
    }
}

// Função para comparar um atributo
int compararAtributo(int atributo, int v1, int v2) {
    if (atributo == 3)
        return (v1 < v2) ? 1 : (v1 > v2 ? 2 : 0); // Densidade: menor vence
    else
        return (v1 > v2) ? 1 : (v1 < v2 ? 2 : 0); // Outros: maior vence
}

// Função para escolher atributo e garantir que não repita
int escolherAtributo(int excluir) {
    int op;
    do {
        mostrarAtributos(excluir);
        scanf("%d", &op);
        if (op < 1 || op > 5 || op == excluir) {
            printf("Opção inválida! Tente novamente.\n");
            op = 0; // força repetir
        }
    } while (op == 0);
    return op;
}

int main() {
    // Cartas pré-cadastradas
    Carta cartas[2] = {
        {"Brasil", 214, 8516, 25, 1868, 76},
        {"Japão", 125, 378, 334, 5085, 84}
    };

    // Exibe nomes das cartas
    printf("Carta 1: %s\n", cartas[0].nome);
    printf("Carta 2: %s\n\n", cartas[1].nome);

    // Escolha dos atributos
    int atributo1 = escolherAtributo(0);
    int atributo2 = escolherAtributo(atributo1);
    printf("\nAtributos escolhidos: %s e %s\n\n", nomeAtributo(atributo1), nomeAtributo(atributo2));

    // Obtém valores de cada carta
    int v1_c1 = obterValor(cartas[0], atributo1);
    int v1_c2 = obterValor(cartas[1], atributo1);
    int v2_c1 = obterValor(cartas[0], atributo2);
    int v2_c2 = obterValor(cartas[1], atributo2);

    // Comparação dos atributos individualmente
    int resultado1 = compararAtributo(atributo1, v1_c1, v1_c2);
    int resultado2 = compararAtributo(atributo2, v2_c1, v2_c2);

    // Soma dos atributos
    int soma_c1 = v1_c1 + v2_c1;
    int soma_c2 = v1_c2 + v2_c2;

    // Exibe resultados detalhados
    printf("Comparação dos atributos:\n");
    printf("%s: %d (%s) x %d (%s) --> %s\n",
           nomeAtributo(atributo1), v1_c1, cartas[0].nome, v1_c2, cartas[1].nome,
           resultado1 == 1 ? cartas[0].nome : resultado1 == 2 ? cartas[1].nome : "Empate");
    printf("%s: %d (%s) x %d (%s) --> %s\n",
           nomeAtributo(atributo2), v2_c1, cartas[0].nome, v2_c2, cartas[1].nome,
           resultado2 == 1 ? cartas[0].nome : resultado2 == 2 ? cartas[1].nome : "Empate");

    printf("\nSoma dos atributos:\n");
    printf("%s: %d\n", cartas[0].nome, soma_c1);
    printf("%s: %d\n", cartas[1].nome, soma_c2);

    // Resultado final
    printf("\nResultado Final: ");
    if (soma_c1 == soma_c2) {
        printf("Empate!\n");
    } else {
        printf("%s venceu a rodada!\n", soma_c1 > soma_c2 ? cartas[0].nome : cartas[1].nome);
    }

    return 0;
}
