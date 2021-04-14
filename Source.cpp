#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void changerank(string& a)
{
	if (a == "V") {
		a = "11";
	}
	if (a == "Q") {
		a = "12";
	}
	if (a == "K") {
		a = "13";
	}
	if (a == "A") {
		a = "14";
	}
}

void print(vector<vector<string>>& a) {
	for (int i = 0; i < 8; i++) {
		for (auto& k : a[i])
		{
			cout << k << " ";
		}
	}
}

void read(vector<vector<string>>& a) {
	string card;
	for (int i = 0; i < 8; i++) {
		cout << "¬ведите " << i + 1 << " кучку карт:" << endl;
		for (int j = 0; j < 9; j++)
		{
			cin >> card;
			changerank(card);
			a[i].push_back(card);
		}
	}
}

struct TOP {
	string top;
	int index;
};

bool cmp(TOP& a, TOP& b) {
	return a.top < b.top;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 9;
	vector < vector <string> > a(8, vector<string> (n));
	TOP b;
	vector <TOP> top_cards(8);
	for (int i = 0; i < 8; i++) {
		b.index = i;
		b.top = a[i][8];
		top_cards.push_back(b);
	}
	sort(begin(top_cards), end(top_cards), cmp);

	read(a);
	print(a);

	return 0;
}