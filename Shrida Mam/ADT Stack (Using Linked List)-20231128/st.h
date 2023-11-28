typedef struct node{
	int data;
	struct node *next;
}node;

typedef node* list;

typedef struct stack{
	list l;
	node *top;
}stack;

void init_stack(stack *s);
void init_list(list *l);
int isempty(stack s);
void push(stack *s,int d);
int pop(stack *s);
int peek(stack s);
void insert(list *l,int d);
void delete1(list *l);
int isemptyl(list l);
void display(stack s);


