#include <crypt.hxx>

int main(int argc, char* argv[]) {
    ofstream dest;
    ifstream source, key;

    if (argc!=4) {
        cout << "Invalid argument numbers: " << argc << endl;
        exit(1);
    }

    source.open(std::string(argv[1]), std::fstream::binary);
    if (!source.is_open() || !source.good()) {
        cout << "Unable to open source at " << argv[1] << endl;
        exit(1);
    }

    key.open(std::string(argv[2]), std::fstream::binary);
    if (!key.is_open() || !key.good()) {
        cout << "Unable to open key at " << argv[2] << endl;
        source.close();
        exit(1);
    }

    dest.open(std::string(argv[3]), std::fstream::binary | std::fstream::trunc);
    if (!dest.is_open() || !dest.good()) {
        cout << "Unable to open dest at " << argv[3] << endl;
        source.close();
        key.close();
        exit(1);
    }

    crypt(source, key, dest);

    source.close();
    key.close();
    dest.close();

    return 0;
}