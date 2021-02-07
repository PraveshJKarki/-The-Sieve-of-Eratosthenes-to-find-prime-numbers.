/**
 * Programmer: Pravesh Jung Karki
 * CSC 240 Program 07
 * Description: In this program  we use
 * a variation of what is called "The Sieve of Eratosthenes" to find
 * the prime numbers. At first we will ask for the lower bound and
 * upper bound from the user and then give them the prime numbers
 * within that bound. We will use pointer to execute different functions.
 */

#include <iostream>

using namespace std;


//PROTOTYPING the functions
int *initialized(int size);

int findingIndex(int size, int array[]);

void findPrime(int array[], int size, int factor);

void circleAllZero(int array[], int size);

int *primeNumbers(int array[], int size, int &size2);

int main() {
    int *pointer;
    int *firstIndex;
    int size2 = 0;
    int lowBound = 0;
    int highBound = 0;
    int index = 0;
    char result;

    cout << " Welcome to the program that gives you a prime number." << endl;
    cout << " You will asked to enter the lower bound and the upper bound. " << endl;
    cout << " The program will display all the prime numbers within that range. "  << endl;
    cout << " ************************ LET'S BEGIN **********************" << endl;
    cout << " " << endl;
    cout << " Specify a range of positive integers with a low and high boundary. " << endl;
    do {
        size2 = 0;
        do {
            do {
                cout << " Enter the low boundary: " << endl;
                cin >> lowBound;
                if (lowBound <= 0) {
                    cout << "Only positive number is accepted for low bound." << endl;
                }
            } while (lowBound <= 0);
            do {
                cout << " Enter the high boundary: " << endl;
                cin >> highBound;
                if (highBound <= 0) {
                    cout << "Only positive number is accepted for high bound." << endl;
                }
            } while (highBound <= 0);
            if (lowBound > highBound) {
                cout << "Low Bound cannot be greater than high bound." << endl;
            }
        } while (lowBound > highBound);

        pointer = initialized(highBound + 1);
        do {
            index = findingIndex(highBound + 1, pointer);
            if (index > sqrt(highBound)) {
                circleAllZero(pointer, highBound + 1);
            } else
                findPrime(pointer, highBound + 1, index);
        } while (sqrt(highBound) > index);

        int *p = primeNumbers(pointer, highBound + 1, size2);
        firstIndex = p;
        cout << " " << endl;
        //resetting the pointer
        //p = firstIndex;
        cout << "The prime numbers within "<< lowBound <<" and " << highBound << " are:" << endl;

        while (*p < lowBound) {
            p++;
        }
        while(p < (size2 + firstIndex)){
            cout << *p << " ";
            p++;
        }
        cout << " " << endl;
        cout << "\n Do you like to repeat again ?" << endl;
        cout << "Enter 'y' for Yes and 'n' for No." << endl;
        cin >> result;
        if( result == 'n' || result == 'N') {
            cout << "Program is now terminating..." << endl;
            cout << " Thank You! " << endl;
        }
    } while (result == 'y' || result == 'Y');

    return 0;
}

/**
Given an integer size, this method will return an array of integers of that size,
with all elements initialized to zero, except for elements at indexes 0 and 1,
that are set to 'NOT PRIME' (-1)
 */
int *initialized(int size) {
    int *array = new int[size];
    int *pointer = array;
    *pointer = -1;
    *(pointer + 1) = -1;
    for (pointer = array + 2; pointer < size + array; pointer++) {
        *pointer = 0;
    }
    return array;
}

// Given an array of integers, and the size of that array,
//We will return the index of the first element that contains a zero.
int findingIndex(int size, int array[]) {
    int *pointer;
    for (pointer = array; pointer < size + array; pointer++) {
        if (*pointer == 0)
            return (pointer - array);

    }


}

/**
Given an array of integers, the size of that array, and an integer factor,
We will 'circle' the element at the index equal to the given
 factor beacuse it is a prime number,
 So we put +1, then we will scan the rest of the array and
 'cross out' (mark with a -1) every other
element with an index that is multiple of the given factor.
**/
void findPrime(int array[], int size, int factor) {
    int *pointer = array;
    *(pointer + factor) = 1;
    int *tempArray = array + factor + factor;
    for (pointer = tempArray; pointer < size + array; pointer += factor) {
        *pointer = -1;
    }

}

/**
Given an array of integers, and the size of that array,
we will scan the array and convert every element
 that contains a zero (unknown) to a +1 (circled).
**/
void circleAllZero(int array[], int size) {
    int *pointer;
    for (pointer = array; pointer < size + array; pointer++)
        if (*pointer == 0)
            *pointer = 1;
}

/**
Given an array of integers, and the size of that array,
we will return another array of integers that contains the indexes of the elements
in the first array that are 'circled' (contain a +1),
and also  we will return the size of that second array.
We will use a reference parameter to return the array's size.)
*/

int *primeNumbers(int array[], int size, int &size2) {
    int *array2 = new int[size];
    int *point1;
    int *point2 = array2;
    int *copyArray = array;
    for (point1 = array; point1 < size + copyArray; point1++) {
        if (*point1 == 1) {
            *point2 = point1 - copyArray;
            point2++; size2++;
        }
    }
    return array2;
}




