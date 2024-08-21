#ifndef PDFREADER_H
#define PDFREADER_H

#include <fstream>
#include <string>
#include <string_view>

class PDFReader {
    public:
        PDFReader() = default;
        explicit PDFReader(const std::string& filePath);
        void loadPDFFile(const std::string& filePath);
        void readHeader();
        const std::string& getHeader() const {return m_headerVersion;};
        const std::ifstream& getFileStream() const {return m_fileStream;};
        int getStreamPos() const { return m_streamPos;};
        static bool isPDFFilePath(std::string_view possibleFilePath); 
    private:
        std::ifstream m_fileStream{};
        std::string m_headerVersion{};
        int m_streamPos{0};
};
#endif
