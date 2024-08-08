#ifndef PDFREADER_H
#define PDFREADER_H

#include <fstream>
#include <print>
#include <string>
#include <string_view>

class PDFReader {
    public:
        void loadPDFFile(const std::string& filePath);
        void readHeader();
        static bool isPDFFilePath(std::string_view possibleFilePath); 
    private:
        std::ifstream m_fileStream{};
        std::string m_headerVersion{};
};
#endif
