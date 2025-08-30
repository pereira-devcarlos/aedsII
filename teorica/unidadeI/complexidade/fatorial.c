#include <stdio.h>

// Função recursiva para calcular o fatorial
long fatorialRecursivo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fatorialRecursivo(n - 1);
}

// Função iterativa para calcular o fatorial
long fatorialIterativo(int n) {
    long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int numero;
    
    // Solicita ao usuário que insira um número
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &numero);
    
    if (numero < 0) {
        printf("Fatorial não existe para números negativos.\n");
        return 1;
    }
    
    // Calculando o fatorial usando ambas as funções
    long resultadoRecursivo = fatorialRecursivo(numero);
    long resultadoIterativo = fatorialIterativo(numero);
    
    // Exibindo os resultados
    printf("Fatorial (Recursivo) de %d: %ld\n", numero, resultadoRecursivo);
    printf("Fatorial (Iterativo) de %d: %ld\n", numero, resultadoIterativo);
    
    return 0;
}
