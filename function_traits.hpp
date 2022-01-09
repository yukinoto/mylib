#ifndef _FUNCTION_TIAITS
#define _FUNCTION_TIAITS

#include <functional>

template<typename T>
struct function_traits;

template<typename Ret,typename ...Args>
struct function_traits<Ret(Args...)>{
	using return_type=Ret;
	typedef Ret(function_type)(Args...);
	enum{arity=sizeof...(Args)};
	using stl_function_type=std::function<function_type>;

	template<size_t I>
	struct args{
		static_assert(I<arity,"Index out of range!");
		using type=typename std::tuple_element<I,std::tuple<Args...>>::type;
	};
};

template<typename Ret,typename ...Args>
struct function_traits<Ret(*)(Args...)>:function_traits<Ret(Args...)>{};

template<typename Ret,typename ...Args>
struct function_traits<std::function<Ret(Args...)>>:function_traits<Ret(Args...)>{};

#endif