#include <iostream>
#include <fstream>
#include <string>

std::string contentReplace(std::string text, const std::string &s1, const std::string &s2) {

    std::string result;
    size_t pos = 0;
    while (true) {
        size_t found = text.find(s1, pos);
        if (found == std::string::npos) {
            result += text.substr(pos);
            break;
        }
        result += text.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty.\n";
        return 1;
    }

    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Error: cannot open file " << filename << "\n";
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(inFile)),
                         std::istreambuf_iterator<char>());
    inFile.close();

    std::string replaced = contentReplace(content, s1, s2);

    std::string outfilename = filename + ".replace";
    std::ofstream outFile(outfilename.c_str());
    if (!outFile) {
        std::cerr << "Error: cannot create file " << filename << ".replace\n";
        return 1;
    }
    outFile << replaced;
    outFile.close();

    std::cout << "File processed successfully: " << filename << ".replace\n";
    return 0;
}
