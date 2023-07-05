// hw08.cpp
// to illustrate pointers, pointer arithmetic & dynamic memory

/*************************************************************************
 * AUTHOR     : Navid Nikoo
 * HW08       : pointers, pointer arithmetic & dynamic memory
 * CLASS      : CS 1C
 * SECTION    : Date & Time
*************************************************************************/

#include <iostream>

using namespace std;

// function definitions go into hw08.cpp:

// hw08.cpp

namespace hw08 {

const int ARRAY_SIZE = 5;
const int DYNAMIC_SIZE = 15;
const int TIC_TAC_TOE_SIZE = 3;

// function definitions:

//------------------------------------------------------------------------------

int  increment_value(int x)
    // pass a value, compute a new value by adding 5 to x and return it
{
    return x += 5;
              // temp, replace when defining function
}

void increment_pointer(int* p)
    // pass a pointer, increment value of p by 1
{
    *p = *p + 1;
}

void increment_reference(int& r)
    // pass a reference, increment value of r by 1
{
    r++;
}

//------------------------------------------------------------------------------

void print_2darray_subscript(double twoDD[][ARRAY_SIZE], int row, int col)
    // print array using subscripts
{
    for(int i=0;i<row;i++)
    {
        for(int j=0; j<col; j++) cout << twoDD[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void print_2darray_pointer(double* twoDD, int row, int col)
    // print array using pointer arithmetic
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            // our 2d array is layed out linearly in memory as contiguous rows, one after another, there are #row rows
            // each row has #col columns
            cout << *(twoDD + i*col + j) << " ";
            // to compute the offset using pointer math
            // offset from twoDD: #row (i) * #col + #col (j), result: pointer to array element
            // ...
        }
        cout << endl;
    }
    cout << endl;
}

//------------------------------------------------------------------------------

void print_2darray_dynamic_subscript(int** twoDD, int row, int col)
    // print array using subscripts
{
    for(int i=0;i<row;i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << twoDD[i][j] << " ";
            cout << endl;
        }
    }
    cout << endl;
}

void print_2darray_dynamic_pointer(int** twoDD, int row, int col)
    // print array using pointer arithmetic
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            // our dynamic 2d array is an array of int pointers
            // each component in the array itself points to an array of ints
            // dynamic array rows are not contiguous in memory

            // to compute the offset using pointer math
            // offset from twoDD: move to the correct row, add #row (i), dereference to obtain pointer to row
            //                    next, add #col (j), result: pointer to array element
            // ...
        }
        cout << endl;
    }
    cout << endl;
}

//------------------------------------------------------------------------------

double* dynamic_allocation_array_doubles(int array_size)
    // the caller is responsible for the memory allocated
{
    int* pi_array = new int[DYNAMIC_SIZE];
    // function uses pi_array
    // function responsible for cleaning up (i.e. deleting) memory allocated for pi_array
    // do stuff here with pi_array
    double* pd_array = new double[array_size];
    // ...    // dynamic memory allocated for pi_array not needed any longer, free it
    return pd_array;
}

//------------------------------------------------------------------------------

} // hw08

//------------------------------------------------------------------------------

