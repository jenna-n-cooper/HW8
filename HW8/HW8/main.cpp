#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	string cirfilename;
	string vecfilename;

	string currWord;

	cout << "What is the name of the circuit file? (ex. circuit.txt) ";
	getline(cin, cirfilename);

	cout << "What is the name of the vector file? ";
	getline(cin, vecfilename);
	
	ifstream inFile;

	inFile.open(cirfilename);

	if (inFile.fail()) {

		cout << "error opening file." << endl;
		return 1;

	}

	string line;
	string ioo;
	char wn;
	int wnum;
	int line_num = 0;
	vector<char>inwiresname;
	vector<char>outwiresname;
	vector<int>wiresnum;

	//just messing with file input right now, this is not exactly how it'll be i dont think
	while (!inFile.eof()) {
		
		line_num++;
		getline(inFile, line);
		
	}
	inFile.seekg(21, fstream::beg);
	while (line_num > 2) {
		
		inFile >> ioo >> wn >> wnum;

		if (ioo == "INPUT") {
			inwiresname.push_back(wn);
			wiresnum.push_back(wnum);

		}
		else if (ioo == "OUTPUT") {
			outwiresname.push_back(wn);
			wiresnum.push_back(wnum);
		}
		
		
		line_num--;
	}

	inFile.close();

	return 0;
}