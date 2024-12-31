g++ -std=c++23 -O2 basic.cpp -o basic
#g++ -std=c++23 -O2 -mprefer-vector-width=512 -march=native basic.cpp -o basic_native
g++ -std=c++23 -O2 -mprefer-vector-width=512 basic.cpp -o basic_native
g++ -std=c++23 -O2 64.cpp -o 64
