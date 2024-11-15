﻿
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<char> removeSpacesBetweenQuestions(vector<char> text) {
    int firstQuestionIndex = -1;
    int secondQuestionIndex = -1;

    // Находим индексы первого и второго знаков вопроса.
    for (int i = 0; text.size() > i; ++i) {
        if (text[i] == '?') {
            if (firstQuestionIndex == -1) {
                firstQuestionIndex = i;
            }
            else {
                secondQuestionIndex = i;
                break;
            }
        }
    }

    if (firstQuestionIndex != -1 && secondQuestionIndex != -1) {
        for (int i = firstQuestionIndex + 1; i < secondQuestionIndex; ++i) {
            if (text[i] == ' ') {
                text.erase(text.begin() + i);
                i--;
            }
            if (text[i] == '?') {
                break;
            }
        }
    }
    return text;
}

int main()
{
    vector<char> str;
    ifstream inputFile("C:\\Users\\Lenovo\\Documents\\ВУЗ ЛАБЫ\\ОП\\OP4\\input.txt");
    ofstream outputFile("C:\\Users\\Lenovo\\Documents\\ВУЗ ЛАБЫ\\ОП\\OP4\\output.txt");

    if (inputFile.is_open() && outputFile.is_open())
    {
        char symbol;
        while (inputFile.get(symbol)) {
             str.push_back(symbol);
        }

        str = removeSpacesBetweenQuestions(str);

        ostream_iterator<char> output_iterator(outputFile);  //вывод результата  в файл
        copy(str.begin(), str.end(), output_iterator);

        return 0;
    }
    else
    {
        cout << "file is not found.";
    }
    str.clear();
    inputFile.clear();
    outputFile.clear();
}