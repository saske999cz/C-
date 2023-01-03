#include<iostream>
#include<math.h>

using namespace std;


float f_(float x)
{
   return 2*(2*x/(pow(x,2)+20))*(log(pow(x,2)+20)+x-20);

}
float f(float x)
{
    return pow(log(pow(x,2) + 20)+ x - 20, 2);
}

float g_(float x){
    return 2*(exp(x)+1)*(exp(x) + x + 20) + 2*x;
}

float g(float x)
{
    return pow(exp(x) + x -20,2) + x*x;
}

float findMin(float *f(float), float *f_(float), float x1, float x2, float eps)
{
    int count = 0 ;
    float tmp;
    do
    {
     tmp = x2;
     x2 = x1 - f(x1)/f_(x1);

    }
}
int main(){


}