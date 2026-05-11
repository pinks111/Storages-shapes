#pragma once
#include "BinTree.h"
#include "../DictPara.h"
#include <stdexcept>


template < typename key, typename value >
class Dict {
public:
	Dict() = default;
  Dict(const Dict&) = delete;
  Dict& operator=(const Dict&) = delete;
  Dict(Dict&&) noexcept = default;
  Dict& operator=(Dict&&) noexcept = default;
  
	value operator[](const key& k) const {
    DictPara<key, value> search(k, value{});
    auto found = data_.find(search);
    if (found != data_.end()) {
      return (*found).get_value();
    }
    throw std::out_of_range("Key not found in Dict");
  }

	void insert(const key& k, const value& v) {
    DictPara<key, value> item(k, v);
    auto found = data_.find(item);
    if (found != data_.end()) {
      data_.erase(found);
    }
    data_.insert(item);
  }

  bool contains(const key& k) const {
    DictPara<key, value> search(k, value{});
    return data_.find(search) != data_.end();
  }

private:
	BinTree<DictPara<key, value>> data_;
};
