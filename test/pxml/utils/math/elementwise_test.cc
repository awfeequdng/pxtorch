#include "pxml/utils/math/elementwise.hh"
#include "pxml/core/context.hh"

#include <iostream>
using namespace std;

int main() {
    double d[] = {-0.2, 0.3, -5.5};
    // pxml::math::Abs<double, >(3, d, d, nullptr);
    pxml::CPUContext* cpu_context = nullptr;
    pxml::math::Abs(3, d, d, cpu_context);
    for (int i = 0; i < 3; i++) {
        cout << " " << d[i];
    }
    cout << " " << endl;
    return 0;
}