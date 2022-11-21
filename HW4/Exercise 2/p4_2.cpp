#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Point{
protected:
    vector<double> mCoordinates;
    double mDistance;

    friend class Point2D;
    friend class Point3D;
    friend class Point4D;
public:
    virtual void print()=0;
    virtual void calculateDistance()=0;
    virtual Point* add(Point* p)=0;
    virtual Point* multiply(Point* p)=0;

    double getDistance(){
        return mDistance;
    }
    uint64_t getSize(){
        return mCoordinates.size();
    }
};

class Point2D:public Point{

public:
    Point2D(){
        Point::mCoordinates.push_back(0);
        Point::mCoordinates.push_back(0);
        Point::mDistance=0;
    }
    Point2D(double a, double b)
    {
        Point::mCoordinates.push_back(a);
        Point::mCoordinates.push_back(b);
        calculateDistance();
    }
    void print() override{
        Point* p = multiply(this);
        if(p->mCoordinates[1]>=0)
            printf("%.3lf+%.3lfi -> %.3lf\n",p->mCoordinates[0],p->mCoordinates[1],this->mDistance);
        else
            printf("%.3lf%.3lfi -> %.3lf\n",p->mCoordinates[0],p->mCoordinates[1],this->mDistance);
    }
    void calculateDistance() override{
        Point::mDistance = ( abs(
                (mCoordinates[0]+mCoordinates[1])/2) +
                             sqrt(abs(mCoordinates[0]*mCoordinates[1])));

    }
    Point* add(Point* p) override{
        double v1=mCoordinates[0]+p->mCoordinates[0],
                v2 = mCoordinates[1]+p->mCoordinates[1];
        return new Point2D(v1,v2);
    }
    Point* multiply(Point* p) override{
        double v1=mCoordinates[0]*p->mCoordinates[0]-mCoordinates[1]*p->mCoordinates[1],
                v2 = mCoordinates[0]*p->mCoordinates[1]+mCoordinates[1]*p->mCoordinates[0];
        return new Point2D(v1,v2);
    }
};

class Point3D:public Point{
public:
    Point3D(){
        Point::mCoordinates.push_back(0);
        Point::mCoordinates.push_back(0);
        Point::mCoordinates.push_back(0);
        Point::mDistance=0;
    }
    Point3D(double a, double b,double c)
    {
        Point::mCoordinates.push_back(a);
        Point::mCoordinates.push_back(b);
        Point::mCoordinates.push_back(c);
        calculateDistance();
    }
    void print() override{
        this->calculateDistance();
        Point* p = multiply(this);
        printf("%.3lf",p->mCoordinates[0]);
        if(p->mCoordinates[1]>=0)
            cout<<'+';
        printf("%.3lfi",p->mCoordinates[1]);
        if(p->mCoordinates[2]>=0)
            cout<<'+';
        printf("%.3lfj -> %.3lf\n",p->mCoordinates[2],this->mDistance);
        free(p);
    }
    void calculateDistance() override{
        double var = abs(mCoordinates[0]*mCoordinates[1]*mCoordinates[2]);
        Point::mDistance = (abs(
                (mCoordinates[0]+mCoordinates[1]+mCoordinates[2])/3) +
                            pow(var,(double)1/3)
        );

    }
    Point* add(Point* p) override{
        double v1=mCoordinates[0]+p->mCoordinates[0],
                v2 = mCoordinates[1]+p->mCoordinates[1],
                v3 = mCoordinates[2]+p->mCoordinates[2];
        return new Point3D(v1,v2,v3);
    }
    Point* multiply(Point* p) override{
        double v1=mCoordinates[0]*p->mCoordinates[0]-mCoordinates[1]*p->mCoordinates[1]-mCoordinates[2]*p->mCoordinates[2],
                v2 = mCoordinates[0]*p->mCoordinates[1]+mCoordinates[1]*p->mCoordinates[0],
                v3 = mCoordinates[0]*p->mCoordinates[2]+mCoordinates[2]*p->mCoordinates[0];
        return new Point3D(v1,v2,v3);
    }
};

