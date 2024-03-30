typedef struct ListaDE ListaDE;

// Protótipos das funções

ListaDE *listaDE_cria();

ListaDE *listaDE_insere(ListaDE *lista, int v);

ListaDE *listaDE_busca(ListaDE *lista, int v);

ListaDE *listaDE_retira(ListaDE *lista, int v);

void listaDE_imprime(ListaDE *lista);
