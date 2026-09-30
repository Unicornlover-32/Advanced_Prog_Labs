#include <stdio.h>
#include <stdbool.h>

// This Lab is preparation for a coding exam on Friday 2nd October @ 3pm in D422 and D417.


// Q1: Check if an inputted year is a Leap Year.
// A leap year is divisible by 4, but not by 100 unless also divisible by 400.
bool isLeapYear(int year) {

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

// Q2 (helper): Reverse the digits of a number and return the reversed integer.
// E.g., 123 -> 321.
int Reversed(int testNumber) {

    int reversedNumber = 0;
    int remainder;

    while (testNumber != 0) {
        remainder = testNumber % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        testNumber = testNumber / 10;
    }

    return reversedNumber;
}

// Q3: Check Whether a Number is Palindrome or Not.
// A palindrome reads the same forwards and backwards (e.g., 121).
bool isAPalindrome(int testNumber) {

    int number = testNumber;            
    int reversedNumber = 0;
    int remainder;

    while (number != 0) {
        remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number = number / 10;
    }

    if (reversedNumber == testNumber) {
        return true;
    }

    return false;
}

// Q4: Check Whether a Number is Prime or Not.
// A prime number is only divisible by itself and 1.
bool isAPrimeNumber(int numbertoTest) { 

    if (numbertoTest <= 1) {
        return false;
    }

    for (int i = 2; i < numbertoTest; i++) {
        if (numbertoTest % i == 0) {
            return false; 
        }
    }
    return true;
}

// Q5: Convert Binary Number to Decimal without using the shift operator.
// E.g., 110 -> 6.
int convertBinarytoDecimal(int binaryNumber) {

    int decimalNumber = 0;
    int remainder;
    int calculator = 1;

    while (binaryNumber != 0) {
        remainder = binaryNumber % 10;
        decimalNumber += remainder * calculator;
        calculator *= 2;
        binaryNumber /= 10;
    }

    return decimalNumber;
}

// Q6: Output a right-angled triangle of 'A's using 2 nested for loops:
// A
// AA
// AAA
// AAAA
void drawRightAngledTriangle() {

    for (int inner = 0; inner <= 5; inner++) {
        for (int outer = 0; outer <= inner; outer++) {
            printf("A");
        }
        printf("\n");
    }
}

// Q7: Output an isosceles (diamond-like) triangle of 'A's using 2 for loops
// and at most 1 if/else:
// A
// AA
// AAA
// AAAA
// AAA
// AA
// A
void drawIsocelesTriangle() {

    int size = 5;

    for (int inner = 0; inner <= size; inner++) {
        for (int outer = 0; outer < inner; outer++) {
            printf("A");
        }
        printf("\n");
    }

    for (int inner = size - 1; inner >= 1; inner--) {
        for (int outer = 0; outer < inner; outer++) {
            printf("A");
        }
        printf("\n");
    }
}

// Q7B (EXTRA): Output the same diamond pattern as Q7 using only 2 for loops
// and no conditional statements.
void drawIsocelesTriangle2() {
}

// Q8: Find an element in an array and print the index where it was found,
// or -1 if not found.
int find(int size, int arr[], int toFind) {

    for (int i = 0; i < size; i++) {
        if (arr[i] == toFind) {
            return i;
        }
    }
    return -1;
}

// Q9: Find and return the second largest element in an array of positive
// integers; returns -1 if it can't find one.
int find2ndLargest(int size, int arr[]) {

    int largest;
    int secLargest = -1;

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            largest = arr[0];
        }
        else if (arr[i] > largest) {
            secLargest = largest;
            largest = arr[i];
        }
    }

    return secLargest;
}

// Q10: Copy all elements from arr1 to arr2. Both arrays are the same size.
void copyArraytoArray(int size, int arr1[], int arr2[]) {

    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
    return;
}

// Q11: Insert an element at a specified index in the array, shifting elements
// to the right. 'count' tracks the number of elements and cannot exceed 'size'.
// Returns true if an element was inserted, otherwise false.
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex) {

    if (count == size - 1) {
        return false;
    }
    else {
        for (int i = count; i >= insertIndex; i--) {
            arr[i + 1] = arr[i];
        }

        arr[insertIndex] = elementToInsert;
        count++;

        return true;
    }
    
    return false;
}

// Q12: Delete an element at a specified position, shifting higher elements
// to the left by one. 'count' tracks the number of elements and cannot exceed
// 'size'. Returns true if an element was deleted, otherwise false.
bool deleteElement(int& size, int& count, int arr[], int deleteIndex) {

    if (count == size - 1) {
        return false;
    }
    else {
        arr[deleteIndex] = 0;

        for (int i = deleteIndex; i < count; i++) {
            arr[i] = arr[i + 1];
        }

        return true;
    }

    return true;
}

// Q13: Count the frequency of a given element in an array.
int frequencyCount(int size, int arr[], int value) {

    int frequency = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            frequency++;
        }
    }

    return frequency;
}

