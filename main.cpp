#include <iostream>
#include <vector>
#include "biginteger.h"

using namespace std;

struct mstr {
    BigInteger a, b, summ, diff, neg_num1, neg_num2;
    bool equal, not_equal, more, less, more_or_equal, less_or_equal;
};

int main() {
    vector <mstr> tests = {
            {
                    BigInteger({5, 4, 7, 8, 0, 1}, false),
                    BigInteger({8, 0, 4}, false),
                    BigInteger({5, 4, 8, 6, 0, 5}, false),
                    BigInteger({5, 4, 6, 9, 9, 7}, false),
                    BigInteger({5, 4, 7, 8, 0, 1}, true),
                    BigInteger({8, 0, 4}, true),
                    false,
                    true,
                    true,
                    false,
                    true,
                    false,
            },
            {
                    BigInteger({7, 4, 7, 8, 0, 1}, true),
                    BigInteger({7, 4, 7, 8, 0, 1}, true),
                    BigInteger({1, 4, 9, 5, 6, 0, 2}, true),
                    BigInteger({0}, false),
                    BigInteger({7, 4, 7, 8, 0, 1}, false),
                    BigInteger({7, 4, 7, 8, 0, 1}, false),
                    true,
                    false,
                    false,
                    false,
                    true,
                    true,
            }
    };

    for (int i = 0; i < tests.size(); i++){
        cout << "Test#" << i << endl;
        auto test = tests[i];
        cout << "a = " << test.a << ", b = " << test.b << endl;
        cout << "-a = " << -test.a << " " << "-b = " << -test.b << endl;

        if (-test.a != test.neg_num1)
            cout << "ERROR neg_num1 = " << test.neg_num1 << endl;
        if (-test.b != test.neg_num2)
            cout << "ERROR neg_num2 = " << test.neg_num2 << endl;

        cout << "a + b = " << test.a + test.b << endl;
        if (test.a + test.b != test.summ)
            cout << "ERROR in sum\n";

        if (test.a == test.b)
            cout << "==\n";
        if ((test.a == test.b) != test.equal)
            cout << "ERROR in equal\n";

        if (test.a != test.b)
            cout << "!=\n";
        if ((test.a != test.b) != test.not_equal)
            cout << "ERROR in not_equal\n";

        if (test.a < test.b)
            cout << "<\n";
        if ((test.a < test.b) != test.less)
            cout << "ERROR in less\n";

        if (test.a > test.b)
            cout << ">\n";
        if ((test.a > test.b) != test.more)
            cout << "ERROR in more\n";

        if (test.a <= test.b)
            cout << "<=\n";
        if ((test.a <= test.b) != test.less_or_equal)
            cout << "ERROR in less_or_equal\n";

        if (test.a >= test.b)
            cout << ">=\n";
        if ((test.a >= test.b) != test.more_or_equal)
            cout << "ERROR in more_or_equal\n";
    }

    return 0;
}
