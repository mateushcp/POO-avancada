#include <iostream>

class NotInicialized {
public:
    NotInicialized() {
        std::cout << "Erro: indice nao inicializado.";
    }
};
class NonPositive {
public:
    NonPositive() {
        std::cout << "Erro: indice negativo.";
    }
};
class Greater {
public:
    Greater() {
        std::cout << "Erro: indice maior que arranjo.";
    }
};

template <class T, int N> class BoundedArray {
public:
    void set(int index, T value) {
        if (index < 0) {
            throw new NonPositive();
        }
        else if (index >= N) {
            throw new Greater();
        }

        buf[index] = value;
    }
    T get(int index) {
        if (index < 0) {
            throw new NonPositive();
        }
        else if (index >= N) {
            throw new Greater();
        }
    if (buf[index] == T()) {
            throw new NotInicialized();
        }

        return buf[index];
    }
private:
    T buf[N];
};


template <class T> void testArray() {
    BoundedArray<T, 8> a;
    char action;
    while (std::cin >> action) {
        int index;
        std::cin >> index;
        try {
            if (action == 's') {
                T value;
                std::cin >> value;
                a.set(index, value);
            }
            else if (action == 'g') {
                std::cout << a.get(index) << std::endl;
            }
        }
        catch (...) {
            std::cerr << "Erro desconhecido." << std::endl;
        }
    }
}

int main() {
    char type;
    std::cin >> type;
    switch (type) {
    case 'd':
        testArray<double>();
        break;
    case 'i':
        testArray<int>();
        break;
    case 's':
        testArray<std::string>();
        break;
    }
    return 0;
}