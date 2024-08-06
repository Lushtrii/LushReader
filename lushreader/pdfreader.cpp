#include "pdfreader.h"

void PDFReader::loadPDFFile(const std::string& filePath) {
    m_fileStream.open(filePath);

    if (!m_fileStream) {
        std::println("ERROR: File could not be opened");
    }
}

bool PDFReader::isPDFFilePath(const std::string_view filePath) {
    return filePath.size() > 4 && filePath.ends_with(".pdf");
}

