#include "clist.c"
int main(){
    clist p;
    init(&p);
    traverse(p);

    insert_end(&p, 16); 
    insert_beg(&p, 10); 
    insert_beg(&p, 69); 
    traverse(p);
    delete_beg(&p); 
    traverse(p);
    delete_beg(&p); 
    traverse(p);
    
    delete_beg(&p); 
    traverse(p);
  
return 0;
    }