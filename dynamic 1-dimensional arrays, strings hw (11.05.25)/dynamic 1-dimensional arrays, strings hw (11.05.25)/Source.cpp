#include "dyn_array_functions.h"

int main() {
	srand(time(0));
	int size;
	set_array_size(&size, true);
	int* ar;
	array_memory_allocation(&ar, size);
	random_fill_array(ar, size);
	print_array(ar, size);

	for (int i = 0; i < 1; i++)
	{
		//add_element_at_the_end_of_array(&ar, &size, 15);
		//delete_element_at_the_end_of_array(&ar, &size);
		//add_element_at_the_beginning_of_array(&ar, &size, 15);
		//delete_element_at_the_beginning_of_array(&ar, &size);
		//add_element_at_the_specified_index(&ar, &size, 15);
		delete_element_at_the_specified_index(&ar, &size);
		print_array(ar, size);
	}

	array_free_memory(ar);
}