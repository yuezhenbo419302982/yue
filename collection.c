#include "collection.h"

// Declare Collection
struct collection *collection_new(void)
{
    struct collection *c = (struct collection *)malloc(sizeof(struct collection));
    c->size = 0;
    return c;
}

// Increase the key value of the deformable parameter (values are multiple)
int collection_add_variable(struct collection *c, char *var_name, int val0, ...)
{
    va_list ap;
    va_start(ap, val0);
    c->list[c->size].name = var_name;
    c->list[c->size].val = val0;
    c->size++;
    while (1)
    {
        int val = va_arg(ap, int);
        if (val == 0)       ///这里关于可变参数的跳出测试很多次  理论上讲valist在参数放空后会指向0 但在Devc的环境下
            break;
        c->list[c->size].name = var_name;
        c->list[c->size].val = val;
        c->size++;
    }
    va_end(ap);
    return 0;
}

// Increase dependencies when adding elements
int collection_add_limit(struct collection *c, limit_fp_t func)
{
    c->limit = func;
    return 0;
}

// Enumerate each to judgment satisfy x >= y && y >= z is True?
int collection_travel_solution(struct collection *c, travel_fp_t func)
{
    int i = 0, j = 0, k = 0;
    int ied = i;
    while(ied < c->size && strcmp(c->list[ied].name, c->list[i].name) == 0) ied ++;
    j = ied;
    int jed = ied;
    while(jed < c->size && strcmp(c->list[jed].name, c->list[j].name) == 0) jed ++;
    k = jed;
    int ked = jed;
    while(ked < c->size && strcmp(c->list[ked].name, c->list[k].name) == 0) ked ++;
    struct item *list = (item*)malloc(3 * sizeof (item));
    
    int u, w, v;
    for(u = i; u < ied; u ++)
        for(w = j; w < jed; w ++)
            for(v = k; v < ked; v ++) {
                if(c->list[u].val >= c->list[w].val
                    && c->list[w].val >= c->list[v].val) {
                    list[0] = c->list[u];
                    list[1] = c->list[w];
                    list[2] = c->list[v];
                    func(3, list);
                }
            }
    return 0;
}
