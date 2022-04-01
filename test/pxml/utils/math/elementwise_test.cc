#include "pxml/utils/math/elementwise.hh"
#include "pxml/core/context.hh"

#include <iostream>
using namespace std;

void test_abs() {
    double src[] = {-0.2, 0.3, -5.5};
    double dst[3] = {0.2, 0.3, 5.5};

    pxml::CPUContext* cpu_context = nullptr;
    pxml::math::Abs(3, src, src, cpu_context);
    for (int i = 0; i < 3; i++) {
        if (src[i] != dst[i]) {
            cout << __LINE__ << " : " << src[i] << " != " << dst[i] << endl;
        }
    }
}

int main() {
    test_abs();
    return 0;
}