#include <vector>
#include <exception>
#include <iostream>
#include <bitset>
#include <climits>
#include <string>
#include <locale>
#include <codecvt>


class Fun {

};


std::string secure_function() 
{
    std::wstring wideMessage(L" b");
    wideMessage[0] = L'\xd800';

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>().to_bytes(wideMessage);

    //try
    //{
    //    return std::wstring_convert<std::codecvt_utf8_utf16 <wchar_t>>().to_bytes(wideMessage);
    //}

    // thrown by std::wstring_convert.to_bytes() for bad conversions
    //catch (const std::range_error& exception)
    //{
        // do something...
    //}

    return " Nothing wrong :) ";
}


int main()
{
    secure_function();
    int n = 999999;
    std::bitset<2> some_set(n);
    //std::cout << something << std::endl;
}