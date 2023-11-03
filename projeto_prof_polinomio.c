#include <stdio.h>
#include <stdlib.h>
#include "projeto_prof_polinomio.h"
#include <math.h>  // Importa a biblioteca para usar a função pow().

Polynomial *createPolynomial() {
    Polynomial *poly = (Polynomial *)malloc(sizeof(Polynomial));
    poly->terms = NULL; // Inicializa a lista de termos como vazia
    return poly;
}

void addTerm(Polynomial *poly, int coefficient, int exponent) {
    PolynomialTerm *newTerm = (PolynomialTerm *)malloc(sizeof(PolynomialTerm));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;

    if (poly->terms == NULL) {
        poly->terms = newTerm;
    } else {
        PolynomialTerm *current = poly->terms;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

void removeTerm(Polynomial *poly, int exponent) {
    if (poly->terms == NULL) {
        return; // O polinômio está vazio, não há termos para remover.
    }

    if (poly->terms->exponent == exponent) {
        PolynomialTerm *temp = poly->terms;
        poly->terms = poly->terms->next;
        free(temp);
        return;
    }

    PolynomialTerm *current = poly->terms;
    while (current->next != NULL) {
        if (current->next->exponent == exponent) {
            PolynomialTerm *temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

int evaluatePolynomial(Polynomial *poly, int x) {
    int result = 0;
    PolynomialTerm *current = poly->terms;
    while (current != NULL) {
        result += current->coefficient * pow(x, current->exponent);
        current = current->next;
    }
    return result;
}

Polynomial *addPolynomials(Polynomial *poly1, Polynomial *poly2) {
    // Implementação para somar dois polinômios
    Polynomial *result = createPolynomial();
    PolynomialTerm *term1 = poly1->terms;
    PolynomialTerm *term2 = poly2->terms;

    while (term1 != NULL || term2 != NULL) {
        int coeff1 = 0, coeff2 = 0, exp1 = 0, exp2 = 0;

        if (term1 != NULL) {
            coeff1 = term1->coefficient;
            exp1 = term1->exponent;
            term1 = term1->next;
        }
        if (term2 != NULL) {
            coeff2 = term2->coefficient;
            exp2 = term2->exponent;
            term2 = term2->next;
        }

        int sum_coeff = coeff1 + coeff2;
        addTerm(result, sum_coeff, exp1);  // Adiciona o termo somado ao resultado.
    }
    return result;
}

void printPolynomial(Polynomial *poly) {
    // Implementação para imprimir o polinômio
    PolynomialTerm *term = poly->terms;
    while (term != NULL) {
        if (term->coefficient != 0) {
            if (term->coefficient > 0) {
                if (term != poly->terms) {
                    printf(" + ");
                }
            } else {
                printf(" - ");
            }
            if (abs(term->coefficient) != 1 || term->exponent == 0) {
                printf("%d", abs(term->coefficient));
                if (term->exponent != 0) {
                    printf(" * ");
                }
            }
            if (term->exponent > 0) {
                printf("x");
                if (term->exponent > 1) {
                    printf("^%d", term->exponent);
                }
            }
        }
        term = term->next;
    }
    printf("\n");
}

void destroyPolynomial(Polynomial *poly) {
    PolynomialTerm *current = poly->terms;
    while (current != NULL) {
        PolynomialTerm *temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}
