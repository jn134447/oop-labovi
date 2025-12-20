#ifndef ZOO_SECTION_H
#define ZOO_SECTION_H

#include <vector>
#include <memory>
#include <stdexcept>

template <typename T>
class ZooSection
{
private:
    std::vector<std::unique_ptr<T>> animals;

public:
    void addAnimal(std::unique_ptr<T> animal);
    double totalFood() const;
    std::size_t size() const;
    T *getAnimal(size_t index) const;
};


#include "zoo_section.tpp"

#endif
