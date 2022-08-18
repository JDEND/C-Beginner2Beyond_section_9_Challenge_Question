#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void printNumbers(vector<int>& vec);
void addNumber(int& newNum, vector<int>& vec);
int findMean(vector<int>& vec);
int findSmall(vector<int>& vec);
int findLarge(vector<int>& vec);
void menu(vector<int>& vec);

int main() {

	vector<int> newVec;

	menu(newVec);




	return 0;
}

void printNumbers(vector<int> &vec) {

	if(vec.size() != 0)
	for (int val : vec)
		if (!(val == vec.at(vec.size() - 1)))
			cout << val << ", ";
		else
			cout << val;

	cout << endl;
}

void addNumber(int& newNum, vector<int>& vec) {

	vec.push_back(newNum);
	
	for (int i = 0; i < vec.size(); i++)
		for (int j = 0; j < vec.size(); j++)
			if (vec[i] < vec[j])
				std::swap(vec[i], vec[j]);
}

int findMean(vector<int>& vec) {
	if (vec.size() != 0) {
		int temp = 0;
		for (int val : vec)
			temp += val;

		return (temp / vec.size());
	}
	else
	{
		return 0;
	}
}

int findSmall(vector<int>& vec) {
	if (vec.size() != 0)
	return(vec[0]);

}

int findLarge(vector<int>& vec) {
	if (vec.size() != 0)
	return(vec[vec.size() - 1]);

}

void menu(vector<int>& vec) {
	bool boolean = true;
	while (boolean) {
		char temp;
		cout << "Choose an option from the menu below:\n";
		cout << "P - Print numbers\nA - Add number\nM - Display mean of numbers\nS - Display the smallest number\nL - Display the largest number\nQ - Quit\n";
		cin >> temp;
		temp = toupper(temp);

		switch (temp){
		case 'P':
			printNumbers(vec);
			break;
		case 'A':
			int numTemp;
			cout << "Input number to add:";
			cin >> numTemp;
			addNumber(numTemp, vec);
			cout << endl;
			break;
		case 'M':
			cout << "Mean: " << findMean(vec) << endl;
			break;
		case 'S':
			cout << "Smallest value: " << findSmall(vec) << endl;
			break;
		case 'L':
			cout << "Largest value: " << findLarge(vec) << endl;
			break;
		case 'Q':
			boolean = false;
			break;
		default:
			cout << "Please enter a valid input:\n";
			break;
		}
	}


}
