#include <string>
#include <stdexcept>

#include <gtest/gtest.h>

#include "Array/Array.h"
#include "Array/DictArray.h"
#include "BinTree/BinTree.h"
#include "BinTree/DictBin.h"
#include "BinTree/DictAVL.h"
#include "BinTree/AVLTree.h"
#include "List/list.h"
#include "List/DictList.h"
#include "Storage/Storage.h"
#include "Storage/DictStorage.h"

// --------------- Containers tests ---------------
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

TEST(AVLTreeTest, AddedItemsArePresentAndMissingItemsAreAbsent) {
    AVLTree<std::string> files;
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

TEST(AVLTreeTest, BalancedTreeHeight) {
    AVLTree<int> tree;
    for (int i = 1; i <= 7; ++i) {
        tree.insert(i);
    }
    EXPECT_EQ(tree.size(), 7u);
    EXPECT_LE(tree.height(), 3u);
}
// ------------------ Dict tests ------------------

TEST(DictBinTest, InsertAndAccess) {
    DictBin<std::string, int> dict;
    dict.insert("one", 1);
    dict.insert("two", 2);
    EXPECT_EQ(dict["one"], 1);
    EXPECT_EQ(dict["two"], 2);
}

TEST(DictBinTest, KeyNotFoundThrows) {
    DictBin<std::string, int> dict;
    dict.insert("key", 42);
    EXPECT_THROW(dict["missing"], std::out_of_range);
}

TEST(DictAVLTest, InsertAndAccess) {
    DictAVL<std::string, double> dict;
    dict.insert("pi", 3.14);
    dict.insert("e", 2.71);
    EXPECT_DOUBLE_EQ(dict["pi"], 3.14);
    EXPECT_DOUBLE_EQ(dict["e"], 2.71);
}

TEST(DictAVLTest, KeyNotFoundThrows) {
    DictAVL<int, std::string> dict;
    EXPECT_THROW(dict[100], std::out_of_range);
}

TEST(DictArrayTest, InsertAndAccess) {
    DictArray<std::string, int> dict;
    dict.insert("a", 10);
    dict.insert("b", 20);
    EXPECT_EQ(dict["a"], 10);
    EXPECT_EQ(dict["b"], 20);
}

TEST(DictArrayTest, KeyNotFoundThrows) {
    DictArray<int, int> dict;
    EXPECT_THROW(dict[999], std::out_of_range);
}

TEST(DictListTest, InsertAndAccess) {
    DictList<std::string, int> dict;
    dict.insert("x", 5);
    dict.insert("y", 15);
    EXPECT_EQ(dict["x"], 5);
    EXPECT_EQ(dict["y"], 15);
}

TEST(DictListTest, KeyNotFoundThrows) {
    DictList<char, float> dict;
    dict.insert('a', 1.1f);
    EXPECT_THROW(dict['z'], std::out_of_range);
}

TEST(DictStorageTest, InsertAndAccess) {
    DictStorage<std::string, int> dict;
    dict.insert("first", 100);
    dict.insert("second", 200);
    EXPECT_EQ(dict["first"], 100);
    EXPECT_EQ(dict["second"], 200);
}

TEST(DictStorageTest, KeyNotFoundThrows) {
    DictStorage<int, bool> dict;
    EXPECT_THROW(dict[42], std::out_of_range);
}
