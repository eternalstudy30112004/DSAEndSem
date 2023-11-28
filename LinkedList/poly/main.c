#include "list.c"

#include <stdio.h>
list Gsum(list p1, list p2, int mul)
{
    node *p, *q;
    list *result = (list *)malloc(sizeof(list));
    init(result);
    p = p1;
    q = p2;
    int highest = p1->degree > p2->degree ? p1->degree : p2->degree;

    while (p != NULL && q != NULL)
    {
        if (p->degree > q->degree)
        {
            append(result, p->degree, p->con);
            p = p->next;
        }
        else if (p->degree < q->degree)
        {
            append(result, q->degree, mul * q->con);
            q = q->next;
        }
        else
        {
            if (p->con + mul*q->con)
                append(result, q->degree, p->con + mul*q->con);
            p = p->next;
            q = q->next;
        }
    }

    while (q != NULL)
    {
        append(result, q->degree, mul * q->con);
        q = q->next;
    }
    while (p != NULL)
    {
        append(result, p->degree, p->con);
        p = p->next;
    }

    return *result;
}

list sum(list p1, list p2)
{
    return Gsum(p1, p2, 1);
}
list diff(list p1, list p2)
{
    return Gsum(p1, p2, -1);
}

int main()
{
    list p1, p2;
    init(&p1);
    init(&p2);
    append(&p1, 3, 7);
    append(&p1, 1, 4);
    append(&p1, 0, 3);
    traverse(p1);
    append(&p2, 4, 5);
    append(&p2, 3, 7);
    append(&p2, 2, 1);
    append(&p2, 1, 4);
    traverse(p2);
    list s = sum(p1, p2);
    traverse(s);
    list d = diff(p1, p2);
    traverse(d);
    return 0;
}