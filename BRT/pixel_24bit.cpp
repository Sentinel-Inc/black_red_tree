// plik zawiera definicje dla funkcji zadeklarowanych w pixel_24bit.h
//
//

//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//

#include "pixel_24bit.h"


unsigned pixel_24bit::gen_hash(const unsigned& max_color) { // zamiana z przestrzeni 3-wymiarowej na 1
							    //
	return r * (max_color + 1) * (max_color + 1) + g * (max_color + 1) + b;
}
