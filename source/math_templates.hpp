#ifndef BUW_MATH_TEMPLATES_HPP
#define BUW_MATH_TEMPLATES_HPP

template<typename T>
T square(T const& value) {
    return value * value;
}

template<typename T>
T add(T const& a, T const& b) {
    return a + b;
}

#endif // BUW_MATH_TEMPLATES_HPP