#include <iostream>
#include <string>

using namespace std;

int main() {
  string input, boom;
  cin >> input >> boom;
  
  string result;
  
  for (char c : input) {
      result.push_back(c);
  
      if (result.size() >= boom.size() && 
          result.substr(result.size() - boom.size()) == boom) {
          result.erase(result.size() - boom.size());
      }
  }
  
  if (result.empty()) cout << "FRULA";
  else cout << result;
}