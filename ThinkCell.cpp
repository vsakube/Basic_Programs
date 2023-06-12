#include <map>
#include<iostream>

using namespace std;

template<typename K, typename V>
class interval_map {
private:
    std::map<K, V> m_map;
    V m_valBegin;
public:
    // Constructor
    interval_map(V const& val)
        : m_valBegin(val)
    {}

        std::map<K, V>& getMap(){
                return m_map;
        }

    // Assign function
    void assign(K const& keyBegin, K const& keyEnd, V const& val) {
        // Input validation: Ensure keyBegin is less than keyEnd
        if (!(keyBegin < keyEnd))
            return;

        // Find the iterators for the given keyBegin and keyEnd
        auto itBegin = m_map.upper_bound(keyBegin);
        auto itEnd = m_map.upper_bound(keyEnd);

        // Update the value for keyBegin if it is different from the previous value
        if (itBegin != m_map.begin()) {
            --itBegin;
            if (itBegin->second == val) {
                ++itBegin;
            }
            else if (itBegin->second != m_valBegin) {
                if (keyBegin < itBegin->first) {
                    m_map[keyBegin] = itBegin->second;
                    ++itBegin;
                }
            }
        }

        // Erase the elements between keyBegin and keyEnd
        m_map.erase(itBegin, itEnd);

        // Insert the new value for keyEnd if it is different from the previous value
        if (m_map.empty() || (--itEnd)->second != val) {
            m_map[keyEnd] = val;
        }
    }

        // look-up of the value associated with key
        V const& operator[]( K const& key ) const {
                auto it=m_map.upper_bound(key);
                if(it==m_map.begin()) {
                        return m_valBegin;
                } else {
                        return (--it)->second;
                }
        }

};

int main() {
    // Create an instance of interval_map with a default value of 0
    interval_map<int, int> myMap(0);

    // Assign different intervals with corresponding values
    myMap.assign(1, 5, 10);
    myMap.assign(7, 9, 20);
    myMap.assign(3, 6, 30);
    myMap.assign(12, 15, 40);

    // Print the contents of the map
    for (const auto& pair : myMap.getMap()) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }

    return 0;
}