// Q14: Count the total number of duplicate elements in an array.
int countDuplicates(int size, int arr[]) {

    int duplicates = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                if (arr[i] == arr[j]) {
                    duplicates++; 
                }
            }
        }
    }

    return duplicates;
}

// Q15: Reverse an array in place using only 1 array.
void reverse(int size, int arr[]) {

    int array_end = size - 1;
    int temp;

    for (int array_start = 0; array_start <= array_end; array_start++) {
        temp = arr[array_start];
        arr[array_start] = arr[array_end];
        arr[array_end] = temp;
        array_end--;
    }

    return;
}

// Q16: Left rotate an array by one position, moving the first element to the end.
int rotateLeft(int size, int arr[]) {

    int temp = 0;

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            temp == arr[i];
        }
        
        if (arr[i + 1] == NULL) {
            arr[i] = temp;
        }
        else {
            arr[i] == arr[i + 1];
        }
    }
    

    return -1;
}

// Q17: Given a flight length and an array of movie lengths, return true if
// there are exactly two movies whose runtimes sum to the flight length.
// Users watch exactly two movies and cannot watch the same movie twice.
bool twoMovies(int flightLength, int movieLengths[], int size) {

    for (int movieOne = 0; movieOne < size; movieOne ++) {
        for (int movieTwo = movieOne + 1; movieTwo < size; movieTwo++) {
            if (movieLengths[movieOne] + movieLengths[movieTwo] == flightLength) {
                return true;
            }
        }
    }

    return false;
}
// Q18: Count the number of separate words in an array of chars, where a word
// is one or more characters in ranges A..Z or a..z separated by spaces.
int wordCounter(int size, char characters[]) {
    
    bool valid = false;
    int wordCount = 0;

    for (int i = 0; i < size; i++) {
        if (characters[i] == ' ' && valid == true) {
            wordCount++;
            valid = false;
        }

        if (characters[i] >= 'A' && characters[i] <= 'Z' || characters[i] >= 'a' && characters[i] <= 'z') {
            valid = true;
        }
        else {
            valid = false;
        }
    }

    if (valid == true) {
        wordCount++;
    }

    return wordCount;
}
// ----------------------------------------------------------------------------
// Q19: PrintArray
// Prints the 4x6 array in rows and columns.
// This is the ONLY function allowed to use printf.
// ----------------------------------------------------------------------------
void PrintArray(int array[4][6])
{
    for (int column = 0; column < 4; column++) {
        for (int row = 0; row < 6; row++) {
            printf("%d", array[column][row]);
            printf(" ");
        }
        printf("\n");
    }
}

// ----------------------------------------------------------------------------
// Q20: ReplaceWithMinusOne
// Scans the array from position (0,0), moving left-to-right across each row.
// At each position, checks for a HORIZONTAL line of 3+ identical items first,
// and if none found, checks for a VERTICAL line of 3+ identical items.
// The first cluster found is scored by summing its values (1-4), then the
// cluster is replaced with -1's. Returns the score, or 0 if no cluster found.
// 0's and -2's are never part of a cluster.
// ----------------------------------------------------------------------------
int ReplaceWithMinusOne(int array[4][6])
{


    return 0;
}

// ----------------------------------------------------------------------------
// Q21:FallDownAndReplace
// Removes the -1's by making all items above them "fall down" into the empty
// space. New items added at the top of the array are given the value -2, and
// these will not be part of the next cluster.
// Works column by column.
// ----------------------------------------------------------------------------
void FallDownAndReplace(int array[4][6])
{
}


// Q22:----------------------------------------------------------------------------
// FindAllVariables
// Scans the C code string and fills 'variables' with a comma-separated list
// of every variable name declared as type "int" or "char".
// Only one variable is declared per line, and strings are 0-terminated.
// E.g., "int var1=10;" adds "var1" to the list.
// ----------------------------------------------------------------------------
void FindAllVariables(char variables[], char code[])
{
}

// Q23----------------------------------------------------------------------------
// FindAllVariablesInScope
// Fills 'variables' with a comma-separated list of variables that are in
// scope AFTER the given lineNumber. The code has no "for" loops, and the
// only function declaration is "int main()". Only one variable is declared
// per line, and only "int" / "char" variables are considered.
//
// Scope is tracked with a brace depth counter. A variable declared at depth
// D is in scope after its declaration line as long as the current depth is
// >= D. A declaration at the same depth as the target line counts; a
// declaration at a deeper depth (inside a block that closes before/at the
// target line) does not.
// ----------------------------------------------------------------------------
void FindAllVariablesInScope(char variables[], char code[], int lineNumber)
{
}



