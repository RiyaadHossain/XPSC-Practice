#include <bits/stdc++.h>
using namespace std;

int left_shift_by_k(int x, int k)
{
    return (x << k);
}

int right_shift_by_k(int x, int k)
{
    return (x >> k);
}

bool is_kth_bit_on(int x, int k)
{
    return (x & (1 << k));
}

bool is_kth_bit_off(int x, int k)
{
    return (x & (1 << k)) == 0;
}

int number_of_bits_on(int x)
{
    int cnt = 0;
    while (x)
    {
        if (x & 1)
            cnt++;
        x >>= 1;
    }
    return cnt;
}

int number_of_bits_off(int x)
{
    int cnt = 0;
    int i = 32;
    while (i--)
    {
        if ((x & 1) == 0)
            cnt++;
        x >>= 1;
    }
    return cnt;
}

void print_bits(int x)
{
    int i = 32;
    while (i--)
    {
        cout << ((x & (1 << 31)) != 0) << " ";
        x <<= 1;
    }
    cout << '\n';
}

void print_bits_reverse(int x)
{
    int i = 32;
    while (i--)
    {
        cout << (x & 1) << " ";
        x >>= 1;
    }
    cout << '\n';
}

int set_kth_bit(int x, int k)
{
    return (x | (1 << k));
}

int unset_kth_bit(int x, int k)
{
    return (x & (~(1 << k)));
}

int toggle_kth_bit(int x, int k)
{
    return (x ^ (1 << k));
}

// Practice Problems 1
string even_or_odd(int x)
{
    bool isEven = (x & 1) == 0;

    if (isEven)
        return "Even";

    return "Odd";
}

// Practice Problem 2
string is_power_of_2(int x)
{
    if (x <= 0)
        return "NO";

    if ((x & x - 1) == 0)
        return "YES";

    return "NO";
}

int main()
{

    // cout << left_shift_by_k(44, 1) << '\n';
    // cout << right_shift_by_k(44, 1) << '\n';
    // cout << is_kth_bit_on(44, 3) << '\n';
    // cout << is_kth_bit_off(44, 4) << '\n';
    // cout << number_of_bits_on(44) << '\n';
    // cout << number_of_bits_off(44) << '\n';
    // print_bits(44);
    // print_bits_reverse(44);
    // cout << set_kth_bit(44, 4) << '\n';
    // cout << unset_kth_bit(44, 2) << '\n';
    // cout << toggle_kth_bit(44, 2) << '\n';

    // cout << even_or_odd(43) << '\n';
    // cout << is_power_of_2(8) << '\n';
}