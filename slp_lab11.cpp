#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <ctime>
#include <cctype>

#define streql(s1, s2) (s1 == s2)

std::ifstream inp;
int wordcount = 0;
std::vector<std::string> words;
std::unordered_map<std::string, std::vector<std::string>> wordPairs;

void fatal(const std::string& msg)
{
    std::cout << "FATAL ERROR: " << msg << std::endl;
    exit(1);
}

void opentext(const std::string& filename)
{
    inp.open(filename);
    if (!inp.is_open()) 
        fatal("file open failed");
}

bool getword(std::string& word)
{
    int c = inp.get();
    if (c <= 0) 
        return false;
    
    while (!std::isalpha(c)) {
        c = inp.get();
        if (c <= 0) 
            return false;
    }
    
    while (std::isalpha(c) && (c >= 0)) {
        word.push_back(c);
        c = inp.get();
    }
    
    if (c >= 0) 
        inp.unget();
    
    return true;
}

void readwords()
{
    std::string word;
    while (getword(word)) {
        words.push_back(word);
        wordcount++;
    }
}

void buildWordPairs()
{
    for (int i = 0; i < wordcount - 2; i++) {
        std::string word1 = words[i];
        std::string word2 = words[i + 1];
        std::string nextWord = words[i + 2];
        
        wordPairs[word1 + " " + word2].push_back(nextWord);
    }
}

std::string pickNextWord(const std::string& word1, const std::string& word2)
{
    std::vector<std::string>& nextWords = wordPairs[word1 + " " + word2];
    if (nextWords.empty())
        fatal("pickNextWord did not find next word");
    
    int randomIndex = rand() % nextWords.size();
    return nextWords[randomIndex];
}

void generate(int howmany, const std::string& word1, const std::string& word2)
{
    std::string currentWord1 = word1;
    std::string currentWord2 = word2;

    std::cout << currentWord1 << " " << currentWord2;

    for (int count = 2; count < howmany; count++) {
        std::string newWord = pickNextWord(currentWord1, currentWord2);
        currentWord1 = currentWord2;
        currentWord2 = newWord;

        if (count % 10 == 0)
            std::cout << "\n";
        else
            std::cout << " ";

        if (std::isupper(currentWord2[0]))
            std::cout << ".";

        std::cout << currentWord2;
    }

    std::cout << "." << std::endl;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    
    opentext("..\\life.txt");
    readwords();
    inp.close();
    
    buildWordPairs();
    
    generate(10000, words[wordcount / 2], words[wordcount / 2 + 1]);
    
    return 0;
}
