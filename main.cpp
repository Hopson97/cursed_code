#include <iostream>
#include <cstddef>

#define cursed_int(n) std::int##n##_t

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
    const int* const cursed_pointer = reinterpret_cast<const cursed_int(32)* const>(&cursed);
    for (int i = 0; i < sizeof T / sizeof(cursed_int(32)); i++) {
        *const_cast<int*>(&cursed_pointer[i]) = i;
    }
}

int main() {
    char* cursed_memory = static_cast<char*>(std::calloc(1, sizeof CursedClass));
    curse(reinterpret_cast<CursedClass*>(cursed_memory));
    CursedClass cursed = *reinterpret_cast<CursedClass*>(cursed_memory);
    cursed_int(32)* cursed_pointer = reinterpret_cast<cursed_int(32)*>(&cursed);
    for (int i = 0; i < sizeof CursedClass / sizeof(cursed_int(32)); i++) {
        std::cout << *cursed_pointer + i << std::endl;
    }
    std::free(cursed_memory);
}
