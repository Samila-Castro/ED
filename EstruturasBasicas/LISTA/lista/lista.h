
typedef struct listaEstatica LISTA;

LISTA *create(int n);

int Find(LISTA *li, int elemento);

int add(LISTA *li, int elemento);

int isFull(LISTA *li);

int isEmpty(LISTA *li);
