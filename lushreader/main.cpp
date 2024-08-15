#include <print>
#include "pdfreader.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::println("Proper usage: {} $filePath", argv[0]);
    }

    PDFReader reader{argv[1]};

    return 0;
}

