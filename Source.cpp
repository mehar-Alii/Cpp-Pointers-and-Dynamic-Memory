#include<iostream>
using namespace std;

void increment(int a) {
	a = a + 1;
	// this will only increment the value of local variable 
	// if we pritn while in t function it will print thte incremented value if a is 8 it will pritn 9
	// but if we use the same a in main it will print a it will display a as 8
	// this is normally callled pass by value
}
void inc(int* addressofvaraible) {
	*addressofvaraible = *addressofvaraible + 1;
	// this is pass by reference
	// here we are dreferencing and incrementing the value stored at the address which was passed in formal argument
}
int sumOfElemnts(int arr[], int size) {
	int sum = {};
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}
int sum(int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(arr + i);
	}
	return sum;
}
void print(char* chararr) {
	for (int i = 0; chararr[i] != '\0'; i++) {
		cout << chararr[i];
	}
	cout << endl;
	cout << "same thing but diferent way" << endl;
	for (int i = 0; *(chararr + i) != '\0'; i++) {
		cout << *(chararr + i);
	}
	cout << endl;
}
void print1(char chararr[]) {
	for (int i = 0; chararr[i] != '\0'; i++) {
		cout << chararr[i];
	}
	cout << endl;
}
// 2D array's functions
int sum2D(int arr[][3], int size) {
	int sum = {};
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
int sum2D1(int (*arr)[3], int size) {
	int sum = {};
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
void print2D(char (*chararr)[100], int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; chararr[i][j] != '\0'; j++) {
			cout << chararr[i][j];
		}
		cout << endl;
	}
}
// dynamic array functions
int sumdynamic(int** arr, int rows, int cols) {
	int sum = {};
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
void printdynamic(char** arr, int rows) {
	for (int i = 0; i < rows; i++) {
		cout << arr[i] << endl;
	}
}
// return throught pointers
int* square(int* a, int* b) {
	int c;
	c = (*a) * (*b);
	return &c; // we are just returning the address of c variable
	// in the main funciton it will be called as
	// int* ptr = squre(&a,&b);
}
char* hellostring(char* arr) {
	char* temp = new char[strlen(arr) + 7];
	strcpy_s(temp,7, "hello ");
	int j = 0;
	for (int i = 6; arr[j] != '\0'; i++, j++) {
		temp[i] = arr[j];
	}
	temp[6+j] = '\0';
	return temp;
}
int main() {
	// basic know how
	{
	int a = 5;
	int* ptra = &a;
	cout << *ptra << endl; // print 5
	cout << a << endl; // print 5
	cout << &a << '\n'; // print address of a such as 4200
	cout << ptra << '\n'; // print address of a such as 4200
	cout << &ptra << '\n'; // print address of ptra such as 5300

	int** ptrptra;
	ptrptra = &ptra; 
	cout << &ptrptra << '\n'; // print address of ptrptra such as 8900
	cout << ptrptra << '\n'; // print value stored in ptrptra which is 5300 bcz it sore the address of ptra
	cout << *ptrptra << '\n'; // print value sotred in ptra as it is dereferencing so it will print 4200
	cout << **ptrptra << '\n'; // print 5 double dereferrencing
	cout << endl;
	}
	// pointers in functions
	{
	int b = 9;
	cout << "address of b is " << &b << endl;
	cout << "value store at b is " << b << endl;
	increment(b);
	cout << "value of b after increment function " << b << endl;
	inc(&b); // we are passing the address of varable b
	cout << "Value of b after inc function " << b << endl;
	cout << endl;
	}
	// pointers and arrays
	{
	int arr[5] = { 2,4,6,8,10 };
	int* ptrarr;
	ptrarr = arr;
	cout << arr << endl; // this will print the address of starting index
	cout << &arr[0] << endl; // this will print the address of 0th index which is same as starting index address
	cout << *arr << endl; // this will print the value of starting index
	// element at index i
	// (arr + i) and &arr[i] gives the address of i
	// *(arr + i) and arr[i] gives the value of i
	cout << endl;
	}
	// arrays as functions arguements
	{
	int arr1[5] = { 1,2,3,4,5 };
	int total = sumOfElemnts(arr1, 5);
	int total1 = sum(arr1, 5);
	cout << "Summ of all elemnts of arr1 is from sumOfElements function  : " << total << endl;
	cout << "Summ of all elemnts of arr1 is from sum funciton  : " << total1 << endl;
	cout << endl;
	}
	// character arrays and pointers
	{
	char chararr[4];
	chararr[0] = 'a';
	chararr[1] = 'l';
	chararr[2] = 'i';
	//chararr[3] = '\0';
	cout << "this is going to be a little mess " << chararr << endl;
	char chararr1[4] = {"for"}; // this has automatically put \0 at the end or at 3rd index
	char chararr2[4] = { 'f','o','r','\0' }; // '' this is used for single character
	cout << chararr1 << endl; // "" this is used for the mutiple characters
	cout << chararr2 << endl;
	// if we are using cin to fill the elemnts of char array we have to expicitly add \0
	cout << endl;
	// arrays and pointers are different types that are used in a similar manner
	char chararr3[20] = {"hello"};
	char* ptrchararr3;
	ptrchararr3 = chararr3;
	for (int i = 0; *(ptrchararr3 + i) != '\0'; i++) {
		cout << *(ptrchararr3 + i);
	} // so here we have just used the address of first index of chararr3 and give that address tp ptrchararr3 and then derefernce it and the incrementing the address
	cout << endl;
	cout << endl;
	}
	// character arrays as function arguments
	{
	char chararr4[] = {"hello"};
	cout << "print function " << endl;
	print(chararr4);
	cout << "print1 funtion " << endl;
	print1(chararr4);
	cout << endl;
	cout << endl;
	}
	// pointers and multidimensional arrays
	{
	int B[2][3] = {   {   1        ,2          ,3},       {      4         ,5         ,6} };
	//              B[0] B[0][0]    B[0][1]   B[0][2]    B[1]  B[1][0]    B[1][1]    B[1][2]
	// print address of first array of B i.e. B[0]
	cout << B << endl; 
	cout << &B[0] << endl; 
	cout << *B << endl; 
	cout << B[0] << endl; 
	cout << &B[0][0] << endl; 
	// print the address of second array of B i.e. B[1]
	cout << B + 1 << endl; 
	cout << &B[1] << endl;
	cout << *(B + 1) << endl;
	cout << B[1] << endl;
	cout << &B[1][0] << endl;
	cout << endl;
	// print address of B[0][0]
	cout << *B << endl;
	// print address of B[0][1]
	cout << *B + 1 << endl;
	// print address of B[0][]
	cout << *B + 2 << endl;
	// print address of B[1][0]
	cout << *B + 3 << endl;            //    *(B + 1) 
	// print address of B[1][1]
	cout << *B + 4 << endl;            // *(B + 1) + 1
	// print address of B[1][2]
	cout << *B + 5 << endl;            // *(B + 1) + 2
	// B[i][j] == *(B[i]+j) == *(*(B+i)+j)
	cout << endl;
	}
	// pointer and multidimensional arrays as arguments in funcitons
	{
	int arr2[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	cout << "from sum2D : ";
	int sum = sum2D(arr2, 2);
	cout << sum << endl;
	cout << "from sum2D1 : ";
	int sum1 = sum2D1(arr2, 2);
	cout << sum1 << endl;
	cout << endl;
	char chararr6[2][100] = {
		{"Hello"},
		{"world"}
	};
	print2D(chararr6, 2);
	cout << endl;
	}
	// Dynamic memory
	// single variable
	{
	int* ptr1;
	ptr1 = new int;
	*ptr1 = 10;
	cout << "this address is at the heap :" << ptr1 << endl;
	cout << *ptr1 << " this is the value store at the heap address " << ptr1 << endl;
	delete ptr1;
	ptr1 = nullptr;
	cout << endl;
	// array
	int* ptr2;
	ptr2 = new int[5];
	cout << "these addresses are on the heap " << endl;
	for (int i = 0; i < 5;i++) {
		cout << ptr2 + i << endl;
	}
	for (int i = 0; i < 5; i++) {
		ptr2[i] = i + 1;
	}
	for (int i = 0; i < 5; i++) {
		cout << ptr2[i] << " ";
	}
	cout << endl;
	delete[] ptr2;
	ptr2 = nullptr;
	cout << endl;
	}
	// char variable
	{
	char* ptr3;
	ptr3 = new char;
	cout << "this is the garbage data stored in ptr3 at address " << &ptr3 << endl;
	cout << *ptr3 << endl;
	*ptr3 = 'a';
	cout << *ptr3 << endl;
	delete ptr3;
	ptr3 = nullptr;
	cout << endl;
	}
	// char array
	{
	cout << "dyanmic array for character array" << endl;
	char* ptr4;
	ptr4 = new char[25];
	char hello[] = { "hello" };
	int x = 0;
	for (; hello[x] != '\0'; x++) {
		ptr4[x] = hello[x];
	}
	ptr4[x] = '\0';
	cout << "this is the pritn out from the loop :" << endl;
	for (int i = 0; ptr4[i] != '\0'; i++) {
		cout << ptr4[i];
	}
	cout << endl;
	cout << "this is direct cout " << endl;
	cout << &ptr4 << endl;
	cout << *(ptr4) << endl;
	delete[] ptr4;
	ptr4 = nullptr;
	cout << endl;
	}
	// dynamic memory for multidimensional arrays
	// integer arrays
	{
	cout << "2d integer dynamic array " << endl;
	int** ptr5;
	ptr5 = new int* [2];
	for (int i = 0; i < 2; i++) {
		ptr5[i] = new int[3];
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			ptr5[i][j] = j + 1;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ptr5[i][j] << " ";
		}
		cout << endl;
	}
	int sum3 = sumdynamic(ptr5, 2, 3);
	cout << "sum 3 is : " << sum3 << endl;
	for (int i = 0; i < 2; i++) {
		delete[]ptr5[i];
	}
	delete[] ptr5;
	ptr5 = nullptr;
	}
	// character array
	{
	char** ptr6;
	ptr6 = new char* [3];
	for (int i = 0; i < 3; i++) {
		ptr6[i] = new char[25];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 24; j++) {
			ptr6[i][j] = 'a' + j;
		}
	}
	for (int i = 0; i < 3; i++) {
		ptr6[i][24] = '\0';
	}
	for (int i = 0; i < 3; i++) {
		cout << ptr6[i] << endl;
	}
	cout << "this is from print function " << endl;
	printdynamic(ptr6, 3);
	for (int i = 0; i < 3; i++) {
		delete[]ptr6[i];
	}
	delete[] ptr6;
	ptr6 = nullptr;
	}
	// returning as functions
	// integers
	{
	int a1 = 9;
	int b1 = 2;
	int* ptr7 = square(&a1,&b1);
	cout << *ptr7 << endl;
	ptr7 = nullptr;
	}
	// character arrays
	{
	char ali[] = { "ali" };
	char *arr5 = hellostring(ali);
	cout << arr5 << endl;
	}
	return 0;
}
