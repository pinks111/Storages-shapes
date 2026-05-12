#pragma once

#include <Storage/Storage.h>
#include <DictPara.h>

#include <stdexcept>

template <typename key, typename value>
class DictStorage {
public:
    DictStorage() = default;

    value operator[](const key& k) {
      for (size_t i = 0; i < storage_.getSize(); ++i) {
        if (storage_.getItem(i).get_key() == k) {
          return storage_.getItem(i).get_value();
        }
      }
      throw std::out_of_range("Key not found");  
    }
    void insert(const key& k, const value& v) {
      storage_.addItem(DictPara<key, value>(k, v));
    }
private:
    Storage<DictPara<key, value>> storage_;
};