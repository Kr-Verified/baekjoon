#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  
  int n, len;
  string input, word;

  cin >> n;
  cin.ignore();
  while (n--) {
    getline(cin, input);
    istringstream iss(input);

    len = 0;
    vector<string> words;
    while (iss >> word) {
      words.push_back(word);
      len++;
    }

    for (int i = 2; i < len; i++) cout << words[i] << " ";
    cout << words[0] << " " << words[1] << '\n';
  }

  return 0;
}