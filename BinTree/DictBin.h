#pragma once
#include "BinTree/BinTree.h"
#include "DictPara.h"


template < typename key, typename value >
class DictBin {
public:
	DictBin() = default;
  
	value operator[](const key& k) {
    DictPara<key, value> search(k, value{});
    auto found = data_.find(search);
    if (found == data_.end()) {
		throw std::out_of_range("Key not found");
    }
	return (*found).get_value();
  }

	void insert(const key& k, const value& v) {
    data_.insert_(DictPara<key, value>(k, v));
  }

private:
	BinTree<DictPara<key, value>> data_;
};
