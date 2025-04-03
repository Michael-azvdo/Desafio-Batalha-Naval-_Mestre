#include <stdio.h>

#define linhas 10
#define colunas 10

int main()
{
    // Imprimindo o tabuleiro com letras em cima e números na lateral
    printf("\n***DESAFIO BATALHA NAVAL***\n"); // \n\n para pular duas linhas
    printf("\n***Nível: Mestre***\n\n");

    char letras[colunas] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // array de caracteres para representar as colunas


    // Declaração do tabuleiro
    int tabuleiro[linhas][colunas];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }


    // Define as coordenadas de início e o tamanho dos navios
    int navio_horizontal_linha = 1;
    int navio_horizontal_coluna = 5;
    int navio_vertical_linha = 6;
    int navio_vertical_coluna = 8;
    int tamanho_navio = 3;
    int navio1_diagonal_linha = 1;
    int navio1_diagonal_coluna = 1;
    int navio2_diagonal_linha = 7;
    int navio2_diagonal_coluna = 1;


    // Iserindo os navios no tabuleiro

    // Validação do Navio Horizontal
    if (navio_horizontal_coluna + tamanho_navio > colunas)
    { // Verifica se o navio horizontal sai do tabuleiro
        printf("Erro: Navio horizontal saiu do tabuleiro!\n");
    }
    else
    {
        for (int j = navio_horizontal_coluna; j < navio_horizontal_coluna + tamanho_navio; j++)
        {                                             // Adiciona o navio horizontal
            tabuleiro[navio_horizontal_linha][j] = 3; // 3 representa o navio
        }
    }


    // Validação do Navio Vertical
    if (navio_vertical_linha + tamanho_navio > linhas)
    {
        printf("Erro: Navio vertical saiu do tabuleiro!\n");
    }
    else
    {
        for (int i = navio_vertical_linha; i < navio_vertical_linha + tamanho_navio; i++)
        {
            tabuleiro[i][navio_vertical_coluna] = 3; // 3 representa o navio
        }
    }


    // Validação do Navio1 Diagonal
    if (navio1_diagonal_linha + tamanho_navio > linhas || navio1_diagonal_coluna + tamanho_navio > colunas)
    {
        printf("Erro: Navio diagonal saiu do tabuleiro!\n");
    }
    else
    {
        for (int i = navio1_diagonal_linha, j = navio1_diagonal_coluna; i < navio1_diagonal_linha + tamanho_navio; i++, j++)
        {
            tabuleiro[i][j] = 3; // 3 representa o navio
        }
    }


    // Validação do Navio2 Diagonal
    if (navio2_diagonal_linha + tamanho_navio > linhas || navio2_diagonal_coluna + tamanho_navio > colunas)
    {
        printf("Erro: Navio diagonal saiu do tabuleiro!\n");
    }
    else
    {
        for (int i = navio2_diagonal_linha, j = navio2_diagonal_coluna; i > navio2_diagonal_linha - tamanho_navio; i--, j++)
        {
            tabuleiro[i][j] = 3; // 3 representa o navio
        }
    }


    // Inserindo as formas geométricas no tabuleiro

    // Desenhando e validando o cone
    int cone_ponta_linha = 7;  // Linha onde ficará a ponta do cone
    int cone_ponta_coluna = 4; // Coluna onde ficará a ponta do cone
    int altura_cone = 3;       // Altura do cone

    if (cone_ponta_linha + altura_cone > linhas ||
        cone_ponta_coluna - altura_cone / 2 < 0 ||
        cone_ponta_coluna + altura_cone / 2 >= colunas)
    {
        printf("Erro: Cone saiu do tabuleiro!\n");
    }
    else
    {
        for (int i = 0; i < altura_cone; i++)
        {
            // Para cada linha, imprime um número crescente de elementos
            // centralizados em relação à ponta do cone
            int elementos_na_linha = 2 * i + 1;        // Número de elementos na linha atual
            int inicio_coluna = cone_ponta_coluna - i; // Coluna inicial da linha atual (centralizado)

            for (int j = 0; j < elementos_na_linha; j++)
            {
                tabuleiro[cone_ponta_linha + i][inicio_coluna + j] = 4; // 4 representa o cone
            }
        }
    }


    // Desenhando e validando a cruz
    int cruz_centro_linha = 4;
    int cruz_centro_coluna = 7;
    int tamanho_braco_cruz = 2;
    
    if (cruz_centro_linha - tamanho_braco_cruz < 0 || cruz_centro_linha + tamanho_braco_cruz >= linhas ||
        cruz_centro_coluna - tamanho_braco_cruz < 0 || cruz_centro_coluna + tamanho_braco_cruz >= colunas)
    {
        printf("Erro: Cruz saiu do tabuleiro!\n");
    }
    else
    {
        // Desenhar o centro da cruz
        tabuleiro[cruz_centro_linha][cruz_centro_coluna] = 5; // 5 representa a cruz

        // Desenhar braço vertical
        for (int i = 1; i <= tamanho_braco_cruz; i++)
        {
            tabuleiro[cruz_centro_linha - i][cruz_centro_coluna] = 5; // Para cima
            tabuleiro[cruz_centro_linha + i][cruz_centro_coluna] = 5; // Para baixo
        }

        // Desenhar braço horizontal
        for (int j = 1; j <= tamanho_braco_cruz; j++)
        {
            tabuleiro[cruz_centro_linha][cruz_centro_coluna - j] = 5; // Para esquerda
            tabuleiro[cruz_centro_linha][cruz_centro_coluna + j] = 5; // Para direita
        }
    }


    // Desenhando e validando o Octaedro
    int octaedro_centro_linha = 4;
    int octaedro_centro_coluna = 1;
    int largura_central = 3; // A linha central terá 3 posições

    int raio = largura_central / 2; // Raio a partir do centro
    if (octaedro_centro_linha - raio < 0 || octaedro_centro_linha + raio >= linhas ||
        octaedro_centro_coluna - raio < 0 || octaedro_centro_coluna + raio >= colunas)
    {
        printf("Erro: Octaedro saiu do tabuleiro!\n");
    }
    else
    {
        // Desenhar o octaedro com linha central de 3 posições

        // Desenhar a ponta superior
        tabuleiro[octaedro_centro_linha - 1][octaedro_centro_coluna] = 6;

        // Desenhar a linha central (3 posições)
        for (int j = -1; j <= 1; j++)
        {
            tabuleiro[octaedro_centro_linha][octaedro_centro_coluna + j] = 6;
        }

        // Desenhar a ponta inferior
        tabuleiro[octaedro_centro_linha + 1][octaedro_centro_coluna] = 6;
    }


    // Imprimindo o cabeçalho com letras (A-J)
    printf("   "); // Espaço para alinhar com os números da lateral (4 espaços)
    for (int j = 0; j < colunas; j++)
    {
        printf("%c ", letras[j]); // Imprime as letras como cabeçalho
    }
    printf("\n"); // Imprime uma nova linha após o cabeçalho

    
    // Imprimindo o tabuleiro com números na lateral
    for (int i = 0; i < linhas; i++)
    {
        printf("%2d ", i); // Imprime o número da linha // %2d para alinhar a direita com 2 espaços
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
