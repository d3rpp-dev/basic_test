#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define u8 char
#define u16 unsigned short
#define u32 unsigned int
#define u64 unsigned long long int

#define i8 signed char
#define i16 signed short
#define i32 signed int
#define i64 signed long long int

#define f32 float
#define f64 double
#define f128 long double

#define str std::string


/* 
 * ******************************
 *   Borrowed from the internet
 * ******************************
 */
// trim from start (in place)
static inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
        }));
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}

constexpr auto RESET = "\x1b[39;40m";
constexpr auto RED =   "\x1b[91;40m";
constexpr auto GREEN = "\x1b[92;40m";
constexpr auto BLUE =  "\x1b[94;40m";
constexpr auto CYAN =  "\x1b[96;40m";