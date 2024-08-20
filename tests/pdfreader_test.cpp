#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include "../lushreader/pdfreader.h"

class PDFReaderTest : public testing::Test {
    protected:
        PDFReaderTest()
            : reader{testPDFFilePath}
        {
        }

        std::string testPDFFilePath{"test.pdf"};
        PDFReader reader{};
        PDFReader emptyReader{};
};

TEST_F(PDFReaderTest, FileProperlyLoads) {
    emptyReader.loadPDFFile(testPDFFilePath);
    const std::ifstream& emptyReaderFileStream = emptyReader.getFileStream();
    ASSERT_TRUE(emptyReaderFileStream.is_open());
    const std::ifstream& readerFileStream = reader.getFileStream();
    ASSERT_TRUE(readerFileStream.is_open());
}

TEST_F(PDFReaderTest, ReadsHeaderProperly) {
    EXPECT_EQ(reader.getHeader(), "1.5");
}

