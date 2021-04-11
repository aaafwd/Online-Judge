/* @JUDGE_ID: 19899RK 282 C++ "By Anadan" */
// Rename
// Accepted (0.080 seconds with low memory spent)

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void ExtractPrefixSuffix(const std::string& str, std::string* prefix,
                         std::string* suffix) {
  int pos = str.find('*');
  *prefix = str.substr(0, pos);
  *suffix = str.substr(pos + 1);
}

bool StartsWith(const std::string& str, const std::string& prefix) {
  return str.rfind(prefix, 0) == 0;
}

bool EndsWith(const std::string& str, const std::string& suffix) {
  return str.size() >= suffix.size() &&
         str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

int main() {
  char buffer[1024];
  std::vector<std::string> files;
  std::string str, old_pattern, new_pattern, prefix1, suffix1, prefix2, suffix2;
  while (1) {
    files.clear();
    while (std::cin >> str) {
      if (str == "end") break;
      files.push_back(std::move(str));
    }
    if (files.empty()) break;
    std::cin >> std::ws;
    while (std::getline(std::cin, str)) {
      if (str == "end") break;
      std::cout << str << std::endl;
      std::stringstream ss(str);
      ss >> str >> old_pattern >> new_pattern;
      ExtractPrefixSuffix(old_pattern, &prefix1, &suffix1);
      ExtractPrefixSuffix(new_pattern, &prefix2, &suffix2);
      const int min_len = prefix1.size() + suffix1.size();
      for (int i = 0; i < files.size(); ++i) {
        const std::string& file = files[i];
        if (file.size() >= min_len && StartsWith(file, prefix1) &&
            EndsWith(file, suffix1)) {
          std::cout << "mv " << file << " " << prefix2
                    << file.substr(prefix1.size(), file.size() - min_len)
                    << suffix2 << std::endl;
        }
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
