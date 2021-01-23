#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;
const double PI = 3.14159265359;

double power(double base, int pow) // done
{
    if (pow == 0)
        return 1.0;
    double product = 1;
    for (int i = 1; i <= pow; i++)
        product *= base;
    return product;
}



double absolute(double n) // done
{
    if (n < 0)
        return -n;
    else
        return n;
}

long long factorial(int n)   // done
{
	bool negative = 0;
    if (n == 0)
        return 1;
    if (n < 0){
       negative = 1;
    }
    n = absolute(n);
    long long product = 1;
    for (int i = 1; i <= n; i++)
        product *= i;
    if(negative == 1)
    	return -product;
   	else
   		return product;
}

double sin(double x, bool d) //done
{
    double result = 0;
    bool z = 1;
    if (d)
    {
        while (x > 360)
            x -= 360;

        if (x == 0 || x == 180 || x == 360)
            return 0;

        x = (x * PI) / 180;
    }

    for (int i = 1; i <= 20; i = i + 2)
    {
        if (z == 1)
        {
            result += power(x, i) / factorial(i);
            z = 0;
        }
        else
        {
            result -= power(x, i) / factorial(i);
            z = 1;
        }
    }
    return result;

}

double cos(double x, bool d) // done
{
    double result = 0;
    bool z = 1;

    if (d)
    {
        while (x > 360)
            x -= 360;
        if (x == 90 || x == 270)
            return 0;
        if (x == 360)
            return 1;
        x = (x * PI) / 180;
    }

    for (int i = 0; i <= 20; i = i + 2)
    {
        if (z == 1)
        {
            result += power(x, i) / factorial(i);
            z = 0;
        }
        else
        {
            result -= power(x, i) / factorial(i);
            z = 1;
        }
    }

    return result;

}
double tan(double x, bool d) // done
{
    if (d)
    {
        if (x == 90 || x == 270){
            cout << "MATH ERROR \n";
            system("pause");
            return 0;
        }
    }
    return sin(x, d) / cos(x, d);

}

double sininverse(double x) // done
{
    double result = 0;

    double bast[20] = { 1, 1, 3, 5, 35, 63, 231, 143, 6435, 12155, 46189, 88179,
                        676039, 1300075, 5014575, 9694845, 100180065, 116680311, 2268783825,
                        1472719325
                      };

    double mkam[20] { 1, 6, 40, 112, 1152, 2816, 13312, 10240, 557056, 1245184,
                      5505024, 12058624, 104857600, 226492416, 973078528, 2080374784,
                      23622320128, 30064771072, 635655159808, 446676598784
                    };
    if (x < -1 || x > 1)
    {
        cout << "MATH ERROR \n";
        system("pause");
        return 0;
    }

    if (x == 1)
        return 90;

    if (x == -1)
        return -90;

    for (int i = 0, j = 1; i < 20; i++, j += 2)
    {
        result += (bast[i] / mkam[i]) * power(x, j);
    }
    result = (result * 180) / PI;
    if (result < 0)
        result = -result + 180;

    return result;
}

double cosinverse(double x) // done
{
    if (x < -1 || x > 1)
    {
        cout << "MATH ERROR \n";
        system("pause");
        return 0;
    }
    return 0.5 * 180 - sininverse(x);

}

double taninverse(double x) // done
{
    double result =0;
    bool z=1;
    for(int i=1 ; i<=1000 ; i+=2)
    {
        if(z==1)
        {
            result+=power(x,i) / i ;
            z=0;
        }
        else
        {
            result-=power(x,i) / i ;
            z=1 ;
        }

    }

    return result *180 /PI ;


}

double sinh(double x) // done
{
    double result =0 ;

    for(int i =1 ; i<=20 ; i+=2)
    {
        result += power(x,i) / factorial(i) ;
    }

    return result ;

}
double cosh(double x) // done
{
    double result=1;
    for(int i=2 ; i<=20 ; i+=2)
    {
        result+= power(x,i) / factorial(i) ;
    }
    return result ;

}

double tanh(double x) // done
{
    return sinh(x) / cosh(x) ;
}



double ln(double x) // done
{
    double result = 0;
    bool y = 1;
    if (x <= 0)
    {
        cout << "MATH ERROR \n";
        system("pause");
        return 0;

    }
    if (x > 2)
    {
        x= 1.0 / x;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (y == 1)
        {
            result += power(x - 1, i) / i;
            y = 0;
        }
        else
        {
            result -= power(x - 1, i) / i;
            y = 1;
        }
    }
    if(result < 0)
        result = -result;
    return result;

}
double log(double x) // done
{

    return ln(x) / ln(10) ;
}

