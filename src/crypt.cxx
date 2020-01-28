#include <crypt.hxx>

void crypt(ifstream& source, ifstream& key, ofstream& dest) {
    char s,k,d=0;
    key.get(k);
    while (source.get(s)) {
        d = s^k;
        dest.put(d);
        if (!key.get(k)) {
            key.clear();
            key.seekg(0, std::fstream::beg);
            key.get(k);
        }
    }
}