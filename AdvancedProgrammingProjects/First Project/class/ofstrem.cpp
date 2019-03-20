#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ofstream out;
	out.open("file4.txt", ios::app); // or ios::out
	if (out) {
		string txt = "This is work too";
		out << txt << endl;
	}
	system("pause>0");
	return 0;
}
