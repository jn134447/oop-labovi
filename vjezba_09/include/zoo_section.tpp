#include "zoo_section.hpp"

template <typename T>
inline void ZooSection<T>::addAnimal(std::unique_ptr<T> animal)
{
    animals.emplace_back(std::move(animal));
}

template <typename T>
double ZooSection<T>::totalFood() const
{
    double total_food = 0;
    for (std::unique_ptr<T> &animal : animals)
    {
        total_food += animal.get()->getDailyFood();
    }
}

template <typename T>
std::size_t ZooSection<T>::size() const
{
    return animals.size();
}

template <typename T>
T *ZooSection<T>::getAnimal(size_t index) const
{
    T *ptr = animals.at(index).get();
    if (ptr == nullptr)
        throw std::runtime_error("getAnimal() returned nullptr");
    else
        return ptr;
}
