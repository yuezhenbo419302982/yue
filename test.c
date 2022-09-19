#include "collection.h"

// return x > y is True?

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