class Point4D:public Point{
public:
    Point4D(){
        Point::mCoordinates.push_back(0);
        Point::mCoordinates.push_back(0);
        Point::mCoordinates.push_back(0);
        Point::mCoordinates.push_back(0);
        Point::mDistance=0;
    }
    Point4D(double a, double b,double c,double d)
    {
        Point::mCoordinates.push_back(a);
        Point::mCoordinates.push_back(b);
        Point::mCoordinates.push_back(c);
        Point::mCoordinates.push_back(d);
        calculateDistance();
    }
    void print() override{
        Point* p = multiply(this);
        printf("%.3lf",p->mCoordinates[0]);
        if(p->mCoordinates[1]>=0)
            cout<<'+';
        printf("%.3lfi",p->mCoordinates[1]);
        if(p->mCoordinates[2]>=0)
            cout<<'+';
        printf("%.3lfj",p->mCoordinates[2]);
        if(p->mCoordinates[3]>=0)
            cout<<'+';
        printf("%.3lfk -> %.3lf\n",p->mCoordinates[3],this->mDistance);
        free(p);
    }
    void calculateDistance() override{
        Point::mDistance = ( abs(
                (mCoordinates[0]+mCoordinates[1]+mCoordinates[2]+mCoordinates[3])/4) +
                             pow(abs(mCoordinates[0]*mCoordinates[1]*mCoordinates[2]*mCoordinates[3]),(double)1/4)
        );

    }
    Point* add(Point* p) override{
        
        if(p->getSize()==2)
        {
            double v1=mCoordinates[0]+p->mCoordinates[0],
                v2 = mCoordinates[1]+p->mCoordinates[1],
                v3 = mCoordinates[2],
                v4 = mCoordinates[3];
        return new Point4D(v1,v2,v3,v4);
        }
        
        if(p->getSize()==3)
        {
            double v1=mCoordinates[0]+p->mCoordinates[0],
                v2 = mCoordinates[1]+p->mCoordinates[1],
                v3 = mCoordinates[2]+p->mCoordinates[2],
                v4 = mCoordinates[3];
        return new Point4D(v1,v2,v3,v4);
        }
        
        double v1=mCoordinates[0]+p->mCoordinates[0],
                v2 = mCoordinates[1]+p->mCoordinates[1],
                v3 = mCoordinates[2]+p->mCoordinates[2],
                v4 = mCoordinates[3]+p->mCoordinates[3];
        return new Point4D(v1,v2,v3,v4);
    }
    Point* multiply(Point* p) override{
        
        if(p->getSize()==2)
        {
            double v1=mCoordinates[0]*p->mCoordinates[0]-mCoordinates[1]*p->mCoordinates[1],
                v2 = mCoordinates[0]*p->mCoordinates[1]+mCoordinates[1]*p->mCoordinates[0],
                v3 = mCoordinates[2]*p->mCoordinates[0],
                v4 = mCoordinates[3]*p->mCoordinates[0];
        return new Point4D(v1,v2,v3,v4);
        }
        
        if(p->getSize()==3)
        {
            double v1=mCoordinates[0]*p->mCoordinates[0]-mCoordinates[1]*p->mCoordinates[1]-mCoordinates[2]*p->mCoordinates[2],
                v2 = mCoordinates[0]*p->mCoordinates[1]+mCoordinates[1]*p->mCoordinates[0],
                v3 = mCoordinates[0]*p->mCoordinates[2]+mCoordinates[2]*p->mCoordinates[0],
                v4 = mCoordinates[3]*p->mCoordinates[0];
        return new Point4D(v1,v2,v3,v4);
        }
        
        
        double v1=mCoordinates[0]*p->mCoordinates[0]-mCoordinates[1]*p->mCoordinates[1]-mCoordinates[2]*p->mCoordinates[2]-mCoordinates[3]*p->mCoordinates[3],
                v2 = mCoordinates[0]*p->mCoordinates[1]+mCoordinates[1]*p->mCoordinates[0],
                v3 = mCoordinates[0]*p->mCoordinates[2]+mCoordinates[2]*p->mCoordinates[0],
                v4 = mCoordinates[0]*p->mCoordinates[3]+mCoordinates[3]*p->mCoordinates[0];
        return new Point4D(v1,v2,v3,v4);
    }
};

bool cmp(Point* p1, Point* p2){
    if(p1->getSize() == p2->getSize())
        return p1->getDistance()>p2->getDistance();
    return p1->getSize()>p2->getSize();
}

int main() {
    vector<double> vec;
    vector<Point*> vecc;
    double a;
    bool sel;
    char c;
    Point* p2 = new Point2D();
    Point* p3 = new Point3D();
    Point* p4 = new Point4D();

    while(scanf("%lf",&a)!=EOF)
    {
        if(scanf("%c",&c)==EOF)
            sel=0;
        else if(c==';')
            sel=1;
        else if (c==' ' || c=='\n')
            sel=0;

        vec.push_back(a);

        if(!sel)
        {
            if(vec.size() ==2)
            {
                vecc.push_back(new Point2D(vec[0],vec[1]));
                p2 = p2->add(new Point2D(vec[0],vec[1]));
            }
            else if(vec.size() ==3)
            {
                vecc.push_back(new Point3D(vec[0],vec[1],vec[2]));
                p3 = p3->add(new Point3D(vec[0],vec[1],vec[2]));
            }
            else if(vec.size() ==4)
            {
                vecc.push_back(new Point4D(vec[0],vec[1],vec[2],vec[3]));
                p4 = p4->add(new Point4D(vec[0],vec[1],vec[2],vec[3]));
            }
            vec.clear();
        }
    }

    sort(vecc.begin(),vecc.end(),cmp);

    for(Point* pp:vecc)
    {
        if(pp->getSize() ==2 && (pp->getDistance() >=p2->getDistance()))
            pp->print();
        if(pp->getSize() ==3 && (pp->getDistance() >=p3->getDistance()))
            pp->print();
        if(pp->getSize() ==4 && (pp->getDistance() >=p4->getDistance()))
            pp->print();
    }

    return 0;
}
