#pragma once

#include <variant>

template<class... Ts>
struct overload : Ts ... { using Ts::operator ()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

template<typename Variant, typename ...Handlers>
auto match(Variant&& v, Handlers&& ...handlers)
{
	return std::visit(overload {std::forward<Handlers>(handlers)...},
					  std::forward<Variant>(v));
}