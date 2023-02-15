#include <iostream>
#include <string>

using namespace std;

bool belongsTo(string temp, string search, int &position);

int main () {
	string templateString;
	string searchString;
	bool includes;
	int position;
	cout << "Give me a string from which to search for: ";
	getline(cin, templateString);
	//cin.ignore();
	cout << "Give serach string: ";
	getline(cin, searchString);
	//cout << templateString << endl;
	//cout << searchString[2] << endl;

	includes = belongsTo(templateString, searchString, position);
	if (includes) {

		cout << "\"" << searchString << "\"" << " found in " << "\"" << templateString << "\"" << " in position " << position << endl;
	} else {
		cout << "\"" << searchString << "\"" << " NOT found in " << "\"" << templateString << "\"" << endl;
	}

	return 0;
}

bool belongsTo(string temp, string search, int &position) {
	size_t found = temp.find(search);
	//cout << found << endl;
	if (found > 100) {

		return false;
	} else {
		position = found;
		return true;
	}
}
//string.find()
