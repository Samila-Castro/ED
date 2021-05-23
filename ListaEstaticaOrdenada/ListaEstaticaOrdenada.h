typedef struct
{
    int *vetor;
    int cont;
    int tam;
    //int fim;
} ListaEstaticaOrdenada;


ListaEstaticaOrdenada *create(int n);

int Find(ListaEstaticaOrdenada *li, int elemento);

int add(ListaEstaticaOrdenada *li, int elemento);

int isFull(ListaEstaticaOrdenada *li);

int isEmpty(ListaEstaticaOrdenada *li);

void Clear(ListaEstaticaOrdenada *li);

int bynarySearch(ListaEstaticaOrdenada *li, int chave);

int Remove(ListaEstaticaOrdenada *li, int elemento);

int Size(ListaEstaticaOrdenada *li);

void swap(int* v, int i, int j);

void printAll(ListaEstaticaOrdenada *li);
