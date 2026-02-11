class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, b1, a2, b2;

        // parse num1
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);

        // parse num2
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);

        int real = a1 * a2 - b1 * b2;
        int imag = a1 * b2 + b1 * a2;

        return to_string(real) + "+" + to_string(imag) + "i";
    }
};
