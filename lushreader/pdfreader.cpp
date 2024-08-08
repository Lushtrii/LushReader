#include "pdfreader.h"

#include <fstream>
#include <print>
#include <regex>
#include <string>
#include <string_view>

void PDFReader::loadPDFFile(const std::string& filePath) {
    m_fileStream.open(filePath);

    if (!m_fileStream) {
        std::println("ERROR: File could not be opened");
    }
}

void PDFReader::readHeader() {
    constexpr int headerSize{8};
    char header[headerSize]{""};
    m_fileStream.read(header, headerSize);

    std::cmatch match{};
    if (!std::regex_match(header, match, std::regex("%PDF-(1.[1-7])"))) {
        std::println("ERROR: This file's header does not match any supported types'");
        return;
    }
    m_headerVersion = match[1].str();
}

bool PDFReader::isPDFFilePath(const std::string_view filePath) {
    return filePath.size() > 4 && filePath.ends_with(".pdf");
}

