#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <fstream>
#include <ios>
#include <iostream>
#include <string>

#define SHRUB_SIGN 145
#define SHRUB_EXEC 137

class ShrubberyCreationForm : public AForm
{
  private:
	std::string _target;

  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();

	const std::string getTarget();
	void execute(const Bureaucrat &bur);

	class FileNotOpenException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return (
				RED
				"ShrubberyCreationForm Exception : file can't be opened." NC);
		};
	};
};

#define ASCII_TREE                                                             \
	"                                                         .\n\
                                              .         ;\n\
                 .              .              ;%     ;;\n\
                   ,           ,                :;%  %;\n\
                    :         ;                   :;%;'     .,\n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'\n\
                        `@%.  `;@%.      ;@@%;\n\
                          `@%%. `@%%    ;@@%;\n\
                            ;@%. :@%%  %@@%;\n\
                              %@bd%%%bd%%:;\n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '\n\
                                %@@@o%;:(.,'\n\
                            `.. %@@@o%::;\n\
                               `)@@@o%::;\n\
                                %@@(o)::;\n\
                               .%@@@@%::;\n\
                               ;%@@@@%::;.\n\
                              ;%@@@@%%:;;;.\n\
                          ...;%@@@@@%%:;;;;,..\n\
"

#endif // !SHRUBBERYCREATIONFORM_HPP
