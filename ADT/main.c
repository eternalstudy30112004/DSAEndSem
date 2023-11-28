#include <stdio.h>
#include "arr.c"
int main(){
    array p, k, m;
    int n = 100;
    init(&p, n);
    init(&k, n);
    init(&m, n);
    printf("adf");
    insertAtIndex(&m, 0, 0);
    insertAtIndex(&m, 0, 0);
    display(m);
    printf("adf");

    append(&p, 69);
    append(&p, 96);
    append(&p, 71);
    append(&p, 6);
    append(&k, 69);
    append(&k, 96);
    append(&k, 71);
    append(&k, 6);

    append(&k, 619);
    display(k);
    insertAtIndex(&k, 1, 17);
    display(k);
    removeAtIndex(&k, 2);
    display(k);

    removeAtIndex(&k, 2);
    display(k);
    reverse(&k);
    printf("aaa");
    display(k);
    display(p);
    merge(&k, p);
    display(k);
    return 0;
}