double e(double x) // done
{
    double result =0;
    for(int i=0 ; i<=20 ; i++)
    {
        result += power(x,i) / (double)factorial(i) ;
    }
    return result ;
}


double X_10 (double x) // done
{
    return e( x * ln(10) ) ;

}

double X_a (double a , double x) // done
{
    if (a<0)
    {
        a = absolute(a);
        int t = x;
        if(x == t && t % 2 == 0)
            return e(x * ln(a)) ;
        else
            return - e(x * ln(a)) ;


    }

    if (a==0 && x<0)
    {
        cout<< "MATH ERROR \n" ;
        system("pause");
        return 0 ;
    }

    if (a==0 && x>0 )
        return 0 ;

    return e(x * ln(a)) ;

}


double sqrt (double x) // done
{

    if (x==0)
        return 0;
    return X_a(x,0.5) ;

}

double root (double x , double n ) // done
{
    return X_a( x , 1/n );

}
bool isNumber(string s)
{
    bool z = 1;
    int numberOfDot = 0;
    if(s[0] == '-'){
        s.erase(0 , 1); // btmsa7 (rakm el index , kam 7arf hatmsa7o bd2an mn el index el mab3oot )
    }
    if(s.size() == 0)
        return false;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '.' && numberOfDot == 0)
        {
            numberOfDot++;
        }
        else if(!isdigit(s[i])) // dy fun gahza bt4of da rakm wala la2
        {
            z = 0;
            break;
        }
    }
    return z;
}
int main()
{

    bool d = 0;
    double res = 0 , num = 0 , MS = 0;
    string op;
    cout << "degree or radians ?" << endl;
    cin >> op;
    if(op == "degree")
        d = 1;
    system("cls");
    cout << res << endl;
    cin >> num;
    while(true)
    {
        system("cls");
        res = num;
        cout << res << endl;
        cin >> op;
        system("cls");
        if(op == "sin")
        {
            num = sin(res , d);
        }
        else if(op == "cos")
        {
            num = cos(res , d);
        }
        else if(op == "tan")
        {
            num = tan(res , d);
        }
        else if(op == "log")
        {
            num = log(res);
        }
        else if(op == "ln")
        {
            num = ln(res);
        }
        else if(op == "root")
        {
            cout << op << endl;
            cin >> num;
            if(num != 2)
                num = root(res , num);
            else
                num = sqrt(res);
        }
        else if(op == "!")
        {
            num = factorial(res);
        }
        else if(op == "pow")
        {
            cout << op << endl;
            cin >> num;
            num = X_a(res , num);
        }
        else if(op == "*")
        {
            cout << op << endl;
            cin >> num;
            num = num * res;
        }
        else if(op == "/")
        {
            cout << op << endl;
            cin >> num;
            num = res / num;
        }
        else if(op == "abs")
        {

            num = absolute(res);
        }
        else if(op == "sinInv")
        {

            num = sininverse(res);
        }
        else if(op == "cosInv")
        {

            num = cosinverse(res);
        }
        else if(op == "tanInv")
        {

            num = taninverse(num);
        }
        else if(op == "sinh")
        {

            num = sinh(res);
        }
        else if(op == "cosh")
        {

            num = cosh(res);
        }
        else if(op == "tanh")
        {

            num = tanh(res);
        }
        else if(op == "e")
        {
            num = e(res);
        }
        else if(op == "ten")
        {
            num = X_10(res);
        }
        else if(op == "+")
        {
            cout << op << endl;
            cin >> num;
            num = res + num;
        }
        else if(op == "-")
        {
            cout << op << endl;
            cin >> num;
            num = res - num;
        }
        else if(op == "degree")
        {
            d = 1;
        }
        else if(op == "radians")
        {
            d = 0;
        }
        else if(op == "MC")
        {
            MS = 0;
        }
        else if(op == "MS")
        {
            MS = num;
        }
        else if(op == "M-")
        {
            MS -= num;
        }
        else if(op == "M+")
        {
            MS += num;
        }
        else if(op == "MR")
        {
            num = MS;
        }
        else if(isNumber(op))
        {
            stringstream ss;
            ss << op;
            ss >> num;
        }
        else if(op == "q")
            break;
    }


    return 0;

}
