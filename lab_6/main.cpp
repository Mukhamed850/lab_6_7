#include <iostream>
#include <cstring>
#include "classes.h"
int main(int argc, char ** argv) {
	const char * flags[5] = {"--help", "--default", "--tofile", "--fromfile", "DefaultOutput.txt"};

	if(argc == 1) {
		std::cerr << "ERROR: flag not found!" << std::endl;
		std::cerr << "You can enter '--help' for instruction output" << std::endl;
		exit(1);
	}
	else if(argc == 2) {
		if(!strcmp(argv[1], flags[0]))
			Help();
		else if(!strcmp(argv[1], flags[1]))
			GetResultFromConsole();
		else if(!strcmp(argv[1], flags[2]))
			GetResultFromConsole(flags[4], false);
		else {
			std::cerr << "ERROR: invalid input!" << std::endl;
			std::cerr << "You can enter '--help' for instruction output" << std::endl;
			exit(1);
		}
	}
	else if(argc == 3) {
		if(!strcmp(argv[1],flags[2]))
			GetResultFromConsole(argv[2], true);
		else if(!strcmp(argv[1], flags[3]))
			GetResultFromFile(argv[2]);
		else {
			std::cerr << "ERROR: invalid input!" << std::endl;
			exit(1);
		}
	}
	else if(argc == 4) {
		if(!strcmp(argv[1], flags[3]) && !strcmp(argv[3], flags[2])) {
			GetResultFromFile(argv[2], flags[4], false);
		}
		else {
			std::cerr << "ERROR: invalid input!" << std::endl;
			exit(1);
		}
	}
	else if(argc == 5) {
		if(!strcmp(argv[1], flags[3]) && !strcmp(argv[3], flags[2])) {
			GetResultFromFile(argv[2], argv[4], true);
		}
		else {
			std::cerr << "ERROR: invalid input!" << std::endl;
			exit(1);
		}
	}
	else {
		std::cerr << "ERROR: invalid input!" << std::endl;
		exit(1);
	}





	return 0;
}