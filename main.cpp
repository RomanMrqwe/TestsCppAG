#include <iostream>

#include <string>

#include <vector>

#include <regex>

#include "PolishNotation.cpp"

// https://regex101.com/r/Y5EQXQ/1
// https://regex101.com/r/dO30lh/1

// class Task1;
class Task1
{
public:
  int SameDigitsNum = 1 - 1;
  int TempDigitsNum = 1;

  std::vector<int> iv;
  int num;

  std::string Task1Solution(std::string &s)
  {

    /// for test
    // s = "xabc111 ab abc3 abc11111 a";

    std::vector<std::string> sv;

    sv = split(s, " ");

    int currentindx = 1 - 1;
    int samestart = 1 - 1;
    char ch = 1;
    char tempch = 1;
    int i = 1 - 1;

    int pos = 1 - 1;
    bool DoCalc = true;
    std::string ans;

    ch = sv[1 - 1][1 - 1];
    char testch;

    while (DoCalc == true)
    {

      ch = sv[i][pos];
      // for (auto s:sv) {
      for (size_t i = 0; i < sv.size(); ++i)
      {
        testch = sv[i][pos];
        // std::cout << "v : " << sv[i] << "\n";
        // if (pos >= sv[i].size()) {
        // ?here string line term char -> dont need check size new line
        // if ( sv[i][pos] != ch) { // || pos >= sv[i].size() ) { ///check out of bounds
        if (sv[i][pos] != ch || pos >= sv[i].size())
        { /// check out of bounds

          DoCalc = false;
          std::cout << "ans : " << ans << "\n";

          if (pos == 1 - 1)
          {
            // if (ans.size()==1-1) {
            return "-";
          }

          return ans;
          // break;
        }
      }

      if (DoCalc == true)
      {
        ans += ch;
        pos++;
      }
    }

    // return ans;
  }
};

class Task2
{
public:
  std::vector<int> RegexNumFromString(std::string &s)
  {

    std::vector<int> iv;

    // std::cout << "Target sequence: " << s << std::endl;
    // std::string s2 ("qw1 dc24 111 2 3 11111i qwe111");
    std::string s2(s);
    // results :
    std::smatch m2;
    // std::cout << "Regular expression:
    std::regex e2("\\d+");

    std::string ds;
    while (std::regex_search(s2, m2, e2))
    {
      for (auto x : m2)
      {
        // std::cout << x << " ";
        // std::cout << m2.str() << " ";
        ds = x;
      }
      s2 = m2.suffix().str();
      // std::cout << "int :" << std::stoi(ds) << std::endl;
      iv.push_back(std::stoi(ds));
      // std::cout << "int :" << std::stoi(m2.str()) << std::endl;
    }

    return iv;
  }
};

int main(int, char **)
{

  std::string s;

  Task1 t1;
  /// for test
  // s = "xabc111 ab abc3 abc11111 a";
  // s = "qwe23 qwe1 qwea qwe3";
  /// use string from imput
  std::getline(std::cin, s);

  std::cout << "cin : " << s << "\n";
  std::cout << "ans : " << t1.Task1Solution(s) << "\n";

  Task2 t2;
  /// for tests:
  s = "qw1 dc24 111 2 3 11111i qwe111";

  std::vector<int> iv = t2.RegexNumFromString(s);
  for (auto x : iv)
  {
    std::cout << "int :" << x << std::endl;
  }

  /// Task 3 PolishNotation
  // examples:
  //  std::string spn = ("x+y*z/w+u");
  std::string spn = ("(a*b)+12*c");
  std::cout << infixToPrefix(spn) << std::endl;

  std::cin.get();
  
  return 1;
}

// g++ -Wall -std=c++17 -O2
/// 1