#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <fstream>

std::string	search_and_replace(const std::string& str, const std::string& seg1, const std::string& seg2)
{
	if (str.empty() || seg1.empty())
		return ("");
	size_t o = seg1.length();
	size_t n = seg2.length();
	//if (o > str.length())
	//	return (str);
	std::string str2 = str;
	size_t i = str.find(seg1, 0);
	while (i != std::string::npos ) 
	{
		str2 = str2.substr(0, i) + seg2 + str2.substr(i + o);
		i = str2.find(seg1, i + n);
	}
	return (str2);
}

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Please include three arguments" << std::endl;;
		return (0);
	}
	//Open argv[1], check for errors
	std::ifstream oldFile(argv[1]);
	if (!oldFile.is_open())
	{
		std::cout << "Could not open input file" << std::endl;;
		return (0);
	}
	//Create filename.replace
	std::string newFileName = std::string(argv[1]) + ".replace";
	std::ofstream newFile(newFileName.c_str());
	if (!newFile.is_open())
	{
		std::cout << "Could not open output file" << std::endl;
		return (0);
	}
	//Copy argv[1] content
	std::string line;
	std::string buff;
	while (std::getline(oldFile, line))
	{
		buff = search_and_replace(line, argv[2], argv[3]);
		if (!buff.empty())
			newFile << buff << std::endl;
		else
			newFile << line << std::endl;
	}
	//Close files
	oldFile.close();
	newFile.close();
	return (0);
}
