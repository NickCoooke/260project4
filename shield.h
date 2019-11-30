#ifdef SHIELD
#define SHIELD

#include "site.h"
#include "tree.h"

class Shield {
    public:
        Shield();
        Shield(const char* file);
        void addSite(const char* topic, const char * addy, const char* sum,
                const char* review, const int rating);
       void displayAll() const;
       void retrieve() const; //search path down towards pointer to site
       void displayTopic(const char* topic) const; 
       void remove(Site* s);
    private:
        void remove(Site* s); 

}


#endif
