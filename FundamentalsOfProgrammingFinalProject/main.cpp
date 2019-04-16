/*
for dev: system("cls");
for code::blocks: system("clear");
*/

#include <iostream>
using namespace std;

void mainMenu();
void numericalCalc();
void mosallasat();
void matrixClac();
void aboutUS(bool);

void mainCalc(char);
long long int power(int base, int exponent);
unsigned long long int fact(double x);
void showDivisors();
void completeNumber();
void primeNumber();
void squareRoot();
void dtetr();
void inputMatA();
void inputMatB();
void printMatRes(int row, int col);
double clacSin(double x);
double clacCos(double x);

int main() {
	mainMenu();
	return 0;
}

void mainCalc(char op) {
	system("clear");
	float x, y, res;
	cout<<"Enter the first number: ";
	cin>>x;
	cout<<"Enter the second number: ";
	cin>>y;

	switch(op) {
		case '+':
			res = x + y;
			break;
		case '-':
			res = x - y;
			break;
		case '*':
			res = x * y;
			break;
		case '/':
			res = x / y;
			break;
	}

	cout<<x<<" "<<op<<" "<<y<<" = "<<res;
}

void squareRoot() {
    system("clear");
    double res = 1;
    double num;
    cout<<"\nEnter a number to calculate its square root: ";
    cin>>num;
    for(int i=0;i <= 100; i++)
        res = (res + (num / res)) / 2;
    cout<<"Square root of "<<num<<" is: "<<res;
}

long long int power(int base, int exponent) {
    long long int res = 1;
	for(int i = exponent; i > 0; i--)
		res *= base;
    return res;
}

unsigned long long int fact(double x) {

    long long int res = 1;
	for(int i = x; i > 0; i--)
		res *= i;
	return res;
}

void showDivisors() {
    system("clear");
    int num;
    cout<<"\nEnter a number to show its divisors: ";
    cin>>num;
    cout<<"\nDivisors of "<<num<<" are: \n";
    for(int i = 1; i <= num; i++) {
        if(num % i == 0)
            cout<<i<<" ";
    }
}

void completeNumber() {
    system("clear");
    int num, sum = 0;
    cout<<"\nEnter a number to check if it's complete or not: ";
    cin>>num;
    for(int i = 1; i <= num / 2; i++)
        if(num % i == 0)
            sum += i;
    cout<<endl;
    if(sum == num)
        cout<<num<<" is a complete number!";
    else
        cout<<num<<" is not a complete number.";
}

void primeNumber() {
    system("clear");
    int num;
    cout<<"Enter a number to check if it's prime or not: ";
    cin>>num;
    int i = 2;
    bool flag = true;
    if(num == 1) {
        cout<<num<<" is not a prime number.";
    } else {
        while(i < num / 2) {
            if(num % i == 0) {
                flag = false;
                break;
            }
            i++;
        }
        if(flag == true)
            cout<<num<<" is a prime number.";
        else
            cout<<num<<" is not a prime number.";
    }
}

