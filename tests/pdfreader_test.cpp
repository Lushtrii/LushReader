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
    EXPECT_EQ(emptyReader.getStreamPos(), headerLineSize);
}

TEST_F(PDFReaderTest, ReadXrefOffsetProperly) {
    EXPECT_EQ(reader.getXrefOffset(), 61919303);
}

TEST_F(PDFReaderTest, ReadTrailerProperly) {
    GTEST_SKIP();
}

TEST_F(PDFReaderTest, IgnoresInvalidObj) {
    GTEST_SKIP();
}

TEST_F(PDFReaderTest, ParseHexString) {
    GTEST_SKIP();
}

TEST_F(PDFReaderTest, ParseNameObject) {
    GTEST_SKIP();
}

TEST_F(PDFReaderTest, ParseDictionaryObject) {
    GTEST_SKIP();
}

TEST_F(PDFReaderTest, ParseArrayObject) {
    GTEST_SKIP();
}

