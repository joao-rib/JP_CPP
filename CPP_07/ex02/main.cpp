#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(void)
{
	Array<int>	empt = Array<int>();
    std::cout << "Empty array is of size " << empt.size() << std::endl;

	Array<int>	numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	{
		Array<int> tmp = numbers;
		std::cout << "Position 2 of the tmp array contains the number " << tmp[2] << std::endl;
		std::cout << "Position 749 of the tmp array contains the number " << tmp[MAX_VAL - 1] << std::endl;
		Array<int> test(tmp);
		std::cout << "Position 2 of the test array contains the number " << test[2] << std::endl;
		std::cout << "Position 749 of the test array contains the number " << test[MAX_VAL - 1] << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		std::cout << "Position 2 of the Numbers array contains the number " << numbers[2] << std::endl;
		numbers[-2] = 0;
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Position 749 of the Numbers array contains the number " << numbers[MAX_VAL - 1] << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    try
    {
        std::cout << '\n' << "Position 2 of the Numbers array now contains the number " << numbers[2] << std::endl;
        std::cout << "Position 2 of the Mirror array contains the number " << mirror[2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Position 749 of the Numbers array now contains the number " << numbers[MAX_VAL - 1] << std::endl;
        std::cout << "Position 749 of the Mirror array contains the number " << mirror[MAX_VAL - 1] << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    const Array<int> constArray(numbers);
    std::cout << "constArray value [2]: " << constArray[2] << std::endl;
    std::cout << "constArray size: " << constArray.size() << std::endl;

    try
    {
        std::cout << "constArray value [-2]: " << constArray[-2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;
    return 0;
}

/*int main(void)
{
    Array<std::string> stringArray(10);
    std::cout << "stringArray contains " << stringArray.size() << " strings." << std::endl << std::endl;
    stringArray[0] = "String 1";
    stringArray[1] = "String 2";
    stringArray[2] = "String 3";
    stringArray[3] = "String 4";
    stringArray[4] = "String 5";
    stringArray[5] = "String 6";
    stringArray[6] = "String 7";
    stringArray[7] = "String 8";
    stringArray[8] = "String 9";
    stringArray[9] = "String 10";

    for ( unsigned int i = 0; i < stringArray.size(); i++ )
        std::cout << stringArray[i] << std::endl << std::endl;

    try
    {
        std::cout << stringArray[10] << std::endl << std::endl ;
    }
    catch( std::exception& e )
    {
        std::cout << "Error caught: " << e.what() << std::endl << std::endl;
    }

    Array<std::string> copyStringArray( stringArray );
    Array<std::string> assignmentStringArray;
    assignmentStringArray = stringArray;

  std::cout << "stringArray value: " << stringArray[0] << std::endl
            << "copyStringArray value: " <<  copyStringArray[0] << std::endl
            << "assignmentStringArray value: " << assignmentStringArray[0]
            << std::endl << std::endl
            << "stringArray address: "  << &stringArray[0] << std::endl
            << "copyStringArray address: "  << &copyStringArray[0] << std::endl
            << "assignmentStringArray address: "  << &assignmentStringArray[0]
            << std::endl << std::endl;

  // Const version of operator []
  const Array<std::string> constArray( stringArray );


  std::cout << "constArray value [3]: " << constArray[3] << std::endl
            << "constArray size: " << constArray.size()
            << std::endl << std::endl;

  // constArray[3] = "Error String";    // Uncomment this line to check for const value error.

  return 0;
}
*/
