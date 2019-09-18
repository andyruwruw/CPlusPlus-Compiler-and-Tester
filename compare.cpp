#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	// Opening Files
	ifstream in(argv[1]);
	ifstream solution(argv[2]);
	if (!solution)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for input";
		return 2;
	}
	ofstream out;
	out.open((argv[3]), std::ofstream::app);

	// Logging File Names
	out << "-- Compairing " << "input" << argv[4] << ".txt with " << argv[2] << " --" << endl << endl;

	// Variables for keeping track of the line.
	string outputLine = "";
	string solutionLine = "";

	// Variables to detect errors.
	bool different = false;
	bool perfect = true;

	// Variables to allow completion of line before printing error
	bool stopOut = false;
	bool stopSol = false;

	// Variables for characters grabbed.
	char outputChar;
	char solutionChar;

	// While neither file is finished
	while (in.peek() != EOF || solution.peek() != EOF) 
	{
		// Stop and wait if end of line is reached.
		if (!stopOut)
		{
			outputChar = in.get();
			if (outputChar != '\n') outputLine += outputChar;
		}
		if (!stopSol)
		{
			solutionChar = solution.get();
			if (solutionChar != '\n') solutionLine += solutionChar;
		}

		// If they are not the same
		if (outputChar != solutionChar)
		{
			different = true;
		}

		// Stop and wait if end of line is reached
		if (outputChar == '\n')
		{
			stopOut = true;
		}
		if (solutionChar == '\n')
		{
			stopSol = true;
		}

		// Once both reach the end of a line
		if (stopOut && stopSol)
		{
			// If a difference has been found
			if (different) {
				perfect = false;
				different = false;
				out << "Difference Found:" << endl;
				out << "   Output File" << endl;
				out << "      " << outputLine << endl;
				out << "   Solution File" << endl;
				out << "      " << solutionLine << endl << endl;
			}
			// Reset variables.
			outputLine = "";
			solutionLine = "";
			stopOut = false;
			stopSol = false;
		}
		// Break at EOF
		if (solutionChar == EOF || outputChar == EOF)
		{
			break;
		}
	}
	// Print Results
	out << "Solution was ";
	if (perfect) {
		out << "valid";
	}
	else {
		out << "INVALID";
	}
	out << endl << endl;
	return 0;
}
