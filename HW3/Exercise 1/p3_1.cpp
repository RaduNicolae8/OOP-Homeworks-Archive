#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

class Vector{
private:
    uint16_t mDim;
    double *mValues;
public:
    Vector(uint16_t mDim){
        this->mDim=mDim;
        mValues = new double[mDim];
    }
    Vector(){
        mDim = 0;
        mValues = new double[mDim];
    }
    Vector(const Vector &r){
        this->mDim=r.mDim;
        this->mValues=r.mValues;
    }

    virtual ~Vector() {
    }

    Vector operator+(const Vector &r)  {
        if (this->mDim == r.mDim)
        {
            Vector a(mDim);
            for (int i=0;i<mDim;++i)
            {
                a.mValues[i]= r.mValues[i] + this->mValues[i];
            }
            return a;
        }
        return Vector();
    }

    double operator*(const Vector &r){
        double ans=0,min;
        if(r.mDim <= this->mDim)
            min = r.mDim;
        else
            min = this->mDim;
        for(int i =0;i<min;i++)
        {
            ans+=(r.mValues[i]*this->mValues[i]);
        }
        return ans;
    }

    double operator!(){
        double ans=0;
        for(int i=0;i<mDim;++i)
        {
            ans+= mValues[i]*mValues[i];
        }
        ans = sqrt(ans);
        return ans;
    }

    Vector operator^(const Vector &r){
        if (this->mDim != r.mDim)
            return Vector();

        if(this->mDim >3 || this->mDim<2)
        {
            Vector a(mDim);
            for (int i=0;i<a.mDim;++i)
                a.mValues[i]=1;
            return a;
        }
        if(this->mDim == 2)
        {
            Vector a(mDim+1);
            a.mValues[0]=0;
            a.mValues[1]=0;
            a.mValues[2]=(this->mValues[0]*r.mValues[1])-(this->mValues[1]*r.mValues[0]);
            return a;
        }
        if(this->mDim == 3)
        {
            Vector a(mDim);
            a.mValues[0]=(this->mValues[1]*r.mValues[2])-(this->mValues[2]*r.mValues[1]);
            a.mValues[1]=(this->mValues[0]*r.mValues[2])-(this->mValues[2]*r.mValues[0]);
            a.mValues[2]=(this->mValues[0]*r.mValues[1])-(this->mValues[1]*r.mValues[0]);
            return a;
        }
        return Vector();
    }

    double getValue(uint16_t r){
        return this->mValues[r];
    }
    void setValue(uint16_t r,double rr)
    {
        this->mValues[r]=rr;
    }
};

int main() {
    uint16_t nr1,nr2;
    double  val;
    int i;
    cin>>nr1>>nr2;
    Vector a(nr1),b(nr2);
    for(i=0; i<nr1;i++)
    {
        cin>>val;
        a.setValue(i,val);
        //cout<<"Valoarea vectorului A ["<<i<<"] = "<<a.getValue(i)<<endl;
    }
    for(i=0; i<nr2;i++)
    {
        cin>>val;
        b.setValue(i,val);
        //cout<<"Valoarea vectorului B ["<<i<<"] = "<<b.getValue(i)<<endl;

    }
    if(nr1==nr2 && nr1<4)
    {
        Vector prodV(3);
            if(nr1==2)
            {
                Vector nou(3);
                nou.setValue(0,a.getValue(0));
                nou.setValue(1,a.getValue(1));
                nou.setValue(2,0);
                 prodV = ((a^b)+nou);
//                 for (i=0;i<3;i++)
//                 {
//                     cout<<"valoarea elem ["<<i<<"] = "<<prodV.getValue(i)<<endl;
//                 }
            }
            else{
                prodV =((a^b)+a);

            }
            double modul = !prodV;
            for (i=0;i<3;i++)
            {
                prodV.setValue(i,prodV.getValue(i)/modul);
            }
            double medie =0;
            for(i=0;i<3;i++)
            {
                medie+=prodV.getValue(i);
            }
            printf("%.2lf",medie/3);

    }
    else if((nr1==nr2 && nr1>3) || nr1!=nr2)
    {
        uint16_t m = max(nr1,nr2);
        Vector nou(m);
        double s = a*b,medie=0;
        for (i=0;i<m;i++)
        {
            nou.setValue(i,s);
        }
        if(m ==nr1)
            nou= nou+a;
        else nou = nou+b;

        double modul = !nou;
        for (i=0;i<m;i++)
        {
            nou.setValue(i,nou.getValue(i)/modul);
        }
        for(i=0;i<m;i++)
        {
            medie+=nou.getValue(i);
        }
        printf("%.2lf",medie/m);
    }


    return 0;
}
