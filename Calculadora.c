#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void Ler_Poli(double poli[])
{
    int grau;
    do{
        printf("\nDigite o grau do seu polinomio(menor ou igual a 10): ");
        scanf("%d", &grau);
        poli[0] = grau;
    }while(grau > 10);
    
    printf("\nA seguir digite os %d coeficientes\n", grau + 1);
    
    for (int i = 1; i <= grau + 1; i++){
        printf("Digite o polinomio %d: ", i);
        scanf("%lf", &poli[i]);
    }
}

int Opcao()
{
    int opcao;
    
    printf("\nEscolha um dos numeros para a opcao desejada\n");
    printf("[1] Calcular um polinomio\n");
    printf("[2] Somar os dois polinomios\n");
    printf("[3] Subtrair os dois polinomios\n");
    printf("[4] Multiplicar os dois polinomios\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);
    
    return opcao;
}

double MaiorGrau(double poli[], double poli2[])
{
    int grau;
    if (poli[0] < poli2[0]){
        grau = poli2[0];
    }else{
        grau = poli[0];
    }
    
    return grau;
}

void DiminuirGrau(double poli[12], double grau)
{
    double cont=0;

    for(int i = grau + 1;i >= 1;i--){ 
        if(poli[i] == 0){
           cont++;
        }else{
           break;
        }
    }
    
    grau = grau - cont;
    poli[0] = grau;
}

void imprimir_polinomio(double poli[])
{
    int grau = poli[0];
    
    if(grau > 0){
        for(int i = 1; i <= grau + 1; i++){
            if(i == 1){
                printf("%.0lf", poli[i]);
            }else if(i == 2 && poli[i] > 0){
                printf("+%.0lfX", poli[i]);
            }else if(i == 2 && poli[i] < 0){
                printf("%.0lfX", poli[i]);    
            }else if(i != 1 && poli[i] > 0){
                printf("+%.0lfX^%d", poli[i], i-1);
            }else if(poli[i] != 0){
                printf("%.0lfX^%d", poli[i], i-1);
            }
        }
    }else{
        printf("Valor de grau nao existe");
    }
}

double CalcularPoli(double poli[])
{
    double ValorY;
    double x;
    
    printf("Digite o valor de X para encontrar o polinomio: ");
    scanf("%lf", &x);
    Ler_Poli(poli);
    
    for (int i = 1;i <= poli[0] + 1; i++){
        ValorY = ValorY + (pow(x, i - 1) * poli[i]);
    }

    return ValorY;
}

void Repete_Leitura(double poli[], double poli2[])
{
    
    printf("\n\nPolinômio 1\n");
    Ler_Poli(poli);
    
    printf("\nPolinômio 2:\n");
    Ler_Poli(poli2);
    
}

void SomaPoli(double poli[], double poli2[])
{
    
    printf("\nSOMA DE DOIS POLINÔMIOS");
    Repete_Leitura(poli, poli2);
    
    double grau = MaiorGrau(poli, poli2);
    
    for(int i = 1;i <= grau + 1; i++){ 
       poli[i] = poli[i] + poli2[i];
    }

    DiminuirGrau(poli, grau);
    
}

void SubPoli(double poli[], double poli2[])
{
    
    printf("\nSUBSTRACAO DE DOIS POLINÔMIOS");
    Repete_Leitura(poli, poli2);
    
    double grau = MaiorGrau(poli, poli2);
    
    for(int i = 1;i <= grau + 1;i++){ 
       poli[i] = poli[i] - poli2[i];
    }

    DiminuirGrau(poli, grau);
    
}

void fazer_VetAux(double inical[], double final[])
{
    int tam = inical[0] + 2;
    for(int i = 0; i < tam; i++){
        final[i] = inical[i];
    }
}

void SomaCoe(double poli[], double poliR[], double AuxExp[], int ope)
{
    
    for(int i = 0;i <= poli[0]; i++){
        poli[i+1] = 0;
        for(int j = 1; j <= ope; j++){
            if(AuxExp[j] == i){
                poli[i+1] = poli[i+1] + poliR[j];
            }
        }
    }
}

bool Multi_Poli(double poli[], double poli2[])
{
    printf("\nMULTIPLICACAO DE DOIS POLINOMIOS");
    Repete_Leitura(poli, poli2);
    
    double poliR[36], AuxExp[36], vetAux[12];
    fazer_VetAux(poli, vetAux);
    double grau = MaiorGrau(poli, poli2);
    double grau1 = poli[0], grau2 = poli2[0];
    double grauT = grau1 + grau2;
    double ope = (grau1 + 1) * (grau2 + 1);
    int aux = 1;
    
    if (grauT <= 10){
        for(int i = 1; i <= grau1 + 1; i++){
            for(int j = 1; j <= grau2 + 1; j++){
                poliR[aux] = vetAux[i] * poli2[j];
                AuxExp[aux]= i + j - 2;
                aux++;
            }
        }
        poli[0] = grauT;
        SomaCoe(poli,poliR, AuxExp, ope);
        DiminuirGrau(poli, grauT);
        printf("\n");
        return true;
    }else{
        return false;
    }
} 

void Programa()
{

    double poli[12]={0}, poli2[12]={0};
    double ValorY;
    int opcao = Opcao();
    
    if (opcao == 1){
        ValorY = CalcularPoli(poli);
        printf("\nO valor do polinomio calculado e: %.2lf", ValorY);
        printf("\n");
    
    }else if(opcao == 2){
        SomaPoli(poli, poli2);
        printf("A soma entre os dois polinomios resultou em: ");
        imprimir_polinomio(poli);
        printf("\n");
    
    }else if(opcao == 3){
        SubPoli(poli, poli2);
        printf("A Subtracao entre os dois polinomios resultou em: ");
        imprimir_polinomio(poli); 
        printf("\n");
    
    }else if(opcao == 4){
        if(Multi_Poli(poli, poli2) == true){
            printf("A Multiplicao entre os dois polinomios resultou em: ");
            imprimir_polinomio(poli);
            printf("\n");
        }else{
            printf("Valor de grau maximo foi ultrapassado\n");
        }
        
    }else{
        printf("Opcao invalida\n");
    }
}

int main()
{
    int opcao_cont;
    
    printf("\033[0;34m");
    printf("-------------------------\n");
    printf("CALCULADORA DE POLINOMIOS\n");
    printf("-------------------------\n");
    printf("\033[0m");
    
    do {
        Programa();
        printf("\nDeseja repetir as operacoes?(1 pra sim ou 2 pra não): ");
        scanf("%d", &opcao_cont);
    }while(opcao_cont == 1);
    
    return 0;
}









