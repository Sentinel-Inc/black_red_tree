# CMakeList.txt: projekt CMake dla elementu BRT, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (BRT "BRT.cpp" "BRT.h" "node.h" "node.cpp" "tree.h" "tree.cpp")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
