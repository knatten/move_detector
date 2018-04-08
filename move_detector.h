#include <iostream>

enum class construction_method {
    unknown, constructed, copy_contstucted, move_constructed, copy_assigned, move_assigned
};

template <typename T>
class move_detector {
public:
    move_detector(T v) :
        value(v),
        method(construction_method::constructed)
    {
        std::cout << "constructed " << value << std::endl;
    }

    move_detector(const move_detector<T>& other) :
        value(other.value),
        method(construction_method::copy_contstucted)
    {
        std::cout << "copy constructed " << value << std::endl;
    }

    move_detector(move_detector<T>&& other) :
        value(std::move(other.value)),
        method(construction_method::move_constructed)
    {
        other.was_moved = true;
        std::cout << "move constructed " << value << std::endl;
    }

    move_detector<T>& operator=(const move_detector<T>& other) {
        value = other.value;
        method = construction_method::copy_assigned;
        std::cout << "copy assigned " << value << std::endl;
        return *this;
    }

    move_detector<T>& operator=(move_detector<T>&& other) {
        value = other.value;
        method = construction_method::move_assigned;
        other.was_moved = true;
        std::cout << "move assigned " << value << std::endl;
        return *this;
    }

    T value;
    bool was_moved = false;
    construction_method method = construction_method::unknown; 
};
