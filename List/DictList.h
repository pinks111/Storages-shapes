#include "ABC.h"
#include "list.h"
#include <stdexcept>

template<typename key, typename value>
class ListDict: public ABCDict<key, value> {
    List<DictPara<key, value>> list_;
public:
    ListDict() {};

    value operator[](const key& k) override {
        for (auto i = list_.begin(); i != list_.end(); ++i) {
            if ((*i).get_key() == k) {
                return (*i).get_value();
            }
        }
        throw std::out_of_range("Key not found in Dict");
    }

	void insert(const key& k, const value& v) override {
        for (auto i = list_.begin(); i != list_.end(); ++i) {
            if ((*i).get_key() == k) {
                *i = DictPara<key, value>(k, v);
                return;
            }
        }
        list_.push_back(DictPara<key, value>(k, v));
    }
};
