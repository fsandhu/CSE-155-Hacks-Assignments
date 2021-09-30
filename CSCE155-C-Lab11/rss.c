#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>

#include "rss.h"

// implement these functions

Rss * createEmptyRss() {
    return createRss ("", "", "", "");
}

Rss * createRss(const char * title, const char * link, const char * date, const char * description) {
    Rss *rss = (Rss*) malloc (sizeof(Rss) * 1);
    
    rss->title = (char*) malloc (sizeof(char) * strlen(title)+1);
    strcpy(rss->title, title);

    rss->link = (char*) malloc (sizeof(char) * strlen(link)+1);
    strcpy(rss->link, link);

   strptime(date, "%a, %d %b %Y %H: %M: %S", &(rss->publicationDate));
   // rss->publicationDate = (char*) malloc (sizeof(char) * strlen(date)+1);
   // strcpy(rss->publicationDate, date);

    rss->description = (char*) malloc (sizeof(char) * strlen(description)+1);
    strcpy(rss->description, description);

    return rss;
}

void printRss(Rss * item) {
   
   printf("%s\n %s\n (%4d-%02d-%02d)\n %s\n", 
         item->title, item->link, item->publicationDate.tm_year +1900, 
         item->publicationDate.tm_mon+1, item->publicationDate.tm_mday,
         item->description);
   
   return;
}