void numericalCalc() {
	cout<<"1. Addition (+)\n";
	cout<<"2. Subtraction (-)\n";
	cout<<"3. Multiplicatoin (*)\n";
	cout<<"4. Division (/)\n";
	cout<<"5. Square root\n";
	cout<<"6. Tavan\n";
	cout<<"7. Factorial\n";
	cout<<"8. Show divisors\n";
	cout<<"9. Complete number\n";
	cout<<"10. Prime number\n";
	cout<<"11. Previous menu\n";
	cout<<"12. Exit\n";

	int option;
	cout<<"\nPlease Enter Your desired option number: ";
	cin>>option;

	switch(option) {
		case 1:
			mainCalc('+');
			break;
		case 2:
			mainCalc('-');
			break;
		case 3:
			mainCalc('*');
			break;
		case 4:
			mainCalc('/');
			break;
		case 5:
            squareRoot();
			break;
		case 6: {
                system("clear");
                int base, exponent;
                cout<<"Base = ";
                cin>>base;
                cout<<"Exponent = ";
                cin>>exponent;
                cout<<base<<" powered by "<<exponent<<" = "<<power(base, exponent);
			}
			break;
		case 7: {
                system("clear");
                double x;
                cout<<"Number = ";
                cin>>x;
                cout<<static_cast<int>(x)<<"! = "<<fact(x);
            }
			break;
		case 8:
            showDivisors();
			break;
		case 9:
            completeNumber();
			break;
		case 10:
            primeNumber();
			break;
		case 11:
            system("clear");
			mainMenu();
			break;
		case 12:
			exit(1);
			break;
		default:
			system("clear");
			cout<<"\aPlease enter a valid option number from the below list!\n\n";
			numericalCalc();
	}

	while(1) {
		cout<<"\n\n1. Previous menu\n";
		cout<<"2. Exit\n\n";
        int option;
        cout<<"Please Enter you desired option number: ";
        cin>>option;
        switch(option) {
            case 1:
                system("clear");
                numericalCalc();
                break;
            case 2:
            	exit(1);
                break;
            default:
                system("clear");
                cout<<"\n\aPlease enter a valid option number from the below list!";
        }
    }
}

const int n = 100;
int rowA, colA, rowB, colB;
double matA[n][n];
double matB[n][n];
int matRes[n][n];

void inputMatA() {
    cout<<"row = ";
    cin>>rowA;
    cout<<"column = ";
    cin>>colA;

	for(int i = 0; i < rowA; i++)
		for(int j = 0; j < colA; j++){
            cout<<"Enter a number for matrix["<<i<<"]["<<j<<"]: ";
			cin>>matA[i][j];
		}
}

void inputMatB() {
    cout<<"row = ";
    cin>>rowB;
    cout<<"column = ";
    cin>>colB;

	for(int i = 0; i < rowB; i++)
		for(int j = 0; j < colB; j++){
            cout<<"Enter a number for matrix["<<i<<"]["<<j<<"]: ";
			cin>>matB[i][j];
		}
}

void printMatRes(int row, int col) {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout<<matRes[i][j]<<"\t";
        cout<<endl<<endl;
    }
}

void dtetr() {
    system("clear");
    int opt;
    cout<<"1. 2 * 2\n";
    cout<<"2. 3 * 3\n\n";
    cout<<"Enter the one you want: ";
    cin>>opt;
    switch(opt) {
        case 1: {
                rowA = 2;
                colA = 2;
                for(int i = 0; i < rowA; i++)
                    for(int j = 0; j < colA; j++){
                        cout<<"Enter a number for matrix["<<i<<"]["<<j<<"]: ";
                        cin>>matA[i][j];
                    }
                int deterRes = (matA[0][0] * matA[1][1]) - (matA[0][1] * matA[1][0]);
                cout<<"\nDeterminan = "<<deterRes;
            }
            break;
        case 2: {
                rowA = 3;
                colA = 3;
                for(int i = 0; i < rowA; i++)
                    for(int j = 0; j < colA; j++){
                        cout<<"Enter a number for matrix["<<i<<"]["<<j<<"]: ";
                        cin>>matA[i][j];
                    }
                int A = matA[0][0] * ((matA[1][1] * matA[2][2]) - (matA[1][2] * matA[2][1]));
                int B = matA[0][1] * ((matA[1][0] * matA[2][2]) - (matA[1][2] * matA[2][0]));
                int C = matA[0][2] * ((matA[1][0] * matA[2][1]) - (matA[1][1] * matA[2][0]));
                int deterRes = A - B + C;
                cout<<"\nDeterminan = "<<deterRes;
            }
            break;
    }
}

