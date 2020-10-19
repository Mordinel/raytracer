#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

/**
 * takes path and content strings,
 * writes out to a file if possible.
 */
int writeFile(std::string& path, std::string& content)
{
    std::ofstream fs(path, std::ofstream::out);

    if (fs.is_open()) {
        fs << content;
        fs.close();
        return 0;
    }

    return 1;
}

int main(int argc, char* argv[])
{
    // args
    if (argc != 2) {
        std::cerr << "Usage: " << std::string(argv[0]) << " <outfile>" << std::endl;
        return 1;
    }

    std::string outContent;
    std::string outPath(argv[1]);

    std::ostringstream contentStream;

    int nx = 200;
    int ny = 100;

    contentStream << "P3\n" << nx << " " << ny << "\n255\n";

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2f;

            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            contentStream << ir << " " << ig << " " << ib << "\n";
        }
    }

    outContent = contentStream.str();

    // in case file can't be written
    if (writeFile(outPath, outContent)) {
        std::cout << "Error: Could not open \"" << outPath << "\"." << std::endl;
        return 1;
    }

    return 0;
}
