#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	Base* generatedClass = generate();
	
	identify(generatedClass);
	identify(*generatedClass);

	delete generatedClass;

	return 0;
}