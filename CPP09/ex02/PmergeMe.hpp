#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <utility>
#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <utility>
#include <cstdlib>
#include <climits>
#include <ctime>

class PmergeMe {
public:
    // Constructeur et destructeur
    PmergeMe(const std::vector<int>& input);
    ~PmergeMe();

    // Méthodes pour std::vector
    void process(); // Lance toutes les étapes pour std::vector
    std::vector<int>& getLarge(); // Retourne le vecteur trié "large"

    // Méthodes pour std::deque
    void processDeque(); // Lance toutes les étapes pour std::deque
    const std::deque<int>& getLargeDeque() const; // Retourne le deque trié "large"

private:
    // Membres pour std::vector
    std::vector<int> numbers;
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> small;
    std::vector<int> large;

    // Méthodes privées pour std::vector
    void splitIntoPairs();
    void sortPairs();
    void splitIntoSmallAndLarge();
    void mergeSortVector(std::vector<int>& vec);
    void mergeVector(std::vector<int>& vec, int left, int mid, int right);
    void mergeSortVectorHelper(std::vector<int>& vec, int left, int right);
    void binaryInsert(std::vector<int>& list, int value);
    void mergeSmallIntoLarge();

    // Membres pour std::deque
    std::deque<int> dequeNumbers;
    std::deque<std::pair<int, int> > dequePairs;
    std::deque<int> dequeSmall;
    std::deque<int> dequeLarge;

    // Méthodes privées pour std::deque
    void splitIntoPairsDeque();
    void sortPairsDeque();
    void splitIntoSmallAndLargeDeque();
    void mergeSortDeque(std::deque<int>& deq);
    void mergeDeque(std::deque<int>& deq, std::deque<int>::iterator left, std::deque<int>::iterator mid, std::deque<int>::iterator right);
    void mergeSortDequeHelper(std::deque<int>& deq, std::deque<int>::iterator left, std::deque<int>::iterator right);
    void binaryInsertDeque(std::deque<int>& list, int value);
    void mergeSmallIntoLargeDeque();
};

#endif