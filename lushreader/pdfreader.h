#include <fstream>
#include <print>
#include <string>
#include <string_view>

class PDFReader {
    public:
        void loadPDFFile(const std::string& filePath);
        static bool isPDFFilePath(std::string_view possibleFilePath); 
    private:
        std::ifstream m_fileStream{};
};
