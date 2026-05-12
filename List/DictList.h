#include "ABC.h"
#include "List/list.h"
#include <stdexcept>

template<typename key, typename value>
class DictList: public ABCDict<key, value> {
    List<DictPara<key, value>> list_;
public:
    DictList() {};

    value operator[](const key& k) {
        for (auto i = list_.begin(); i != list_.end(); ++i) {
            if (i->word_ == k) {
                return i->translate_;
            }
        }
        throw std::out_of_range("Key not found");
    }

	void insert(const key& k, const value& v) {
        list_.push_back(DictPara(k, v));
    }
};