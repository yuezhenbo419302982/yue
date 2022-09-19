#include "stdarg.h"
#include "stdbool.h"
#include "string.h"
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
};
bool x_bigger_than_y(int size, struct item *list)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (strcmp(list[i].name, list[j].name) == 0)
			{
				if (list[i].val > list[j].val)
				{
					return true;
				}
			}
		}
	}
	return false;
}

// return y > z is True ?
bool y_bigger_than_z(int size, struct item *list)
{
	int i, j, k;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (strcmp(list[i].name, list[j].name) == 0)
			{
				for (k = j + 1; k < size; k++)
				{
					if (strcmp(list[j].name, list[k].name) == 0)
					{
						if (list[j].val > list[k].val)
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

// print solution to screen
void print_result(int size, struct item *list)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if(!i) printf("%s = %d", list[i].name, list[i].val);
		else printf(", %s = %d", list[i].name, list[i].val);
	}
	printf("\n");
}

struct collection *collection_new(void);
int collection_add_variable(struct collection *c, char *var_name, int val0, ...);
int collection_add_limit(struct collection *c, limit_fp_t func);
int collection_travel_solution(struct collection *c, travel_fp_t func);
