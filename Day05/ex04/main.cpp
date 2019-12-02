#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
int main()
{
	OfficeBlock dude;

	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 14);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 15);
	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	try
	{
		ob.doBureaucracy("shrubbery creation", "Bobby Bobson");
	}
	catch (OfficeBlock::NoSigner & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoIntern & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecutor & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::Monkey & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "ohh god, do bureaucracy failed because " << e.what() << std::endl;
	}
}