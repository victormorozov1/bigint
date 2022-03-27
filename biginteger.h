#include <vector>
#include <iostream>

using namespace std;

class BigInteger{
public:
    vector <char> vec;
    char negative = 0;

    BigInteger(const vector <char>& value, bool _negative, bool reverse=true){
        negative = _negative;

        if (reverse)
            for (auto i = value.rbegin(); i != value.rend(); i++)
                vec.push_back(*i);
        else
            for (auto i = value.begin(); i != value.end(); i++)
                vec.push_back(*i);
    }

    BigInteger ABS(){
        return BigInteger(vec, 0, false);
    }

    BigInteger operator-(){
        return BigInteger(vec, (negative + 1) % 2, false);
    }

    bool operator>(BigInteger& other){
        if (negative != other.negative)
            return negative < other.negative;
        if (negative) {
            auto wtf = -(*this);
            auto wtf2 = -other;
            return wtf < wtf2;
        }
        if (vec.size() != other.vec.size())
            return vec.size() > other.vec.size();
        int i = vec.size() - 1;
        while (i != -1){
            if (vec[i] != other.vec[i])
                return vec[i] > other.vec[i];
            i -= 1;
        }
        return false;
    }

    bool operator==(BigInteger& other){
        if (negative != other.negative)
            return false;
        if (vec.size() != other.vec.size())
            return false;
        int i = vec.size() - 1;
        while (i != -1){
            if (vec[i] != other.vec[i])
                return false;
            i -= 1;
        }
        return true;
    }

    bool operator!=(BigInteger& other){
        return !(*this == other);
    }

    bool operator<(BigInteger& other){
        return !(*this == other || *this > other);
    }

    bool operator<=(BigInteger& other){
        return *this == other || *this < other;
    }

    bool operator>=(BigInteger& other){
        return *this == other || *this > other;
    }

    BigInteger operator+(BigInteger& other) {
        if (negative != other.negative && ABS() < other)
            return other + *this;

        BigInteger res = BigInteger({}, negative);
        short int z = 0;
        for (int i = 0; i < max(vec.size(), other.vec.size()); i++){
            res.vec.push_back((vec.size() <= i?0:vec[i]) + (other.vec.size() <= i?0:other.vec[i]) * (negative==other.negative?1:-1) + z);
            //cerr << (vec.size() <= i?0:vec[i]) << " " << (other.vec.size() <= i?0:other.vec[i]) << " " << z << endl;

            z = 0;
            if (res.vec[i] >= 10){
                z = 1;
                res.vec[i] %= 10;
            }
            else if (res.vec[i] < 0){
                z = -1;
            }
//            cerr << "= " << (int)res.vec[i] << endl;
        }
        if (z)
            res.vec.push_back(1);
        return res;
    }
};

std::ostream& operator<< (std::ostream &out, const BigInteger &num)
{
    if (num.negative)
        out << "-";
    for (auto i = num.vec.rbegin(); i != num.vec.rend(); i++)
        out << (short int)*i;
    return out;
}