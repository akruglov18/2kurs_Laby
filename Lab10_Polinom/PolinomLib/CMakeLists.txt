project(PolinomLib)

add_library(PolinomLib Polinom.cpp Monom.cpp Polinom.h Monom.h List.cpp TListElem.cpp List.h TListElem.h)

target_include_directories(PolinomLib PUBLIC .)