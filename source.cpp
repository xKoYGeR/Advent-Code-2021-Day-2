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

    int horizontalPos = 0;
    int depth = 0;
    for (const auto& line : fileData)
    {
        std::string cmd = line.substr(0, line.find_last_of(" "));
        int cmdValue = std::stoi(line.substr(line.find_last_of(" ") + 1));
        if (!strcmp(cmd.c_str(), "forward"))
            horizontalPos += cmdValue;
        else if (!strcmp(cmd.c_str(), "down"))
            depth += cmdValue;
        else if (!strcmp(cmd.c_str(), "up"))
            depth -= cmdValue;
    }
    std::cout << horizontalPos * depth << std::endl;

    horizontalPos = 0;
    depth = 0;
    int aim = 0;
    for (const auto& line : fileData)
    {
        std::string cmd = line.substr(0, line.find_last_of(" "));
        int cmdValue = std::stoi(line.substr(line.find_last_of(" ") + 1));
        if (!strcmp(cmd.c_str(), "forward"))
        {
            horizontalPos += cmdValue;
            if (aim)
                depth += aim * cmdValue;
        }
        else if (!strcmp(cmd.c_str(), "down"))
            aim += cmdValue;
        else if (!strcmp(cmd.c_str(), "up"))
            aim -= cmdValue;
    }
    std::cout << horizontalPos * depth << std::endl;

    std::cin.get();
    return 0;
}
