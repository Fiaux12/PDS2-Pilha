typedef struct Pilha Pilha;
typedef struct Elemento Elemento;

// Protótipos das funções

/*
 *  Cria uma pilha vazia
 *  @return Retorna um ponteiro para o ultimo elemento adicionado na pilha
 */
Pilha *criaPilha();
/*
 *  Adiciona um novo elemento a uma pilha
 *  @param pilha Pilha onde o valor será adicionado
 *  @param valor valor que será adicionado na pilha
 */
void push(Pilha *pilha, int valor);
/*
 *  Verifica se a pilha esta vezia
 *  @param pilha Pilha que será verificada
 *  @return Retorna 1 se estiver vazia e 0 caso contrário 
 */
int pilhaVazia(Pilha *pilha);
/*
 *  Remove o Ultimo elemento adicionado na pilha
 *  @param pilha Pilha que tera um elemento removido
 *  @return Retorna o valor que foi removido
 */
int pop(Pilha *pilha);
/*
 *  Desaloca o espaço de memoria da pilha como um todo
 *  @param pilha Pilha que será desalocada
 */
void pilhaLibera(Pilha *pilha);
/*
 *  Imprime os valor da pilha
 *  @param pilha Pilha que será mostrada
 */
void imprimePilha(Pilha *pilha);