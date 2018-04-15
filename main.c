#include <stdio.h>

#include <math.h>

double a, b, eps;//Нижний и верхний пределы интегрирования (a, b), погрешность (eps).
double maxStep; // Количество разбиений

double f1(double x)
{
    return 1/(x*log(x));
}

void input(){
    printf("Enter a:"); //2
    scanf("%lf",&a);
    printf("Enter b:"); //3
    scanf("%lf",&b);
    printf("Enter eps:"); //0.0001
    scanf("%lf",&eps);
    printf("Enter maxStep:"); //36
    scanf("%lf",&maxStep);
}

void solve (double (*pf)(double)){

    double I=eps+1, I1=0;//I-предыдущее вычисленное значение интеграла, I1-новое, с большим N.
    for (int N=2; (N<=36)||(fabs(I1-I)>eps); N*=2)
    {
        double h, sum2=0, sum4=0, sum=0;
        h=(b-a)/(2*N);//Шаг интегрирования.
        for (int i=1; i<=2*N-1; i+=2)
        {
            sum4+=pf(a+h*i);//Значения с нечётными индексами, которые нужно умножить на 4.
            sum2+=pf(a+h*(i+1));//Значения с чётными индексами, которые нужно умножить на 2.
        }
        sum=pf(a)+4*sum4+2*sum2-pf(b);//Отнимаем значение f(b) так как ранее прибавили его дважды.
        I=I1;
        I1=(h/3)*sum;
    }
    printf("%lf",I1);
}
int main() {
    input();
    solve(f1);

    getchar();
    return 0;
}