#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream in;
	in.open("file.txt", ios::in);
	if (in) {
		string txt;
		getline(in, txt);
		cout << txt;
	}
	else {
		cout << "Error" << endl;
	}
	system("pause>0");
	return 0;
}