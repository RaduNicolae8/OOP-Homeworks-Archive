#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

class Person{
private:
    string mName;
    uint16_t mAge;
    double mSalary;
public:
    string getMName() const {
        return mName;
    }

    uint16_t getMAge() const {
        return mAge;
    }

    double getMSalary() const {
        return mSalary;
    }

    Person() : mName(""), mAge(0), mSalary(0) {}
    Person(const string &mName, uint16_t mAge, double mSalary) : mName(mName), mAge(mAge), mSalary(mSalary) {}

    bool operator == (const Person & p) const
    {
        if(p.getMAge()==this->mAge && p.getMName()==this->mName && p.getMSalary()==this->mSalary)
            return 1;
        return 0;
    }
    bool operator < (const Person & p) const
    {
        if (this->mName < p.getMName())
            return 1;
        return 0;
    }

};

class  Building{
protected:
    string mBuildingName,mType;
    Person mCoordinator;
    vector<Person> mEmployees,mCitizens;

public:
    Building(const string &mBuildingName, const string &mType) : mBuildingName(mBuildingName), mType(mType) {}

    virtual void add ( const Person & p) =0 ;
    virtual void remove ( const Person & p) = 0;

    virtual Building* operator + (const Person & p) =0;

    virtual Building* operator - ()
    {return this;}
    virtual Building* operator - (const Person & p)
    {return this;}

    string getBuildingName() const {
        return mBuildingName;
    }

    string getType() const {
        return mType;
    }

    uint16_t getEmployeesSize() const {
        return this->mEmployees.size();
    }

    uint16_t getCitizensSize() const {
        return this->mCitizens.size();
    }
    Person getEmployee(uint16_t index) const{
        return this->mEmployees[index];
    }

    Person getCitizen(uint16_t index)const {
        int16_t a = 0;
        for (Person p: mCitizens)
        {
            if(a==index)
                return p;
            a++;
        }
        Person abc;
        return abc;
    }

    Person getCoordinator() const{
        return mCoordinator;
    }
};

class CityHall : public Building{
public:
    CityHall(const string &mBuildingName) : Building(mBuildingName, "CityHall") {
        mCitizens.clear();
        Person p;
        this->mCoordinator = p;
    }

    Building *operator+(const Person & p)  {
        Person p2;
        if (this->mCoordinator == p2)
            this->mCoordinator = p;
        return this;
    }

    Building *operator-() override {
        Person p2;
        this->mCoordinator = p2;
        return this;    }

    void add(const Person & p) override {
        this->mCitizens.push_back(p);
    }

    void remove(const Person & p) override {
        int a=0;
        for (Person p1 : mCitizens) {
            if (p1 == p)
                this->mCitizens.erase(this->mCitizens.begin()+a);
            a++;
        }
    }
};

class Hospital : public Building{
public:
    Hospital(const string &mBuildingName) : Building(mBuildingName, "Hospital") {
        this->mCitizens.clear();
        this->mEmployees.clear();
    }

    Building *operator+(const Person & p)  {
        this->mEmployees.push_back(p);
        return this;  }

    Building *operator-(const Person & p)  {
        int a=0;
        for (Person p1 : mEmployees) {
            if (p1 == p)
                this->mEmployees.erase(this->mEmployees.begin()+a);
            a++;
        }
        return Building::operator-(p);
    }

    void add(const Person & p) override {
        this->mCitizens.push_back(p);
    }

    void remove(const Person & p) override {
        int a=0;
        for (Person p1 : mCitizens) {
            if (p1 == p)
                this->mCitizens.erase(this->mCitizens.begin()+a);
            a++;
        }
    }
};
class PoliceStation : public Building{
public:
    PoliceStation(const string &mBuildingName) : Building(mBuildingName, "PoliceStation") {
        this->mCitizens.clear();
        this->mEmployees.clear();
    }

    void add(const Person & p) override {
        this->mCitizens.push_back(p);
    }

    void remove(const Person & p) override {
        int a=0;
        for (Person p1 : mCitizens) {
            if (p1 == p)
                this->mCitizens.erase(this->mCitizens.begin()+a);
            a++;
        }
    }

    Building *operator+(const Person & p)  {
        this->mEmployees.push_back(p);
        return this;
    }

