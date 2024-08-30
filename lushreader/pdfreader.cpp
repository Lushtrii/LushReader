#include "pdfreader.h"

#include <fstream>
#include <ios>
#include <print>
#include <regex>
#include <string>
#include <string_view>

PDFReader::PDFReader(const std::string& filePath) {
    PDFReader::loadPDFFile(filePath);
    PDFReader::readHeader();
    PDFReader::readXrefOffset();

}

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
    m_streamPos += headerSize;

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

// Line read will be (CurrentLineNumber - numLinesBack)
std::string PDFReader::readPreviousLine(int numLinesBack) {
    std::ifstream& stream {this->m_fileStream};
    char currChar {};

    for (int i{numLinesBack + 1}; i > 0; i--) {
        // Pointer starts at \n so go back one char
        stream.seekg(this->m_streamPos - 1);
        this->m_streamPos -= 1;

        // Case reach start of file
        currChar = stream.get();
        while (stream.tellg() > 0 && currChar != '\n') {
            stream.seekg(this->m_streamPos -1);
            this->m_streamPos -= 1;
            currChar = stream.get();
        }

        if (stream.tellg() <= 0) {
            break;
        }
    }

    return PDFReader::readCurrLine();
}

std::string PDFReader::readCurrLine() {
    std::string line{};
    std::getline(m_fileStream, line);
    m_streamPos = m_fileStream.tellg();
    return line;
}

void PDFReader::readXrefOffset() {
    // Get to end of file
    constexpr int eofStringSize{6};
    m_fileStream.seekg(-eofStringSize, std::ios_base::end);
    
    // size 6 because looking for "%%EOF" string
    char eofContainer[eofStringSize]{""};
    m_fileStream.get(eofContainer, eofStringSize);
    m_streamPos = m_fileStream.tellg();

    // Go up 2 lines
    std::string line {};
    line = PDFReader::readPreviousLine(2);
    if (line != "startxref") {
        std::println("ERROR: Cross reference offset marker not found.");
    }
    
    m_xrefOffset = std::stol(PDFReader::readCurrLine());
}
