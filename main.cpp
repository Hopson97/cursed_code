#include <iostream>

class CursedClass {
	public:
		void curse() 
		{
			a = 0;
			b = 1;
			c = 2;
			d = 3;
		}

	private:
		int a;
		int b;
		int c;
		int d;
};

int main() 
{
	char* cursed_memory = static_cast<char*>(std::calloc(1, sizeof CursedClass));
	CursedClass cursed = *reinterpret_cast<CursedClass*>(cursed_memory);
	cursed.curse();
	int* cursed_pointer = reinterpret_cast<int*>(&cursed);
	for (int i = 0; i < 4; i++) {
		std::cout << *cursed_pointer + i << std::endl;
	}
	std::free(cursed_memory);
}