typedef struct  {
 	int codigo;
 	float valor;
}Compra;



 Compra* createCompra(int codigo, float valor);

 void printCompra(Compra *comp);
