#include <iostream>
#include <vector>

using namespace std;

class BigInteger{
public:
    vector <char> vec;

    BigInteger(const vector<char>& value){
        for (auto i = value.rbegin(); i != value.rend(); i++)
            vec.push_back(*i);
    }

    BigInteger operator+(BigInteger& other) {
        BigInteger res = BigInteger({});
        bool z = 0;
        for (int i = 0; i < max(vec.size(), other.vec.size()); i++){
            res.vec.push_back((vec.size() <= i?0:vec[i]) + (other.vec.size() <= i?0:other.vec[i]) + z);
            cerr << (vec.size() <= i?0:vec[i]) << " " << (other.vec.size() <= i?0:other.vec[i]) << " " << z << endl;

            z = 0;
            if (res.vec[i] >= 10){
                z = 1;
                res.vec[i] %= 10;
            }
            cerr << "= " << (int)res.vec[i] << endl;
        }
        if (z)
            res.vec.push_back(1);
        return res;
    }
};

std::ostream& operator<< (std::ostream &out, const BigInteger &num)
{
    for (auto i = num.vec.rbegin(); i != num.vec.rend(); i++)
        out << (short int)*i;
    return out;
}

int main() {
    auto a = BigInteger({1, 2, 4, 9, 4, 0, 0, 1});
    auto b = BigInteger({9, 8, 8 , 3, 9, 5, 0, 0});
    cout << a + b;
    return 0;
}
