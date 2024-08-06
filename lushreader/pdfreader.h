#include <fstream>
#include <print>
#include <string>
#include <string_view>

class PDFReader {
    public:
        void loadPDFFIle(const std::string& filePath);
        static bool isPDFFilePath(std::string_view possibleFilePath); 
    private:
        std::ifstream m_fileStream{};
};
