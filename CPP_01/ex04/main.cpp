#include <iostream>
#include <fstream>
#include <cstring>

void parseLine(std::string* line, std::string occ, std::string rep)
{
	size_t index;
	size_t occIndex;

	if (!std::strcmp(occ.c_str(), rep.c_str()))
		return ;
	index = 0;
	while (1)
	{
		occIndex = line->find(occ, index);
		if (occIndex == std::string::npos)
			break;
		line->erase(occIndex, occ.length());
		line->insert(occIndex, rep);
		index += occIndex + (occ.length() - 1);
	}
}

int main(int ac, char **av)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		filename;
	std::string		line;

	if (ac != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}

	filename = av[1];
	infile.open(av[1]);
	if (!infile.is_open())
	{
		std::cout << "Something went wrong while opening infile" << std::endl;
		return 1;
	}

	outfile.open(filename.append(".replace").c_str());
	if (!outfile.is_open())
	{
		std::cout << "Something went wrong while opening outfile" << std::endl;
		return 1;
	}

	while (std::getline(infile, line))
	{
		parseLine(&line, av[2], av[3]);
		outfile << line << std::endl;
	}

	infile.close();
	outfile.close();

	return 0;
}
