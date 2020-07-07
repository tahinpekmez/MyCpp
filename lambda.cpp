/*************************************************************************************
#include <iostream>
#include <algorithm>
#include <cmath>

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
        //capture, parameters, mutuable(ops), throw()(ops), -> int, return(ops), lambda body
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // end of lambda expression
    );
}
**************************************************************************************/

/**********************************************************************
struct S {void f(int i); };

void S iki nokta f(int i) {

    [&, i]{}; //OK, cunku tek by reference capture var ikincisi olamaz.
    [&, &i]{}; //ERROR, birden fazla by reference capture olamaz.
    [=, this]{}; //ERROR, "=" zaten default olarak var. ikinci value olamaz.
    [=, *this]{}; //OK, capture "this" by value
    [i, i]{}; //ERROR, "i" tekrarlanamaz.
}
**************************************************************************/

/*****************************************
//VARIADIC TEMPLATE icinde capture

template<class... Args>
void f(Args... args) {
    auto x = [args...] {return g(args...)};
    x();
}
*******************************************/

/******************************************
 //scope disindaki tanimlanacak degisken de 
 //lambda icinde yaklanabilir (unique_ptr gibi)

pNums = make_unique<vector<int>>(nums);
//...
     
      auto a = [ptr = move(pNums)]()
        {
            // use ptr
        };
*******************************************/

/**********************************
//fonksiyonlar gibi parametre listsi yapabiliriz lambda icinde

auto y = [] (int first, int second)
{
    return first + second;
};
************************************/

/************************************
 // fonksiyon ve parametreler anonim olabilir.
 //ve lambda bunu anlar.

auto y = [] (auto first, auto second)
{
    return first + second;
}
*************************************/

/**********************************************************
auto x1 = [](int i){return i};
auto x2 = []{return}{1, 2}; }; //ERROR return type is void,
                               //return type from braced-init-list is not valid

//yani diyor ki return tipini anlayamadim belli de değil.
//return tipin void yani donemez diyor.
*****************************************************************/

// captures_lambda_expression
// compile with: /W4 /EHsc

//#include <iostream>
//#include <vector>

//using namespace std;

/***********************************************
int main()  
{
    int m = 0;
    int n = 0;

    [&, n] (int a) mutable {m = ++n + a;}(4);
    cout << m << endl; 
    cout << n << endl;
}

***************************************************/

/*********************************************************
void fillVector(vector<int>& v)
{
    // a local static variable
    static int nextValue = 1;

    //the lambda expression that appears in the following
    //call to the generate function modifies and uses the
    //local static variable nextValue

    generate(v.begin(), v.end(), [] {return nextValue++; });
 //WARNING this is not thread-safe and is shown for illustration only
}
**********************************************************************/


#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename C> void print(const string& s, const C& c)
{
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

void fillVector(vector<int>& v)
{
    // a local static variable
    static int nextValue = 1;

    //the lambda expression that appears in the following
    //call to the generate function modifies and uses the
    //local static variable nextValue

// EMPTY LAMBDA CAPTURE EXPRESSION
generate(v.begin(), v.end(), [] { return nextValue++; });
 
}

int main()
{
    //the number of elements in the vector.
    const int elementcount = 9;

    //create a vector object with each element set to 1.
    vector<int> v(elementcount, 1);

    //these variables hold the previous two elements of the vector
    int x = 1;
    int y = 1;
    
    //sets each element in the vector to the sum of the
    //previous two elements.
    generate_n(v.begin() + 2, elementcount - 2,
    
    // CAPTURE BY VALUE
    // mutable ile capture by value olarak yakalanan deger modifiye edilebilir.
    [=]() mutable throw() -> int {//lambda is the 3rd parameter
    //generate current value.
    int n = x + y;
    //update previous two values.
    x = y;
    y = n;
    return n;
    });
    
    print ("vector v after call to generate_n() with lambda: ", v);
    
    //print the local variables x and y.
    //the values of x and y hold their initial values 
    //because they are captured by value.

     cout << "x: " << x << " y: " << y << endl;

     // Fill the vector with a sequence of numbers
    fillVector(v);
    print("vector v after 1st call to fillVector(): ", v);
    // Fill the vector with the next sequence of numbers
    fillVector(v);
    print("vector v after 2nd call to fillVector(): ", v);
}


/************************************************************************************************************************************
 fillVector ile bir sonraki sayi attirilmak suretiyle bir vektor olusturulmustur.
 main icinde generate_n fonksiyonu ve icindeki lambda expression ile kendisinden onceki 2 sayiyi toplayan bir fonksiyon olusturulmustur.
 
 ------------------->>lamndanin adimlari<<---------------------------
  [=] --> capture by value; degiskenleri degeri ile algilar, ulasir
  () --> parameter list; bos birakildi, opsiyonel
  mutable; capture by value degiskenleri modifiye etmemizi saglar (capture by reference ise opsiyoneldir)
  throw(); herhangi bir olagan disi durum beklenmiyor. (opsiyoneldir)
  ->int; trailing return type; generate_n fonksiyonunun return tipidir.(opsiyonel) trailing return belirtilmiosa auto kullanilmayabilir. 
 ~~~LAMBDA BODY~~~ 
  int n = x + y
  x=y
  y=n
  return n 
  burada ilk iki sayi toplanacak cikan sonuc olan n ayni zamanda yeni y olacak.
************************************************************************************************************************************/

/**********************************************************************************************
#include <functional>
#include <iostream>

int main()
{
   using namespace std;

   int i = 3;
   int j = 5;


    // [&, i]{}; //OK, cunku tek by reference capture var ikincisi olamaz.
    // [&, &i]{}; //ERROR, birden fazla by reference capture olamaz.
    // [=, this]{}; //ERROR, "=" zaten default olarak var. ikinci value olamaz.
    // [=, *this]{}; //OK, capture "this" by value
    // [i, i]{}; //ERROR, "i" tekrarlanamaz.


// Lambda ifadesi icin fonksiyonun argumanlarini capture ederken 
// farkli bir metoddan ornek verilmistir. Tek bir yapi yoktur.
   function<int (void)> f = [i, &j] { return i + j; };

   i = 22;
   j = 44;

   cout << f() << endl;
}// "i" capture by value oldugundan degismez. SONUC: 47
*************************************************************************/




