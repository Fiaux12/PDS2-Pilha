typedef struct lista Lista;

// Protótipos das funções

Lista* lista_cria();

Lista* lista_insere(Lista *l, int i);

void lista_imprime(Lista *l);

int lista_vazia(Lista *l);

Lista* lista_busca(Lista *l, int v);

Lista *lista_retira(Lista *l, int v);

void lista_libera(Lista *l);

int lista_igual(Lista *l1, Lista *l2);

Lista *lista_insere_ordenado(Lista *l, int v);