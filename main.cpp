#include <iostream>

#ifdef _WIN32
    #pragma warning( push )
    #pragma warning( disable : 4789 )
#endif // _WIN32

class CursedClass {
    int
        #include "letters"
    ;
};

template<typename T>
void curse(const T* const cursed) {
    const int* const cursed_pointer = reinterpret_cast<const int* const>(&cursed);
    for (int i = 0; i < sizeof T / sizeof(int); i++) {
        *const_cast<int*>(&cursed_pointer[i]) = i;
    }
}

int main() {
    char* cursed_memory = static_cast<char*>(std::calloc(1, sizeof CursedClass));
    curse(reinterpret_cast<CursedClass*>(cursed_memory));
    CursedClass cursed = *reinterpret_cast<CursedClass*>(cursed_memory);
    int* cursed_pointer = reinterpret_cast<int*>(&cursed);
    for (int i = 0; i < sizeof CursedClass / sizeof(int); i++) {
        std::cout << *cursed_pointer + i << std::endl;
    }
    std::free(cursed_memory);
}
