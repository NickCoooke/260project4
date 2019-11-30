//site.cpp


#include "site.h"
#include "myutil.h"

//defualt constructor 
Site::Site(){
	int dRating = 0;
	char dAddy[] = "no addy";
	char dSum[] = "no sum";
	char dReview[] = "no review";
    char dTopic[] = "no topic";
    init(dTopic, dAddy, dSum, dReview, dRating); 
}

//creates and populates site
Site::Site(const char* topic, const char* addy, const char* sum, const char* review, const int rating){
	init(topic, addy, sum, review, rating);
}

//initializes members
void Site::init(const char* topic, const char* addy, const char* sum, const char* review, const int rating)
{

	this->topic = new char[strlen(topic) + 1];
	strcpy(this->topic, topic);
	
    this->addy = new char[strlen(addy) + 1];
	strcpy(this->addy, addy);
	
    this->sum = new char[strlen(sum) + 1];
	strcpy(this->sum, sum);
	
    this->review = new char[strlen(review) + 1];
	strcpy(this->review, review);
	
    this->rating = rating;
    
    keyGen();     
}

//handles sites deletion and mannages allocated data
Site::~Site()
{
	
	if (this->topic) {
		delete[] topic;
	}
    topic = nullptr;

	if (this->addy) {
		delete[] addy;
	}
	addy = nullptr;
    
	if (this->sum) {
		delete[] sum;
	}
	sum = nullptr;
	
    if (this->review) {
		delete[] review;
	}
	review = nullptr;

     if (this->key) {
		delete[] key;
	}
	key = nullptr;
}



//return a copy of this->topic
char * Site::getTopic() const{
	return this->topic;
}



//return a copy of this->addy 
char * Site::getAddy() const{
	return this->addy;
}



//return a copy of this->sum 
char* Site::getSum() const {
	return this->sum;	
}



//return a copy of this->review 
char* Site::getReview() const {
	return this->review;	
}



//return a copy of this->rating 
int Site::getRating() const {
	return rating;
}



//Returns a copy of this->key
char* Site::getKey() const {
    return key; 
}

//Private key generator. 
void Site::keyGen()
{ 
    if(addy)
        key = addy;
    else
        key = nullptr;
    /*
    //key = topic + addy
    char* ret = new char[MAX_CHAR];
    strcpy(ret, this->getTopic());
    strcat(ret, this->getAddy());
    if(key)
    {
        //Key exists
        delete[] key;
	    this->key = new char[strlen(ret) + 1];
    	strcpy(key, ret);
    }
    else
        key = ret;
    */  

}


//change this->rating to input rating
void Site::setRating(const int rating) {
	this->rating = rating;
}



//change this->review to input review
void Site::setReview(const char* review) 
{
	delete[] this->review;
	this->review = new char[strlen(review) + 1];
	strcpy(this->review, review);
}



//format Site S data and retrun ostream obj 
ostream& operator<<(ostream& out, const Site* S) 
{   
    
    out << "Key:      \t" << S->getKey()
        << "\nTopic:    \t" << S->getTopic()  
        << "\nAddress:\t" << S->getAddy()
        << "\nSummary:\t" << S->getSum()
        << "\nReview: \t" << S->getReview()
        << "\nRating(0-5):\t";
    for(int i = 0; i < S->getRating(); i++) 
        out << "*";
    out << endl;
    
    return out;
}


/*
   const Site& Site::operator=(const Site& s)
   { INCOMPLETE!!!
   if (this == &s)
   return *this;
   this->setTopic(s.topic);
   this->setAddy(s.addy);
   this->setReview
   return *this;
   }
   */

bool Site::operator>(const Site& s) const
{
    return strcmp(s.getKey(), key) < 0;
}
bool Site::operator<(const Site& s) const
{
    return strcmp(key, s.getKey()) < 0;
}
bool Site::operator!=(const Site& s) const
{
    if(strcmp(key, s.getKey()) == 0)
        return false;
    else 
        return true;
}


