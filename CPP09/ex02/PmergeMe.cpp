#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>

PmergeMe::PmergeMe(const std::vector<int>& input)
    : numbers(input), dequeNumbers(input.begin(), input.end()) {}

PmergeMe::~PmergeMe() {}


// === Méthodes pour std::vector ===
void PmergeMe::process()
{
    splitIntoPairs();
    sortPairs();
    splitIntoSmallAndLarge();
    mergeSortVector(large);
    mergeSmallIntoLarge();
}

void PmergeMe::splitIntoPairs() {
    pairs.clear();
    for (size_t i = 0; i < numbers.size(); i += 2)
    {
        if (i + 1 < numbers.size())
            pairs.push_back(std::make_pair(numbers[i], numbers[i + 1]));
        else
            pairs.push_back(std::make_pair(numbers[i], -1));
    }
}

void PmergeMe::sortPairs()
{
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].second != -1 && pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

void PmergeMe::splitIntoSmallAndLarge()
{
    small.clear();
    large.clear();
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        small.push_back(pairs[i].first);
        if (pairs[i].second != -1)
            large.push_back(pairs[i].second);
    }
}

void PmergeMe::mergeVector(std::vector<int>& vec, int left, int mid, int right)
{
    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (vec[i] <= vec[j])
            temp.push_back(vec[i++]);
        else
            temp.push_back(vec[j++]);
    }

    while (i <= mid) temp.push_back(vec[i++]);
    while (j <= right) temp.push_back(vec[j++]);

    for (int k = left; k <= right; ++k)
    {
        vec[k] = temp[k - left];
    }
}

void PmergeMe::mergeSortVectorHelper(std::vector<int>& vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortVectorHelper(vec, left, mid);
        mergeSortVectorHelper(vec, mid + 1, right);
        mergeVector(vec, left, mid, right);
    }
}

void PmergeMe::mergeSortVector(std::vector<int>& vec)
{
    mergeSortVectorHelper(vec, 0, vec.size() - 1);
}

void PmergeMe::binaryInsert(std::vector<int>& list, int value)
{
    int left = 0, right = list.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (list[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    list.insert(list.begin() + left, value);
}

void PmergeMe::mergeSmallIntoLarge()
{
    for (size_t i = 0; i < small.size(); ++i)
        binaryInsert(large, small[i]);
}

std::vector<int>& PmergeMe::getLarge()
{
    return large;
}





// === Méthodes pour std::deque ===
void PmergeMe::processDeque()
{
    splitIntoPairsDeque();
    sortPairsDeque();
    splitIntoSmallAndLargeDeque();
    mergeSortDeque(dequeLarge);
    mergeSmallIntoLargeDeque();
}

void PmergeMe::splitIntoPairsDeque()
{
    dequePairs.clear();
    for (std::deque<int>::iterator it = dequeNumbers.begin(); it != dequeNumbers.end();)
    {
        int first = *it++;
        int second = (it != dequeNumbers.end()) ? *it++ : -1;
        dequePairs.push_back(std::make_pair(first, second));
    }
}

void PmergeMe::sortPairsDeque()
{
    for (size_t i = 0; i < dequePairs.size(); ++i)
    {
        if (dequePairs[i].second != -1 && dequePairs[i].first > dequePairs[i].second)
            std::swap(dequePairs[i].first, dequePairs[i].second);
    }
}

void PmergeMe::splitIntoSmallAndLargeDeque()
{
    dequeSmall.clear();
    dequeLarge.clear();
    for (size_t i = 0; i < dequePairs.size(); ++i)
    {
        dequeSmall.push_back(dequePairs[i].first);
        if (dequePairs[i].second != -1)
            dequeLarge.push_back(dequePairs[i].second);
    }
}

void PmergeMe::mergeDeque(std::deque<int>& /*deq*/, std::deque<int>::iterator left, std::deque<int>::iterator mid, std::deque<int>::iterator right)
{
    std::deque<int> temp;
    std::deque<int>::iterator i = left;
    std::deque<int>::iterator j = mid;

    while (i != mid && j != right)
    {
        if (*i <= *j)
            temp.push_back(*i++);
        else
            temp.push_back(*j++);
    }

    while (i != mid) temp.push_back(*i++);
    while (j != right) temp.push_back(*j++);

    std::copy(temp.begin(), temp.end(), left);
}

void PmergeMe::mergeSortDequeHelper(std::deque<int>& deq, std::deque<int>::iterator left, std::deque<int>::iterator right)
{
    if (std::distance(left, right) > 1)
    {
        std::deque<int>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        mergeSortDequeHelper(deq, left, mid);
        mergeSortDequeHelper(deq, mid, right);
        mergeDeque(deq, left, mid, right);
    }
}

void PmergeMe::mergeSortDeque(std::deque<int>& deq)
{
    mergeSortDequeHelper(deq, deq.begin(), deq.end());
}

void PmergeMe::binaryInsertDeque(std::deque<int>& list, int value)
{
    std::deque<int>::iterator left = list.begin(), right = list.end();
    while (left != right)
    {
        std::deque<int>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        if (*mid < value)
            left = mid + 1;
        else
            right = mid;
    }
    list.insert(left, value);
}

void PmergeMe::mergeSmallIntoLargeDeque()
{
    for (size_t i = 0; i < dequeSmall.size(); ++i)
        binaryInsertDeque(dequeLarge, dequeSmall[i]);
}

const std::deque<int>& PmergeMe::getLargeDeque() const
{
    return dequeLarge;
}
