#include <iostream>

class machinelan {
private:
    double d;
public:
    machinelan(double d) : d(d) {}
    char Get() const {
        return d;
    }
};

class assemblylan {
private:
    char n;
    int p;
public:
    assemblylan(char c, int a = 0) : n(c), p(a) {}
    char Get() const {
        return n;
    }
    int preGet() const {
        return p;
    }
};

class interpreterhl {
private:
    const char n;
    int p;
public:
    interpreterhl(char c, int a = 0) : n(c), p(a) {}
    char Get() const {
        return n;
    }
    int preGet() const {
        return p;
    }
};

class compilerhlan {
private:
    const char n;
    int p;
public:
    compilerhlan(char c, int a = 0) : n(c), p(a) {}
    char Get() const {
        return n;
    }
    int preGet() const {
        return p;
    }
};

class exe {
private:
    double d;
public:
    exe(double d) : d(d) {}
    double Get() const {
        return d;
    }
};
template <typename T>
T preprocessor(T s) {
    if (s.preGet() == 1) {
        return s;
    }
    else {
        return T(s.Get(), 1);
    }
}

using namespace std;
template <typename T>
machinelan compiler(T a)
{
    return machinelan(static_cast<double>(a.Get()));
}
exe linker(machinelan a, machinelan b) {
    return exe(a.Get() + b.Get());
}
template<typename T>
void debug(T a,T b) {
    exe c=linker(compiler(preprocessor(a)), compiler(preprocessor(b)));
    std::cout << c.Get()<<std::endl;
}


int main() {
    compilerhlan comp('a', 0);
    interpreterhl interp('b', 0);
    assemblylan assem('c', 0);

    debug(comp, comp);
    debug(interp, interp);
    debug(assem, assem);

    return 0;
}
