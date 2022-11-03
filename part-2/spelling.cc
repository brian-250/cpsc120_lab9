// Grey Espinoza
// CPSC 120-12
// 2022-11-03
// gray@csu.fullerton.edu
// @CSUFgrey
//
// Lab 09-02
// Partners: @brian-250
//
// returns whether a word is in the dictionary
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> ReadWords(const std::string& filename) {
  std::vector<std::string> words{};
  std::ifstream file{filename};
  while (file.good()) {
    std::string word_buffer;
    file >> word_buffer;
    words.push_back(word_buffer);
  }
  return words;
}

bool InDictionary(const std::vector<std::string>& dictionary,
                  const std::string& word) {
  bool word_in_dictionary = false;
  for (const std::string& element : dictionary) {
    if (word == element) {
      word_in_dictionary = true;
    }
  }
  return word_in_dictionary;
}

std::vector<std::string> MisspelledWords(
    const std::vector<std::string>& dictionary,
    const std::vector<std::string>& document) {
  std::vector<std::string> misspelled_words{};
  for (const std::string& element : document) {
    if (!(InDictionary(dictionary, element))) {
      misspelled_words.push_back(element);
    }
  }
  return misspelled_words;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);

  if (arguments.size() != 2) {
    std::cout << "error: you must give a document filename\n";
    return -1;
  }

  std::string file_name = arguments.at(1);
  std::vector<std::string> dictionary{ReadWords("words.txt")};
  std::vector<std::string> document{ReadWords(file_name)};
  std::vector<std::string> misspelled_words{
      MisspelledWords(dictionary, document)};

  std::cout << "spelling errors:\n";
  for (const std::string& element : misspelled_words) {
    std::cout << element << "\n";
  }

  return 0;
}