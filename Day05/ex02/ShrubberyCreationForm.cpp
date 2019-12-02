//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
		: Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = name;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {


}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) : Form::Form(a)
{
	this->_target = a.getTarget();
}

void ShrubberyCreationForm::execute(Bureaucrat const &a) const
{
		if (this->getGradeToExecute() < a.getGrade())
			throw Bureaucrat::GradeTooLowException();
		if (!this->isSign())
			throw Form::NotSigned();
		std::string outfile_name("<");
		outfile_name += this->getTarget();
		outfile_name += ">_shrubbery";
		std::ofstream outfile;
		outfile.open(outfile_name, std::ofstream::out | std::ofstream::app);
		outfile << "                                                         .\n"
				   "                                              .         ;  \n"
				   "                 .              .              ;%     ;;   \n"
				   "                   ,           ,                :;%  %;   \n"
				   "                    :         ;                   :;%;'     .,   \n"
				   "           ,.        %;     %;            ;        %;'    ,;\n"
				   "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
				   "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
				   "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
				   "                `%;.     ;%;     %;'         `;%%;.%;'\n"
				   "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
				   "                    `:%;.  :;bd%;          %;@%;'\n"
				   "                      `@%:.  :;%.         ;@@%;'   \n"
				   "                        `@%.  `;@%.      ;@@%;         \n"
				   "                          `@%%. `@%%    ;@@%;        \n"
				   "                            ;@%. :@%%  %@@%;       \n"
				   "                              %@bd%%%bd%%:;     \n"
				   "                                #@%%%%%:;;\n"
				   "                                %@@%%%::;\n"
				   "                                %@@@%(o);  . '         \n"
				   "                                %@@@o%;:(.,'         \n"
				   "                            `.. %@@@o%::;         \n"
				   "                               `)@@@o%::;         \n"
				   "                                %@@(o)::;        \n"
				   "                               .%@@@@%::;         \n"
				   "                               ;%@@@@%::;.          \n"
				   "                              ;%@@@@%%:;;;. \n"
				   "                          ...;%@@@@@%%:;;;;,.." << std::endl;
		outfile.close();
}

const std::string &ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::setTarget(const std::string &target) {
	_target = target;
}
