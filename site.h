//site.h
/*
Site class stores information pertaining to a specific website and 
provides safe methods to access that data
*/

#ifndef SITE_H
#define SITE_H
#include "myutil.h"

class Site
{
    public:
        Site();
        Site(const char* topic, const char * addy, const char* sum,
                const char* review, const int rating);
        ~Site();
        char*   getTopic() const;
        char* 	getAddy() const;
        char* 	getSum() const;
        char* 	getReview() const;
        int 	getRating() const;
        char*   getKey() const;
        void    setRating(const int rating);
        void    setReview(const char* review);
        friend	ostream& operator<<(ostream& out, const Site* S); 
        bool    operator< (const Site& s) const;

    private:
        char*   topic;
        char*	addy;
        char*	sum;
        char*	review;
        int 	rating;
        void    init(const char* topic, const char * addy, const char* sum, 
                const char* review, const int rating);
        char*   key;
        void   keyGen();
};

#endif
