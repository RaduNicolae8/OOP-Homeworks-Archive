#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cctype>

bool comparator(std::pair<std::string, unsigned> w1, std::pair<std::string, unsigned> w2) {
    if(w1.second == w2.second) return w1.first < w2.first;
    return w1.second < w2.second;
}

std::string tolowercase(std::string word) {
    for(int i = 0; i < word.size(); i++) tolower(word[i]);
    return word;
}

int main() {
    std::string word;
    std::unordered_map<std::string, unsigned> wordMap;
    while(std::cin >> word) {
        word = tolowercase(word);
        wordMap[word]++;
    }
    std::vector<std::pair<std::string, unsigned>> words(wordMap.begin(), wordMap.end());
    std::sort(words.begin(), words.end(), comparator);
    for(std::pair<std::string, unsigned> entry : words) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }
    return 0;
}