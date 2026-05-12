#include "DictPara.h"
#include "List/list.h"

#include <stdexcept>

template<typename key, typename value>
class DictList: public ABCDict<key, value> {
    List<DictPara<key, value>> data_;
public:
    DictList() = default;

    value operator[](const key& k) {
        for (auto i = data_.begin(); i != data_.end(); ++i) {
            if ((*i).get_key() == k) {
                return (*i).get_value();
            }
        }
        throw std::out_of_range("Key not found");
    }

	void insert(const key& k, const value& v) {
        data_.push_back(DictPara<key, value>(k, v));
    }
};