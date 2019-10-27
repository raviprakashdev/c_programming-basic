#include <stdio.h>

int main(int argc, char *argv[])
{
    int tamLinhaMatA, tamLinhaMatB, tamColunMatA, tamColunMatB;
    int i,j,k, somatorioMultiplicaoLinhaxColuna;
    
    
    
    /*
        este loop (do while) serve para garantir que o usuario nao digitarah nada errado
     
            Ex: tamanho da matriz negativa, 
                linha da matriz A for diferente do tamanho a coluna da matriz B.
     
     */
    do{
        
        printf("\nInsira a quantidade de linhas na matriz A: ");
        scanf("%d", &tamLinhaMatA);
        printf("Insira a quantidade de colunas na matriz A: ");
        scanf("%d", &tamColunMatA);
    
        printf("Insira a quantidade de linhas na matriz B: ");
        scanf("%d", &tamLinhaMatB);
        printf("Insira a quantidade de colunas na matriz B: ");
        scanf("%d", &tamColunMatB);
        
        if(tamColunMatA< 0 || tamColunMatB < 0 || tamLinhaMatA < 0 || tamLinhaMatB < 0){
            printf("\n ERRO! \nA o tamanho da matriz nao pode ser negativa, insira o dado corretamente!\n");
        }
        if (tamColunMatA != tamLinhaMatB) {
            printf("\n ERRO! \nO tamanho da linha da matriz A deve ser igual ao tamanho de colunas da matriz B\n");
        }
   
    }while (tamColunMatA!=tamLinhaMatB);
    

    /*
     
        Agora que jah temos os tamanhos das matrizes podemos defini-las, declaramos tambem a matriz C que eh a 
     matriz que irah "receber" o resultado da multiplicacao das matrizes A e B
     
     e como a multiplicacao de matrizes eh dada por 
        
            linhaA x Coluna B (somatorio desses produtos)
     
     sabemos que a matriz C ou matriz resultante terah que ter o tamanho de linhas da matriz A e a quantidade de colunas
     da matriz B.
     
     
     */
    int matrizA[tamLinhaMatA][tamColunMatA], matrizB[tamLinhaMatB][tamColunMatB], matrizC[tamLinhaMatA][tamColunMatB];
    
    
    /*Preenchendo a matriz A */
    printf("\n\n **************** PREENCHA A MATRIZ A *******************\n\n\n");
    for (i=0; i<tamLinhaMatA; i++) {
        for (j=0; j<tamColunMatA; j++) {
            
            printf("Valor da posicao A[%d][%d]", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }
    
    
    /*  Preenchendo a matriz B */
    printf("\n\n **************** PREENCHA A MATRIZ A *******************\n\n\n");
    
    for (i=0; i<tamLinhaMatB; i++) {
        for (j=0; j<tamColunMatB; j++) {
            
            printf("Valor da posicao B[%d][%d]", i,j);
            scanf("%d", &matrizB[i][j]);
        }
    }
    
    
     /* imprimindo a matriz A*/
    printf("\n Matriz A ");
    for (i=0; i<tamLinhaMatA; i++) {
        printf("\n");
        for (j=0; j<tamColunMatA; j++) {
            
            printf("%d  ",matrizA[i][j] );
        }
    }
    
    /* imprimindo a matriz B */
    
    printf("\n Matriz B ");
    for (i=0; i<tamLinhaMatB; i++) {
        printf("\n");
        for (j=0; j<tamColunMatB; j++) {
            
            printf("%d  ",matrizB[i][j] );
        }
    }
    
    
   
    for (i = 0; i< tamLinhaMatA; i++) {  // neste for o i assume todas as posicoes das linhas da matriz A
        for (j=0; j<tamColunMatB; j++) { // jah este pega todos os valores das colunas da matriz B
            
            somatorioMultiplicaoLinhaxColuna = 0; //
            
            for (k=0; k<tamColunMatA; k++) {
                
                /* 
                    K serve para pegar todos os valores que estao presentes na linha da matriz A
                 
                 */
                
                somatorioMultiplicaoLinhaxColuna += matrizA[i][k] * matrizB[j][k];
                
                /*
                   a variavel somatorioMultiplica.... armazena os valores da multiplicacao do valor atual
                 que estah na coluna da matriz B pelos valores que estao na linha da matriz A
                 */
            }
            
            
            // assim que tiver o resultado armazena na matriz C
            
           
            matrizC[i][j] = somatorioMultiplicaoLinhaxColuna;
            
        }
    }
    /*
        imprimindo a matriz C ou matriz resultante
     */
    printf("\n Matriz resultante : \n");
    for (i=0; i<tamLinhaMatA; i++) {
        printf("\n");
        for (j=0; j<tamColunMatB; j++) {
            
            printf("%d  ",matrizC[i][j] );
        }
    }
    return 0;
}