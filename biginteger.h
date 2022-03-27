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

    void delete_lead_zeros(){
        while (vec[vec.size() - 1] == 0 && vec.size() > 1)
            vec.pop_back();
        if (negative && vec[0] == 0 && vec.size() == 1)
            negative = 0;
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
                res.vec[i] += 10;
            }
//            cerr << "= " << (int)res.vec[i] << endl;
        }
        if (z)
            res.vec.push_back(1);
        res.delete_lead_zeros();
        return res;
    }

    BigInteger operator-(BigInteger& other) {
        auto wtf = (-other);
        return *this + wtf;
    }

    void set_zeros_to_begin(int len){
        while (vec.size() < len)
            vec.push_back(0);
    }

    void set_zeros_to_end(int zeros_num){
        vector <char> new_vec(zeros_num, 0);
        for (auto i : vec)
            new_vec.push_back(i);
        vec = new_vec;
    }

    void f(BigInteger* q, BigInteger* w){
        for (int i = vec.size() / 2; i < vec.size(); i++)
            q->vec.push_back(vec[i]);
        for (int i = 0; i < vec.size() / 2; i++)
            w->vec.push_back(vec[i]);
    }

    BigInteger operator*(BigInteger& other) {
        if (max(vec.size(), other.vec.size()) == 1){
            char p = vec[0] * other.vec[0];
            const char p1 = p / 10;
            const char p2 = p % 10;

            auto res = BigInteger({p1, p2}, (negative + other.negative) % 2);
            res.delete_lead_zeros();

            return res;
        }

        int len = max(vec.size(), other.vec.size()) % 2 + max(vec.size(), other.vec.size());

        set_zeros_to_begin(len);
        other.set_zeros_to_begin(len);

        auto x1 = new BigInteger({}, false);
        auto x2 = new BigInteger({}, false);
        auto y1 = new BigInteger({}, false);
        auto y2 = new BigInteger({}, false);

        f(x1, x2);
        other.f(y1, y2);

        BigInteger x1y1 = *x1 * *y1;
        BigInteger x2y2 = *x2 * *y2;
        auto wtf = (*x1 + *x2);
        auto wtf2 = (*y1 + *y2);
        BigInteger x1x2y1y2 = wtf * wtf2;
        BigInteger x1y2x2y1 = x1x2y1y2 - x1y1 - x2y2;

        x1y1.set_zeros_to_end(len);
        x1y2x2y1.set_zeros_to_end(len / 2);

        auto res = x1y1 + x1y2x2y1 + x2y2;
        res.delete_lead_zeros();

        res.negative = (negative + other.negative) % 2;

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