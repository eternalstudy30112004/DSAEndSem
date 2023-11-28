#include "list.c"
int main(){
    list s1,s2;
    init(&s1);
    init(&s2);

    append(&s1, 1);
    traverse(s1);
    append(&s1, 2);
    traverse(s1);
    append(&s1, 1);
    traverse(s1);
   destroy(&s1);
    traverse(s1);
    insert_beg(&s1, 4);
    insert_beg(&s1, 6);
    insert_beg(&s1, 8);
    traverse(s1);
    append(&s1, 6-4);
    append(&s1, 8-4);
    traverse(s1);
    reverse_n(&s1);
    traverse(s1);
    reverse_even(&s1);
    traverse(s1);
    traverse(s1);
    delete_end(&s1);
    printf("exited");
    return 0;
}