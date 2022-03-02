#include <iostream>
#include <cmath>

int* generateIntegers(int);
bool isMultiple(int, int, int);

#define START_PRIME 2
#define CROSSED 0

int main() {
    int n, prime = 0;
    int *ptr_list;


    // User input regarding size of integer list.
    std::cout << "Enter the list size: " << std::endl;
    std::cin >> n;
    n = n - 1; // Remove 1 size from the list, first prime start at number 2. Example: (2-30) = 29 in size.

    int list_Of_Numbers[n];

    // Generate integer list.
    ptr_list = generateIntegers(n);

    // Copy list of integers from pointer.
    for(int i = 0; i < n; i++) {
        list_Of_Numbers[i] = *ptr_list;
        ptr_list = ptr_list + 1;

    }

    // Delete the object at pointed address.
    delete[] ptr_list;

    // Run and find all primes from the generated integer list.
    for(int i = 0; i < n; i++) {
        if(list_Of_Numbers[i] > sqrt(n)) // Break if square root(n) < next number.
            break;


        if(list_Of_Numbers[i] != CROSSED && list_Of_Numbers[i] > prime) // Find next prime number.
            prime = list_Of_Numbers[i];

        for(int i = 0; i < n; i++)  // Cross numbers.
            if(isMultiple(prime, list_Of_Numbers[i], n) && list_Of_Numbers[i] > prime) // Run if number is multiple of prime number.
                list_Of_Numbers[i] = CROSSED;
            
   

    }

    // Print primes
    std::cout << "Primes: ";
    for(int i = 0; i < n; i++)
        if(list_Of_Numbers[i] != CROSSED)
            std::cout << " " << list_Of_Numbers[i];

    return 0;
}

int *generateIntegers(int n) {
    // Create an array stored on the heap memory.
    int* list_Of_Numbers = new int[n];
    int addNum = START_PRIME;

    // Generate the list of integers.
    for(int i = 0; i < n; i++) {
        list_Of_Numbers[i] = addNum;
        addNum++; // Increment to next value.
    }

    // Return address of the array.
    return list_Of_Numbers;
}

bool isMultiple(int prime, int multiple, int n) {
    // Find multiples. 
    for(int i = 1;i < n;i++){
        if((prime * i) == multiple)
            return true;
    }

    return false;
}
