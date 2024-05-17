#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

bool isVowel(char ch)
{
    ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

bool isConsonant(char ch)
{
    ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
    return (ch >= 'a' && ch <= 'z') && !isVowel(ch);
}

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

int main() 
{
    //1

    const char* PATH_TO_FILE_1 = "file1.txt";
    const char* PATH_TO_FILE_2 = "file2.txt";
   
    FILE* file1 = fopen(PATH_TO_FILE_1, "r");
    FILE* file2 = fopen(PATH_TO_FILE_2, "r");

    const int N = 200;
    char line1[N], line2[N];
    int lineNumber = 1;

    if (file1 != nullptr && file2 != nullptr)
    {
        while (fgets(line1, N, file1) && fgets(line2, N, file2))
        {
            if (strcmp(line1, line2) != 0)
            {
                cout << "Lines " << lineNumber << " doesn`t match:" << endl;
                cout << "With file 1: " << line1 << endl;
                cout << "With file 2: " << line2 << endl;
                fclose(file1);
                fclose(file2);
                return 0;
            }
            lineNumber++;
        }

        if (fgets(line1, N, file1))
        {
            cout << "File 1 has more lines" << endl;
            cout << "Additional line from file 1: " << line1;
        }
        else if (fgets(line2, N, file2))
        {
            cout << "File 2 has more lines" << endl;
            cout << "Additional line from file 2: " << line2;
        }
        else
        {
            cout << "The files are identical" << endl;
        }
        fclose(file1);
        fclose(file2);
    }
    else
    {
        cout << "Error";
    }

    //2
 
    const char* PATH_TO_FILE = "input.txt";
    const char* OUTPUT_FILE = "output.txt";

    FILE* file = fopen(PATH_TO_FILE, "r");
    FILE* outfile = fopen(OUTPUT_FILE, "w");

    const int A = 200;
    char line[A];

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    if (file != nullptr && outfile != nullptr)
    {
        while (fgets(line, A, file))
        {
            lineCount++;
            for (int i = 0;line[i] != '\0'; i++)
            {
                charCount++;
                if (isDigit(line[i]))
                {
                    digitCount++;
                }
                else if (isVowel(line[i]))
                {
                    vowelCount++;
                }
                else if (isConsonant(line[i]))
                {
                    consonantCount++;
                }
            }
        }
        fclose(file);
        fclose(outfile);
    }
    else
    {
        cout << "Error";
    }

    cout << "Statistics of the file:" << endl;
    cout << "Number of characters: " << charCount << endl;
    cout << "Number of lines: " << lineCount << endl;
    cout << "Number of vowels: " << vowelCount << endl;
    cout << "Number of consonants: " << consonantCount << endl;
    cout << "Number of digits: " << digitCount << endl;

   
}


