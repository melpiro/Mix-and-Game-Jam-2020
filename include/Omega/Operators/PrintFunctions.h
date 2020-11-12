#pragma once

#include <vector>
#include <iostream>
#include <tuple>
#include <SFML/Graphics.hpp>
#include "Data/triplet.h"
#include "String/EncodeFunction.h"

template<typename T> struct is_vector : public std::false_type {};

template<typename T, typename A>
struct is_vector<std::vector<T, A>> : public std::true_type {};


std::ostream& operator<<(std::ostream& os, sf::String str);

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);

template <typename T>
std::ostream& operator<<(std::ostream& os, const sf::Vector2<T>& v);
template <typename T>
std::ostream& operator<<(std::ostream& os, const sf::Vector3<T>& v);

std::ostream& operator<<(std::ostream& os, const sf::Color v);


template <typename T, typename J>
std::ostream& operator<<(std::ostream& os, const std::pair<T, J >& v);
template<typename T, typename J, typename K>
std::ostream& operator<<(std::ostream& os, const std::tuple<T, J, K>& v);

template<typename T, typename J, typename K>
std::ostream& operator<<(std::ostream& os, const O::data::triplet<T, J, K>& v);


#include "PrintFunctions.ipp"


