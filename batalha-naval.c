#include <stdio.h>

// Função para imprimir o tabuleiro com letras nas colunas e números no interior.
void imprimirTabuleiro(int tabuleiro[10][10], const char* titulo) {
    int i, j;
    printf("\n--- %s ---\n\n", titulo);
    printf("Legenda: 0 = Água | 3 = Navio | 4 = Cone | 5 = Cruz | 6 = Octaedro\n\n");

    // Imprime cabeçalho das colunas (letras)
    printf("   ");                      // Espaço para alinhar com os números.
    for (j = 0; j < 10; j++) {          // Imprime letras de A a J.
        printf("%c ", 'A' + j); // Converte número para letra (A, B, C...).
    }
    printf("\n");
    printf("  --------------------\n");

    // Imprime o tabuleiro
    for (i = 0; i < 10; i++) {          // Percorre as linhas do tabuleiro.
        printf("%d |", i);              // Imprime cabeçalho das linhas (números).
        for (j = 0; j < 10; j++) {      // Percorre as colunas do tabuleiro.
            printf("%d ", tabuleiro[i][j]); // Imprime o número do elemento (0, 3, 5, 6 ou 7).
        }
        printf("\n");
    }
}

// Função auxiliar para inicializar um tabuleiro com 0s
void inicializarTabuleiro(int tabuleiro[10][10]) {          // Limpa o tabuleiro, preenchendo com 0s.
    int i, j;                                              // Declaração de variáveis para iteração.
    for (i = 0; i < 10; i++) {                             // Percorre as linhas do tabuleiro.                      
        for (j = 0; j < 10; j++) {                         // Percorre as colunas do tabuleiro.
            tabuleiro[i][j] = 0;                           // Define cada célula como 0 (água).
        }
    }
}