    Building *operator-(const Person & p)  {
        int a=0;
        for (Person p1 : mEmployees) {
            if (p1 == p)
                this->mEmployees.erase(this->mEmployees.begin()+a);
            a++;
        }
        return Building::operator-(p);
    }
};
class House : public Building{
private:
    uint16_t mMaxNumber;
public:
    House(const string &mBuildingName, uint16_t mMaxNumber) : Building(mBuildingName, "House"), mMaxNumber(mMaxNumber) {
        this->mCitizens.clear();
        Person p;
        this->mCoordinator = p;
    }
    Building *operator+(const Person & p)  {
        Person p2;
        if (this->mCoordinator == p2)
            this->mCoordinator = p;
        return this;    }

    Building *operator-()  {
        Person p2;
        this->mCoordinator = p2;
        return Building::operator-();
    }

    void add(const Person & p) override {
        if(this->getCoordinator()==Person())
        {
            if (mCitizens.size()<this->mMaxNumber)
                this->mCitizens.push_back(p);
        }
        else if (mCitizens.size()<(this->mMaxNumber-1 ))
            this->mCitizens.push_back(p);

    }

    void remove(const Person & p) override {
        if(p.getMAge()>=18)
        {
            int a=0;
            for (Person p1 : mCitizens) {
                if (p1 == p)
                    this->mCitizens.erase(this->mCitizens.begin()+a);
                a++;
            }
        }
    }
};

class Block : public Building{
private:
    uint16_t mMaxNumberPerFloor;
public:
    Block(const string &mBuildingName,uint16_t numar_etaje, uint16_t mMaxNumberPerFloor) : Building(mBuildingName,"Block"),mMaxNumberPerFloor(mMaxNumberPerFloor) {
        this->mCitizens.clear();
        Person p;
        this->mCoordinator = p;
        this->mCitizens.reserve(numar_etaje*mMaxNumberPerFloor);
        int a = 1;
        while (a!=numar_etaje*mMaxNumberPerFloor){
            this->mCitizens.push_back(p);
            a++;
        }
    }
    Building *operator+(const Person & p)  {
        Person p2;
        if (this->mCoordinator == p2)
            this->mCoordinator = p;
        return this;    }

    Building *operator-()  {
        Person p2;
        this->mCoordinator = p2;
        return this;
    }

    void add(const Person & p) override {
        Person p1;
        for(int i=0;i<mCitizens.size();i++)
            if (mCitizens[i] == p1)
            {
                mCitizens[i]=p;
                break;
            }
    }

    void remove(const Person & p) override {
        if (p.getMAge()>=18) {
            for (int i=0;i<mCitizens.size();i++)
                if (p==mCitizens[i])
                    mCitizens.erase(mCitizens.begin()+i);
        }

    }
};


