00.
    the code finds the minimum and maximum values in an array of integers
    the logic in the function `mm` is incorrect. The check for the maximum only happens when the integer is smaller than the previous minimum
    replace `else if` with `if`
        `else if (a[i] > *mx)` => `if (a[i] > *mx)`

01.
    the code calculates and prints the product of the digits of numbers. For each number, it also prints the digits involved in the multiplication.
    the variable `i` is used globally and is not reset properly between function calls.
    reset the variable i with each function call.

02.
    the code multiplies a number `x` by `a` a given number of times (the given code evaluates 2^60)
    `x` is declared as an int. `px` is declared as the pointer to an int. In the function `mul` there is a space missing before the multiplication operator (*)
    use long long int instead of int for `x` and `px`, add a space between the star and the variable `a` in the function

03.
    the code sorts a string in descending order using a bubble sort algorithm
    the `myswap` function does not correctly swap the characters because it swaps the pointers, instead of the values they point to
    correctly swap the values the pointers point to. Add a star before every variable besides `aux` inside the function:
        `char *aux = c; c = d; d = aux;` => `char aux = *c; *c = *d; *d = aux;`

04.
    the code counts how many times the decomposition of `x` results in two different parts before `x` becomes zero (essentially counting the amount of 1's in binary)
    `p2` is not initialised as a pointer
    add a star before `p2`
        `long long *p1, p2;` => `long long *p1, *p2;`

05.
    the code finds the smallest element in an array
    the function `find_smallest` returns the pointer to a local variable, leading to undefined behaviour. Additionally, divison by 0 can cause a runtime error in `main`
    inside `find_smallest`, return the pointer to the smallest element in the array, working with `min` as a pointer and not as a value. In `main`, start the loop from 1 and initialise the first term seperately
        `float *find_smallest(float* a, int n){
            float min = a[0];
            for (int i=1; i<n; i++)
                if (a[i] < min)
                    min = a[i];
            float *pmin = &min;
            return pmin;
        }`
    =>
        `float *find_smallest(float* a, int n){
            float *min = &a[0];
            for(int i=1; i<n; i++)
                if (a[i] < *min)
                    min = &a[i];
            return min;
        }`
        `for (int i=0; i<n; i++) *(x+i) = 1.f / i;` => `for (int i=1; i<n; i++) *(x+i) = 1.f / i; x[0] = 1.f`

06.
    the code counts the number of consecutive elements in an array that are equal to a specified value `x`, starting from the first occurrence of that value
    the second while loop in the `cnt` function may access memory out of bounds if x is not found in the array
    inside `cnt` add a boundary check in the second while loop
        `while(*a == x){ r++; a++; }` => `while(n && *a == x){ n--; r++; a++; }

07.
    the code calculates and prints the first 20 digits of the fractional part of the division of p by q in base b
    the expression `*k--` is incorrect because it decrements the pointer `k` instead of the value it points to. The if statement doesn't check whether `p` is equal to `q`, leading to an incorrect result in that scenario decrement the value the pointer `k` points to instead of the pointer itself. 
    add an additional check inside the if statement
        `*k--;` => `(*k)--;`
        `if (*k == 0 || !p)` => `if (*k == 0 || !p || p == q)`

08.
    the code implements a binary search algorithm to find a specific value in a sorted array
    array indices start at 0 and go up to n-1 for an array of size n, so having an upper bound of `n` is incorrect
    adjust the upper bound of the array
        `int a = 0, b = n;` => `int a = 0, b = n - 1;`

09.
    the code swaps elements symmetrically around the middle of the array
    `p1` and `p2` do not target the left and right sides of the array around its middle
    adjust the initialisation of `p1` and `p2` to correctly target the left and right sides of the array around its middle
        `short *p1 = b + n/2; short *p2 = p1 + 1;` => `short *p1 = b + (n / 2 - 1); short *p2 = b + (n / 2 + (n % 2));`


10.
    the code calculates the product of all elements in an array of floats
    the `getprod` function expects an array of int but is being passed an array of float 
    change the type of the array parameter in the `getprod` function to float.    
        `void getprod(int n, float *res, int *x);` => `void getprod(int n, float *res, float *x);`

11.
    the code calculates the sum of elements in an array of floats
    `sizeof(x)` in the `getsum` function returns the size of the pointer, not the size of the array
    pass the size of the array as an additional parameter to the `getsum` function
        `float getsum(float *x) {
            float sum = 0;
            for(int i=0; i<sizeof(x)/sizeof(float); i++)
                sum += x[i];
        return sum;
        }`
    =>
        `float getsum(float* x, int size) {
            float sum = 0;
            for(int i = 0; i < size; i++)
                sum += x[i];
            return sum;
        }`
    `float s = getsum(x);` => `float s = getsum(x, sizeof(x)/sizeof(float));`

12.
    the code finds the largest element in an array of doubles and store it in a variable
    inside the `getbiggest` function, res is a local pointer variable, and assigning `&max` to `res` does not change the value of the pointer `p` in the `main` function
    dereference `res` and assign `max` to the location it points to
        `res = &max;` => `*res = max;`

13.
    the code calculates the average of an array of doubles and prints the result
    the pointer `p` is not initialised before being used in the `getaverage` function
    allocate memory for `p` before passing it to the function.
        `double *p;` => `double result; double *p = &result;`

14.
    the code sorts the array `a` in ascending order using the selection sort algorithm, and then prints the elements that appear more than once in the sorted array
    the size of the array `a` is not correctly calculated (the size of an int can vary). The inner while loop in the second part of the code does not check for array bounds
    calculate the size of `a` dividing by the size of one of its elements. Add a boundary check in the inner while loop
    	`int n = sizeof(a) / 4;` => `int n = sizeof(a) / sizeof(a[0]);`
        `while(i<n)` => `while(i < n && a[i] == x)`

15.
    the code reads an array of floats from the user, finds the minimum and maximum values in the array, and then prints these values
    `pmin` and `pmax` both point to the first element of the array `a`
    pass separate variables to store the minimum and maximum values.
        `float *pmin = a; float *pmax = a;` => `float min = a[0]; float max = a[0]; float *pmin = &min; float *pmax = &max;`