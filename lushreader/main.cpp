#include <print>
#include "pdfreader.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::println("Proper usage: {} $filePath", argv[0]);
    }

    PDFReader reader{};
    reader.loadPDFFile(argv[1]);
    reader.readHeader();

    return 0;
}

