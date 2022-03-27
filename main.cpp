#include <iostream>
#include <vector>
#include "biginteger.h"

using namespace std;

struct mstr {
    BigInteger a, b, summ, diff, neg_num1, neg_num2, mult;
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
                    BigInteger({4, 4, 0, 4, 3, 2, 0, 0, 4}, false),
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
                    BigInteger({5, 5, 9, 2, 0, 6, 3, 3, 5, 6, 0, 1}, false),
                    true,
                    false,
                    false,
                    false,
                    true,
                    true,
            },
            {
                    BigInteger({7, 0, 0, 9, 0, 1}, true),
                    BigInteger({7, 0, 1, 8, 6, 5}, true),
                    BigInteger({1, 4, 0, 2, 7, 6, 6}, true),
                    BigInteger({9, 6, 4}, false),
                    BigInteger({7, 0, 0, 9, 0, 1}, false),
                    BigInteger({7, 0, 1, 8, 6, 5}, false),
                    BigInteger({4, 9, 1, 9, 3, 7, 8, 8, 0, 3, 6, 5}, false),
                    false,
                    true,
                    true,
                    false,
                    true,
                    false,
            },
            {
                    BigInteger({5, 6, 7, 8, 9, 1, 0}, true),
                    BigInteger({9, 9, 9, 9, 9, 9, 9, 9}, false),
                    BigInteger({9, 4, 3, 2, 1, 0, 8, 9}, false),
                    BigInteger({1, 0, 5, 6, 7, 8, 9, 0, 9}, true),
                    BigInteger({5, 6, 7, 8, 9, 1, 0}, false),
                    BigInteger({9, 9, 9, 9, 9, 9, 9, 9}, true),
                    BigInteger({5, 6, 7, 8, 9, 0, 9, 9, 4, 3, 2, 1, 0, 9, 0}, true),
                    false,
                    true,
                    false,
                    true,
                    false,
                    true,
            },
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

        cout << "a * b = " << test.a * test.b << endl;
        if (test.a * test.b != test.mult)
            cout << "ERROR in mult\n";

        cout << "a - b = " << test.a - test.b << endl;
        if (test.a - test.b != test.diff)
            cout << "ERROR in diff\n";

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
