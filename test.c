#include "collection.h"

// return x > y is True?
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

int main(void)
{
	/* Demo of APIs' usage */
	struct collection *collection = collection_new();

	/* Add variables to collection */
	collection_add_variable(collection, "x", 1, 2, 3, 5,0);
	collection_add_variable(collection, "y", 3, 5,0);     //输入测试用例 以0结束  0不会被计算在内 
	collection_add_variable(collection, "z", 1, 2, 3, 5,0);

	/* Add limits to collection */
	collection_add_limit(collection, (limit_fp_t)x_bigger_than_y);
	collection_add_limit(collection, (limit_fp_t)y_bigger_than_z);

	/* Travel all solutions */
	collection_travel_solution(collection, (travel_fp_t)print_result);
	system("pause");
	/* Expect:
	 *	x = 5, y = 3, z = 1
	 *	x = 5, y = 3, z = 2
	 *	x = 5, y = 3, z = 3
	 *	...
	 * */
};
