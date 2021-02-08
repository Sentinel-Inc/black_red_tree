// definicje wyj¹tków wystêpuj¹chych przy wczytywaniu danych z plików
// jako ¿e wyj¹tki mog¹ byæ spowodowane tylko wadliwym plikiem
// nigdzie w funkcjach wyj¹tki nie s¹ ³apane 
//
//
//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//


#pragma once
#ifndef FILE_EXCEPTION_H
#define FILE_EXCEPTION_H
#include <exception>
namespace exception {

	class file_error_exception : public  std::exception
	{
	public:
		const char* what() const throw () { // b³¹d pliku 
			return "file error";
		}



	};

	class bad_dimentions_exception : public  file_error_exception {
	public:
		const char* what() const throw () {
			return "invalid image dimentions";// niew³aœciwy rozmiar pliku
		}
	};




	class invalid_path_exception : public  file_error_exception {
	public:
		const char* what() const throw () { // niew³aœciwa œcie¿ka, lub niew³aœciwe rozszerzenie pliku
			return "invalid image path";
		}
	};



	class invalid_file_format_exception : public  file_error_exception {
	public:
		const char* what() const throw () { // niew³aœciwy nag³ówek pliku
			return "invalid file format";
		}
	};



	class invalid_character_exception : public  file_error_exception {
	public:
		const char* what() const throw () { //nieporz¹dany znak
			return "unexpected caracter occured";
		}
	};

	class not_implemented_file_format_exception : public  file_error_exception {
	public:
		const char* what() const throw () { // niezaimplementowany nag³ówek 
			return "not implemented file format";
		}
	};


}
#endif // !FILE_EXCEPTION_H
