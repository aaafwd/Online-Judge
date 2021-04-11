/* @JUDGE_ID: 19899RK 10352 C++ "By Anadan" */ 
// Count the eWords
// Accepted (4.355 seconds using as much as 1072 kbytes)

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	int set = 0;
	string s, ss;
	map<string, int> ewords;
	map<string, string> last;

	while (1){
		ewords.clear();
		last.clear();
		while (cin >> s && s != "#"){
			if (s.size() > 5) s = s.substr(0, 5);
			ss = s;
			if (s.size() > 2) s[2] = ' ';
			++ewords[s];
			last[s] = ss;
		}

		if (!ewords.size()) break;
		cout << "Set #" << ++set << ":" << endl;
		for (map<string, int>::iterator i = ewords.begin(); i != ewords.end(); *i++){
			cout << last[i->first] << " " << i->second << endl;
		}

		cout << endl;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
