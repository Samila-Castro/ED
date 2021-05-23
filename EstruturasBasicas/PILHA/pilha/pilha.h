
typedef struct pilha Pilha;

Pilha *create(int n);

int add(Pilha *pi, int elemento);

int top(Pilha *pi);

int botton(Pilha *pi);

int isEmpty(Pilha *pi);

int isFull(Pilha *pi);

int pop(Pilha *pi);

int Size(Pilha *pi);

int Find(Pilha *pi, int dado);

int Clear(Pilha *pi);
