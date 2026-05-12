#pragma once

#include <BinTree/AVLTree.h>
#include "DictPara.h"

#include <stdexcept>

template <typename key, typename value>
class DictAVL {
public:
    DictAVL() = default;

    value operator[](const key& k) {
        DictPara<key, value> searchKey(k, value{});
        auto found = tree_.find(searchKey);
        
        if (found == tree_.end()) {
            throw std::out_of_range("Key not found");
        }
        
        return (*found).get_value();
    }

    void insert(const key& k, const value& v) {
        tree_.insert(DictPara<key, value>(k, v));
    }

private:
    AVLTree<DictPara<key, value>> tree_;
};