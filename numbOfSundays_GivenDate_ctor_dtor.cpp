#include<iostream>

class sunday
{
    public:
    int i, j, k, z; 
    int x[3] = {7, 1, 1900}; //first sunday
    int y[3];
    int day {};
    int total_sunday {};
    
   sunday()
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
    }
    
    ~sunday();
    
};

sunday::~sunday()
{
    std::cout <<"\nOBJECT IS DELETED";
};

int main()
{   
    sunday *p = new sunday;
    std::cout << "Total sunday on 1st of month during 1 jan 1900 to 31 dec 2000 are: " << p->total_sunday;
    delete p;
   
    return 0;
    
}