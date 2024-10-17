#include <iostream>
#include<string.h>
//v2 해석 대상을 스트링으로 바꾸어 인터프리터 고급언어랑 컴파일러고급언어의 차이를 보이고자 했습니다.

class machinelan {
private:
    int d;
public:
    machinelan(int d) : d(d) {}
    int Get() const {
        return d;
    }
};

class assemblylan {
private:
    std::string n;
    int p;
public:
    assemblylan(std::string c, int a = 0) : n(c), p(a) {}
    std::string Get() const {
        return n;
    }
    int preGet() const {
        return p;
    }
};

class interpreterhl {
private:
    const std::string n;
    int p;
public:
    interpreterhl(std::string c, int a = 0) : n(c), p(a) {}
    std::string Get() const {
        return n;
    }
    int preGet() const {
        return p;
    }
};

class compilerhlan {
private:
    const std::string n;
    int p;
public:
    compilerhlan(std::string c, int a = 0) : n(c), p(a) {}
    std::string Get() const {
        return n;
    }
    int preGet() const {
        return p;
    }
};

class exe {
private:
    int d;
public:
    exe(int d) : d(d) {}
    int Get() const {
        return d;
    }
};
template <typename T>
T preprocessor(T s) {
    if (s.preGet() == 1) {
        return s;
    } else {
        return T(s.Get(), 1);
    }
}

template <typename T>
machinelan compiler(T a)
{
    if (typeid(a) == typeid(interpreterhl)){
        int c=0;
        for (int b=0;b<a.Get().size();b++){
            c+=pow(10, a.Get().size() - 1 - b) * (a.Get()[b] - '0');
        }
        return machinelan(c);
    }
    return machinelan(stoi(a.Get()));
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
    compilerhlan comp("1234", 0);
    interpreterhl interp("2345", 0);
    assemblylan assem("5678", 0);

    debug(comp, comp);
    debug(interp, interp);
    debug(assem, assem);

    return 0;
}
