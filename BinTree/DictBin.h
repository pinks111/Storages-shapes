#pragma once
#include "BinTree/BinTree.h"
#include "DictPara.h"


template < typename key, typename value >
class DictBin {
public:
	DictBin() = default;
  
	value operator[](const key&) {
    DictPara<key, value> search(k, value{});
    auto found = tree_.find(search);
    if (found == tree_.end()) {
		throw std::out_of_range("Key not found");
    }
	return (*it).get_value();
  }

	void insert(const key& k, const value& v) {
    tree.insert_(DictPara<key, value>(k, v));
  }

private:
	BinTree<DictPara<key, value>> data_;
};
