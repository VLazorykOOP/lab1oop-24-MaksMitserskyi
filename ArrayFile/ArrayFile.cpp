#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <locale>

using namespace std;

// Task 1
void task1() {
  
    int N;
    cout << "Введіть розмір масиву N: ";
    cin >> N;
    int A[100];
    cout << "Введіть елементи масиву A:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }
    long long C[100];
    for (int i = 0; i < N; ++i) {
        C[i] = static_cast<long long>(pow(2, i + 1)) * A[i];
    }
    cout << "Масив C:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "C[" << i << "]: " << C[i] << endl;
    }
}

// Task 2
void task2() {
    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cout << "Введіть " << i + 1 << "-й елемент: ";
        cin >> a[i];
    }
    int c, d;
    cout << "Введіть ліву межу діапазону: ";
    cin >> c;
    cout << "Введіть праву межу діапазону: ";
    cin >> d;
    int max_idx = c;
    for (int i = d; i >= c; i--) {
        if (a[i] > a[max_idx]) {
            max_idx = i;
        }
    }
    if (max_idx == c) {
        cout << "В діапазоні немає непарних чисел." << endl;
    }
    else {
        cout << "Номер останнього максимального непарного елемента: " << max_idx << endl;
    }
}

// Task 3
void task3() {
    cout << "Введіть розмір масиву: ";
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cout << "Введіть " << i + 1 << "-й елемент: ";
        cin >> a[i];
    }
    unordered_map<double, int> count;
    for (double num : a) {
        count[num]++;
    }
    double sum_repeats = 0;
    double product_unique = 1;
    for (auto it : count) {
        if (it.second > 1) {
            sum_repeats += it.first * it.second;
        }
        else {
            product_unique *= it.first;
        }
    }
    cout << "Сума повторюваних чисел: " << sum_repeats << endl;
    cout << "Добуток не повторюваних чисел: " << product_unique << endl;
}

int main() {
    setlocale(LC_CTYPE, "Ukr");
    int task;
    cout << "Введіть номер завдання (1, 2, або 3): ";
    cin >> task;
    switch (task) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    default:
        cout << "Невірний номер завдання." << endl;
    }
    return 0;
}


#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

#include <time.h>

using namespace std;

typedef double* pDouble;
/*
*   ConsoleInputArrayDouble
*   
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0; 
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
        for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1=0, r2=0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble &pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double> &A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return ;
}


/*
*  WriteArrayTextFile 
*
*/

void WriteArrayTextFile(int n, double *arr, const char *fileName )
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}
/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;   
    for (int i = 0; i < n; i++)
       fin>> arr[i];
    fin.close();
    return size;
    
}


void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) *sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size=0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

void ShowMainMenu()
{
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
  }

void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 \n";
    cout << "    3.  Dynamic array 2  new \n"; 
    cout << "    4.  Dynamic array : vector \n";
    cout << "    5.  Exit \n";
}

void MenuInput()
{
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
}


/*
* Задано одновимірний масив А розміру 2N. 
* Побудувати два масиви В і С розміру N, 
* включивши  у масив В елементи масиву А з парними індексами,
* а у С - з непарними.
*****************
*  A - in 
*  B, C - out 
*/
void  TestVariant(int N, double* A, double* B, double* C) {
    for (int i = 0; i < N; i++) {
        B[i] = A[2 * i];
        C[i] = A[2 * i + 1];
    }
}
/*
*  Task  Var
* 
* 
*/
void TaskV()
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
            switch (ch) {
             case '1': cout << " 1 "; break;
             case '2': cout << " 2 "; break;
            //
            case '5': return;
            }
        cout << " Press any key and enter\n";
        ch = getchar();
        } while (ch != 27);
    
}

void ArrayLocal()
{
    double A[1000], B[500], C[500];
    int n;
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}

//
//
//

