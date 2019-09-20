#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string parseFileName(string path);

int main(int argc, char* argv[]) 
{
    ifstream output(argv[1]);
    ifstream solution(argv[2]);
    ofstream out;
    out.open(argv[3], std::ofstream::app);
    ofstream dout(argv[4]);

    out << " --- Compairing " << parseFileName(argv[1]) << " with " << parseFileName(argv[2]) << "---" << endl;
    dout << " --- Detailed Comparison for " << parseFileName(argv[1]) << " with " << parseFileName(argv[2]) << endl << endl;

    int diffLines = 0;
	int line = 1;
	char outChar;
	char solChar;
	bool outLineEnd = false;
	bool solLineEnd = false;
    string outLine = "";
	string solLine = "";
	bool diff = false;
	while (outChar != EOF && solChar != EOF)
	{	
		if (!outLineEnd) 
        {
            outChar = output.get();
            outLine += outChar;
        }
		if (!solLineEnd) 
        {
            solChar = solution.get();
            solLine += solChar;
        }
		if (outChar != solChar) 
        {
            diff = true;
        }

		if (outChar == '\n') 
        {
            outLineEnd = true;
        }
		if (solChar == '\n') 
        {
            solLineEnd = true;
        }
		if (outLineEnd && solLineEnd)
		{
			if (diff) {
				diffLines += 1;
				dout << "Difference found on line " << to_string(line) << ":" << endl;
				dout << " -- Output File --" << endl;
				dout << outLine;
				dout << " -- Solution File --" << endl;
				dout << solLine << endl;
			}
            outLine = "";
            solLine = "";
			outLineEnd = false;
			solLineEnd = false;
			diff = false;
			line += 1;
		}
	}
	

    out << "Differences: " << to_string(diffLines) << endl << endl;
    return 0;
}

string parseFileName(string path) 
{
    for (int i = path.size() - 1; i >= 0; i--)
    {
        if (path.at(i) == '/' || path.at(i) == '\\')
        {
            return path.substr(i + 1, path.size() - 1);
        }
    }
    return path;
}
