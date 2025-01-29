#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <fstream>

/*static char	*replace_short(const char *str, char *old, char *new, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	b;
	char	*str2;

	i = 0;
	j = 0;
	b = ft_strnstr_pos(str, old, len);
	str2 = ft_calloc(len - ft_strlen(old) + ft_strlen(new), sizeof(char *));
	if (!str2)
		return (NULL);
	while (i <= len)
	{
		if (i == b)
		{
			j = ft_strlen(new);
			ft_memcpy(&str2[i], new, j);
			b = ft_strlen(old);
			i += b;
			j = b - j;
		}
		str2[i - j] = str[i];
		i++;
	}
	return (str2);
}

static char	*replace_long(const char *str, char *old, char *new, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	b;
	char	*str2;

	i = 0;
	j = 0;
	b = ft_strnstr_pos(str, old, len);
	str2 = ft_calloc(len - ft_strlen(old) + ft_strlen(new), sizeof(char *));
	if (!str2)
		return (NULL);
	while (i <= len)
	{
		if (i == b)
		{
			j = ft_strlen(new);
			ft_memcpy(&str2[i], new, j);
			b = ft_strlen(old);
			i += b;
			j -= b;
		}
		str2[i + j] = str[i];
		i++;
	}
	return (str2);
}*/

/*char	*ft_str_repl_seg(const std::string str, const std::string seg1, const std::string seg2)
{
	char	*str2;

	if (str.empty())
		return (NULL);
	size_t len = str.length();
	size_t o = seg1.length();
	size_t n = seg2.length();
	str.find(seg1, len);
	if (seg1.empty() || o > len || !ft_strnstr(str, seg1, len))
		return (NULL);
	if (n > o)
		str2 = replace_long(str, seg1, seg2, len);
	else
		str2 = replace_short(str, seg1, seg2, len);
	return (str2);
}*/

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Please include three arguments" << std::endl;;
		return (0);
	}
	//Abrir argv[1], verificar se houve erro
	std::ifstream oldFile(argv[1]);
	if (!oldFile.is_open())
	{
		std::cout << "Could not open input file" << std::endl;;
		return (0);
	}
	//Criar filename.replace
	std::string newFilename = std::string(argv[1]) + ".replace";
	std::ofstream newFile(newFilename);
	if (!newFile.is_open())
	{
		std::cout << "Could not open output file" << std::endl;;
		return (0);
	}
	//Copiar ficheiro argv[1]
	std::string line;
	std::string buff;
	while (std::getline(oldFile, line))
	{
		//buff = ft_str_repl_seg(line, argv[2], argv[3]);
		if (!buff.empty())
			newFile << buff << std::endl;
		else
			newFile << line << std::endl;
	}
	//Fechar
	oldFile.close();
	newFile.close();
	return (0);
}

/*#include <iostream>
#include <fstream>

void replaceAll(std::string &str, const std::string &search, const std::string &new_word) 
{
    size_t pos = 0;
    size_t searchLength = search.length();
    size_t new_wordLength = new_word.length();
    
    while ((pos = str.find(search, pos)) != std::string::npos) 
    {
        // a parte comentada serve para se quiser apenas a palavra e nao qq ocorrencia onde exista a palavra
        // if ((pos == 0 && ((str[pos + searchLength] == '\0') || str[pos + searchLength] == ' ')) || ((pos > 0 && str[pos - 1] == ' ') && ((str[pos + searchLength] == ' ') || str[pos + searchLength] == '\0')))
        // {
            str = str.substr(0, pos) + new_word + str.substr(pos + searchLength);
            pos += new_wordLength; // Avança na string de substituição
        // }
        // else
        // {
        //     pos += searchLength; // Avança a posição para evitar encontrar a mesma ocorrência novamente
        // }
    }
}

int main(int argc, char **argv)
{   
    std::string original;
    // verifica se tem o numero de args valido
    if (argc != 4)
    {
        std::cout << "Invalid inputs" << std::endl;
        return 1;
    }
    
    // verifica se argv[1] e ficheiro valido
    std::ifstream file1(argv[1]);
    if (!file1) 
    {
        std::cerr << "Erro ao abrir o arquivo de entrada." << std::endl;
        return 1;
    }

    // cria copia de ficheiro dado em argv[1]
    std::string outputFilename = std::string(argv[1]) + ".replace";
    std::ofstream file2(outputFilename.c_str());

    // verifica se ficheiro copia foi criado com sucesso
    if (!file2) 
    {
        std::cerr << "Erro ao criar o arquivo de saída." << std::endl;
        return 1;
    }

    // duplica conteudo de ficheiro para ficheiro copia
    while (file1)
    {
        while (getline(file1, original)) 
        {
            replaceAll(original, argv[2], argv[3]); // funcao onde substitui s1 por s2
            file2 << original << std::endl; // 

        }

    }
    file1.close();
    file2.close();
    return 0;
}

    // std::cout << firstLine << std::endl;
    // std::cout << secondLine << std::endl;

    // este exemplo serve para criar um ficheiro a partir
    // de um imput do utilizador usando o ofstream

    // std::string Ementa;
    // std::cout << "Adicione Pedido. Digite FIM para sair" << std::endl;
    // std::ofstream file("Jesse.txt");
    // while (Ementa != "FIM")
    // {
    //     getline(std::cin, Ementa);
    //     if (Ementa != "FIM")
    //         file << Ementa << std::endl;
    // }
    // file.close();

    // este exemplo serve para abrir um ficheiro e escrever
    // o seu conteudo

    // std::ifstream file("TESTE.txt");
    // std::string Ementa;
    // std::cout << "Ementa: " << std::endl;
    // while (!file.eof())
    // {
    //     (getline(file, Ementa));
    //     std::cout << Ementa << std::endl;
    // }
    // file.close();
*/