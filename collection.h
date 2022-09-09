#include "stdarg.h"
#include "stdbool.h"

/* Note:
 *   We just give you a **DEMO**.
 *   You can modify all the defintions if you want.
 * */

#define MAX_SIZE_COLLECTION 100

typedef bool (*limit_fp_t)(int size, struct item *list);
typedef void (*travel_fp_t)(int size, struct item *list);

typedef struct item {
	char *name;
	int val;
}item;

struct collection {
	/* You can define any variables you want. */
	int size;
	item list[MAX_SIZE_COLLECTION];
	limit_fp_t limit;
};

struct collection *collection_new(void);
int collection_add_variable(struct collection *c, char *var_name, int val0, ...);
int collection_add_limit(struct collection *c, limit_fp_t func);
int collection_travel_solution(struct collection *c, travel_fp_t func);

