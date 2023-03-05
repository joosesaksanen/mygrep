#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool belongsTo(string temp, string search, int &position);
void simplePrint(string temp, string search, bool found, int &pos);

int main (int argc,char* argv[]) {
	string templateString;
	string searchString;
	bool includes;
	int position;
	int counter;
	if (argc == 1) {
		cout << "Give me a string from which to search for: ";
		getline(cin, templateString);
		cout << "Give serach string: ";
		getline(cin, searchString);
		includes = belongsTo(templateString, searchString, position);
		simplePrint(templateString, searchString, includes, position);

	}
	if (argc == 2) {
		cout << "Invalid number of arguments!" << endl;
	}
	if (argc == 3) {
		searchString = argv[1];
		ifstream textFile;
		string line;
		textFile.open(argv[2]);
		while(getline(textFile, line)) {
			includes = belongsTo(line, searchString, position);
			if (includes == true) {
				cout << line << endl;
			}
		}

	}
	/*if (argc == 4) {
		searchString = argv[2];
		ifstream textFile;
		string line;
		textFile.open(argv[3]);
		string argument = argv[1];
		if (argument == "-olo") {
			//cout << "-olo" << endl;

		} if (argument == "")
		while(getline(textFile, line)) {
			includes = belongsTo(line, searchString, position);
			if (includes == true) {
				cout << line << endl;
			}
		}
	}
	*/
	return 0;
}

bool belongsTo(string temp, string search, int &position) {
	size_t found = temp.find(search);
	if (found > 100) {	//if find function doesn't find correct value, it returns a very big number
		return false;
	} else {
		position = found;
		return true;
	}
}

void simplePrint(string temp, string search, bool found, int &pos) {
	if (found) {
		cout << "\"" << search << "\"" << " found in " << "\"" << temp << "\"" << " in position " << pos << endl;
	} else {
		cout << "\"" << search << "\"" << " NOT found in " << "\"" << temp << "\"" << endl;
	}

}