void matrixClac() {
	cout<<"1. Addition (+)\n";
	cout<<"2. Subtraction (-)\n";
	cout<<"3. Multiplicatoin (*)\n";
	cout<<"4. Transposed Matrix\n";
	cout<<"5. Determinan (2 * 2 & 3 * 3)\n";
	cout<<"6. Multiply matrix by a number\n";
	cout<<"7. Previous menu\n";
	cout<<"8. Exit\n";

	int option;
	cout<<"\nPlease Enter Your desired option number: ";
	cin>>option;

	switch(option) {
		case 1:
            system("clear");
            cout<<"Enter the count of rows and columns of the first matrix:\n";
            inputMatA();
            cout<<"Enter the count of rows and columns of the second matrix:\n";
            inputMatB();

            if(rowA == rowB && colA == colB) {
                for(int i = 0; i < rowA; i++)
                    for(int j = 0; j < colA; j++)
                        matRes[i][j] = matA[i][j] + matB[i][j];
                system("clear");
                cout<<"The addition of these two matrixes is: \n\n";
                printMatRes(rowA, colA);
            } else {
                cout<<"\nThe count of rows and columns of the two matrixes should be equal!\n\n";
            }
			break;
		case 2:
            system("clear");
            cout<<"Enter the count of rows and columns of the first matrix:\n";
            inputMatA();
            cout<<"Enter the count of rows and columns of the second matrix:\n";
            inputMatB();

            if(rowA == rowB && colA == colB) {
                for(int i = 0; i < rowA; i++)
                    for(int j = 0; j < colA; j++)
                        matRes[i][j] = matA[i][j] - matB[i][j];
                system("clear");
                cout<<"The subtraction of these two matrixes is: \n\n";
                printMatRes(rowA, colA);
            } else {
                cout<<"\nThe count of rows and columns of the two matrixes should be equal!\n\n";
            }
            break;
		case 3: {
                system("clear");
                cout<<"Enter the count of rows and columns of the first matrix:\n";
                inputMatA();
                cout<<"Enter the count of rows and columns of the second matrix:\n";
                inputMatB();
                if(colA == rowB) {
                    int sum = 0;
                    for(int i = 0; i < rowA; i++)
                        for(int j = 0; j < colB; j++) {
                            for(int k = 0; k < colA; k++)
                                sum += matA[i][k] * matB[k][j];
                            matRes[i][j] = sum;
                            sum = 0;
                        }
                    cout<<endl;
                    cout<<"The multiplication of these two matrixes is: \n\n";
                    printMatRes(rowA, colB);
                } else {
                    cout<<"\nError! These two matrixes are not able to be multiplied by each other.\n\n";
                }
            }
			break;
		case 4:
            system("clear");
            cout<<"Enter the count of rows and columns of the matrix:\n";
            inputMatA();

            for(int i = 0; i < rowA; i++)
                for(int j = 0; j < colA; j++)
                    matRes[j][i] = matA[i][j];
            printMatRes(colA, rowA);
			break;
        case 5:
            dtetr();
			break;
        case 6:
            system("clear");
            int n;
            cout<<"Enter a number to multiply by the matrix: ";
            cin>>n;
            cout<<"Enter the count of rows and columns of the matrix:\n";
            inputMatA();

            for(int i = 0; i < rowA; i++)
                for(int j = 0; j < colA; j++)
                    matRes[i][j] = matA[i][j] * n;
            system("clear");
            cout<<"The matrix you entered multiplied by "<<n<<" is: \n\n";
            printMatRes(rowA, colA);
			break;
        case 7:
            system("clear");
			mainMenu();
			break;
		case 8:
			exit(1);
			break;
		default:
			system("clear");
			cout<<"\aPlease enter a valid option number from the below list!\n\n";
			matrixClac();
	}

	while(1) {
		cout<<"\n\n1. Previous menu\n";
		cout<<"2. Exit\n\n";
        int option;
        cout<<"Please Enter you desired option number: ";
        cin>>option;
        switch(option) {
            case 1:
                system("clear");
                matrixClac();
                break;
            case 2:
            	exit(1);
                break;
            default:
                system("clear");
                cout<<"\n\aPlease enter a valid option number from the below list!";
        }
    }

}

double clacSin(double x) {
    double sign = 1;
    if (x < 0) {
        sign = -1.0;
        x = -x;
    }
    if (x > 360) x -= int(x / 360) * 360;
    if(x == 180 || x == 360) return 0;
    x*= 3.14159265359 / 180.0;
    double res = 0;
    double term = x;
    int k = 1;
    while (res + term != res){
        res += term;
        k += 2;
        term *= -x * x / k / (k - 1);
    }

  return sign * res;
}

