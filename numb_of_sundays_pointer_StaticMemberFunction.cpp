#include<iostream>
using namespace std;

class sunday
{
    private:
    static int i, j, k, z;
    static int y[3];
    static int day;
    static int total_sunday;
    
   public:
   int x[3] = {7, 1, 1900}; //first sunday
   
   
   static int number_of_sunday()
   {
       for (i = 1900; i <= 2000; i++)
       {
           for (j = 1; j <= 12; j++)
           {
               if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 12)
                {
                   z = 31;
                }
                else if (j == 4 || j == 6 || j == 9 || j == 10 || j == 11)
                {
                    z = 30;
                }
                else if (j==2 && i%4 == 0)
                {
                    z = 29;
                }
                else
                {
                    z = 28;
                }
                for (k = 1; k <= z; k++)
                {
                    y[0] = k;
                    y[1] = j;
                    y[2] = i;
                    day++;
                    
                    if (day > 7)
                    {
                        day = 1;
                    }
                    
                    if (day == 7 && y[0] == 1 && y[2] > 1900)
                    {
                        total_sunday++;
                    }
                }
            }
        }

        return total_sunday++;
    }
};

int sunday::day;
int sunday::i;
int sunday::j;
int sunday::k;
int sunday::total_sunday;
int sunday::z;
int sunday::y[3];

int main()
{
    sunday *p;   
    cout << "Total sunday on 1st of month during 1 jan 1900 to 31 dec 2000 are: " << p->number_of_sunday() << endl;
    delete p;
    
    return 0;
}
