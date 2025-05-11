#include <iostream>
#include <windows.h>
using namespace std;

void array_free_memory(int* ar);
void print_array(int* ar, const unsigned int size);
void random_fill_array(int* ar, const unsigned int size, int min = 0, int max = 100);
void set_array_size(int* psize, bool user_input = false);
void array_memory_allocation(int** ar, const unsigned int size);
void add_element_at_the_end_of_array(int** par, int* psize, int value);
void delete_element_at_the_end_of_array(int** par, int* psize);

//hw
void add_element_at_the_beginning_of_array(int** par, int* psize, int value);
void delete_element_at_the_beginning_of_array(int** par, int* psize);
void add_element_at_the_specified_index(int** par, int* psize, int value);
void delete_element_at_the_specified_index(int** par, int* psize);


void print_array(int* ar, const unsigned int size) {
	for (int i = 0; i < size; i++) {
		cout << ar[i] << ", ";
	}
	cout << "\n";
}

void random_fill_array(int* ar, const unsigned int size, int min, int max) {
	int k = max - min + 1;
	for (int i = 0; i < size; i++)
		ar[i] = rand() % k + min;
}

void set_array_size(int* psize, bool user_input) {
	if (user_input) {
		cout << "Please, enter size of array (5-100000): ";
		cin >> *psize;
		if (*psize <= 0) *psize = 5;
		if (*psize > 100000) *psize = 100000;
	}
	else
		*psize = 10;
}

void array_memory_allocation(int** ar, const unsigned int size) {
	(*ar) = new int[size];
	if (*ar == nullptr) {
		cout << "Oops! Memory was not allocated!\n";
		exit(0);
	}
	ZeroMemory(*ar, size * sizeof(int));
}

void array_free_memory(int* ar) {
	delete[] ar;
}

void add_element_at_the_end_of_array(int** par, int* psize, int value) {
	int* temp = new int[*psize + 1]; 
	for (int i = 0; i < *psize; i++) 
		temp[i] = (*par)[i];
	temp[*psize] = value; 
	delete[](*par); 
	*par = temp; 
	(*psize)++;
}

void delete_element_at_the_end_of_array(int** par, int* psize)
{
	int* temp = new int[*psize - 1];
	for (int i = 0; i < *psize - 1; i++)
		temp[i] = (*par)[i];
	delete[](*par);
	*par = temp;
	--(*psize);

}

void add_element_at_the_beginning_of_array(int** par, int* psize, int value)
{
	int* temp = new int[*psize + 1];
	temp[0] = value;
	for (int i = 0; i < *psize; i++)
		temp[i + 1] = (*par)[i];
	delete[](*par);
	*par = temp;
	++(*psize);
}

void delete_element_at_the_beginning_of_array(int** par, int* psize)
{
	int* temp = new int[*psize - 1];
	for (int i = 0; i < *psize - 1; i++)
		temp[i] = (*par)[i];
	delete[](*par);
	*par = temp;
	--(*psize);
}



void add_element_at_the_specified_index(int** par, int* psize, int value)
{
	int index;
	int* temp = new int[*psize + 1];
	cout << "choose on what place should we put your number: \n1st place is a 0\n2nd is 1\netc..\n";
	cin >> index;
	for (int i = 0; i < index; i++)
		temp[i] = (*par)[i];
	temp[index] = value;
	for (int i = index; i < *psize;i++)
		temp[i + 1] = (*par)[i];
	delete[](*par);
	*par = temp;
	++(*psize);
}

void delete_element_at_the_specified_index(int** par, int* psize)
{
	int index;
	int* temp = new int[*psize + 1];
	cout << "choose on what place should we delete number: ";
	cin >> index;
	for (int i = 0; i < index; i++)
		temp[i] = (*par)[i];
	for (int i = index; i < *psize; i++)
		temp[i - 1] = (*par)[i];
	delete[](*par);
	*par = temp;
	--(*psize);
}