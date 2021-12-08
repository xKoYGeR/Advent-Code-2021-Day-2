#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>

int main()
{
    std::fstream dataFile;
    dataFile.open("data2.txt", std::ios::in);
    std::vector <std::string> fileData;
    if (dataFile.good())
    {
        std::string strLine;
        while (!dataFile.eof())
        {
            std::getline(dataFile, strLine);
            fileData.push_back(strLine);
        }
        dataFile.close();
    }
    else std::cout << "Error!" << std::endl;

    int sum1 = 0;
    int sum2 = 0;
    for (const auto& line : fileData)
    {
        std::string cmd = line.substr(0, line.find_last_of(" "));
        if (!strcmp(cmd.c_str(), "forward"))
            sum1 += std::stoi(line.substr(line.find_last_of(" ") + 1));
        else if (!strcmp(cmd.c_str(), "down"))
            sum2 += std::stoi(line.substr(line.find_last_of(" ") + 1));
        else if (!strcmp(cmd.c_str(), "up"))
            sum2 -= std::stoi(line.substr(line.find_last_of(" ") + 1));
        std::cout << "Wykonano" << std::endl;
    }

    std::cout << sum1 * sum2 << std::endl;

    std::cin.get();
    return 0;
}
