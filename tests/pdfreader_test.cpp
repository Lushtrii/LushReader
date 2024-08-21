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
    emptyReader.loadPDFFile(testPDFFilePath);
    EXPECT_EQ(emptyReader.getStreamPos(), 0);
    emptyReader.readHeader();
    EXPECT_EQ(emptyReader.getHeader(), "1.6");
    int headerLineSize{8};
    EXPECT_EQ(reader.getStreamPos(), headerLineSize);
}
