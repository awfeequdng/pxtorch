#pragma once
#include "pxml/macros/export.hh"

namespace pxml {
namespace math {

template <typename T, class Context>
PXTORCH_API void Exp(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Log(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Log1p(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Sin(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Asin(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Cos(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Acos(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Tan(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Atan(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Sinh(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Cosh(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void SinCos(int N, const T* X, T* S, T* C, Context* context);
template <typename T, class Context>
PXTORCH_API void Tanh(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Abs(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Sqr(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Sqrt(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Rsqrt(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Cube(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Cbrt(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Neg(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Sign(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Not(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Powx(int N, const T* A, const T b, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Inv(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void Erf(int N, const T* X, T* Y, Context* context);
template <typename T, class Context>
PXTORCH_API void CdfNorm(int N, const T* X, T* Y, Context* context);

} // namespace pxml
} // namespace math