int main()
{
    // console header
    cout << endl;
    cout << "************************************** " << endl;
    cout << "*           Running HW08             * " << endl;
    cout << "*      Programmed by First Last      * " << endl;
    cout << "*      CS1C Date & Time              * " << endl;
    cout << "************************************** " << endl;
    cout << endl;

    // complete the following pointer examples
    // indicate if the requested operation is not allowed, why not?
    // Q#1 - pointer examples
    int x = 10;
    // ... // [1.1] variable p of type pointer to int points to x (i.e. int* p = ?;), use & to get the address of x
    int* p = &x;
    
    // ... // [1.2] variable q of type pointer to double is points to x
    //double* q = &x; It will not work as a value can only be one pointer type
    
    // ... // [1.3] update the value of p to 5, use * to assign to x through p
    *p = 5;
    // ... // [1.4] store the value of p in variable x2 of type int, use * to read x through p
    int x2 = *p;
    
    // ... // [1.5] variable p2 of type pointer to int points to x2, use & to get a pointer to x2
    int* p2 = &x2;
    
    // ... // [1.6] assign p to p2, p2 and p both point to x
    p = p2;
    
    // ... // [1.7] point p to x2, what does p2 point to now?
    p = &x2;

    // complete the following reference examples
    // indicate if the requested operation is not allowed, why not?
    // Q#1 - reference examples
    int y = 50;
    // ... // [1.8] variable r of type reference to int refers to y (i.e. int& r = ?;), nothing special to do here in the initializer
    int& r = y;
    
    // ... // [1.9] variable s of type reference to double refers to y
    //double& s = y; does not work because y can only work with one type
    
    
    // ... // [1.10] update the value of r to 10, assign to y through r (notice * is not needed)
    r = 10;
    
    // ... // [1.11] store the value of r in variable y2 of type int, read y through r (notice * is not needed)
    int y2 = r;
    
    // ... // [1.12] variable r2 of type reference to int refers to y2, get a reference to int y2
    int& r2 = y2;
    
    // ... // [1.13] assign r to r2, the value of y is assigned to y2
    r = r2;
    
    // ... // [1.14] assign y2 to r, r2 and r both point to y2
    y2 = r;
    
    // ... // [1.15] variable r3 of type reference to int is defined but not initialized (i.e. does not refer to an int)
    //int& r3; Does not work, it needs initializer otherwise it is just an empty data slot
    
    // Q#1 - pointer vs reference: increment functions
    // implementation the function definitions for the following increment operations
    { // allows definition of variables within block scope avoiding redefinition errors
        int x = 100;
        int x2 = 25;
        int* p = &x2;
        int& r = x;

        cout << "increment pointer vs reference" << endl << endl;

        cout << x << endl;
        cout << hw08::increment_value(x) << endl; // x not changed when passed by value
        cout << x << endl;

        cout << x2 << endl;
        hw08::increment_pointer(p); // p points to x2, x2 updated
        cout << x2 << endl;

        cout << x << endl;
        hw08::increment_reference(r); // r refers to x, x updated
        cout << x << endl;
    }

    // complete the following pointer arithmetic examples
    // indicate if the requested operation is not allowed, why not?
    // Q#2 - pointer arithmetic
    double aDoubles[10];
    double aDoubles2[10];
    double* pd = &aDoubles[5]; // point to aDoubles[5]
    double* pd2 = &aDoubles[7]; // point to aDoubles[7]
    double* pd3 = &aDoubles2[7]; // point to aDoubles[7]

    *pd = 3;
    pd[2] = 4;
    pd[-3] = 5;
    pd2[5] = 6;

    // ... // [2.1] move pd three elements to the right
    pd += 3;
    
    // ... // [2.2] move pd six elements to the left
    pd -= 6;
    
    //pd += 1000;    // [2.3] // ... error explain. There is an error because the array is fixed to size 10
    //double d = *pd;// [2.4] // ... error explain. This would not work because d is a variable and *pd works with arrays
    //*pd = 12.34;   // [2.5] // ... error explain. This work not work because we are giving a container a value

    // ... // [2.6] compute the number of elements between pd and pd2 by taking the difference between pd2 and pd
    double elements = pd2 - pd;
    cout << elements << endl;
    //int dif2 = pd + pd2; // [2.7] // ... error explain. It would not work because pd is of type double and not int.
    //int dif3 = pd2 - pd3;// [2.8] // ... error explain. It would not work because pd is of type double and not int.

    cout << endl << "print array of doubles forward and backward" << endl << endl;

    // [2.9] print array going forwards
    // p starts at address aDoubles[0], ends at address &aDoubles[9], increment p, cout value pointed to by p
    //for (double* p = // ... ) cout << // ...  << '\n';
    for(double* p = &aDoubles[0]; p <= &aDoubles[9]; p++){
        cout << *p << '\n';
    }
    
    cout << endl;

    // [2.10] print array going backwards
    // p starts at address aDoubles[9], ends at address &aDoubles[0], decrement p, cout value pointed to by p
    //for (double* p = // ... ) cout << // ...  << '\n';
    for(double* p = &aDoubles[9]; p > &aDoubles[0];p--){
        cout << *p << endl;
    }
    
    cout << endl;

    double* pd4 = &aDoubles[0];
    double* pd5 = aDoubles+5;
    double* pd6 = &aDoubles[5];
    double* pd7 = &aDoubles2[5];
    // [2.11] using the equality operator, compare pointers to array elements
    //if (// ...) cout << "pointers point to the same element of the array" << endl;
    if(pd5 == pd6)
    {
        cout << "Pointers point to the same element of the array!" << '\n';
    }
    else
    {
        cout << "Pointers do not point to the same element of the array!" << '\n';
    }
    
    // [2.12] ... error explain
    //if (pd6 != pd7) cout << "pointers point to the different elements of the array" << endl; the statement will be executed because they do point at different memory locations. So they're not the same although the statement says it is

    // complete the following function implementations
    // Q#3 - pointer arithmetic, indexing multidimensional arrays
    double twoDDoubles[hw08::ARRAY_SIZE][hw08::ARRAY_SIZE] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    
    cout << endl << "print 2d array of doubles" << endl << endl;

    // print 2ddoubles via subscript operator
    hw08::print_2darray_subscript(twoDDoubles, hw08::ARRAY_SIZE, hw08::ARRAY_SIZE);
    // print 2ddoubles via pointer arithmetic
    hw08::print_2darray_pointer((double*)twoDDoubles, hw08::ARRAY_SIZE, hw08::ARRAY_SIZE);

    // complete the following dynamic allocation examples
    // Q#4 - new, delete operator examples
    {
        int* pi = new int;                              // [4.1] allocate one int
        int* qi = new int[5];                           // [4.2] allocate five ints (an array of 5 ints)
        int& ri = *pi;
        int& ri2 = *qi;
        int*& ri3 = qi;
        ri = 100;
        ri2 = 200;

        double* pd = new double;                        // [4.3] allocate one double
        double* qd = new double[hw08::DYNAMIC_SIZE];    // [4.4] allocate DYNAMIC_SIZE doubles (an array of DYNAMIC_SIZE doubles)

        //pi = pd;  // [4.5] pi points to pd
                    // ... error explain. This would not work because pi is of type int and pd is of type double
        //pd = pi;  // [4.6] pd points to pi
                    // ... error explain. This would not work because pi is of type int and pd is of type double

        double x = *pd;       // read the (first) object pointed to by pd
        double y = qd[5];     // read the sixth object pointed to by qd
        double z = *(qd+10);  // read the tenth object pointed to by qd

        delete pd;
        delete [] qd;

        cout << endl << "ri, ri2, ri3 before delete" << endl << endl;

        cout << ri << endl;   // ri refers to *pi
        cout << ri2 << endl;  // ri2 refers to *qi
        cout << ri3 << endl;  // ri3 refers to qi

        delete pi;            // [4.7] how are the values of ri, ri2, ri3 affected by delete statement?
                              //They are deallocated from the heap because ri, ri2, and ri3 all point to pi
        
        delete [] ri3;        // [4.8] how are the values of ri, ri2, ri3 affected by delete statement?
                              //Values ri and ri2 become dangling references and ri3 becomes a dangling pointer with just a memory address

        cout << endl << "ri, ri2, ri3 after delete" << endl << endl;

        cout << ri << endl;
        cout << ri2 << endl;
        cout << ri3 << endl << endl;
    }

    double* array_of_doubles = hw08::dynamic_allocation_array_doubles(1000);
    // use array_of_doubles here
    // ... // [4.9] free array, no longer needed
    delete [] array_of_doubles;

    // Q#5 - dynamic 2d arrays, indexing via subscript operator, pointer arithmetic

    // tic tac toe board is an array of int pointers
    // each int pointer in the board points to a row

    // declare a pointer to an array of int pointers (i.e. a pointer to a pointer of type int)
    int** p_p_tictactoe = new int*[hw08::TIC_TAC_TOE_SIZE];
    // ...  // [5.1] row1: dynamically allocate int[TIC_TAC_TOE_SIZE], use initializer list to init to {1,0,0}
    p_p_tictactoe[0] = new int[hw08::TIC_TAC_TOE_SIZE] {1, 0, 0};
    
    // ...  // [5.2] row2: dynamically allocate int[TIC_TAC_TOE_SIZE], use initializer list to init to {0,1,0}
    p_p_tictactoe[1] = new int[hw08::TIC_TAC_TOE_SIZE] {0, 1, 0};
    
    // ...  // [5.3] row3: dynamically allocate int[TIC_TAC_TOE_SIZE], use initializer list to init to {0,0,1}
    p_p_tictactoe[2] = new int[hw08::TIC_TAC_TOE_SIZE] {0, 0, 1}; // [5.3] row3

    // print 2dints via subscript operator
    hw08::print_2darray_dynamic_subscript(p_p_tictactoe, hw08::TIC_TAC_TOE_SIZE, hw08::TIC_TAC_TOE_SIZE);
    // print 2dints via pointer arithmetic
    hw08::print_2darray_dynamic_pointer(p_p_tictactoe, hw08::TIC_TAC_TOE_SIZE, hw08::TIC_TAC_TOE_SIZE);

    // clean up board, go in reverse order of declaration

    // [5.4] delete individual rows (i.e. rows are int arrays, use delete [])
    for(int i = 0; i < hw08::TIC_TAC_TOE_SIZE; i++) {
        delete[] p_p_tictactoe[i];
    }
    
    //for(// ...) // ...
    // [5.5] delete board (board is an array of int pointers, use delete [])
    // ...
    delete[] p_p_tictactoe;

    return 0;
}

//------------------------------------------------------------------------------

// WRITTEN ANSWERS

// add written answers here ... Q#1 Q#3 Q#5

//Q#1: A pointer is a variable that holds a memory address as it’s value, so you have pointer of type int holding this other variable’s address. A reference can be seen as an alias for a variable, so both this alias and original variable hold the same value. Pointers can change to a different variable throughout the runtime however, references cannot be reassigned to a different variable. References use the ampersand, &. Pointers use an asterisk.

//Q#3: The twoDDoubles array stores data in tabular order or in row major order. Depending on the data type, the bytes of one element may vary. It is necessary to to cast a twoDDoubles to a *double in the print_2darray_pointer call because the function only sees the first element of the array when it is called. So when *double is called, it treats twoDDoubles a 1D array.

//Q#5: The p_p_tictactoe pointer 2d array points to a block of memory that points to another block of memory. Hence, it is a pointer to a pointer. We need to pass a pointer to a pointer so that we can traverse through each row of the array.