// Very simple tests for Questions 1 to 8..and 19 to 23 . Add Test for Questions 9 to 18 
int main() {
    // example of printf()
    // example printf("Leapyear\n");
    printf("Leapyear\n");
    printf("Leapyear\n");
    if (!isLeapYear(1700))
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    if (isLeapYear(1600))
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    if (isLeapYear(2016))
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    printf("NumberReversed\n");
    if (Reversed(123) == 321)
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    if (Reversed(1) == 1)
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    if (Reversed(1234) != 321)
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    printf("Palindrome\n");
    if (isAPalindrome(1))
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    if (isAPalindrome(121))
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    if (!isAPalindrome(1213))
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    printf("Prime Number\n");
    if (isAPrimeNumber(3))
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    /*if (isAPrimeNumber(2147483647))
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }*/
    if (!isAPrimeNumber(4))
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    printf("Binary to Decimal\n");
    if (convertBinarytoDecimal(110) == 6)
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    if (convertBinarytoDecimal(111) == 7)
    {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    printf("Triangles\n");
    drawRightAngledTriangle();
    drawIsocelesTriangle();
    //example of calling the functions
   
    // ------------------------------------------------------------------
    // Added tests for Q9 - Q18 (none of the code above/below this block
    // has been modified)
    // ------------------------------------------------------------------

    printf("Find (Q8 extra cases)\n");
    int arr8a[] = { 5, 10, 15, 20 };

    if (find(4, arr8a, 15) == 2) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    if (find(4, arr8a, 99) == -1) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    printf("2nd Largest\n");

    int arr9a[] = { 1, 3, 2, 5, 4 };
    if (find2ndLargest(5, arr9a) == 4) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    int arr9b[] = { 10, 20 };
    if (find2ndLargest(2, arr9b) == 10) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    int arr9c[] = { 7 };
    if (find2ndLargest(1, arr9c) == -1) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    printf("Copy Array\n");
    int arr10src[] = { 1, 2, 3, 4, 5 };
    int arr10dst[5];
    copyArraytoArray(5, arr10src, arr10dst);
    bool copyMatch = true;
    for (int i = 0; i < 5; i++) {
        if (arr10src[i] != arr10dst[i]) {
            copyMatch = false;
        }
    }
    if (copyMatch) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    printf("Insert Element\n");
    int size11 = 6;
    int count11 = 4;
    int arr11[6] = { 1, 2, 3, 4, 0, 0 };
    bool inserted11 = insertElement(size11, count11, arr11, 99, 2);
    if (inserted11 && arr11[2] == 99 && count11 == 5) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    int size11b = 4;
    int count11b = 3;
    int arr11b[4] = { 1, 2, 3, 0 };
    bool inserted11b = insertElement(size11b, count11b, arr11b, 5, 1);
    if (!inserted11b) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n");
    }

    printf("Delete Element\n");
    int size12 = 6;
    int count12 = 4;
    int arr12[6] = { 10, 20, 30, 40, 0, 0 };
    bool deleted12 = deleteElement(size12, count12, arr12, 1);
    if (deleted12 && arr12[1] == 30) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    int size12b = 4;
    int count12b = 3;
    int arr12b[4] = { 1, 2, 3, 0 };
    bool deleted12b = deleteElement(size12b, count12b, arr12b, 0);
    if (!deleted12b) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    printf("Frequency Count\n");
    int arr13[] = { 1, 2, 2, 3, 2, 4 };
    if (frequencyCount(6, arr13, 2) == 3) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    if (frequencyCount(6, arr13, 5) == 0) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    printf("Count Duplicates\n");
    int arr14[] = { 1, 2, 2, 3, 3, 3 };
    if (countDuplicates(6, arr14) == 8) {
        printf("yes\n");
    }
    else { 
        printf("no\n"); 
    }

    int arr14b[] = { 1, 2, 3, 4 };
    if (countDuplicates(4, arr14b) == 0) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    printf("Reverse Array\n");
    int arr15[] = { 1, 2, 3, 4, 5 };
    reverse(5, arr15);
    bool reverseMatch = (arr15[0] == 5 && arr15[1] == 4 && arr15[2] == 3 && arr15[3] == 2 && arr15[4] == 1);
    if (reverseMatch) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    printf("Rotate Left\n");
    int arr16[] = { 1, 2, 3, 4, 5 };
    rotateLeft(5, arr16);
    bool rotateMatch = (arr16[0] == 2 && arr16[1] == 3 && arr16[2] == 4 && arr16[3] == 5 && arr16[4] == 1);
    if (rotateMatch) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    printf("Two Movies\n");
    int movies17[] = { 30, 45, 60, 90, 120 };
    if (twoMovies(150, movies17, 5) == true) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    if (twoMovies(1000, movies17, 5) == false) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    printf("Word Counter\n");
    char words18a[] = "Hello World Foo";

    if (wordCounter(15, words18a) == 3) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    char words18b[] = "   ";
    if (wordCounter(3, words18b) == 0) { 
        printf("yes\n"); 
    }
    else { 
        printf("no\n"); 
    }

    // ------------------------------------------------------------------
    // End of added Q9 - Q18 tests
    // ------------------------------------------------------------------

    int array[4][6] = { {0,0,3,1,3,4},
                       {0,0,2,3,4,3},
                       {0,0,1,3,3,2},
                       {0,0,1,1,1,1} };
    PrintArray(array);
    int score = ReplaceWithMinusOne(array);

    FallDownAndReplace(array);
    char code[1000] = "";

    char variables[1000] = "";

    FindAllVariables(variables, code);
    FindAllVariablesInScope(variables, code, 12);

    return 0;
}