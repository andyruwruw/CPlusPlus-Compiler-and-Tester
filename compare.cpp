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

    out << " --- Comparison Results ---" << endl << "File 1: " << parseFileName(argv[5]) << " (output)" << endl << "File 2: " << parseFileName(argv[2]) << endl;
    dout << " --- Detailed Comparison for " << parseFileName(argv[5]) << " with " << parseFileName(argv[2]) << " ---" << endl << endl;

    int diffLines = 0;
	int line = 1;
	char outChar;
	char solChar;
	bool outLineEnd = false;
	bool solLineEnd = false;
    string outLine = "";
	string solLine = "";
    string outFile = "";
	bool diff = false;
	while (outChar != EOF || solChar != EOF)
	{	
		if (!outLineEnd || solChar == EOF) 
        {
            outChar = output.get();
            if (outChar != EOF)
            {
                outFile += outChar;
                outLine += outChar;
            }   
        }
		if (!solLineEnd || outChar == EOF) 
        {
            solChar = solution.get();
            if (solChar != EOF)
            {
                solLine += solChar;
            } 
        }
		if (outChar != solChar) 
        {
            diff = true;
        }

		if (outChar == '\n' || outChar == EOF) 
        {
            outLineEnd = true;
        }
		if (solChar == '\n' || solChar == EOF) 
        {
            solLineEnd = true;
        }
		if (outLineEnd && solLineEnd)
		{
			if (diff) {
				diffLines += 1;
				dout << "DIFFERENCE FOUND ON LINE " << to_string(line) << ":" << endl;
                if (outChar != EOF)
                {
                    dout << "---Output---" << endl;
                    dout << outLine;
                }
                else 
                {
                    dout << "---Output EOF---" << endl;
                }
                if (solChar != EOF)
                {
                    dout << "---Solution---" << endl;
				    dout << solLine << endl;
                }
                else 
                {
                    dout << "---Solution EOF---" << endl << endl;
                }
				
			}
            outLine = "";
            solLine = "";
			outLineEnd = false;
			solLineEnd = false;
			diff = false;
			line += 1;
		}
	}

    dout << endl << "----Full Output Text----" << endl << endl;
    dout << outFile;

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