int main() {
    // Representação do Tabuleiro 10x10
    int tabuleiro[10][10];
    int i, j;

    // Posições iniciais dos navios que serão usadas no tabuleiro final.
    int linhaH = 1, colunaH = 2; // Navio horizontal
    int linhaV = 4, colunaV = 5; // Navio vertical
    int linhaD1 = 0, colunaD1 = 0; // Navio diagonal principal
    int linhaD2 = 0, colunaD2 = 9; // Navio diagonal secundária

    // Definição das Habilidades e Aplicação para VISUALIZAÇÃO INDIVIDUAL 
    int habilidade_size = 5;                                // Tamanho das matrizes de habilidade.
    int origemX_visualizacao, origemY_visualizacao;         // Posições para visualização centralizada.
    int matriz_temp[habilidade_size][habilidade_size];       // Matriz temporária para gerar as formas.

    // Visualização da Habilidade Cone (valor 4)
    inicializarTabuleiro(tabuleiro); // Limpa o tabuleiro para ver apenas o cone
    origemX_visualizacao = 4; origemY_visualizacao = 4;          // Centro do tabuleiro para garantir que a forma caiba
    for (i = 0; i < habilidade_size; i++) {                      // Percorre as linhas da matriz de habilidade.
        for (j = 0; j < habilidade_size; j++) {                  // Percorre as colunas da matriz de habilidade.
            matriz_temp[i][j] = (j >= (habilidade_size / 2) - i && j <= (habilidade_size / 2) + i) ? 1 : 0;     // Define a forma do cone.
            int x = origemX_visualizacao - (habilidade_size / 2) + i;                                           // Calcula a posição x ajustada para o centro da habilidade.
            int y = origemY_visualizacao - (habilidade_size / 2) + j;                                           // Calcula a posição y ajustada para o centro da habilidade.
            if (x >= 0 && x < 10 && y >= 0 && y < 10 && matriz_temp[i][j] == 1) {                               // Verifica se a posição está dentro dos limites do tabuleiro.
                tabuleiro[x][y] = 4;                                                                            // Marca a posição no tabuleiro com o valor 4 (CONE).
            }
        }
    }
    imprimirTabuleiro(tabuleiro, "Visualização da Habilidade: CONE");           // Imprime o tabuleiro com a visualização do cone.

    // Visualização da Habilidade Cruz (valor 5).
    inicializarTabuleiro(tabuleiro);                                            // Limpa o tabuleiro novamente.
    origemX_visualizacao = 4; origemY_visualizacao = 4;                         // Centro do tabuleiro.
    for (i = 0; i < habilidade_size; i++) {
        for (j = 0; j < habilidade_size; j++) {
            matriz_temp[i][j] = (i == (habilidade_size / 2) || j == (habilidade_size / 2)) ? 1 : 0;
            int x = origemX_visualizacao - (habilidade_size / 2) + i;
            int y = origemY_visualizacao - (habilidade_size / 2) + j;
            if (x >= 0 && x < 10 && y >= 0 && y < 10 && matriz_temp[i][j] == 1) {
                tabuleiro[x][y] = 5;
            }
        }
    }
    imprimirTabuleiro(tabuleiro, "Visualização da Habilidade: CRUZ");

    // Visualização da Habilidade Octaedro (valor 6).
    inicializarTabuleiro(tabuleiro); // Limpa o tabuleiro novamente.
    origemX_visualizacao = 4; origemY_visualizacao = 4; // Centro do tabuleiro.
    for (i = 0; i < habilidade_size; i++) {
        for (j = 0; j < habilidade_size; j++) {
            int dist_x = (i > (habilidade_size / 2)) ? i - (habilidade_size / 2) : (habilidade_size / 2) - i;
            int dist_y = (j > (habilidade_size / 2)) ? j - (habilidade_size / 2) : (habilidade_size / 2) - j;
            matriz_temp[i][j] = (dist_x + dist_y <= (habilidade_size / 2)) ? 1 : 0;
            int x = origemX_visualizacao - (habilidade_size / 2) + i;
            int y = origemY_visualizacao - (habilidade_size / 2) + j;
            if (x >= 0 && x < 10 && y >= 0 && y < 10 && matriz_temp[i][j] == 1) {
                tabuleiro[x][y] = 6;
            }
        }
    }
    imprimirTabuleiro(tabuleiro, "Visualização da Habilidade: OCTAEDRO");

    // Tabuleiro Final com Navios e TODAS as Habilidades em NOVAS POSIÇÕES.
    inicializarTabuleiro(tabuleiro);        // Limpa para a visualização final. 

    // Posiciona os navios
    if (colunaH + 3 <= 10) {                                                                        // Verifica se o navio horizontal cabe.
        for (i = 0; i < 3; i++) {                                                                   // Percorre as posições do navio horizontal.
            if (tabuleiro[linhaH][colunaH + i] == 0) { tabuleiro[linhaH][colunaH + i] = 3; }        // Marca com 3 (navio).
        }
    }
    if (linhaV + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 0) { tabuleiro[linhaV + i][colunaV] = 3; }
        }
    }
    if (linhaD1 + 3 <= 10 && colunaD1 + 3 <= 10) {                                                  // Verifica se o navio diagonal principal cabe.
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == 0) { tabuleiro[linhaD1 + i][colunaD1 + i] = 3; }    // Marca com 3 (navio).
        }
    }
    if (linhaD2 + 3 <= 10 && colunaD2 - 2 >= 0) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] == 0) { tabuleiro[linhaD2 + i][colunaD2 - i] = 3; }
        }
    }

    // Aplica Habilidade Cone (valor 4) em uma nova posição
    int origemConeX = 0, origemConeY = 8;                       // Nova posição: topo direito
    for (i = 0; i < habilidade_size; i++) {                     // Percorre as linhas da matriz de habilidade.  
        for (j = 0; j < habilidade_size; j++) {                 // Percorre as colunas da matriz de habilidade.
            matriz_temp[i][j] = (j >= (habilidade_size / 2) - i && j <= (habilidade_size / 2) + i) ? 1 : 0;     // Define a forma do cone.
            int x = origemConeX - (habilidade_size / 2) + i;                                                    // Ajusta para o centro da habilidade.  
            int y = origemConeY - (habilidade_size / 2) + j;                                                    // Ajusta para o centro da habilidade.
            if (x >= 0 && x < 10 && y >= 0 && y < 10 && matriz_temp[i][j] == 1 && tabuleiro[x][y] == 0) {       // Verifica se a posição está dentro dos limites do tabuleiro e se é água.
                tabuleiro[x][y] = 4;                                                                            // Marca a posição no tabuleiro com o valor 4 (CONE).
            }
        }
    }

    // Aplica Habilidade Cruz (valor 5) em uma nova posição
    int origemCruzX = 7, origemCruzY = 2; // Nova posição: canto inferior esquerdo
    for (i = 0; i < habilidade_size; i++) {
        for (j = 0; j < habilidade_size; j++) {
            matriz_temp[i][j] = (i == (habilidade_size / 2) || j == (habilidade_size / 2)) ? 1 : 0;
            int x = origemCruzX - (habilidade_size / 2) + i;
            int y = origemCruzY - (habilidade_size / 2) + j;
            if (x >= 0 && x < 10 && y >= 0 && y < 10 && matriz_temp[i][j] == 1 && tabuleiro[x][y] == 0) {
                tabuleiro[x][y] = 5;
            }
        }
    }

    // Habilidade Octaedro (valor 6) 
    int origemOctaedroX = 4, origemOctaedroY = 4; 
    for (i = 0; i < habilidade_size; i++) {             
        for (j = 0; j < habilidade_size; j++) {         
            int dist_x = (i > (habilidade_size / 2)) ? i - (habilidade_size / 2) : (habilidade_size / 2) - i;       
            int dist_y = (j > (habilidade_size / 2)) ? j - (habilidade_size / 2) : (habilidade_size / 2) - j;       
            matriz_temp[i][j] = (dist_x + dist_y <= (habilidade_size / 2)) ? 1 : 0;                                 
            int x = origemOctaedroX - (habilidade_size / 2) + i;                                                    
            int y = origemOctaedroY - (habilidade_size / 2) + j;                                                   
            if (x >= 0 && x < 10 && y >= 0 && y < 10 && matriz_temp[i][j] == 1 && tabuleiro[x][y] == 0) {           
                tabuleiro[x][y] = 6;                                                                               
            }
        }
    }
    // Imprime o tabuleiro final com navios e habilidades.
    imprimirTabuleiro(tabuleiro, "Tabuleiro Final com Navios e Habilidades"); 

    return 0;
}