double clacCos(double x){
    if (x < 0) x = -x;
    if (x > 360) x -= int(x / 360) * 360;
    if(x == 90 || x == 270) return 0;
    x *= 3.14159265359 / 180.0;
    double res = 0;
    double term = 1;
    int k = 0;
    while (res + term != res) {
        res += term;
        k += 2;
        term *= -x * x / k / (k - 1);
    }
    return res;
}

void mosallasat() {
	cout<<"1. sinx\n";
	cout<<"2. cosx\n";
	cout<<"3. tanx\n";
	cout<<"4. cotx\n";
	cout<<"5. Previous menu\n";
	cout<<"6. Exit\n";

	int option;
	cout<<"\nPlease Enter Your desired option number: ";
	cin>>option;

	switch(option) {
		case 1: {
                system("clear");
                double deg;
                cout<<"Enter the degree: ";
                cin>>deg;
                cout<<"Sin("<<deg<<") = "<<clacSin(deg);
            }
			break;
		case 2: {
                system("clear");
                double deg;
                cout<<"Enter the degree: ";
                cin>>deg;
                cout<<"Cos("<<deg<<") = "<<clacCos(deg);
            }
			break;
		case 3: {
                system("clear");
                double deg;
                cout<<"Enter the degree: ";
                cin>>deg;
                cout<<"tan("<<deg<<") = "<<clacSin(deg) / clacCos(deg);
            }
			break;
		case 4: {
                system("clear");
                double deg;
                cout<<"Enter the degree: ";
                cin>>deg;
                cout<<"cot("<<deg<<") = "<<clacCos(deg) / clacSin(deg);
            }
			break;
		case 5:
            system("clear");
			mainMenu();
			break;
		case 6:
			exit(1);
			break;
		default:
			system("clear");
			cout<<"\aPlease enter a valid option number from the below list!\n\n";
			mosallasat();
	}

	while(1) {
		cout<<"\n\n1. Previous menu\n";
		cout<<"2. Exit\n\n";
        int option;
        cout<<"Please Enter you desired option number: ";
        cin>>option;
        switch(option) {
            case 1:
                system("clear");
                mosallasat();
                break;
            case 2:
            	exit(1);
                break;
            default:
                system("clear");
                cout<<"\n\aPlease enter a valid option number from the below list!";
        }
    }
}


void aboutUs(bool err) {
	cout<<"About us:\n\n";
	cout<<"Name: Ali Alizadeh\n";
	cout<<"Student ID: 97440175\n";
	cout<<"Teacher's Name: Mr Shokrani\n\n";

	if(err == true)
		cout<<"\aPlease enter a valid option number from the below list!\n\n";

	cout<<"1. Previous menu\n";
	cout<<"2. Exit\n\n";

	int option;
	cout<<"Please Enter you desired option number: ";
	cin>>option;
	switch(option) {
		case 1:
			system("clear");
			mainMenu();
			break;
		case 2:
			break;
		default:
			system("clear");
			aboutUs(true);
	}
}

void mainMenu() {
	cout<<"1. Mohasebat Adadi\n";
	cout<<"2. Amal Riazi Matris\n";
	cout<<"3. Mosalast\n";
	cout<<"4. About Us\n";
	cout<<"5. Exit\n";

	int option;
	cout<<"\nPlease Enter Your desired option number: ";
	cin>>option;

	switch(option) {
		case 1:
			system("clear");
			numericalCalc();
			break;
		case 2:
			system("clear");
			matrixClac();
			break;
        case 3:
			system("clear");
            mosallasat();
			break;
		case 4:
			system("clear");
			aboutUs(false);
			break;
		case 5:
			exit(1);
			break;
		default:
			system("clear");
			cout<<"\aPlease enter a valid option number from the below list!\n\n";
			mainMenu();
	}

}
