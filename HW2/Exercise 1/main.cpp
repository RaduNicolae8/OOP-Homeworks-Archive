#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;

class Point{
private:
    double x,y,z;
    bool flag=false;
public:
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    Point() :x(0),y(0),z(0){}
    Point(double x, double y) : x(x), y(y),z(0),flag(true) {}
    double getX(){
        return this->x;
    }
    double getY(){
        return this->y;
    }
    double getZ(){
        return this->z;
    }
    double getRadius(){
        double r;
        r=sqrt(x*x+y*y+z*z);
        return r;
    }
    double getPhi(){
        double p;
        if(x>=0 && y>=0)
               p=atan2(y,x)*180/M_PI;
             else
             p=(abs((atan2(y,x)+M_PI)*180/M_PI))+180;
             if(p>360)
            {
                int s = p/360;
                p=p-(360*s);
            }
                 
            return p;
            
    

    }
    double getTheta(){
        //double t=atan2(y,x);
        double t = atan2(hypot(x,y),z);
        return t*180/M_PI;
    }


};

int main() {
    char c;
    double x,y,z;
    double vec[9999][3];
    cin>>vec[0][0];
    int cont=1,k=0;
    while(scanf("%c",&c)!=EOF)
    {

        //if(c!=';' || c!=' ')
            //cout<<"error "<<c<<' ';
        if(c==';') {
            cin >> vec[k][cont];
            cont++;
        }
        if(c==' ' || c=='\n') {
            if(cont==2)
                vec[k][cont]=-1;
            k++;
            cont=1;
            cin>>vec[k][0];
        }
    }
    for(int i=k-1;i>=0;i--)
    {
        x=vec[i][0]; y=vec[i][1];z=vec[i][2];
        //cout<<x<<' '<<y<<' '<<z<<endl;
        if(z==-1)
        {
            Point p(x,y);
            printf("(r=%.3lf; phi=%.3lf)",p.getRadius(),p.getPhi());
        } else
        {
          Point p(x,y,z);
            printf("(r=%.3lf; phi=%.3lf; th=%.3lf)",p.getRadius(),p.getPhi(),p.getTheta());
        }
        cout<<endl;
    }

    return 0;
}
