// #include <iostream>
// using namespace std;
// int main()
// {
//     int num1, num2, result;
//     cout << "enter the values of num1";
//     cin >> num1;
//     cout << "enter the value of num2";
//     cin >> num2;
//     try
//     {
//         if (num2 != 0)
//         {
//             result = num1 / num2;
//             cout << "result is :" << result;
//         }
//         else
//             throw num2;
//     }
//     catch (int k)
//     {
//         cout << "division by" << k << "not possible";
//     }
//     cout << "END";
//     return 0;
// }

// exception handling in  function

// #include <iostream>
// using namespace std;
// void divide(int x, int y, int z)
// {
//     cout << "\nwe are inside the function\n";
//     if ((x - y) != 0)
//     {
//         int r = z / (x - y);
//         cout << "result =" << r << endl;
//     }
//     else
//     {
//         throw(x - y);
//     }
// }
// int main()
// {
//     try
//     {
//         cout << "we are inside in try block" << endl;
//         divide(10, 20, 30);
//         divide(10, 10, 20);
//     }
//     catch (int i)
//     {
//         cout << "caught the exceptions" << endl;
//     }
//     return 0;
// }

//exception handling in constructor

#include<iostream>
using namespace std;

int main()
{

    return 0;
}