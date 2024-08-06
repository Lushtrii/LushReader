#include "pdf.h"

bool PDFReader::isPDFFilePath(const std::string_view filePath) {
    return filePath.size() > 4 && filePath.ends_with(".pdf");
}
