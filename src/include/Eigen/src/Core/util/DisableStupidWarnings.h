#ifndef EIGEN_WARNINGS_DISABLED
#define EIGEN_WARNINGS_DISABLED

#ifdef _MSC_VER
  // 4100 - unreferenced formal parameter (occurred e.g. in aligned_allocator::destroy(pointer p))
  // 4101 - unreferenced local variable
  // 4181 - qualifier applied to reference type ignored
  // 4211 - nonstandard extension used : redefined extern to static
  // 4244 - 'argument' : conversion from 'type1' to 'type2', possible loss of data
  // 4273 - QtAlignedMalloc, inconsistent DLL linkage
  // 4324 - structure was padded due to declspec(align())
  // 4503 - decorated name length exceeded, name was truncated
  // 4512 - assignment operator could not be generated
  // 4522 - 'class' : multiple assignment operators specified
  // 4700 - uninitialized local variable 'xyz' used
  // 4714 - function marked as __forceinline not inlined
  // 4717 - 'function' : recursive on all control paths, function will cause runtime stack overflow
  // 4800 - 'type' : forcing value to bool 'true' or 'false' (performance warning)
  #ifndef EIGEN_PERMANENTLY_DISABLE_STUPID_WARNINGS

  #endif


#elif defined __INTEL_COMPILER
  // 2196 - routine is both "inline" and "noinline" ("noinline" assumed)
  //        ICC 12 generates this warning even without any inline keyword, when defining class methods 'inline' i.e. inside of class body
  //        typedef that may be a reference type.
  // 279  - controlling expression is constant
  //        ICC 12 generates this warning on assert(constant_expression_depending_on_template_params) and frankly this is a legitimate use case.
  // 1684 - conversion from pointer to same-sized integral type (potential portability problem)
  // 2259 - non-pointer conversion from "Eigen::Index={ptrdiff_t={long}}" to "int" may lose significant bits
  #ifndef EIGEN_PERMANENTLY_DISABLE_STUPID_WARNINGS

  #endif


#elif defined __clang__
  // -Wconstant-logical-operand - warning: use of logical && with constant operand; switch to bitwise & or remove constant
  //     this is really a stupid warning as it warns on compile-time expressions involving enums
  #ifndef EIGEN_PERMANENTLY_DISABLE_STUPID_WARNINGS

  #endif

  #if __clang_major__ >= 3 && __clang_minor__ >= 5

  #endif
  #if ( defined(__ALTIVEC__) || defined(__VSX__) ) && __cplusplus < 201103L
    // warning: generic selections are a C11-specific feature
    // ignoring warnings thrown at vec_ctf in Altivec/PacketMath.h

  #endif

#elif defined __GNUC__

  #if (!defined(EIGEN_PERMANENTLY_DISABLE_STUPID_WARNINGS)) &&  (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))

  #endif
  // g++ warns about local variables shadowing member functions, which is too strict

  #if __GNUC__ == 4 && __GNUC_MINOR__ < 8
    // Until g++-4.7 there are warnings when comparing unsigned int vs 0, even in templated functions:

  #endif
  #if __GNUC__>=6

  #endif
  #if __GNUC__==7
    // See: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=89325

  #endif
#endif

#if defined __NVCC__

  // Disable the "statement is unreachable" message

  // Disable the "dynamic initialization in unreachable code" message

  // Disable the "invalid error number" message that we get with older versions of nvcc

  // Disable the "calling a __host__ function from a __host__ __device__ function is not allowed" messages (yes, there are many of them and they seem to change with every version of the compiler)











#endif

#else
// warnings already disabled:
# ifndef EIGEN_WARNINGS_DISABLED_2
#  define EIGEN_WARNINGS_DISABLED_2
# elif defined(EIGEN_INTERNAL_DEBUGGING)
#  error "Do not include \"DisableStupidWarnings.h\" recursively more than twice!"
# endif

#endif // not EIGEN_WARNINGS_DISABLED