int main() {
    /*cout << "Hello, World!" << endl;
    Person p1("abc",16,16);
    Person p2("abc",16,16);
    Person p3("abz",16,16);
    Person p4("coordonator",22,2000);
    int a = p1==p3;
    cout<<a;
    int b = p1<p3;
    cout<<' '<<b << endl;
    // test city hall

    CityHall c1("wow");
    c1.add(p1);
    c1.add(p3);
    c1+p4;
    c1+p2;
    c1.remove(p3);
    cout<<c1.getCitizensSize()<<endl;
    cout<<c1.getCoordinator().getMName(); */
    char a[2000][200]; int b=0,k=0,max;
    vector<Hospital> Hospitals;
    vector<CityHall> CityHalls;
    vector<PoliceStation> PoliceStations;
    vector<House> Houses;
    vector<Block> Blocks;
    vector<Person> People;
    int zz[100][2], indexc=0,indexb=0;
    for(int i=0;i<100;i++)
    {
        zz[i][0]=-1; // casa/block
        zz[i][1]=-1;  // index
    }
    while(scanf("%s", &a[k]) != EOF)
    { k++;}

    max =k; k=0;

    while (k!=max){
        if (strcmp(a[k],"add") == 0) {
            b = 1; k++;
            continue;
        }

        if (strcmp(a[k],"remove") == 0) {
            b = -1; k++;
            continue;
        }

        if (b==-1 && (strcmp(a[k],"citizen") == 0)){
            uint16_t age; double salary; int found =0;

            for (int i=0;i<Hospitals.size();i++){
                if (Hospitals[i].getBuildingName()==a[k+2]){
                    for (int j=0;j<Hospitals[i].getCitizensSize();j++)
                        if(a[k+1]==Hospitals[i].getCitizen(j).getMName())
                            Hospitals[i].remove(Hospitals[i].getCitizen(j));

                    break;}}

            for (int i=0;i<CityHalls.size();i++){
                if (CityHalls[i].getBuildingName()==a[k+2]){
                    for (int j=0;j<CityHalls[i].getCitizensSize();j++)
                        if(a[k+1]==CityHalls[i].getCitizen(j).getMName())
                            CityHalls[i].remove(CityHalls[i].getCitizen(j));

                    break;}}

            for (int i=0;i<PoliceStations.size();i++){
                if (PoliceStations[i].getBuildingName()==a[k+2]){
                    for (int j=0;j<PoliceStations[i].getCitizensSize();j++)
                        if(a[k+1]==PoliceStations[i].getCitizen(j).getMName())
                            PoliceStations[i].remove(PoliceStations[i].getCitizen(j));

                    break;}}

            for (int i=0;i<Houses.size();i++){
                if (Houses[i].getBuildingName()==a[k+2]){
                    for (int j=0;j<Houses[i].getCitizensSize();j++)
                        if(a[k+1]==Houses[i].getCitizen(j).getMName()) {
                            Houses[i].remove(Houses[i].getCitizen(j));

                        }
                    break;}}

            for (int i=0;i<Blocks.size();i++){
                if (Blocks[i].getBuildingName()==a[k+2]){
                    for (int j=0;j<Blocks[i].getCitizensSize();j++)
                        if(a[k+1]==Blocks[i].getCitizen(j).getMName())
                            Blocks[i].remove(Blocks[i].getCitizen(j));

                    break;}}

            b=0;k+=3;continue;


        }

        if (b==-1 && (strcmp(a[k],"employee") == 0)){
            uint16_t age; double salary; int found =0;

            for (int i=0;i<Hospitals.size();i++){
                if (Hospitals[i].getBuildingName()==a[k+2]){
                    for (int j=0;j<Hospitals[i].getEmployeesSize();j++)
                        if(a[k+1]==Hospitals[i].getEmployee(j).getMName())
                            Hospitals[i]-Hospitals[i].getEmployee(j);

                    break;}}


            for (int i=0;i<PoliceStations.size();i++){
                if (PoliceStations[i].getBuildingName()==a[k+2]){
                    for (int j=0;j<PoliceStations[i].getEmployeesSize();j++)
                        if(a[k+1]==PoliceStations[i].getEmployee(j).getMName())
                            PoliceStations[i]-PoliceStations[i].getEmployee(j);
                    break;}}
            b=0;k+=3;continue;

        }

        if (b==-1 && (strcmp(a[k],"coordinator") == 0)){
            uint16_t age; double salary; int found =0;


            for (int i=0;i<CityHalls.size();i++){
                if (CityHalls[i].getBuildingName()==a[k+2]){
                    if(a[k+1]==CityHalls[i].getCoordinator().getMName())
                        CityHalls[i].operator-();

                    break;}}

            for (int i=0;i<Houses.size();i++){
                if (Houses[i].getBuildingName()==a[k+2]){
                    if(a[k+1]==Houses[i].getCoordinator().getMName())
                        Houses[i].operator-();

                    break;}}

            for (int i=0;i<Blocks.size();i++){
                if (Blocks[i].getBuildingName()==a[k+2]){
                    if(a[k+1]==Blocks[i].getCoordinator().getMName())
                        Blocks[i].operator-();

                    break;}}

            b=0;k+=3;continue;


        }

        if (b==1 && (strcmp(a[k],"Hospital") == 0)){

            Hospital H(a[k+1]);
            Hospitals.push_back(H);
            b=0; k+=2;
            continue;
        }
        if (b==1 && (strcmp(a[k],"CityHall") == 0)){
            CityHall H(a[k+1]);
            CityHalls.push_back(H);
            b=0; k+=2;
            continue;

        }
        if (b==1 && (strcmp(a[k],"PoliceStation") == 0)){
            PoliceStation H(a[k+1]);
            PoliceStations.push_back(H);
            b=0; k+=2;
            continue;
        }
        if (b==1 && (strcmp(a[k],"House") == 0)){

            uint16_t size;
            sscanf(a[k+2],"%hu",&size);
            House H(a[k+1],size);
            Houses.push_back(H);
            zz[indexc+indexb][0]=0;
            zz[indexc+indexb][1]=indexc;
            indexc++;
            b=0; k+=3; continue;

        }
        if (b==1 && (strcmp(a[k],"Block") == 0)){
            uint16_t etaje,maxetaj;
            sscanf(a[k+2],"%hu",&etaje);
            sscanf(a[k+3],"%hu",&maxetaj);
            Block H(a[k+1],etaje,maxetaj);
            Blocks.push_back(H);
            zz[indexc+indexb][0]=1;
            zz[indexc+indexb][1]=indexb;
            indexb++;
            b=0; k+=4; continue;

        }

        if (b==1 && (strcmp(a[k],"coordinator") == 0)){
            uint16_t age; double salary;
            //sscanf("%s", &nume); k+1
            sscanf(a[k+2],"%hu",&age);
            sscanf(a[k+3],"%lf",&salary);
            //scanf("%s", &a); k+4
            Person p(a[k+1],age,salary);
            People.push_back(p);

            for (int i=0;i<Hospitals.size();i++){
                if (Hospitals[i].getBuildingName()==a[k+4]){
                    Hospitals[i]+p;
                    break;}}

            for (int i=0;i<CityHalls.size();i++){
                if (CityHalls[i].getBuildingName()==a[k+4]){
                    CityHalls[i]+p;
                    break;}}

            for (int i=0;i<PoliceStations.size();i++){
                if (PoliceStations[i].getBuildingName()==a[k+4]){
                    PoliceStations[i]+p;
                    break;}}

            for (int i=0;i<Houses.size();i++){
                if (Houses[i].getBuildingName()==a[k+4]){
                    if(!(Houses[i].getCoordinator()==Person()))
                        remove(People.begin(),People.end(),p);
                    Houses[i]+p;
                    break;}}

            for (int i=0;i<Blocks.size();i++){
                if (Blocks[i].getBuildingName()==a[k+4]){
                    Blocks[i]+p;
                    break;}}

            b=0;k+=5;continue;



        }
        if (b==1 && (strcmp(a[k],"employee") == 0)){
            uint16_t age; double salary;
            //sscanf("%s", &nume); k+1
            sscanf(a[k+2],"%hu",&age);
            sscanf(a[k+3],"%lf",&salary);
            //scanf("%s", &a); k+4
            Person p(a[k+1],age,salary);

            for (int i=0;i<Hospitals.size();i++){
                if (Hospitals[i].getBuildingName()==a[k+4]){
                    Hospitals[i]+p;
                    break;}}

            for (int i=0;i<CityHalls.size();i++){
                if (CityHalls[i].getBuildingName()==a[k+4]){
                    CityHalls[i]+p;
                    break;}}

            for (int i=0;i<PoliceStations.size();i++){
                if (PoliceStations[i].getBuildingName()==a[k+4]){
                    PoliceStations[i]+p;
                    break;}}

            for (int i=0;i<Houses.size();i++){
                if (Houses[i].getBuildingName()==a[k+4]){
                    Houses[i]+p;
                    break;}}

            for (int i=0;i<Blocks.size();i++){
                if (Blocks[i].getBuildingName()==a[k+4]){
                    Blocks[i]+p;
                    break;}}

            b=0;k+=5;continue;
        }
        if (b==1 && (strcmp(a[k],"citizen") == 0)){
            uint16_t age; double salary;
            //sscanf("%s", &nume); k+1
            sscanf(a[k+2],"%hu",&age);
            sscanf(a[k+3],"%lf",&salary);
            //scanf("%s", &a); k+4
            Person p(a[k+1],age,salary);
            for (int i=0;i<Hospitals.size();i++){
                if (Hospitals[i].getBuildingName()==a[k+4]){
                    Hospitals[i].add(p);
                    break;}}

            for (int i=0;i<CityHalls.size();i++){
                if (CityHalls[i].getBuildingName()==a[k+4]){
                    CityHalls[i].add(p);
                    break;}}

            for (int i=0;i<PoliceStations.size();i++){
                if (PoliceStations[i].getBuildingName()==a[k+4]){
                    PoliceStations[i].add(p);
                    break;}}

            for (int i=0;i<Houses.size();i++){
                if (Houses[i].getBuildingName()==a[k+4]){
                    Houses[i].add(p);
                    break;}}

            for (int i=0;i<Blocks.size();i++){
                if (Blocks[i].getBuildingName()==a[k+4]){
                    Blocks[i].add(p);
                    break;}}

            b=0;k+=5;continue;


        }

    }
    /* cout<<Hospitals[0].getBuildingName()<<endl;
     cout<<Blocks[0].getBuildingName()<<endl;
     cout<<Hospitals[0].getCitizensSize()<<endl;
     cout<<Hospitals[0].getCitizen(0).getMName()<<endl;
     cout<<Blocks[0].getCitizensSize()<<endl;
     cout<<Blocks[0].getCitizen(0).getMName()<<endl;
     cout<<Hospitals[0].getEmployee(0).getMName()<<endl;
     cout<<Hospitals[0].getEmployeesSize()<<endl; */

    //main run
    cout<<"Type: ";
    if(CityHalls.size()>=3 && Hospitals.size()>=2 && PoliceStations.size()>=3 && Houses.size() >= 8 && Blocks.size()>=4)
        cout<<"Capital";
    else if(CityHalls.size()>=2 && Hospitals.size()>=1 && PoliceStations.size()>=2 && Houses.size() >= 4 && Blocks.size()>=1)
        cout<<"Town";
    else cout<<"Village";
    cout<<endl;

    int j=0;
    for (Hospital h:Hospitals)
        j+=h.getCitizensSize();
    cout<<"Number of patients in hospitals: "<<j<<endl;

    double salariu=0, medie=0;
    for (Hospital h:Hospitals){
        for(int i=0;i<h.getEmployeesSize();i++){
            salariu+=h.getEmployee(i).getMSalary();
            medie++;
        }
    }
    if(salariu==0)
        cout<<"Average salary for doctors: 0"<<endl;
    else
        cout<<"Average salary for doctors: "<<salariu/medie<<endl;

    salariu=0;medie=0;
    for (PoliceStation h:PoliceStations){
        for(int i=0;i<h.getEmployeesSize();i++){
            salariu+=h.getEmployee(i).getMSalary();
            medie++;
        }
    }
    if(salariu==0)
        cout<<"Average salary for cops: 0"<<endl;
    else
        cout<<"Average salary for cops: "<<salariu/medie<<endl;

    salariu=0;medie=0;
    for (CityHall c:CityHalls)
    {
        if(c.getCoordinator().getMSalary()!=0){
            salariu+= c.getCoordinator().getMSalary();
            medie++;}
    }
    if(salariu==0)
        cout<<"Average salary for mayors: 0"<<endl;
    else
        cout<<"Average salary for mayors: "<<salariu/medie<<endl;

    salariu=0;medie=0;
    for (CityHall h:CityHalls){
        for(int i=0;i<h.getCitizensSize();i++){
            salariu+=h.getCitizen(i).getMSalary();
            medie++;
        }
    }
    if(salariu==0)
        cout<<"Average salary for city hall employees: 0"<<endl;
    else
        cout<<"Average salary for city hall employees: "<<salariu/medie<<endl;

    salariu=0;medie=0; double varsta =0;
    for (PoliceStation h:PoliceStations){
        for(int i=0;i<h.getCitizensSize();i++){
            varsta+=h.getCitizen(i).getMAge();
            medie++;
        }
    }
    if(varsta==0)
        cout<<"Average age of busted in police stations: 0"<<endl;
    else
        cout<<"Average age of busted in police stations: "<<varsta/medie<<endl;

    int ph[100];
    for(int i=0;i<100;i++)
        ph[i]=0; //aici o sa fie indexul casei <=> i
    for(int i=0;i<Houses.size();i++){
        ph[i]+=Houses[i].getCitizensSize();
        if(!(Houses[i].getCoordinator()==Person()))
            ph[i]++;
    }

    Person PP;
    int pb[100];
    for(int i=0;i<100;i++)
        pb[i]=0; //aici o sa fie indexul b <=> i
    for(int i=0;i<Blocks.size();i++){
        for (int j=0;j<Blocks[i].getCitizensSize();j++){
            if(Blocks[i].getCitizen(j).getMAge()!=0)
                pb[i]++;
        }
        if(Blocks[i].getCoordinator().getMAge()!=0)
            pb[i]++;
    }
    for (int i=0;i<100;i++){
        if(zz[i][1]==-1)
            break;
        if(zz[i][0]==0)
            cout << "Number of people in House " << Houses[zz[i][1]].getBuildingName() << ": " << ph[zz[i][1]] << endl;

        if(zz[i][0]==1)
            cout<<"Number of people in Block "<<Blocks[zz[i][1]].getBuildingName()<<": "<<pb[zz[i][1]]<<endl;

    }
    cout<<"Administrators of house and block: ";

    map<string, int> people2;
    for (int i=0;i<People.size();i++)
    {
        if(people2.count(People[i].getMName()))
            continue;

        people2.insert({People[i].getMName(),0});
        for(House h:Houses){
            if(People[i] == h.getCoordinator())
                people2[People[i].getMName()]++;
        }
        for(Block h:Blocks){
            if(People[i] == h.getCoordinator())
                people2[People[i].getMName()]++;
        }
    }
    bool foundd = false;
    for(pair<string,int> p: people2)
    {
        if(p.second == 2)
        {
            cout<<p.first<<' ';
            foundd=true;
        }
    }
    if(!foundd)
        cout<<"nobody";

    return 0;

}
