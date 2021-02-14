# CMakeList.txt: projekt CMake dla elementu BRT, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (BRT "main.cpp"  "node.h" "node.cpp" "tree.h"  "pair.h" "map.h" "FreaquencyCounter.h" "pixel_24bit.h" "pixel_24bit.cpp" "ppm.h" "ppm.cpp"  "file_exception.h")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
