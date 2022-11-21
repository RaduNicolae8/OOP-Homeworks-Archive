#include <iostream>
#include<cstdio>
#include <vector>
#include <algorithm>

using namespace std;
class Video {
private:
    string mVideoId;
    uint32_t mLikes, mDislikes,mViews;
protected :
    Video(const string &mVideoId, const uint32_t &mLikes, const uint32_t &mDislikes, const uint32_t &mViews):
            mVideoId(mVideoId),mLikes(mLikes),mDislikes(mDislikes),mViews(mViews){}
public:
   string getId() const{
    return mVideoId;
}

    virtual ~Video() {
    }

    uint32_t getDislikes() const{
    return mDislikes;
}
double getSimpleScore() const{
    return (double) mLikes /(double) mDislikes +1 - 1/(double)mViews ;
}

void update(uint32_t likes, uint32_t dislikes, uint32_t views)
{
    mLikes = likes;
    mDislikes = dislikes;
    mViews = views;
}

  virtual double getAdvancedScore() const =0;

void print(bool simple) const{

    cout<<mVideoId;
    if(simple==true)
        printf(" %.2lf\n",getSimpleScore());
    else
        printf(" %.2lf\n",getAdvancedScore());
}

};
 class StudyVideo: public Video {
 public :
     StudyVideo(const string &a, uint32_t b, uint32_t c, uint32_t d)
     : Video(a,b,c,d)
     { }
     double getAdvancedScore() const{
     return getSimpleScore()*2;
 }
 };

 class AnimalVideo: public Video{
 public:
     AnimalVideo(const string &a, uint32_t b, uint32_t c, uint32_t d )
     : Video(a,b,c,d)
     { }
     double getAdvancedScore() const{
         return getSimpleScore()*0.75;
     }

     virtual ~AnimalVideo() {
     }
 };

class SportsVideo: public Video{
public:
    SportsVideo(const string &a, uint32_t b, uint32_t c, uint32_t d )
            : Video(a,b,c,d)
    { }
    double getAdvancedScore() const{
        return getSimpleScore()*0.5;
    }
};

class VideoFactory: public Video{
public:
    VideoFactory(): Video("",0,0,0){
    }
    static Video* createVideo(const string & id, const string & type, uint32_t likes, uint32_t dislikes, uint32_t views)
    {
        if (type == "Animale")
            return new AnimalVideo(id,likes,dislikes,views);
        else if(type == "Studiu")
            return new StudyVideo(id,likes,dislikes,views);
        else if(type == "Sport")
            return new SportsVideo(id,likes,dislikes,views);
        else{
            //throw error
            throw invalid_argument("EROARE");
        }
    }
    double getAdvancedScore() const{
        return 0;
    }

     ~VideoFactory() {

    }

};



static bool comparare(Video* a, Video* b){
    if(a->getSimpleScore()>b->getSimpleScore())
        return false;
    else if(a->getSimpleScore()==b->getSimpleScore())
    {
       if(a->getDislikes()>b->getDislikes())
           return true;
       else return false;
    }
    return true;
}

static bool comparare2(Video* a, Video* b){
    if(a->getAdvancedScore()>b->getAdvancedScore())
        return false;
    return true;
}

int main() {
    string id,type;
    uint32_t n,likes,dislikes,views;
    char cerinta;
    cin>>n;
    vector<Video*> lista;
    VideoFactory fac;

    for(int i=0;i<n;i++)
    {
        cin>>id>>type>>views>>likes>>dislikes;
        try{
            lista.push_back(fac.createVideo(id,type,likes,dislikes,views));
        }
        catch(invalid_argument e)
        {
            cerr<< e.what()<< endl;
            return -1;
        }
    }
    cin>>cerinta;

    if(cerinta == 'a')
    {
        sort(lista.begin(),lista.end(),comparare);
        for (Video* v : lista)
        {
            v->print(true);
        }
    }

    else if(cerinta == 'b')
    {
        double suma=0,medie;
        int contor=0;
        for(Video* v : lista)
        {
            suma+=v->getSimpleScore();
            contor++;
        }
        medie = suma/contor;

        for(Video* v : lista)
        {
            if(v->getSimpleScore() > medie)
                v->print(true);
        }
    }

    else if(cerinta == 'c')
    {
        bool gasit;
        char a;
        //        cin>>id>>type>>views>>likes>>dislikes;
        while(scanf("%c",&a)!=EOF)
        {
            cin>>id;
            gasit = false;
            cin>>type>>views>>likes>>dislikes;
            for (int i=0;i<lista.size();i++)
            {
                //cout<<"IDS = ~~"<<lista[i]->getId()<<" + "<<id<<endl;
                if (lista[i]->getId() == id)
                {
                    //cout<<"ID EGALE  ~~"<<lista[i]->getId()<<" + "<<id<<endl;
                    lista[i]->update(likes,dislikes,views);
                    gasit = true;
                    break;
                }
            }
            if (!gasit)
             lista.push_back(fac.createVideo(id,type,likes,dislikes,views));
        }
        sort(lista.begin(),lista.end(),comparare);
        for (Video* v : lista)
        {
            v->print(true);
        }
    }
    else if(cerinta == 'd')
    {
        sort(lista.begin(),lista.end(),comparare2);
        for (Video* v: lista)
        {
            v->print(false);
        }
    }


    return 0;
}
