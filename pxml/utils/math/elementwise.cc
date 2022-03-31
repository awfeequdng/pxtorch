#include "pxml/utils/math/elementwise.hh"

#include "pxml/core/context.hh"
#include "pxml/utils/eigen_utils.hh"

#ifdef PXML_USE_MKL
#include <mkl.h>
#endif // PXML_USE_MKL

namespace pxml {
namespace math {

#ifdef PXML_USE_MKL
// not implement yet
#else // PXML_USE_MKL

#define DELEGATE_SIMPLE_UNARY_FUNCTION(T, Func, EigenFunc)        \
  template <>                                                     \
  EXPORT void Func<T, CPUContext>(                                \
      const int N, const T* X, T* Y, CPUContext* /* context */) { \
    EigenVectorArrayMap<T>(Y, N) =                                \
        ConstEigenVectorArrayMap<T>(X, N).EigenFunc();            \
  }
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Exp, exp)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Exp, exp)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Log, log)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Log, log)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Log1p, log1p)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Log1p, log1p)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Sin, sin)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Sin, sin)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Asin, asin)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Asin, asin)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Cos, cos)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Cos, cos)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Acos, acos)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Acos, acos)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Tan, tan)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Tan, tan)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Atan, atan)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Atan, atan)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Abs, abs)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Abs, abs)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Sqr, square)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Sqr, square)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Sqrt, sqrt)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Sqrt, sqrt)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Rsqrt, rsqrt)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Rsqrt, rsqrt)
DELEGATE_SIMPLE_UNARY_FUNCTION(float, Inv, inverse)
DELEGATE_SIMPLE_UNARY_FUNCTION(double, Inv, inverse)
// #undef DELEGATE_SIMPLE_UNARY_FUNCTION

#endif // PXML_USE_MKL

} // namespace pxml
} // namespace math
