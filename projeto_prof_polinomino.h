typedef struct PolynomialTerm {
    int coefficient;               // Coeficiente do termo
    int exponent;                  // Expoente do termo
    struct PolynomialTerm *next;   // Próximo termo na lista
} PolynomialTerm;

typedef struct Polynomial {
    PolynomialTerm *terms;         // Lista de termos do polinômio
} Polynomial;

Polynomial *createPolynomial();              // Cria um polinômio vazio
void addTerm(Polynomial *poly, int coefficient, int exponent);  // Adiciona um termo ao polinômio
void removeTerm(Polynomial *poly, int exponent);  // Remove um termo do polinômio
int evaluatePolynomial(Polynomial *poly, int x);  // Avalia o polinômio para um valor de x
Polynomial *addPolynomials(Polynomial *poly1, Polynomial *poly2);  // Soma dois polinômios
void printPolynomial(Polynomial *poly);        // Imprime o polinômio
void destroyPolynomial(Polynomial *poly);       // Libera a memória alocada para o polinômio





