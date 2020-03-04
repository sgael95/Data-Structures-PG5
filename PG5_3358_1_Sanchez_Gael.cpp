//  Roster Number/s: 37
//
//  Author/s: Gael Sanchez
//  Due Date: 04/09/18
//  Programming Assignment Number 5
//
//  Spring 2018 - CS 3358 - 261
//
//  Instructor: Husain Gholoom
//
//  The program takes user input and uses recursive function to manipulate random generated data.


#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int isPrime(int num, int i){
    if(i==1)
        return 1;
    else {
        if(num% i ==0){
            return 0;
        }
        else {
            return isPrime(num, i-1);
        }
    }

}

int sumOfDigits(int n){
    if(n==0){
        return 0;
    } else{
        return (n %10 + sumOfDigits(n/10));
    }
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int start, int last) {
  int pivot = a[last];
  int i = (start -1);

  for (int j= start; j<= last -1; j++){
    if(a[j] <= pivot){
        i++;
        swap(a[i], a[j]);
    }
  }
  swap(&a[i+1], &a[last]);
  return(i+1);
}


void quickSort(int a[], int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quickSort(a, p, q - 1);
    quickSort(a, q + 1, r);
  }
}



int findMaxRec(int A[], int n){
    if(n==1)
        return A[0];
    return max(A[n-1], findMaxRec(A, n-1));
}

int power(int x, int n){
    if(n==0)
        return 1;
    if(n %2 == 0){
        if(n==2)
            return x*x;
        return power(power(x,n/2), 2);
    }
    else
        return x*power(x, n-1);
}

int tableSquares(int n, int lim){
    if(n == lim ){
        cout << n << "\t" << n*n << endl;
        return lim;
    }else{
        cout << n << "\t" << n*n << endl;
        return tableSquares(n+1, lim);
    }
}

void runit(){
    int num;
    bool accepted2;
    int xrand;

    cout << "Enter Array Size: ";
    do{
        try{
            cin >> num;
            if (!cin){
                cin.clear();
                cin.ignore();
                throw "***  Invalid Array Size Value  ***\nEnter an integer not a char:\t";
            }
        }catch(const char* msg){
            cout << msg;
            accepted2 = true;
        }

        if(num<10 || num > 1000){
            cout << "***  Invalid Array Size Value  ***\n";
            cout << "***  Enter Array Size That is >=10 and <= 1000 :\t";
            accepted2 = true;
        } else{
            int numbers[num];

            srand ( time(0) );

            for(int i=0;i<num; i++){
                xrand = rand() % 1000 +1;
                numbers[i] = xrand;
            }

            cout << "\nThe generated array is:\n\n";
            for(int i=0;i<10;i++){
                cout << numbers[i] << " ";
            }

            cout << "\n\nTable of square values 1 - " << numbers[9] << endl << endl;
            cout << "N\t N Squared\n";
            tableSquares(1, numbers[9]);

            cout << "\n\n\nPower Function:\n\n";
            cout << numbers[0] << " raised to the 2nd power is: " << power(numbers[0], 2);

            cout << "\n\n\nMax Number of ( ";
            for (int i=0; i<10; i++){
                if(i==9){
                    cout << numbers[i];
                }
                else{
                    cout << numbers[i] << " , ";
                }
            }
            int n = sizeof(numbers)/sizeof(numbers[0]);
            cout << ") is : ";
            cout << findMaxRec(numbers, num) << endl << endl;

            cout << "Sorted array\n\n";
            quickSort(numbers, 0, n-1);
            for(int i=9; i>=0;i--){
                cout << numbers[i] << " ";
            }

            cout << "\n\nSum of digits for the number " << numbers[0] << " is " << sumOfDigits(numbers[0]);

            cout << "\n\nIs it prime:\n\n";

            int check;

            for(int i = num-1; i>=0 ; i--){
                check = isPrime(numbers[i], numbers[i]/2);
                if(check ==1) {
                    cout << numbers[i] << " is Prime\n";
                } else {
                    cout << numbers[i] << " is Not Prime\n";
                }
            }
        }
        accepted2 = false;

    }while(accepted2 != false);
}


void finish(){
    cout << "\n\nGael Sanchez - Tweak Programming Developer\n";
    cout << "April 2018\n";
}


int main(){

    bool accepted;

    cout << "The function of this program is to\n";
    cout << "use recursion in order to perform the following operations :-\n";
    cout << endl;
    cout << "\t1.  Display squares of integers in ascending order form 1 to the\n";
    cout << "\t    last element in the array\n";
    cout << "\t2.  Raise the first number to a power  2\n";
    cout << "\t3.  Find the array's max value.\n";
    cout << "\t4.  Sort the array in descending order\n";
    cout << "\t5.  Calculating sum of digits\n";
    cout << "\t6.  Determine if a number is prime (processes all array values)";

    do{
            cout << "\n\nSelect form the following menu\n";
            cout << "A.\t Enter Array Size that is >=10 and <=1000 >.\n";
            cout << "X.\t Terminate The Program.\t";

            char ans;

            try{
                cin >> ans;

                if(!cin){
                    cin.clear();
                    cin.ignore();
                    throw "***  Invalid Option  ***\n";
                }
            }catch(const char* msg){
                cout << msg << endl;
                accepted = true;
            }

            switch(ans){
                case 'A':{
                    runit();
                    accepted = true;
                } break;
                case 'a':{
                    runit();
                    accepted = true;
                } break;
                case 'X':{
                    finish();
                    return 0;
                } break;
                case 'x':{
                    finish();
                    return 0;
                } break;
                default: cout << "***  Invalid Option  ***\n";
            }
            accepted = true;
    }while(accepted != false);

return 0;
}
