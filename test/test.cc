#include <string>
#include <stdexcept>

#include <gtest/gtest.h>

#include "Array/Array.h"
#include "BinTree/BinTree.h"
#include "List/list.h"
#include "Storage/Storage.h"

TEST(ArrayTest, AddedItemsArePresentAndMissingItemsAreAbsent) {
    Array<std::string> files;

    files.push_back("first.txt");
    files.push_back("second.txt");
    files.push_back("third.txt");

    EXPECT_EQ(files.size(), 3u);
    EXPECT_NE(files.find("first.txt"), files.end());
    EXPECT_NE(files.find("second.txt"), files.end());
    EXPECT_NE(files.find("third.txt"), files.end());

    EXPECT_EQ(files.find("missing.txt"), files.end());
    EXPECT_EQ(files.find("unknown.txt"), files.end());
}

TEST(ArrayTest, OutOfRangeIndexThrows) {
    Array<std::string> files;

    files.push_back("first.txt");
    files.push_back("second.txt");

    EXPECT_THROW(files[2], std::out_of_range);
}

TEST(ListTest, AddedItemsArePresentAndMissingItemsAreAbsent) {
    List<std::string> files;

    files.push_back("first.txt");
    files.push_back("second.txt");
    files.push_back("third.txt");

    EXPECT_EQ(files.size(), 3u);
    EXPECT_NE(files.find("first.txt"), files.end());
    EXPECT_NE(files.find("second.txt"), files.end());
    EXPECT_NE(files.find("third.txt"), files.end());

    EXPECT_EQ(files.find("missing.txt"), files.end());
    EXPECT_EQ(files.find("unknown.txt"), files.end());
}

TEST(BinTreeTest, AddedItemsArePresentAndMissingItemsAreAbsent) {
    BinTree<std::string> files;

    files.insert("first.txt");
    files.insert("second.txt");
    files.insert("third.txt");

    EXPECT_EQ(files.size(), 3u);
    EXPECT_NE(files.find("first.txt"), files.end());
    EXPECT_NE(files.find("second.txt"), files.end());
    EXPECT_NE(files.find("third.txt"), files.end());

    EXPECT_EQ(files.find("missing.txt"), files.end());
    EXPECT_EQ(files.find("unknown.txt"), files.end());
}

TEST(StorageTest, AddedItemsArePresent) {
    Storage<std::string> files;

    files.addItem("first.txt");
    files.addItem("second.txt");
    files.addItem("third.txt");

    EXPECT_EQ(files.getSize(), 3u);
    EXPECT_EQ(files.getItem(0), "first.txt");
    EXPECT_EQ(files.getItem(1), "second.txt");
    EXPECT_EQ(files.getItem(2), "third.txt");
}
