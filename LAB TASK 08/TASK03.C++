#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_DIGITS = 1000;

class BigInteger {
private:
    int digits[MAX_DIGITS];
    int length;
    bool isNegative;

    void removeLeadingZeros() {
        while (length > 1 && digits[length - 1] == 0)
            length--;
        if (length == 1 && digits[0] == 0)
            isNegative = false;
    }

    static int compareAbs(const BigInteger& a, const BigInteger& b) {
        if (a.length != b.length) return a.length - b.length;
        for (int i = a.length - 1; i >= 0; i--) {
            if (a.digits[i] != b.digits[i])
                return a.digits[i] - b.digits[i];
        }
        return 0;
    }

public:
    BigInteger() {
        for (int i = 0; i < MAX_DIGITS; i++) digits[i] = 0;
        length = 1;
        isNegative = false;
    }

    BigInteger(string str) {
        for (int i = 0; i < MAX_DIGITS; i++) digits[i] = 0;
        isNegative = false;
        if (str[0] == '-') {
            isNegative = true;
            str = str.substr(1);
        }
        reverse(str.begin(), str.end());
        length = str.length();
        for (int i = 0; i < length; i++)
            digits[i] = str[i] - '0';
        removeLeadingZeros();
    }

    friend istream& operator>>(istream& in, BigInteger& num) {
        string str;
        in >> str;
        num = BigInteger(str);
        return in;
    }

    friend ostream& operator<<(ostream& out, const BigInteger& num) {
        if (num.isNegative && !(num.length == 1 && num.digits[0] == 0))
            out << '-';
        for (int i = num.length - 1; i >= 0; i--)
            out << num.digits[i];
        return out;
    }

    BigInteger operator+(const BigInteger& other) const {
        if (this->isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = this->isNegative;
            int carry = 0;
            int maxLength = max(length, other.length);
            for (int i = 0; i < maxLength || carry; i++) {
                int sum = digits[i] + other.digits[i] + carry;
                result.digits[i] = sum % 10;
                carry = sum / 10;
            }
            result.length = maxLength + (carry ? 1 : 0);
            result.removeLeadingZeros();
            return result;
        } else {
            if (isNegative) {
                BigInteger temp = *this;
                temp.isNegative = false;
                return other - temp;
            } else {
                BigInteger temp = other;
                temp.isNegative = false;
                return *this - temp;
            }
        }
    }

    BigInteger operator-(const BigInteger& other) const {
        if (!isNegative && other.isNegative) {
            BigInteger temp = other;
            temp.isNegative = false;
            return *this + temp;
        } else if (isNegative && !other.isNegative) {
            BigInteger temp1 = *this;
            BigInteger temp2 = other;
            temp1.isNegative = false;
            BigInteger res = temp1 + temp2;
            res.isNegative = true;
            return res;
        } else {
            int cmp = compareAbs(*this, other);
            const BigInteger *larger = this, *smaller = &other;
            bool resultNegative = false;
            if (cmp < 0) {
                swap(larger, smaller);
                resultNegative = !larger->isNegative;
            } else {
                resultNegative = this->isNegative;
            }

            BigInteger result;
            int borrow = 0;
            for (int i = 0; i < larger->length; i++) {
                int diff = larger->digits[i] - smaller->digits[i] - borrow;
                if (diff < 0) {
                    diff += 10;
                    borrow = 1;
                } else borrow = 0;
                result.digits[i] = diff;
            }
            result.length = larger->length;
            result.isNegative = resultNegative;
            result.removeLeadingZeros();
            return result;
        }
    }

    bool operator==(const BigInteger& other) const {
        if (length != other.length || isNegative != other.isNegative) return false;
        for (int i = 0; i < length; i++)
            if (digits[i] != other.digits[i]) return false;
        return true;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative)
            return isNegative;
        int cmp = compareAbs(*this, other);
        return isNegative ? cmp > 0 : cmp < 0;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }
};
int main() {
    BigInteger num1, num2;
    cout << "Enter first BigInteger: ";
    cin >> num1;
    cout << "Enter second BigInteger: ";
    cin >> num2;

    cout << "Sum: " << num1 + num2 << endl;
    cout << "Difference: " << num1 - num2 << endl;

    if (num1 == num2)
        cout << "Numbers are equal" << endl;
    else if (num1 > num2)
        cout << "First is greater" << endl;
    else
        cout << "Second is greater" << endl;

    return 0;
}
